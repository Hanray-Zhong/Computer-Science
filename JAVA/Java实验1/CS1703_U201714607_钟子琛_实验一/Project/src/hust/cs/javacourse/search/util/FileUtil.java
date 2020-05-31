package hust.cs.javacourse.search.util;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

/*
文件操作的工具类
 */
public class FileUtil extends Object {
    private FileUtil() { }

    public static String read(String filePath) {
        File file = new File(filePath);
        StringBuilder result = new StringBuilder();
        BufferedReader bufferedReader = null;
        try {
            bufferedReader = new BufferedReader(new FileReader(file));
            String line = null;
            while ((line = bufferedReader.readLine()) != null) {
                result.append(line + "\n");
            }
        } catch (Exception e) {
            System.out.println("读取文件内容出错");
            e.printStackTrace();
        }finally {
            try {
                bufferedReader.close();
            } catch (IOException e1) {
                e1.printStackTrace();
            }
        }

        return result.toString();
    }

    public static void write(String content, String filePath) {

    }

    public static List<String> list(String dirPath) {
        List<String> result = new ArrayList<>();



        return result;
    }

    public static List<String> list(String dirPath, String suffix) {
        List<String> result = new ArrayList<>();



        return result;
    }


}
