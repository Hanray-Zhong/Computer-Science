package NO_11_�̳кͶ�̬;

public class Faculty extends Employee {
	
	public static void main(String[] args) {
		new Faculty();
	}
	
	public Faculty() {
		System.out.println("(4)Performs Faculty's tasks");
	}
	
	@Override
	public String toString() {
		return super.toString() + "\n override add ";
	}
}

class Employee extends Person {
	public Employee(){
		this("(2)Invoke Employee's overloaded constructor");
		System.out.println("(3)Performs Employee's tasks ");
	}

	public Employee(String s){
		System.out.println(s);
	}
}

class Person{
	public Person() {
		System.out.println("(l)Performs Person's tasks");
	}
}