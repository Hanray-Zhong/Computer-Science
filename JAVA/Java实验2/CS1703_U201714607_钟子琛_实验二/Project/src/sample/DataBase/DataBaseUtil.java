package sample.DataBase;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import sample.Others.BrColumn;
import sample.Others.SrColumn;
import sample.Others.Tuple;

import java.sql.*;
import java.util.HashMap;

public class DataBaseUtil {
    //驱动程序名
    static String driver = "com.mysql.cj.jdbc.Driver";
    //URL指向要访问的数据库名
    static String url = "jdbc:mysql://localhost:3306/jdbc?serverTimezone=UTC";
    //MySQL配置时的用户名
    static String user = "root";
    //MySQL配置时的密码
    static String db_password = "1234";


    /**
     * 检查医生登录信息
     * @param account 用户名
     * @param password 密码
     * @return 是否正确
     */
    public static boolean CheckDoctor(String account, String password) {
        boolean checkbool = false;
        Connection con;
        try {
            Class.forName(driver);
            con = DriverManager.getConnection(url, user, db_password);
            if(!con.isClosed())
                System.out.println("Succeeded connecting to the Database!");

            Statement statement;
            statement = con.createStatement();

            String password_fromDb;
            String selectSql = "select DLKL from t_ksys where YSBH='" + account + "'";
            ResultSet selectRes = statement.executeQuery(selectSql);
            if (selectRes.next()) {
                password_fromDb = selectRes.getString("DLKL");
                if (password_fromDb.equals(password)) {
                    checkbool = true;
                }
            }
            con.close();
        } catch (Exception e) {
            System.out.print("医生登陆检查---checkDoctor----MYSQL ERROR:" + e.getMessage());
        }
        return checkbool;
    }

    /**
     * 检查病人登录信息
     * @param account 用户名
     * @param password 密码
     * @return 是否正确
     */
    public static boolean CheckPatient(String account, String password) {
        boolean checkbool = false;
        Connection con;
        try {
            Class.forName(driver);
            con = DriverManager.getConnection(url, user, db_password);
            if(!con.isClosed())
                System.out.println("Succeeded connecting to the Database!");

            Statement stmt;
            stmt = con.createStatement();

            String password_fromDb;
            String selectSql = "SELECT DLKL FROM t_brxx where BRBH='"+account+"'";
            ResultSet selectRes = stmt.executeQuery(selectSql);
            if (selectRes.next()) {
                password_fromDb = selectRes.getString("DLKL");
                if (password_fromDb.equals(password)) {
                    checkbool = true;
                }
            }
            con.close();
        } catch (Exception e) {
            System.out.print("病人登陆检查----check_bingren----MYSQL ERROR:" + e.getMessage());
        }
        return checkbool;
    }

    /**
     * 获得科室信息
     * @return 科室名称, 科室编号
     */
    public static HashMap<String, String> getKSinfo() {
        HashMap<String, String> KsName = new HashMap<>();
        try {
            Connection con = null;
            Class.forName(driver);
            con = DriverManager.getConnection(url, user, db_password);
            if(!con.isClosed())
                System.out.println("Succeeded connecting to the Database!");
            Statement stmt;
            stmt = con.createStatement();

            String PYZS_fromDb, KSMC_fromDb, KSBH_fromDb;

            String selectSql = "SELECT * FROM t_ksxx";
            ResultSet selectRes = stmt.executeQuery(selectSql);

            System.out.println("\n科室名称：");
            while (selectRes.next()) {
                PYZS_fromDb = selectRes.getString("PYZS");
                KSMC_fromDb = selectRes.getString("KSMC");
                KSBH_fromDb = selectRes.getString("KSBH");
//                if (!PYZS_fromDb.isEmpty()) {
//                    KsName.put(PYZS_fromDb, KSBH_fromDb);
//                }
                if (!KSMC_fromDb.isEmpty()) {
                    KsName.put(KSMC_fromDb, KSBH_fromDb);
                }
                System.out.println(KSMC_fromDb);
            }
            con.close();
        } catch (Exception e) {
            System.out.print("MYSQL ERROR:" + e.getMessage());
        }
        return KsName;
    }

    /**
     * 获得科室医生信息
     * @param KSBH 科室编号
     * @return 医生名称, 医生编号
     */
    public static HashMap<String, String> getKSYSinfo(String KSBH) {
        HashMap<String, String> KsYsName = new HashMap<>();
        try {
            Connection con = null;
            Class.forName(driver);
            con = DriverManager.getConnection(url, user, db_password);
            if(!con.isClosed())
                System.out.println("Succeeded connecting to the Database!");

            Statement stmt;
            stmt = con.createStatement();
            String YSMC_fromDb, PYZS_fromDb, YSBH_fromDb;
            String selectSql;
            if (KSBH.equals("all")) {
                selectSql = "SELECT * FROM t_ksys";
            }
            else {
                selectSql = "SELECT * FROM t_ksys WHERE KSBH = '"+KSBH+"'";
            }

            ResultSet selectRes = stmt.executeQuery(selectSql);

            System.out.println("医生名称输出:");

            while (selectRes.next()) { //循环输出结果集

                YSMC_fromDb = selectRes.getString("YSMC");
                PYZS_fromDb = selectRes.getString("PYZS");
                YSBH_fromDb = selectRes.getString("YSBH");
                if (!YSMC_fromDb.isEmpty()) {
                    KsYsName.put(YSMC_fromDb.trim(), YSBH_fromDb);
                }
//                if (!PYZS_fromDb.isEmpty()) {
//                    KsYsName.put(PYZS_fromDb.trim(), YSBH_fromDb);
//                }
                System.out.println(YSMC_fromDb.trim());
            }
            System.out.println("医生名称输出完毕\n");
            con.close();
        } catch (Exception e) {
            System.out.print("MYSQL ERROR:" + e.getMessage());
        }
        return KsYsName;
    }

    /**
     * 获得科室医生信息
     * @param ksys 科室医生
     * @return 是否是专家
     */
    public static int isZJ(String ksys) {

        int isZJ = 0;

        try {
            Connection con = null;
            Class.forName(driver);
            con = DriverManager.getConnection(url, user, db_password);
            if(!con.isClosed())
                System.out.println("Succeeded connecting to the Database!");

            Statement stmt; //创建声明
            stmt = con.createStatement();

            String selectSql = "SELECT SFZJ FROM t_ksys where YSMC='" + ksys + "' OR PYZS='" + ksys + "'";
            ResultSet selectRes = stmt.executeQuery(selectSql);

            if (selectRes.next()) {
                isZJ = selectRes.getInt("SFZJ");
                return isZJ;
            }
            con.close();
        } catch (Exception e) {
            System.out.print("MYSQL ERROR:" + e.getMessage());
        }

        return 0;
    }

    /**
     * 获得科室医生信息
     * @return 号种名称, 号种编号
     */
    public static HashMap<String, String> getHZBHinfo() {
        HashMap<String, String> HzInfo = new HashMap<>();
        try {
            Connection con = null;
            Class.forName(driver);
            con = DriverManager.getConnection(url, user, db_password);
            if(!con.isClosed())
                System.out.println("Succeeded connecting to the Database!");
            Statement stmt;
            stmt = con.createStatement();

            String HZMC_fromDb, PYZS_fromDb, HZBH_fromDb;

            String selectSql = "SELECT * FROM t_hzxx";
            ResultSet selectRes = stmt.executeQuery(selectSql);

            while (selectRes.next()) {
                HZMC_fromDb = selectRes.getString("HZMC");
                PYZS_fromDb = selectRes.getString("PYZS");
                HZBH_fromDb = selectRes.getString("HZBH");
                if (!HZMC_fromDb.isEmpty()) {
                    HzInfo.put(HZMC_fromDb, HZBH_fromDb);
                }
            }
            con.close();
        } catch (Exception e) {
            System.out.print("MYSQL ERROR:" + e.getMessage());
        }
        return HzInfo;
    }

    /**
     * 挂号操作
     * @param hzbh 号种编号
     * @param ysbh 医生编号
     * @param brbh 病人编号
     * @param ghfy 挂号费用
     * @param rqsj 时间
     * @return 挂号编号
     */
    public static String getGuaHao(String hzbh, String ysbh, String brbh, double ghfy, String rqsj) {
        String GHBH = "0";
        try {
            Connection con = null;
            Class.forName(driver);
            con = DriverManager.getConnection(url, user, db_password);
            if(!con.isClosed())
                System.out.println("Succeeded connecting to the Database!");

            Statement stmt; //创建声明
            stmt = con.createStatement();

            boolean sfzj_fromDb;
            String GHBH_fromDb, HZBH_fromDb,GHRC_fromDb;
            int Current_GHBH = 0, Current_GHRC = 0;

            String selectSql = "SELECT * FROM t_ghxx";
            ResultSet selectRes = stmt.executeQuery(selectSql);

            while (selectRes.next()) { //循环输出结果集
                GHBH_fromDb = selectRes.getString("GHBH");
                HZBH_fromDb = selectRes.getString("HZBH");
                GHRC_fromDb = selectRes.getString("GHRC");
                if (Integer.parseInt(GHBH_fromDb) > Current_GHBH) {
                    Current_GHBH = Integer.parseInt(GHBH_fromDb);
                }
                if (HZBH_fromDb.equals(hzbh)) {
                    if (Integer.parseInt(GHRC_fromDb) > Current_GHRC) {
                        Current_GHRC = Integer.parseInt(GHRC_fromDb);
                    }
                }
            }

            Current_GHRC++;
            Current_GHBH++;

            System.out.println("时间：" + rqsj + "挂号费用：" + ghfy);
            String updateSql = "INSERT INTO t_ghxx (GHBH,HZBH,YSBH,BRBH,GHRC,THBZ,GHFY,RQSJ) VALUES('" + String.format("%06d", Current_GHBH) + "','" + hzbh + "','" + ysbh + "','" + brbh + "','" + Current_GHRC + "'," +
                    "'" + 0 + "','" + ghfy + "','" + rqsj + "')";
            int i = stmt.executeUpdate(updateSql);
            if (i != 0) {
                GHBH = String.format("%06d", Current_GHBH);
            }
            con.close();
        } catch (Exception e) {
            System.out.print("MYSQL ERROR:" + e.getMessage());
        }

        return GHBH;
    }

    /**
     * 获得挂号人次
     * @param hzbh 号种编号
     * @return 挂号人次
     */
    public static int getGHRC(String hzbh) {
        int Current_GHRC = 0;
        try {
            Connection con = null;
            Class.forName(driver);
            con = DriverManager.getConnection(url, user, db_password);
            if(!con.isClosed())
                System.out.println("Succeeded connecting to the Database!");

            Statement stmt;
            stmt = con.createStatement();

            boolean sfzj_fromDb;
            String HZBH_fromDb, GHRC_fromDb;

            String selectSql = "SELECT * FROM t_ghxx";
            ResultSet selectRes = stmt.executeQuery(selectSql);

            while (selectRes.next()) { //循环输出结果集
                HZBH_fromDb = selectRes.getString("HZBH");
                GHRC_fromDb = selectRes.getString("GHRC");
                if (HZBH_fromDb.equals(hzbh)) {
                    if (Integer.parseInt(GHRC_fromDb) > Current_GHRC) {
                        Current_GHRC = Integer.parseInt(GHRC_fromDb);
                    }
                }
            }
            con.close();
        } catch (Exception e) {
            System.out.print("MYSQL ERROR:" + e.getMessage() + "\n");
        }

        return Current_GHRC;
    }

    /**
     * 获得最大挂号人次
     * @param hzbh 号种编号
     * @return 最大挂号人次
     */
    public static int getMAX_GHRS(String hzbh) {
        int MAX_GHRS = 0;
        try {
            Connection con = null;
            Class.forName(driver);
            con = DriverManager.getConnection(url, user, db_password);
            if(!con.isClosed())
                System.out.println("Succeeded connecting to the Database!");

            Statement stmt;
            stmt = con.createStatement();

            boolean sfzj_fromDb;
            String HZBH_fromDb, GHRC_fromDb;

            String selectSql;
            selectSql = "SELECT * FROM t_hzxx WHERE HZBH='"+hzbh+"'";
            ResultSet selectRes = stmt.executeQuery(selectSql);
            if (selectRes.next())
                MAX_GHRS = selectRes.getInt("GHRS");
            con.close();
        } catch (Exception e) {
            System.out.print("MYSQL ERROR:" + e.getMessage() + "\n");
        }
        return MAX_GHRS;
    }

    public static double getGHFY(String HZMC, int SFZJ) {
        try {
            Connection con = null;
            Class.forName(driver);
            con = DriverManager.getConnection(url, user, db_password);
            if(!con.isClosed())
                System.out.println("Succeeded connecting to the Database!");

            Statement stmt; //创建声明
            stmt = con.createStatement();

            boolean sfzj_fromDb;
            String HZMC_fromDb;
            String PYZS_fromDb;

            String selectSql = "SELECT * FROM t_hzxx";
            ResultSet selectRes = stmt.executeQuery(selectSql);

            while (selectRes.next()) { //循环输出结果集
                sfzj_fromDb = selectRes.getBoolean("SFZJ");
                HZMC_fromDb = selectRes.getString("HZMC");
                PYZS_fromDb = selectRes.getString("PYZS");
                double GHFY_fromDb = selectRes.getDouble("GHFY");

                if (HZMC_fromDb.startsWith(HZMC) || PYZS_fromDb.startsWith(HZMC)) {
                    if (SFZJ == 1 && sfzj_fromDb) {
                        return GHFY_fromDb;
                    } else if (SFZJ == 0 && !sfzj_fromDb) {
                        return GHFY_fromDb;
                    }
                }

            }
            con.close();
        } catch (Exception e) {
            System.out.print("MYSQL ERROR:" + e.getMessage());
        }

        return 0;
    }

    /**
     * 扣病人余额
     * @param BRBH 病人编号
     * @param BrYuCun 病人预存
     * @return 病人余额
     */
    public static int setBrYuE(String BRBH, double BrYuCun) {

        try {
            Connection con = null;
            Class.forName(driver);
            con = DriverManager.getConnection(url, user, db_password);
            if(!con.isClosed())
                System.out.println("Succeeded connecting to the Database!");

            Statement stmt;
            stmt = con.createStatement();

            String userBianHao_fromDb;

            String selectSql = "SELECT * FROM t_brxx where BRBH='"+BRBH+"'";
            ResultSet selectRes = stmt.executeQuery(selectSql);

            if (selectRes.next()) {
                String updateSql = "UPDATE t_brxx set YCJE = " + BrYuCun + " where BRBH = '" + BRBH + "'";
                int i = stmt.executeUpdate(updateSql);
                return i;
            }
            con.close();
        } catch (Exception e) {
            System.out.print("扣病人余额---setBrYuE---MYSQL ERROR:" + e.getMessage());
        }
        return 0;
    }

    /**
     * 病人登陆成功之后，获取名称以及预存金额
     * @param BRBH 病人编号
     * @return 病人名称，预存金额
     */
    public static Tuple<String, Double> getBRinfo(String BRBH) {
        Tuple<String, Double> Br = null;
        try {
            Connection con = null;
            Class.forName(driver);
            con = DriverManager.getConnection(url, user, db_password);
            if(!con.isClosed())
                System.out.println("Succeeded connecting to the Database!");
            Statement stmt;
            stmt = con.createStatement();

            String selectSql = "SELECT BRMC,YCJE FROM t_brxx where BRBH='"+BRBH+"'";
            ResultSet selectRes = stmt.executeQuery(selectSql);

            if (selectRes.next()) {
                double BrYuCun_fromDb = selectRes.getDouble("YCJE");
                Br = new Tuple<>(selectRes.getString("BRMC"), BrYuCun_fromDb);
                return Br;
            }
            con.close();
        } catch (Exception e) {
            System.out.print("病人登陆成功之后，获取名称以及预存金额----getBRinfo----MYSQL ERROR:" + e.getMessage());
        }
        return Br;
    }

    /**
     * 获取医生:YSBH 下对应的病人列表
     * @param YSBH 医生编号
     * @return ObservableList
     */
    public static ObservableList<BrColumn> getBrLieBiao(String YSBH) {
        final ObservableList<BrColumn> data = FXCollections.observableArrayList();
        String YsName = null;
        try {
            Connection con = null;
            Class.forName(driver);
            con = DriverManager.getConnection(url, user, db_password);
            if(!con.isClosed())
                System.out.println("Succeeded connecting to the Database!");


            Statement stmt, stmt1, stmt2; //创建声明
            stmt = con.createStatement();
            stmt1 = con.createStatement();
            stmt2 = con.createStatement();

            String userBianHao_fromDb;
            String GHBH = null, HZBH = null, BRBH = null, RQSJ = null;
            Boolean SFZJ = null;
            String BRMC = null;

            String selectSql1, selectSql2;
            ResultSet selectRes1, selectRes2;

            String selectSql = "SELECT * FROM t_ghxx where YSBH='" + YSBH + "'";
            ResultSet selectRes = stmt.executeQuery(selectSql);

            while (selectRes.next()) { //循环输出结果集
                GHBH = selectRes.getString("GHBH");
                HZBH = selectRes.getString("HZBH");
                BRBH = selectRes.getString("BRBH");
                RQSJ = selectRes.getString("RQSJ");

                //HZBH
                selectSql1 = "SELECT * FROM t_hzxx";
                selectRes1 = stmt1.executeQuery(selectSql1);
                String HZBH_from_db = null;
                while (selectRes1.next()) { //循环输出结果集
                    HZBH_from_db = selectRes1.getString("HZBH");
                    if (HZBH_from_db.equals(HZBH)) {
                        SFZJ = selectRes1.getBoolean("SFZJ");
                        break;
                    }
                }

                //BRBH
                selectSql2 = "SELECT * FROM t_brxx";
                selectRes2 = stmt2.executeQuery(selectSql2);
                String BRBH_from_db = null;
                while (selectRes2.next()) { //循环输出结果集
                    BRBH_from_db = selectRes2.getString("BRBH");
                    if (BRBH_from_db.equals(BRBH)) {
                        BRMC = selectRes2.getString("BRMC");
                        break;
                    }
                }
                data.addAll(new BrColumn(GHBH, BRMC, RQSJ, SFZJ ? "普通号" : "专家号"));
            }

            con.close();
        } catch (Exception e) {
            System.out.print("MYSQL ERROR:" + e.getMessage());
        }
        return data;
    }

    public static ObservableList<SrColumn> getShouRuLieBiao(String startTime, String endTime) {
        final ObservableList<SrColumn> data = FXCollections.observableArrayList();
        ObservableList<SrColumn> new_data = FXCollections.observableArrayList();
        String YsName = null;
        try {
            Connection con = null;
            Class.forName(driver);
            con = DriverManager.getConnection(url, user, db_password);
            if(!con.isClosed())
                System.out.println("Succeeded connecting to the Database!");


            Statement stmt, stmt1, stmt2, stmt3; //创建声明
            stmt = con.createStatement();
            stmt1 = con.createStatement();
            stmt2 = con.createStatement();
            stmt3 = con.createStatement();

            String YSBH_fromDb;
            String HZBH_fromDb;

            String YSMC = null, HZBH = null, BRBH = null, RQSJ = null, KSMC = null, HZLB = null;
            Boolean SFZJ = null;
            String BRMC = null;
            double GHFY = 0;

            String selectSql1, selectSql2, selectSql3;
            ResultSet selectRes1, selectRes2, selectRes3;

            String selectSql = "SELECT * FROM t_ghxx WHERE RQSJ BETWEEN '" + startTime + "' and '" + endTime + "'";
            ResultSet selectRes = stmt.executeQuery(selectSql);
            System.out.println("开始统计:");

            while (selectRes.next()) { //循环输出结果集
                YSBH_fromDb = selectRes.getString("YSBH");
                HZBH_fromDb = selectRes.getString("HZBH");
                GHFY = selectRes.getDouble("GHFY");

                //YSMC
                selectSql1 = "SELECT * FROM t_ksys";
                selectRes1 = stmt1.executeQuery(selectSql1);
                String YSBH_from_db = null;
                String KSBH_from_db = null;
                while (selectRes1.next()) { //循环输出结果集
                    YSBH_from_db = selectRes1.getString("YSBH");
                    if (YSBH_from_db.equals(YSBH_fromDb)) {
                        YSMC = selectRes1.getString("YSMC");
                        KSBH_from_db = selectRes1.getString("KSBH");
                        break;
                    }
                }

                //KSMC
                selectSql2 = "SELECT * FROM t_ksxx";
                selectRes2 = stmt2.executeQuery(selectSql2);
                String KSBH_from_db1 = null;
                while (selectRes2.next()) { //循环输出结果集
                    KSBH_from_db1 = selectRes2.getString("KSBH");
                    if (KSBH_from_db.equals(KSBH_from_db1)) {
                        KSMC = selectRes2.getString("KSMC");
                        break;
                    }
                }

                //HZLB
                selectSql3 = "SELECT * FROM t_hzxx";
                selectRes3 = stmt3.executeQuery(selectSql3);
                String HZBH_from_db = null;
                while (selectRes3.next()) { //循环输出结果集
                    HZBH_from_db = selectRes3.getString("HZBH");
                    if (HZBH_from_db.equals(HZBH_fromDb)) {
                        SFZJ = selectRes3.getBoolean("SFZJ");
                        break;
                    }
                }
                data.addAll(new SrColumn(KSMC, YSBH_fromDb, YSMC, SFZJ ? "专家号":"普通号" , 0, GHFY));
            }

            Object[] mydata = data.toArray();
            for (int i = 0; i < mydata.length; i++) {
                SrColumn iidata = (SrColumn) mydata[i];
                int GHRC = 0;
                double SRHJ = 0;
                for (int j = 0; j < mydata.length; j++) {
                    SrColumn jjdata = (SrColumn) mydata[j];
                    if (!jjdata.isVisited()) {
                        if (iidata.getKSMC().contains(jjdata.getKSMC()) && iidata.getYSBH().contains(jjdata.getYSBH()) && iidata.getYSMC().contains(jjdata.getYSMC()) && iidata.getHZLB().contains(jjdata.getHZLB())) {
                            GHRC++;
                            SRHJ += jjdata.getSRHJ();
                            ((SrColumn) mydata[j]).setVisited(true);
                        } else {
                        }
                    }
                }
                if (GHRC != 0) {
                    new_data.addAll(new SrColumn(iidata.getKSMC(), iidata.getYSBH(), iidata.getYSMC(), iidata.getHZLB(), GHRC, SRHJ));
                }
            }
            con.close();
        } catch (Exception e) {
            System.out.print("MYSQL ERROR:" + e.getMessage());
        }
        return new_data;
    }
}
