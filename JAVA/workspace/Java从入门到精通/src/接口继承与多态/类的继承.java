package �ӿڼ̳����̬;

public class ��ļ̳� {
	public static void main(String[] args) {
		Test t1 = new Test();
		t1.doSomething();
		
		Test2 t2 = new Test2();
		t2.newDoSomething();
		t2.doSomething();
	}
}

class Test{
	public Test(){            //���췽��
		System.out.println("����ɹ�");
	}
	
	protected void doSomething() {       //��Ա����
		System.out.println("���෽��");
	}
	
	protected Test dolt() {          //����ֵ����ΪTest�ķ���
		return new Test();
	}
}

class Test2 extends Test{        //�̳и���
	public Test2() {
		super();                 //���ø��๹�췽��
		super.doSomething();     //���ø��෽��
	}
	
	public void newDoSomething() {
		System.out.println("�����·���");
	}
	
	public void doSomething() {    //��д���෽��
		System.out.println("��д���෽��");
	}
	
	protected Test2 dolt() {       //��дһ������ֵΪTest2�ķ���
		return new Test2();
	}
}

