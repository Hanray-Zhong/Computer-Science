package Chapter_6_7;

public class Test2 {

	public static void main(String[] args) {
		int[] a = {1};
        String[] s = {"Hello"};
        int i = a[0];
        m(s,a,i);
        for(String v:s){
            System.out.println(v);
        }
        for(int v:a){
            System.out.println(v);
        }
        System.out.println(i);
    }
    public static void m(String[] a1, int[] a2, int i){
        for(String s :a1){
            s = "Java";
        }
        for(int v :a2){
            v++;
        }
        i++;
    }

}
