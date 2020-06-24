package sample.FXML;

import javafx.application.Platform;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import sample.DataBase.DataBaseUtil;
import sample.Main;

import java.net.URL;
import java.sql.Timestamp;
import java.time.LocalDate;
import java.util.List;
import java.util.ResourceBundle;

public class Controller_UserRegistration implements Initializable {
    private Main application;
    private String account;
    private boolean isVip;
    private int rentStatus;
    private double userAmount;

    @FXML
    Label label_name, label_VIP, label_rentStatus;
    @FXML
    ComboBox comboBox_carType, comboBox_carID;
    @FXML
    TextField textField_rentalAmount, textField_deposit, textField_totalAmount, textField_userAmount, textField_userPay;

    @FXML
    public void UpdateCarIDCombobox() {
        System.out.println(comboBox_carType.getValue().toString() + " Update Car ID Combobox");
        List<String> list_carid = DataBaseUtil.GetCarIDList(comboBox_carType.getValue().toString());
        if (list_carid == null)
            return;
        comboBox_carID.getItems().clear();
        textField_rentalAmount.clear();
        textField_deposit.clear();
        for (String id : list_carid) {
            comboBox_carID.getItems().add(id);
        }
    }
    @FXML
    public void UpdateAmountandDeposit() {
        System.out.println("Update Amount and Deposit");
        double rentalAmount, deposit, totalAmount;
        rentalAmount = DataBaseUtil.GetRentalAmount(comboBox_carID.getValue().toString());
        deposit = DataBaseUtil.GetDeposit(comboBox_carID.getValue().toString());
        totalAmount = rentalAmount + deposit;
        textField_rentalAmount.setText("" + rentalAmount);
        textField_deposit.setText("" + deposit);
        textField_totalAmount.setText("" + totalAmount);
    }
    @FXML
    public void Caculate() {
        if (rentStatus != 0) {
            Alert information = new Alert(Alert.AlertType.ERROR,"暂时无法租车！");
            information.setTitle("提示");
            information.setHeaderText("错误：");
            Button infor = new Button("确定");
            information.showAndWait();
            return;
        }

        double totalAmount, userAmount, userPay;
        totalAmount = Double.valueOf(textField_totalAmount.getText());
        userAmount = Double.valueOf(textField_userAmount.getText());
        userPay = Double.valueOf((textField_userPay.getText().equals("") || textField_userPay.getText() == null) ? "0" : textField_userPay.getText());
        if (totalAmount > userAmount + userPay) {
            Alert information = new Alert(Alert.AlertType.ERROR,"余额不足！");
            information.setTitle("提示");
            information.setHeaderText("错误：");
            Button infor = new Button("确定");
            information.showAndWait();
        }
        else {
            // 更新金额
            DataBaseUtil.UpdateUserAmount(account, userAmount + userPay - totalAmount);
            textField_userAmount.setText("" + (userAmount + userPay - totalAmount));
            textField_userPay.clear();
            // 更新租车信息
            DataBaseUtil.UpdateRentalStatus(account, comboBox_carID.getValue().toString(), new Timestamp(System.currentTimeMillis()));
            Alert information = new Alert(Alert.AlertType.INFORMATION,"租车成功！");
            information.setTitle("提示");
            information.setHeaderText("提示：");
            Button infor = new Button("确定");
            information.showAndWait();
            Platform.exit();
        }
    }

    @Override
    public void initialize(URL location, ResourceBundle resources) {

    }


    public void setApp(Main main, String account) {
        this.application = main;
        this.account = account;
        myInitialize();
    }

    private void myInitialize() {
        Welcome();
        CheckVip();
        CheckRentStatus();
        InitializeCarTypes();
        InitializeUserAmount();
    }
    private void Welcome() {
        // welcome
        label_name.setText("欢迎！" + DataBaseUtil.GetUserName(account));
    }
    private void CheckVip() {
        // check vip
        int isVIP = DataBaseUtil.CheckVIP(account);
        if (isVIP == 0) {
            label_VIP.setText("您暂时还不是会员！");
            this.isVip = false;
        }
        else if (isVIP == 1) {
            label_VIP.setText("您现在是会员！");
            this.isVip = true;
        }
        else {
            label_VIP.setText("检查会员状态异常！");
            this.isVip = false;
        }
    }
    private void CheckRentStatus() {
        rentStatus = DataBaseUtil.CheckUserRentStatus(account);
        if (rentStatus == 0) {
            label_rentStatus.setText("尚未租车");
        }
        else if (rentStatus == 1) {
            label_rentStatus.setText("已经租车");
        }
        else {
            label_rentStatus.setText("状态异常");
        }
    }
    private void InitializeCarTypes() {
        List<String> carTypes = DataBaseUtil.GetCarTypes(isVip);
        System.out.println(carTypes);
        for (String type : carTypes) {
            comboBox_carType.getItems().add(type);
        }
    }
    private void InitializeUserAmount() {
        userAmount = DataBaseUtil.GetUserAmount(account);
        textField_userAmount.setText("" + userAmount);
    }
}
