package Chapter_19;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;


public class Test2 {

	static class TwoTuple<T1 extends Comparable, T2 extends Comparable> implements Comparable
	{
        private T1 first;
        private T2 second;

        public T1 GetFirst() {
            return first;
        }
        public void SetFirst(T1 first) {
            this.first = first;
        }
        public T2 GetSecond() {
            return second;
        }
        public void SetSecond(T2 second) {
            this.second = second;
        }
        
        public TwoTuple() {
        	
        }
        public TwoTuple(T1 first, T2 second) {
        	this.first = first;
        	this.second = second;
        }
        
        @Override
		public int compareTo(Object o) {
        	if (!first.equals(((TwoTuple<T1, T2>) o).GetFirst()))
            	return first.compareTo(((TwoTuple<T1, T2>) o).GetFirst());
            else
            	return second.compareTo(((TwoTuple<T1, T2>) o).GetSecond());
		}
        @Override
        public boolean equals(Object o) {
            if (first.equals(((TwoTuple<T1, T2>) o).GetFirst()) && second.equals(((TwoTuple<T1, T2>) o).GetSecond())) {
                return true;
            }
            return false;
        }
		public String toString() {
            return "(" + first.toString() + ", " + second.toString() + ")";
        }
		
	}
	
	public static void main(String[] args) {
		TwoTuple<Integer,String> twoTuple1 = new TwoTuple<>(1, "ccc");
        TwoTuple<Integer,String> twoTuple2 = new TwoTuple<>(1, "bbb");
        TwoTuple<Integer,String> twoTuple3 = new TwoTuple<>(1, "aaa");
        TwoTuple<Integer,String> twoTuple4 = new TwoTuple<>(2, "ccc");
        TwoTuple<Integer,String> twoTuple5 = new TwoTuple<>(2, "bbb");
        TwoTuple<Integer,String> twoTuple6 = new TwoTuple<>(2, "aaa");
        List<TwoTuple<Integer,String>> list = new ArrayList<>();
        list.add(twoTuple1);
        list.add(twoTuple2);
        list.add(twoTuple3);
        list.add(twoTuple4);
        list.add(twoTuple5);
        list.add(twoTuple6);

        
        TwoTuple<Integer,String> twoTuple10 =new TwoTuple<>(1, "ccc"); 
        System.out.println(twoTuple1.equals(twoTuple10)); 
        if(!list.contains(twoTuple10)){
            list.add(twoTuple10);  
        }

        Collections.sort(list);
        for (TwoTuple<Integer, String> t: list) {
            System.out.println(t);
        }
	
        TwoTuple<TwoTuple<Integer,String >,TwoTuple<Integer,String >> tt1 = new TwoTuple<>(new TwoTuple<>(1,"aaa"),new TwoTuple<>(1,"bbb"));
        TwoTuple<TwoTuple<Integer,String >,TwoTuple<Integer,String >> tt2 = new TwoTuple<>(new TwoTuple<>(1,"aaa"),new TwoTuple<>(2,"bbb"));
        System.out.println(tt1.compareTo(tt2)); //输出-1
        System.out.println(tt1);
	}

}
