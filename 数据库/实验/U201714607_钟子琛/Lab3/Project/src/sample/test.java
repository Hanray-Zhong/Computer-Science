package sample;

import java.sql.Date;
import java.text.SimpleDateFormat;
import java.util.Calendar;

public class test {
    public static void main(String[] args) {
        SimpleDateFormat s = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
        Date date = new Date(System.currentTimeMillis());//获取当前时间
        Calendar calendar = Calendar.getInstance();
        calendar.setTime(date);
        calendar.add(Calendar.DATE, -1);//当前时间减去一年，即一年前的时间
        System.out.println(s.format(calendar.getTime()));
        calendar.add(Calendar.YEAR, -1);//当前时间减去一年，即一年前的时间
        System.out.println(s.format(calendar.getTime()));
        calendar.add(Calendar.MONTH, -1);//当前时间前去一个月，即一个月前的时间    
        System.out.println(s.format(calendar.getTime()));
    }
}
