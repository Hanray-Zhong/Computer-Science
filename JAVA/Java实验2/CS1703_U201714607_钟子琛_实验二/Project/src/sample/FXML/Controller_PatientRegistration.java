package sample.FXML;

import javafx.event.Event;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.*;
import sample.DataBase.DataBaseUtil;
import sample.Main;
import sample.Others.AutoCompleteComboBoxListener;
import sample.Others.Tuple;

import javax.xml.soap.Text;
import java.net.URL;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.*;
import java.util.regex.Pattern;


public class Controller_PatientRegistration implements Initializable {
    public Main application;

    private HashMap<String, String> KSYSinfo = null;
    HashMap<String, String> KSinfo = null;
    HashMap<String, String> HZinfo = null;
    private String BRBH = null;
    private Tuple<String, Double> BRinfo = null;
    private double BrYuCun = 0;
    public String Text_KSMC;//科室名称
    public String Text_KSYS;//科室医生
    public String Text_HZLB;//号中类别

    // FSML
    @FXML
    ComboBox comboBox_KSMC;
    @FXML
    ComboBox comboBox_YSMC;
    @FXML
    ComboBox comboBox_HZLB;
    @FXML
    Label label_user_name;
    @FXML
    TextField TextField_JKJE, TextField_YJJE, TextField_GHHM, TextField_HZMC;
    @FXML
    TextField TextField_KLYE;

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        Initialize_GetKSInfo();
        Initialize_GetKSYSInfo();
        Initialize_SetHZLB();
    }

    private void Initialize_GetKSInfo() {
        /*科室信息获取*/
        KSinfo = DataBaseUtil.getKSinfo();
        Set KSinfoSet = KSinfo.keySet();
        Iterator KSinfoSetIter = KSinfoSet.iterator();
        while (KSinfoSetIter.hasNext()) {
            String key = (String) KSinfoSetIter.next();
            comboBox_KSMC.getItems().addAll(key);
        }
        /*编辑科室信息comboBox*/
        comboBox_KSMC.setEditable(true);
        comboBox_KSMC.setOnAction((Event ev) -> {
            Text_KSMC = comboBox_KSMC.getEditor().getText().trim();
            int size = comboBox_YSMC.getItems().size();
            for (int i = 0; i < size; i++) {
                comboBox_YSMC.getItems().remove(0);
            }
            setKSYScomboxInfo();
            setHZMC();
        });
        new AutoCompleteComboBoxListener<ComboBox>(comboBox_KSMC);
    }
    private void Initialize_GetKSYSInfo() {
        /*医生信息获取*/
        KSYSinfo = DataBaseUtil.getKSYSinfo("all");
        Set KSYSinfoSet = KSYSinfo.keySet();
        Iterator KSYSinfoSetIter = KSYSinfoSet.iterator();
        while (KSYSinfoSetIter.hasNext()) {
            String key = (String) KSYSinfoSetIter.next();
            comboBox_YSMC.getItems().addAll(key);
        }
        /*编辑科室医生信息comboBox*/
        comboBox_YSMC.setEditable(true);
        comboBox_YSMC.setOnAction((Event ev) -> {
            Text_KSYS = comboBox_YSMC.getEditor().getText().trim();
            int size = comboBox_HZLB.getItems().size();
            for (int i = 0; i < size; i++) {
                comboBox_HZLB.getItems().remove(0);
            }
            setHZLB_combo_Box(Text_KSYS);
            // progres_indct.setProgress(0);
            TextField_JKJE.setEditable(true);
        });
        new AutoCompleteComboBoxListener<ComboBox>(comboBox_YSMC);
    }
    private void setHZLB_combo_Box(String KSYS) {
        int isZJ = DataBaseUtil.isZJ(KSYS);
        if (isZJ==1) {
            comboBox_HZLB.getItems().addAll("专家号","普通号");
        }
        else {
            comboBox_HZLB.getItems().addAll("普通号");
        }
    }
    private void setKSYScomboxInfo() {
        KSYSinfo = DataBaseUtil.getKSYSinfo(KSinfo.get(Text_KSMC).trim());
        Set set1 = KSYSinfo.keySet();
        Iterator iter1 = set1.iterator();
        while (iter1.hasNext()) {
            String key = (String) iter1.next();
            comboBox_YSMC.getItems().addAll(key);
        }
    }
    private void Initialize_SetHZLB() {
        comboBox_HZLB.getItems().addAll("普通号","专家号");
        comboBox_HZLB.setEditable(true);
        comboBox_HZLB.setOnAction((Event ev) -> {
            Text_HZLB = comboBox_HZLB.getEditor().getText().trim();
            setHZMC();
            if (Text_KSMC != null && Text_HZLB != null) {
                int BhType = 1;
                if (comboBox_HZLB.getEditor().getText().trim().equals("普通号")) {
                    BhType = 0;
                }
                TextField_YJJE.setText(String.valueOf(DataBaseUtil.getGHFY(Text_KSMC, BhType)));
            }
            else
                TextField_YJJE.setText(String.valueOf(""));
        });
        new AutoCompleteComboBoxListener<ComboBox>(comboBox_HZLB);
        HZinfo = DataBaseUtil.getHZBHinfo();
    }
    public void setHZMC() {
        if (Text_KSMC == null || Text_HZLB == null)
            return;
        TextField_HZMC.setText(Text_KSMC+" "+Text_HZLB);
        TextField_JKJE.setEditable(true);
    }

    @FXML
    public void onGuaHaoStart() {
        if (comboBox_KSMC.getEditor().getText().isEmpty()) {
            Alert information = new Alert(Alert.AlertType.INFORMATION, "科室名称不能为空！");
            information.setTitle("提示");
            information.setHeaderText("错误：");
            Button infor = new Button("确定");
            information.showAndWait();
        }
        else if (comboBox_HZLB.getEditor().getText().isEmpty()) {
            Alert information = new Alert(Alert.AlertType.INFORMATION, "号种类别不能为空！");
            information.setTitle("提示");
            information.setHeaderText("错误：");
            Button infor = new Button("确定");
            information.showAndWait();
        }
        else if (comboBox_YSMC.getEditor().getText().isEmpty()) {
            Alert information = new Alert(Alert.AlertType.INFORMATION, "科室医生不能为空！");
            information.setTitle("提示");
            information.setHeaderText("错误：");
            Button infor = new Button("确定");
            information.showAndWait();
        }
        // 排除异常，可以挂号
        else {
            double GHFY = Double.valueOf(TextField_YJJE.getText());
            // 预存不足
            if (BrYuCun < GHFY) {
                if (TextField_JKJE.getText() == null || TextField_JKJE.getText().isEmpty()) {
                    Alert information = new Alert(Alert.AlertType.INFORMATION, "您的余额不足，交款金额不能为空！");
                    information.setTitle("提示");
                    information.setHeaderText("错误：");
                    Button infor = new Button("确定");
                    information.showAndWait();
                    TextField_JKJE.setFocusTraversable(true);
                    return;
                }
                else if(!isNumeric(TextField_JKJE.getText())) {
                    Alert information = new Alert(Alert.AlertType.INFORMATION, "您的余额不足，请输入交款金额！");
                    information.setTitle("提示");
                    information.setHeaderText("错误：");
                    Button infor = new Button("确定");
                    information.showAndWait();
                    TextField_JKJE.setFocusTraversable(true);
                    TextField_JKJE.setEditable(true);
                    TextField_JKJE.setText("");
                    return;
                }
                else {
                    if (Double.valueOf(TextField_JKJE.getText()) < GHFY - BrYuCun) {
                        Alert information = new Alert(Alert.AlertType.INFORMATION, "交款金额不足！");
                        information.setTitle("提示");
                        information.setHeaderText("错误：");
                        Button infor = new Button("确定");
                        information.showAndWait();
                        TextField_JKJE.setFocusTraversable(true);
                        return;
                    }
                    else {
                        Date now= new Date();
                        DateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
                        String dateTimeString = df.format(now);
                        String getGHBH = onGetingGuaHao(KSYSinfo.get(Text_KSYS), BRBH, GHFY, dateTimeString);
                        if (!getGHBH.equals("0")) {
                            TextField_JKJE.setEditable(false);
                            BrYuCun = Double.valueOf(TextField_JKJE.getText()) - GHFY + BrYuCun;
                            int returnFromDBC = DataBaseUtil.setBrYuE(BRBH, BrYuCun);
                            if (returnFromDBC == 0) {
                                Alert information = new Alert(Alert.AlertType.INFORMATION, "挂号成功，更新卡余额失败！");
                                information.setTitle("提示");
                                information.setHeaderText("错误：");
                                Button infor = new Button("确定");
                                information.showAndWait();
                            }
                            TextField_KLYE.setText(""+BrYuCun);
                            TextField_GHHM.setText(""+getGHBH);
                        }
                    }
                }
            }
            // 余额足够
            else {
                TextField_JKJE.setEditable(false);
                TextField_JKJE.setText("有余额，无需交款！");

                Date now= new Date();
                DateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
                String dateTimeString = df.format(now);
                String getGHBH = onGetingGuaHao(KSYSinfo.get(Text_KSYS), BRBH, Double.valueOf(TextField_YJJE.getText()), dateTimeString);
                if (!getGHBH.equals("0")) {
                    double AfterYuE = BrYuCun - Double.valueOf(TextField_YJJE.getText());
                    int returnFromDBC = DataBaseUtil.setBrYuE(BRBH, AfterYuE);
                    if (returnFromDBC == 0) {
                        Alert information = new Alert(Alert.AlertType.INFORMATION, "扣除余额失败，请重试！");
                        information.setTitle("提示"); //设置标题，不设置默认标题为本地语言的information
                        information.setHeaderText("错误："); //设置头标题，默认标题为本地语言的information
                        Button infor = new Button("确定");
                        information.showAndWait(); //显示弹窗，同时后续代码等挂起
                    }
                    BrYuCun = AfterYuE;
                    System.out.println("剩下的余额为:" + AfterYuE + "，数据库返回："+returnFromDBC);
                    TextField_KLYE.setText(BrYuCun + "");
                    TextField_GHHM.setText(""+getGHBH);
                }
            }
        }
    }
    public static boolean isNumeric(String str){
        Pattern pattern = Pattern.compile("[0-9]*");
        return pattern.matcher(str).matches();
    }
    public String onGetingGuaHao(String YSBH, String BRBH, double GHFY, String RQSJ) {
        String HZBH = "";
        Set set2 = HZinfo.keySet();
        Iterator iter2 = set2.iterator();
        while (iter2.hasNext()) {
            String key = (String) iter2.next();
            if (key.contains(Text_KSMC.trim()) && key.contains(Text_HZLB.trim())) {
                HZBH = HZinfo.get(key.trim());
                break;
            }
        }
        String GHBH = "0";
        // 检查已经挂号人数
        if (DataBaseUtil.getGHRC(HZBH) >= DataBaseUtil.getMAX_GHRS(HZBH)) {
            Alert information = new Alert(Alert.AlertType.INFORMATION, "挂号失败，挂号人数达到上限！");
            information.setTitle("提示");
            information.setHeaderText("错误：");
            Button infor = new Button("确定");
            information.showAndWait();
            return GHBH;
        }
        GHBH = DataBaseUtil.getGuaHao(HZBH,YSBH,BRBH,GHFY,RQSJ);
        return GHBH;
    }

    @FXML
    public void ClearAll() {
        TextField_JKJE.setEditable(true);
        comboBox_KSMC.getSelectionModel().clearSelection();
        comboBox_HZLB.getSelectionModel().clearSelection();
        comboBox_YSMC.getSelectionModel().clearSelection();
        TextField_HZMC.setText(null);
        TextField_JKJE.setText(null);
        TextField_YJJE.setText(null);
        TextField_KLYE.setText(null);
        TextField_GHHM.setText(null);
    }

    public void setApp(Main main, String BRBH) {
        application = main;
        this.BRBH = new String(BRBH);
        BrYuCun = DataBaseUtil.getBRinfo(BRBH).second;
        TextField_KLYE.setText(""+BrYuCun);
    }
}
