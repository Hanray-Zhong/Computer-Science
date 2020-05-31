package sample.FXML;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import jdk.nashorn.internal.ir.PropertyNode;
import sample.DataBase.DataBaseUtil;
import sample.Main;
import sample.Others.BrColumn;
import sample.Others.SrColumn;

import java.net.URL;
import java.time.LocalDate;
import java.util.ResourceBundle;

public class Controller_DoctorRegistration implements Initializable {
    public Main application;

    private String YSBH_in_Controller;
    private ObservableList<BrColumn> data = FXCollections.observableArrayList();
    private ObservableList<SrColumn> Srdata = FXCollections.observableArrayList();
    @FXML
    TableColumn GHBH_1,BRMC_1,GhTime_1,HzType_1;
    @FXML
    TableColumn KSMC_2,YSBH_2,YSMC_2,HZLB_2,GHRC_2,SRHJ_2;
    @FXML
    TableView<BrColumn> BrTableView;
    @FXML
    TableView<SrColumn> SrTableView;
    @FXML
    DatePicker DatePicker_end;
    @FXML
    DatePicker DatePicker_start;
    @FXML
    ComboBox ComboBox_S_1, ComboBox_E_1, ComboBox_S_2, ComboBox_E_2;
    @FXML
    private Label label_user_name;

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        DatePicker_start.setValue(LocalDate.now());
        DatePicker_end.setValue(DatePicker_start.getValue().plusDays(1));

        for (int i = 0; i < 24; i++) {
            ComboBox_S_1.getItems().addAll(i + " 点");
            ComboBox_E_1.getItems().addAll(i + " 点");
        }
        ComboBox_S_1.getSelectionModel().select(0);
        ComboBox_E_1.getSelectionModel().select(0);

        for (int i = 0; i < 60; i++) {
            ComboBox_S_2.getItems().addAll(i + " 分");
            ComboBox_E_2.getItems().addAll(i + " 分");
        }
        ComboBox_S_2.getSelectionModel().select(0);
        ComboBox_E_2.getSelectionModel().select(0);
    }

    @FXML
    public void setTableData() {
        GHBH_1.setCellValueFactory(new PropertyValueFactory("GHBH"));
        BRMC_1.setCellValueFactory(new PropertyValueFactory("BRMC"));
        GhTime_1.setCellValueFactory(new PropertyValueFactory("GHTime"));
        HzType_1.setCellValueFactory(new PropertyValueFactory("HZLB"));
        data = DataBaseUtil.getBrLieBiao(YSBH_in_Controller);
        BrTableView.setItems(data);
    }

    @FXML
    public void startCalculate() {
        int S_1 = Integer.parseInt(ComboBox_S_1.getSelectionModel().getSelectedItem().toString().replace("点", "").replace("分", "").trim());
        int S_2 = Integer.parseInt(ComboBox_S_2.getSelectionModel().getSelectedItem().toString().replace("点", "").replace("分", "").trim());
        int E_1 = Integer.parseInt(ComboBox_E_1.getSelectionModel().getSelectedItem().toString().replace("点", "").replace("分", "").trim());
        int E_2 = Integer.parseInt(ComboBox_E_2.getSelectionModel().getSelectedItem().toString().replace("点", "").replace("分", "").trim());
        String startTime = DatePicker_start.getValue().toString() + " " + String.format("%02d", S_1) + ":" + String.format("%02d", S_2) + ":00";
        String endTime = DatePicker_end.getValue().toString() + " " + String.format("%02d", E_1) + ":" + String.format("%02d", E_2) + ":00";

        System.out.println("开始时间：" + startTime + "\n结束时间：" + endTime);

        KSMC_2.setCellValueFactory(new PropertyValueFactory("KSMC"));
        YSBH_2.setCellValueFactory(new PropertyValueFactory("YSBH"));
        YSMC_2.setCellValueFactory(new PropertyValueFactory("YSMC"));
        HZLB_2.setCellValueFactory(new PropertyValueFactory("HZLB"));
        GHRC_2.setCellValueFactory(new PropertyValueFactory("GHRC"));
        SRHJ_2.setCellValueFactory(new PropertyValueFactory("SRHJ"));

        Srdata = DataBaseUtil.getShouRuLieBiao(startTime,endTime);
        SrTableView.setItems(Srdata);

    }

    public void setApp(Main main, String YSBH) {
        YSBH_in_Controller = YSBH;
        application = main;
    }
}
