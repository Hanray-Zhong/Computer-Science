package 接口继承与多态;

public class 类的继承 {
	public static void main(String[] args) {
		Test t1 = new Test();
		t1.doSomething();
		
		Test2 t2 = new Test2();
		t2.newDoSomething();
		t2.doSomething();
	}
}

class Test{
	public Test(){            //构造方法
		System.out.println("构造成功");
	}
	
	protected void doSomething() {       //成员方法
		System.out.println("父类方法");
	}
	
	protected Test dolt() {          //返回值类型为Test的方法
		return new Test();
	}
}

class Test2 extends Test{        //继承父类
	public Test2() {
		super();                 //调用父类构造方法
		super.doSomething();     //调用父类方法
	}
	
	public void newDoSomething() {
		System.out.println("子类新方法");
	}
	
	public void doSomething() {    //重写父类方法
		System.out.println("重写父类方法");
	}
	
	protected Test2 dolt() {       //重写一个返回值为Test2的方法
		return new Test2();
	}
}

