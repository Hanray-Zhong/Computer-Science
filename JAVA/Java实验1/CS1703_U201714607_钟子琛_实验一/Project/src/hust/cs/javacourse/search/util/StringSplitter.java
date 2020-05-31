package hust.cs.javacourse.search.util;

import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/*
字符串分割类，根据标点符号和空白符将字符串分成一个个单词
 */
public class StringSplitter extends Object {
    private String splitRegex;
    private Pattern pattern;
    private Matcher match;


    public void setSplitRegex(String regex) {

    }

    public List<String> splitByRegex(java.lang.String input) {
        List<String> result = new ArrayList<String>();


        return result;
    }

    public static void main(String[] args) {

    }
}
