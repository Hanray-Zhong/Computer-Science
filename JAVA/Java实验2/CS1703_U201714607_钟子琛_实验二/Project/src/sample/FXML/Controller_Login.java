package sample.FXML;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.stage.Stage;
import sample.DataBase.DataBaseUtil;
import sample.Main;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;

public class Controller_Login implements Initializable {
    public Main application;

    @FXML
    TextField textField_account;
    @FXML
    PasswordField passwordField_password;
    @FXML
    MenuButton menuButton_userType;

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        System.out.println("Login initialize");
    }

    public void Login(ActionEvent event) throws IOException {
        application.UserLogin(textField_account.getText(), passwordField_password.getText(), menuButton_userType.getText());
    }

    public void ChangeUser2Patient() {
        menuButton_userType.setText("病人");
    }
    public void ChangeUser2Doctor() {
        menuButton_userType.setText("医生");
    }

    public void setApp(Main main) {
        application = main;
    }
}
