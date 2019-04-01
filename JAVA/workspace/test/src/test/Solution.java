package test;

public class Solution {
    public String convert(String s, int numRows) {
        int i = 0;
        int j = 0;
        int k = 0;
        boolean isBack = false;
        char[][] z_str = new char[numRows][1000];
        StringBuffer result = new StringBuffer();
        while (k < s.length()) {
            z_str[i][j] = s.charAt(k);
            if (i == numRows - 1)
                isBack = true;
            if (i == 0 && isBack == true)
                isBack = false;
            if (isBack) {
                i -= 1;
                j += 1;
            }
            else {
                i += 1;
            }
            k += 1;
        }
        for (i = 0; i < numRows; i++) {
            for (char var : z_str[i]) {
                if (var != 0)
                    result.append(var);
            }
        }

        return result.toString();
    }
}