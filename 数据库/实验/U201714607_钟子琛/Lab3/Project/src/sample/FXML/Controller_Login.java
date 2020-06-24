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

    public void Change2User() {
        menuButton_userType.setText("用户");
    }
    public void Change2Staff() {
        menuButton_userType.setText("员工");
    }

    public void setApp(Main main) {
        application = main;
    }
}
