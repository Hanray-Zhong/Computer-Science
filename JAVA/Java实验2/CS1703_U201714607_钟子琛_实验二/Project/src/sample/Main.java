package sample;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.fxml.JavaFXBuilderFactory;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.SplitPane;
import javafx.scene.layout.AnchorPane;
import javafx.stage.Stage;
import sample.DataBase.DataBaseUtil;
import sample.FXML.Controller_DoctorRegistration;
import sample.FXML.Controller_Login;
import sample.FXML.Controller_PatientRegistration;

import java.io.IOException;
import java.io.InputStream;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Main extends Application {
    private Stage stage;
    private static FXMLLoader myloader = null;

    @Override
    public void start(Stage primaryStage) throws Exception{
        stage = primaryStage;
        stage.setTitle("登陆界面");
        stage.setMinWidth(500);
        stage.setMinHeight(280);
        gotologin();
        stage.setResizable(false);
        stage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }

    private Initializable replaceSceneContent(String title, String fxml, double width, double height, int type) throws Exception {
        FXMLLoader loader = new FXMLLoader();
        InputStream in = Main.class.getResourceAsStream(fxml);
        loader.setBuilderFactory(new JavaFXBuilderFactory());
        loader.setLocation(Main.class.getResource(fxml));
        SplitPane Spage;
        AnchorPane Apage;
        if (type == 0) {
            Apage = (AnchorPane) loader.load(in);
            Scene scene = new Scene(Apage, width, height);
            stage.setTitle(title);
            stage.setScene(scene);
            stage.sizeToScene();
        }
        else if (type == 1) {
            Spage = (SplitPane) loader.load(in);
            Scene scene = new Scene(Spage, width, height);
            stage.setTitle(title);
            stage.setScene(scene);
            stage.sizeToScene();
        } else {

        }
        in.close();
        myloader = loader;
        return (Initializable) loader.getController();
    }

    public void gotologin(){
        try {
            Controller_Login login =
                    (Controller_Login) replaceSceneContent("登陆界面", "FXML/Login.fxml", 500, 280, 0);
            login.setApp(this);
        } catch (Exception ex) {
            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    public void gotoDocMain(String account){
        try {
            Controller_DoctorRegistration docMain =
                    (Controller_DoctorRegistration) replaceSceneContent("医生信息", "FXML/DoctorRegistration.fxml", 800, 600, 1);
            docMain.setApp(this, account);
        } catch (Exception ex) {
            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    public void gotoPatientMain(String account) {
        try {
            Controller_PatientRegistration patientMain =
                    (Controller_PatientRegistration) replaceSceneContent("医院挂号系统", "FXML/PatientRegistration.fxml", 600, 400, 1);
            patientMain.setApp(this, account);
        } catch (Exception ex) {
            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    public void UserLogin(String account, String password, String type) throws IOException {
        if (type.equals("医生")) {
            if (DataBaseUtil.CheckDoctor(account, password)) {
                System.out.println("Login Success");
                gotoDocMain(account);
            }
            else {
                Alert information = new Alert(Alert.AlertType.ERROR,"登陆失败！");
                information.setTitle("提示");
                information.setHeaderText("错误：");
                Button infor = new Button("确定");
                information.showAndWait();
            }
        }
        else  {
            if (DataBaseUtil.CheckPatient(account, password)) {
                System.out.println("Login Success");
                gotoPatientMain(account);
            }
            else {
                Alert information = new Alert(Alert.AlertType.ERROR,"登陆失败！");
                information.setTitle("提示");
                information.setHeaderText("错误：");
                Button infor = new Button("确定");
                information.showAndWait();
            }
        }

    }
}
