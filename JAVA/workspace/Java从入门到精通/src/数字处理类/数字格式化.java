package 数字处理类;

import java.text.DecimalFormat;

public class 数字格式化 {
	static public void SimgleFormat(String pattern, double value){
		//实例化DecimalFormat
		DecimalFormat myFormat = new DecimalFormat(pattern);
		String output = myFormat.format(value);//将数字格式化
		System.out.println(value + " " + pattern + " " + output);
	}
	
	//使用ApplyPattern方法进行格式化
	static public void UseApplyPatternMethodFormat(String pattern, double value) {
		DecimalFormat myFormat = new DecimalFormat();
		myFormat.applyPattern(pattern);//设置格式化模板
		System.out.println(value + " " + pattern + " " + myFormat.format(value));
	}
	
	public static void main(String[] args) {
		SimgleFormat("###,###.###", 123456.789);
		SimgleFormat("0000000.###kg", 123456.789);
		
		SimgleFormat("000000.000", 123.78);
		UseApplyPatternMethodFormat("#.###%", 0.789);
		UseApplyPatternMethodFormat("###.##", 123456.789);
		UseApplyPatternMethodFormat("0.00\u2030",0.789);
	}

}
