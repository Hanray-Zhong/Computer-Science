package sample.FXML;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import sample.DataBase.DataBaseUtil;
import sample.Main;
import sample.Others.*;

import java.net.URL;
import java.sql.Date;
import java.text.SimpleDateFormat;
import java.time.LocalDate;
import java.util.Calendar;
import java.util.List;
import java.util.ResourceBundle;

public class Controller_StaffRegistration implements Initializable {
    private Main application;
    private String account;
    private ObservableList<RentalRecordColumn> rentalRecord = FXCollections.observableArrayList();
    private ObservableList<RepairRecordColumn> repairRecord = FXCollections.observableArrayList();
    private ObservableList<RevenueColumn> revenue_D = FXCollections.observableArrayList();
    private ObservableList<RevenueColumn> revenue_M = FXCollections.observableArrayList();
    private ObservableList<RevenueColumn> revenue_S = FXCollections.observableArrayList();
    private ObservableList<RevenueColumn> revenue_Y = FXCollections.observableArrayList();

    @FXML
    ComboBox comboBox_users;
    @FXML
    TextField textField_carid, textField_fine, textField_userAmount, textField_userpay;
    @FXML
    Label label_trafficViolation;
    @FXML
    TableView tableView_RentalRecord;
    @FXML
    TableColumn userId_1, userName_1, carType_1, carId_1, rentDate_1, returnDate_1;
    @FXML
    TableView tableView_RepairRecord;
    @FXML
    TableColumn carType_2, carId_2;
    @FXML
    TableView tableView_Revenue_D;
    @FXML
    TableColumn userName_3, carId_3, rentAmount_3, rentDate_3;
    @FXML
    TableView tableView_Revenue_M;
    @FXML
    TableColumn userName_4, carId_4, rentAmount_4, rentDate_4;
    @FXML
    TableView tableView_Revenue_S;
    @FXML
    TableColumn userName_5, carId_5, rentAmount_5, rentDate_5;
    @FXML
    TableView tableView_Revenue_Y;
    @FXML
    TableColumn userName_6, carId_6, rentAmount_6, rentDate_6;


    @FXML
    public void UpdateCarIdTextfield() {
        if (comboBox_users.getValue() == null) return;

        String userid = DataBaseUtil.GetUserId(comboBox_users.getValue().toString());
        textField_carid.setText(DataBaseUtil.GetCarIdFromUserName(comboBox_users.getValue().toString()));
        textField_userAmount.setText("" + DataBaseUtil.GetUserAmount(userid));
        double fine = DataBaseUtil.GetFine(userid);
        if (fine != -1) {
            label_trafficViolation.setText("您存在违反交规的情况！请缴纳罚金！");
            textField_fine.setText("" + fine);
            textField_userpay.setEditable(true);
        }
        else {
            label_trafficViolation.setText("您不存在违反交规的情况！");
        }
    }
    @FXML
    public void ConfirmReturn() {
        if (comboBox_users.getValue() == null) {
            Alert information = new Alert(Alert.AlertType.ERROR,"错误！");
            information.setTitle("提示");
            information.setHeaderText("提示：");
            Button infor = new Button("确定");
            information.showAndWait();
            return;
        }

        String userid = DataBaseUtil.GetUserId(comboBox_users.getValue().toString());
        String carid = textField_carid.getText();
        double fine = DataBaseUtil.GetFine(userid);
        double deposit = DataBaseUtil.GetDeposit(carid);
        double userAmount = Double.valueOf(textField_userAmount.getText());
        if (fine == -1) {
            DataBaseUtil.ReturnCar(userid, carid);
            DataBaseUtil.UpdateUserAmount(userid, userAmount + deposit);
            Alert information = new Alert(Alert.AlertType.INFORMATION,"还车成功！");
            information.setTitle("提示");
            information.setHeaderText("提示：");
            Button infor = new Button("确定");
            information.showAndWait();
        }
        else {
            double userpay = Double.valueOf((textField_userpay.getText().equals("") || textField_userpay.getText() == null) ? "0" : textField_userpay.getText());
            if (fine > userAmount + deposit + userpay) {
                Alert information = new Alert(Alert.AlertType.ERROR,"余额不足，还车失败！");
                information.setTitle("提示");
                information.setHeaderText("提示：");
                Button infor = new Button("确定");
                information.showAndWait();
            }
            else {
                DataBaseUtil.UpdateUserAmount(userid, userAmount + deposit + userpay - fine);
                DataBaseUtil.UpdateTrafficFineStatus(userid);
                DataBaseUtil.ReturnCar(userid, carid);
                Alert information = new Alert(Alert.AlertType.INFORMATION,"还车成功！");
                information.setTitle("提示");
                information.setHeaderText("提示：");
                Button infor = new Button("确定");
                information.showAndWait();
            }
        }

        textField_carid.clear();
        textField_fine.clear();
        textField_userpay.clear();
        textField_userAmount.clear();
        InitializeComboboxUsers();
    }
    @FXML
    public void CaculateRentalRecord() {
        userId_1.setCellValueFactory(new PropertyValueFactory("userId"));
        userName_1.setCellValueFactory(new PropertyValueFactory("userName"));
        carType_1.setCellValueFactory(new PropertyValueFactory("carType"));
        carId_1.setCellValueFactory(new PropertyValueFactory("carId"));
        rentDate_1.setCellValueFactory(new PropertyValueFactory("rentDate"));
        returnDate_1.setCellValueFactory(new PropertyValueFactory("returnDate"));

        rentalRecord = DataBaseUtil.GetRentalRecord();
        tableView_RentalRecord.setItems(rentalRecord);
    }
    @FXML
    public void CaculateRepairRecord() {
        carType_2.setCellValueFactory(new PropertyValueFactory("carType"));
        carId_2.setCellValueFactory(new PropertyValueFactory("carId"));

        repairRecord = DataBaseUtil.GetRepairRecord();
        tableView_RepairRecord.setItems(repairRecord);
    }
    @FXML
    public void CaculateRevenue_D() {
        userName_3.setCellValueFactory(new PropertyValueFactory("userName"));
        carId_3.setCellValueFactory(new PropertyValueFactory("carId"));
        rentAmount_3.setCellValueFactory(new PropertyValueFactory("rentAmount"));
        rentDate_3.setCellValueFactory(new PropertyValueFactory("rentDate"));

        SimpleDateFormat s = new SimpleDateFormat("yyyy-MM-dd");
        Date date = new Date(System.currentTimeMillis());//获取当前时间
        Calendar calendar = Calendar.getInstance();
        calendar.setTime(date);
        calendar.add(Calendar.DATE, -1);

        revenue_D = DataBaseUtil.GetRevenue(s.format(calendar.getTime()), date.toString());
        tableView_Revenue_D.setItems(revenue_D);
    }
    @FXML
    public void CaculateRevenue_M() {
        userName_4.setCellValueFactory(new PropertyValueFactory("userName"));
        carId_4.setCellValueFactory(new PropertyValueFactory("carId"));
        rentAmount_4.setCellValueFactory(new PropertyValueFactory("rentAmount"));
        rentDate_4.setCellValueFactory(new PropertyValueFactory("rentDate"));

        SimpleDateFormat s = new SimpleDateFormat("yyyy-MM-dd");
        Date date = new Date(System.currentTimeMillis());//获取当前时间
        Calendar calendar = Calendar.getInstance();
        calendar.setTime(date);
        calendar.add(Calendar.MONTH, -1);

        revenue_M = DataBaseUtil.GetRevenue(s.format(calendar.getTime()), date.toString());
        tableView_Revenue_M.setItems(revenue_M);
    }
    @FXML
    public void CaculateRevenue_S() {
        userName_5.setCellValueFactory(new PropertyValueFactory("userName"));
        carId_5.setCellValueFactory(new PropertyValueFactory("carId"));
        rentAmount_5.setCellValueFactory(new PropertyValueFactory("rentAmount"));
        rentDate_5.setCellValueFactory(new PropertyValueFactory("rentDate"));

        SimpleDateFormat s = new SimpleDateFormat("yyyy-MM-dd");
        Date date = new Date(System.currentTimeMillis());//获取当前时间
        Calendar calendar = Calendar.getInstance();
        calendar.setTime(date);
        calendar.add(Calendar.MONTH, -3);

        revenue_S = DataBaseUtil.GetRevenue(s.format(calendar.getTime()), date.toString());
        tableView_Revenue_S.setItems(revenue_S);
    }
    @FXML
    public void CaculateRevenue_Y() {
        userName_6.setCellValueFactory(new PropertyValueFactory("userName"));
        carId_6.setCellValueFactory(new PropertyValueFactory("carId"));
        rentAmount_6.setCellValueFactory(new PropertyValueFactory("rentAmount"));
        rentDate_6.setCellValueFactory(new PropertyValueFactory("rentDate"));

        SimpleDateFormat s = new SimpleDateFormat("yyyy-MM-dd");
        Date date = new Date(System.currentTimeMillis());//获取当前时间
        Calendar calendar = Calendar.getInstance();
        calendar.setTime(date);
        calendar.add(Calendar.YEAR, -1);

        revenue_Y = DataBaseUtil.GetRevenue(s.format(calendar.getTime()), date.toString());
        tableView_Revenue_Y.setItems(revenue_Y);
    }


    @Override
    public void initialize(URL location, ResourceBundle resources) {

    }

    public void setApp(Main main, String account) {
        application = main;
        this.account = account;
        MyInitialize();
    }

    private void MyInitialize() {
        InitializeComboboxUsers();
    }
    private void InitializeComboboxUsers() {
        comboBox_users.getItems().clear();
        List<String> userslist = DataBaseUtil.GetRentUsers();
        for (String users : userslist) {
            comboBox_users.getItems().add(users);
        }
    }
}
