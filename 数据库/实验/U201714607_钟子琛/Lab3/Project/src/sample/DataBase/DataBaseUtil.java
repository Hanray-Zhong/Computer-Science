package sample.DataBase;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import sample.Others.*;

import java.sql.*;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

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
     * 检查用户登录信息
     * @param account 用户名
     * @param password 密码
     * @return 是否正确
     */
    public static boolean CheckUser(String account, String password) {
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
            String Sql = "select password from userlist where id = '" + account + "'";
            ResultSet selectRes = statement.executeQuery(Sql);
            if (selectRes.next()) {
                password_fromDb = selectRes.getString("password");
                if (password_fromDb.equals(password)) {
                    checkbool = true;
                }
            }
            con.close();
        } catch (Exception e) {
            System.out.print("MYSQL ERROR:" + e.getMessage() + '\n');
        }
        return checkbool;
    }

    /**
     * 检查员工登录信息
     * @param account 用户名
     * @param password 密码
     * @return 是否正确
     */
    public static boolean CheckStaff(String account, String password) {
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
            String Sql = "SELECT password FROM stafflist where id = '" + account + "'";
            ResultSet selectRes = stmt.executeQuery(Sql);
            if (selectRes.next()) {
                password_fromDb = selectRes.getString("password");
                if (password_fromDb.equals(password)) {
                    checkbool = true;
                }
            }
            con.close();
        } catch (Exception e) {
            System.out.print("MYSQL ERROR:" + e.getMessage());
        }
        return checkbool;
    }

    /**
     * 获得用户名称
     * @param id 用户id
     * @return 名称
     */
    public static String GetUserName(String id) {
        String userName = new String();
        try {
            Connection con = null;
            Class.forName(driver);
            con = DriverManager.getConnection(url, user, db_password);
            if(!con.isClosed())
                System.out.println("Succeeded connecting to the Database!");
            Statement stmt;
            stmt = con.createStatement();

            String Sql = "select name from userlist where id = '" + id + "'";
            ResultSet selectRes = stmt.executeQuery(Sql);

            while (selectRes.next()) {
                userName = selectRes.getString("name");
            }
            con.close();
        } catch (Exception e) {
            System.out.print("MYSQL ERROR:" + e.getMessage());
        }
        return userName;
    }

    /**
     * 检查用户租车情况
     * @param
     * @return 结果
     */
    public static String GetUserId(String username) {
        String userid = new String();
        try {
            Connection con = null;
            Class.forName(driver);
            con = DriverManager.getConnection(url, user, db_password);
            if(!con.isClosed())
                System.out.println("Succeeded connecting to the Database!");
            Statement stmt;
            stmt = con.createStatement();

            String sql = new String();
            sql = "select id from userlist where name = '" + username + "'";
            ResultSet selectRes = stmt.executeQuery(sql);
            while (selectRes.next()) {
                userid = selectRes.getString("id");
            }
            con.close();
        } catch (Exception e) {
            System.out.print("MYSQL ERROR:" + e.getMessage());
        }
        return userid;
    }

    /**
     * 检查用户是否是vip
     * @param id 用户id
     * @return 结果
     */
    public static int CheckVIP(String id) {
        int isVIP = -1;
        try {
            Connection con = null;
            Class.forName(driver);
            con = DriverManager.getConnection(url, user, db_password);
            if(!con.isClosed())
                System.out.println("Succeeded connecting to the Database!");
            Statement stmt;
            stmt = con.createStatement();

            String Sql = "select isVIP from userlist where id = '" + id + "'";
            ResultSet selectRes = stmt.executeQuery(Sql);

            while (selectRes.next()) {
                isVIP = selectRes.getInt("isVIP");
            }
            con.close();
        } catch (Exception e) {
            System.out.print("MYSQL ERROR:" + e.getMessage());
        }
        return isVIP;
    }

    /**
     * 检查用户租车情况
     * @param id 用户id
     * @return 结果
     */
    public static int CheckUserRentStatus(String id) {
        int rentStatus = -1;
        try {
            Connection con = null;
            Class.forName(driver);
            con = DriverManager.getConnection(url, user, db_password);
            if(!con.isClosed())
                System.out.println("Succeeded connecting to the Database!");
            Statement stmt;
            stmt = con.createStatement();

            String Sql = "select isrent from userlist where id = '" + id + "'";
            ResultSet selectRes = stmt.executeQuery(Sql);
            if (selectRes.next()) {
                rentStatus = selectRes.getInt("isrent");
            }

            con.close();
        } catch (Exception e) {
            System.out.print("MYSQL ERROR:" + e.getMessage());
        }
        return rentStatus;
    }

    /**
     * 获取用户可以租借的所有车
     * @param isVip 是否是会员
     * @return 结果
     */
    public static List<String> GetCarTypes(boolean isVip) {
        List<String> carTypes = new ArrayList<>();

        try {
            Connection con = null;
            Class.forName(driver);
            con = DriverManager.getConnection(url, user, db_password);
            if(!con.isClosed())
                System.out.println("Succeeded connecting to the Database!");
            Statement stmt;
            stmt = con.createStatement();

            String Sql;
            if (isVip) {
                Sql = "select cartype from carlist";
            }
            else {
                Sql = "select cartype from carlist where isvip = 0 and isdamaged = 0 and isrented = 0";
            }
            ResultSet selectRes = stmt.executeQuery(Sql);
            while (selectRes.next()) {
                if (!carTypes.contains(selectRes.getString("cartype")))
                    carTypes.add(selectRes.getString("cartype"));
            }
            con.close();
        } catch (Exception e) {
            System.out.print("MYSQL ERROR:" + e.getMessage());
        }
        return carTypes;
    }

    /**
     * 获取对应车型的所有id
     * @param   车辆id
     * @return 结果
     */
    public static List<String> GetCarIDList(String cartype) {
        List<String> list_carid = new ArrayList<>();
        try {
            Connection con = null;
            Class.forName(driver);
            con = DriverManager.getConnection(url, user, db_password);
            if(!con.isClosed())
                System.out.println("Succeeded connecting to the Database!");
            Statement stmt;
            stmt = con.createStatement();

            String Sql = new String();
            Sql = "select id from carlist where cartype = '" + cartype + "' and isdamaged = 0 and isrented = 0 ";
            ResultSet selectRes = stmt.executeQuery(Sql);
            while (selectRes.next()) {
                list_carid.add(selectRes.getString("id"));
            }
            con.close();
        } catch (Exception e) {
            System.out.print("MYSQL ERROR:" + e.getMessage());
        }
        return list_carid;
    }

    /**
     * 通过车的id获取车型
     * @param
     * @return 结果
     */
    public static String GetCarTypeFromId(String carid) {
        String cartype = new String();
        try {
            Connection con = null;
            Class.forName(driver);
            con = DriverManager.getConnection(url, user, db_password);
            if(!con.isClosed())
                System.out.println("Succeeded connecting to the Database!");
            Statement stmt;
            stmt = con.createStatement();

            String sql = new String();
            sql = "select cartype from carlist where id = '" + carid + "'";
            ResultSet selectRes = stmt.executeQuery(sql);
            while (selectRes.next()) {
                cartype = selectRes.getString("cartype");
            }
            con.close();
        } catch (Exception e) {
            System.out.print("MYSQL ERROR:" + e.getMessage());
        }
        return cartype;
    }

    /**
     * 获取租金
     * @param   id 车辆id
     * @return 结果
     */
    public static double GetRentalAmount(String id) {
        double rentalamount = -1;
        try {
            Connection con = null;
            Class.forName(driver);
            con = DriverManager.getConnection(url, user, db_password);
            if(!con.isClosed())
                System.out.println("Succeeded connecting to the Database!");
            Statement stmt;
            stmt = con.createStatement();

            String Sql = new String();
            Sql = "select rentalamount from carlist where id = '" + id + "'";
            ResultSet selectRes = stmt.executeQuery(Sql);
            while (selectRes.next()) {
                rentalamount = selectRes.getDouble("rentalamount");
            }
            con.close();
        } catch (Exception e) {
            System.out.print("MYSQL ERROR:" + e.getMessage());
        }
        return rentalamount;
    }

    /**
     * 获取押金
     * @param   id 车辆id
     * @return 结果
     */
    public static double GetDeposit(String id) {
        double deposit = -1;
        try {
            Connection con = null;
            Class.forName(driver);
            con = DriverManager.getConnection(url, user, db_password);
            if(!con.isClosed())
                System.out.println("Succeeded connecting to the Database!");
            Statement stmt;
            stmt = con.createStatement();

            String Sql = new String();
            Sql = "select deposit from carlist where id = '" + id + "'";
            ResultSet selectRes = stmt.executeQuery(Sql);
            while (selectRes.next()) {
                deposit = selectRes.getDouble("deposit");
            }
            con.close();
        } catch (Exception e) {
            System.out.print("MYSQL ERROR:" + e.getMessage());
        }
        return deposit;
    }

    /**
     * 获取用户余额
     * @param   id 用户id
     * @return 结果
     */
    public static double GetUserAmount(String id) {
        double amount = 0;
        try {
            Connection con = null;
            Class.forName(driver);
            con = DriverManager.getConnection(url, user, db_password);
            if(!con.isClosed())
                System.out.println("Succeeded connecting to the Database!");
            Statement stmt;
            stmt = con.createStatement();

            String Sql = new String();
            Sql = "select amount from userlist where id = '" + id + "'";
            ResultSet selectRes = stmt.executeQuery(Sql);
            while (selectRes.next()) {
                amount = selectRes.getDouble("amount");
            }
            con.close();
        } catch (Exception e) {
            System.out.print("MYSQL ERROR:" + e.getMessage());
        }
        return amount;
    }

    /**
     * 更新用户余额
     * @param id 用户id
     * @param newAmount 更新后的余额
     * @return 结果
     */
    public static void UpdateUserAmount(String id, double newAmount) {
        try {
            Connection con = null;
            Class.forName(driver);
            con = DriverManager.getConnection(url, user, db_password);
            if(!con.isClosed())
                System.out.println("Succeeded connecting to the Database!");
            Statement stmt;
            stmt = con.createStatement();

            String Sql = new String();
            Sql = "update userlist set amount = " + newAmount + " where id = '" + id + "';";
            stmt.executeUpdate(Sql);
            con.close();
        } catch (Exception e) {
            System.out.print("MYSQL ERROR:" + e.getMessage());
        }
    }

    /**
     * 更新租车状态
     * @param id 用户id
     * @param newAmount 更新后的余额
     * @return 结果
     */
    public static void UpdateRentalStatus(String userid, String carid, Timestamp time) {
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd hh:mm:ss");
        String s_time = sdf.format(time);
        try {
            Connection con = null;
            Class.forName(driver);
            con = DriverManager.getConnection(url, user, db_password);
            if(!con.isClosed())
                System.out.println("Succeeded connecting to the Database!");
            Statement stmt;
            stmt = con.createStatement();

            String Sql = new String();
            Sql = "insert into rentalstatus set carid = '" + carid + "', userid = '" + userid + "', rentdate = '" + s_time + "'";
            stmt.execute(Sql);
            Sql = "update carlist set isrented = 1 where id = '" + carid + "'";
            stmt.executeUpdate(Sql);
            Sql = "update userlist set isrent = 1 where id = '" + userid + "'";
            stmt.executeUpdate(Sql);
            con.close();
        } catch (Exception e) {
            System.out.print("MYSQL ERROR:" + e.getMessage());
        }
    }



/****************************************************************************/




    /**
     * 归还车辆操作
     * @param
     * @return 结果
     */
    public static void ReturnCar(String userid, String carid) {
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd hh:mm:ss");
        String time = sdf.format(System.currentTimeMillis());
        try {
            Connection con = null;
            Class.forName(driver);
            con = DriverManager.getConnection(url, user, db_password);
            if(!con.isClosed())
                System.out.println("Succeeded connecting to the Database!");
            Statement stmt;
            stmt = con.createStatement();

            String Sql = new String();
            Sql = "update userlist set isrent = 0 where id = '" + userid + "'";
            stmt.executeUpdate(Sql);
            Sql = "update carlist set isrented = 0 where id = '" + carid + "'";
            stmt.executeUpdate(Sql);
            Sql = "update rentalstatus set returndate = '" + time + "' where userid = '" + userid + "' and isnull(returndate)";
            stmt.executeUpdate(Sql);
            con.close();
        } catch (Exception e) {
            System.out.print("MYSQL ERROR:" + e.getMessage());
        }
    }

    /**
     * 查询罚款情况
     * @param
     * @return
     */
    public static double GetFine(String userid) {
        double fine = -1;
        try {
            Connection con = null;
            Class.forName(driver);
            con = DriverManager.getConnection(url, user, db_password);
            if(!con.isClosed())
                System.out.println("Succeeded connecting to the Database!");
            Statement stmt;
            stmt = con.createStatement();

            String Sql = new String();
            Sql = "select fine from trafficfinelist where userid = '" + userid + "' and done = 0";
            ResultSet selectRes = stmt.executeQuery(Sql);
            while (selectRes.next()) {
                fine = selectRes.getDouble("fine");
            }
            con.close();
        } catch (Exception e) {
            System.out.print("MYSQL ERROR:" + e.getMessage());
        }
        return fine;
    }

    /**
     * 查询罚款情况
     * @param
     * @return
     */
    public static void UpdateTrafficFineStatus(String userid) {
        try {
            Connection con = null;
            Class.forName(driver);
            con = DriverManager.getConnection(url, user, db_password);
            if(!con.isClosed())
                System.out.println("Succeeded connecting to the Database!");
            Statement stmt;
            stmt = con.createStatement();

            String Sql = new String();
            Sql = "update trafficfinelist set done = 1 where userid = '" + userid + "' and done = 0";
            stmt.executeUpdate(Sql);
            con.close();
        } catch (Exception e) {
            System.out.print("MYSQL ERROR:" + e.getMessage());
        }
    }

    /**
     * 获取所有需要换车的用户
     * @param
     * @return 结果
     */
    public static List<String> GetRentUsers() {
        List<String> userlist = new ArrayList<>();
        try {
            Connection con = null;
            Class.forName(driver);
            con = DriverManager.getConnection(url, user, db_password);
            if(!con.isClosed())
                System.out.println("Succeeded connecting to the Database!");
            Statement stmt;
            stmt = con.createStatement();

            String sql = new String();
            sql = "select userid from rentalstatus where isnull(returndate)";
            ResultSet selectRes = stmt.executeQuery(sql);
            while (selectRes.next()) {
                userlist.add(DataBaseUtil.GetUserName(selectRes.getString("userid")));
            }
            con.close();
        } catch (Exception e) {
            System.out.print("MYSQL ERROR:" + e.getMessage());
        }
        return userlist;
    }

    /**
     * 通过用户名称获取需要换的车的id
     * @param username 用户名称
     * @return 结果
     */
    public static String GetCarIdFromUserName(String username) {
        String userid = new String();
        String carid = new String();
        try {
            Connection con = null;
            Class.forName(driver);
            con = DriverManager.getConnection(url, user, db_password);
            if(!con.isClosed())
                System.out.println("Succeeded connecting to the Database!");
            Statement stmt;
            stmt = con.createStatement();

            String sql = new String();
            sql = "select id from userlist where name = '" + username + "'";
            ResultSet selectRes = stmt.executeQuery(sql);
            while (selectRes.next()) {
                userid = selectRes.getString("id");
            }
            sql = "select carid from rentalstatus where userid = '" + userid + "' and isnull(returndate)";
            selectRes = stmt.executeQuery(sql);
            while (selectRes.next()) {
                carid = selectRes.getString("carid");
            }
            con.close();
        } catch (Exception e) {
            System.out.print("MYSQL ERROR:" + e.getMessage());
        }
        return carid;
    }

    /**
     * 获得租车情况列表
     * @param
     * @return 结果
     */
    public static ObservableList<RentalRecordColumn> GetRentalRecord() {
        final ObservableList<RentalRecordColumn> data = FXCollections.observableArrayList();
        String YsName = null;
        try {
            Connection con = null;
            Class.forName(driver);
            con = DriverManager.getConnection(url, user, db_password);
            if(!con.isClosed())
                System.out.println("Succeeded connecting to the Database!");


            Statement stmt; //创建声明
            stmt = con.createStatement();

            String userId = null, userName = null, carType = null, carId = null, rentDate = null, returnDate = null;

            String selectSql = "select * from rentalstatus";
            ResultSet selectRes = stmt.executeQuery(selectSql);

            while (selectRes.next()) { //循环输出结果集
                userId = selectRes.getString("userId");
                userName = DataBaseUtil.GetUserName(userId);
                carId = selectRes.getString("carId");
                carType = DataBaseUtil.GetCarTypeFromId(carId);
                rentDate = selectRes.getString("rentDate");
                returnDate = selectRes.getString("returnDate");

                data.addAll(new RentalRecordColumn(userId, userName, carType, carId, rentDate, returnDate));
            }
            con.close();
        } catch (Exception e) {
            System.out.print("MYSQL ERROR:" + e.getMessage());
        }
        return data;
    }

    /**
     * 获得需要修理的车的列表
     * @param
     * @return 结果
     */
    public static ObservableList<RepairRecordColumn> GetRepairRecord() {
        final ObservableList<RepairRecordColumn> data = FXCollections.observableArrayList();
        String YsName = null;
        try {
            Connection con = null;
            Class.forName(driver);
            con = DriverManager.getConnection(url, user, db_password);
            if(!con.isClosed())
                System.out.println("Succeeded connecting to the Database!");

            Statement stmt;
            stmt = con.createStatement();

            String carType = null, carId = null;

            String selectSql = "select * from carlist where isdamaged = 1";
            ResultSet selectRes = stmt.executeQuery(selectSql);

            while (selectRes.next()) { //循环输出结果集
                carId = selectRes.getString("id");
                carType = DataBaseUtil.GetCarTypeFromId(carId);

                data.addAll(new RepairRecordColumn(carType, carId));
            }
            con.close();
        } catch (Exception e) {
            System.out.print("MYSQL ERROR:" + e.getMessage());
        }
        return data;
    }

    /**
     * 获得收入列表
     * @param
     * @return 结果
     */
    public static ObservableList<RevenueColumn> GetRevenue(String stratTime, String endTime) {
        final ObservableList<RevenueColumn> data = FXCollections.observableArrayList();
        String YsName = null;
        try {
            Connection con = null;
            Class.forName(driver);
            con = DriverManager.getConnection(url, user, db_password);
            if(!con.isClosed())
                System.out.println("Succeeded connecting to the Database!");

            Statement stmt;
            stmt = con.createStatement();

            String userName = null, carId = null, carRentAmount = null, rentDate = null;

            String selectSql = "select * from rentalstatus where rentdate between '" + stratTime + "' and '" + endTime + "'";
            ResultSet selectRes = stmt.executeQuery(selectSql);

            while (selectRes.next()) {
                userName = DataBaseUtil.GetUserName(selectRes.getString("userid"));
                carId = selectRes.getString("carid");
                carRentAmount = "" + DataBaseUtil.GetRentalAmount(carId);
                rentDate = selectRes.getString("rentdate");

                data.addAll(new RevenueColumn(userName, carId, carRentAmount, rentDate));
            }
            con.close();
        } catch (Exception e) {
            System.out.print("MYSQL ERROR:" + e.getMessage());
        }
        return data;
    }
}
