package Chapter_9;

public class FanTest {

	public static void main(String[] args) {
		Fan fan_1 = new Fan();
		Fan fan_2 = new Fan();

		fan_1.SetSpeed(Fan.FAST);
		fan_1.SetRadius(10);
		fan_1.SetColor("yellow");
		fan_1.SetOn(true);

		fan_2.SetSpeed(Fan.MEDIUM);
		fan_2.SetRadius(5);
		fan_2.SetColor("blue");
		fan_2.SetOn(false);

		System.out.println("fan 1: ");
		System.out.println(fan_1.toString());
		System.out.println("fan 2: ");
		System.out.println(fan_2.toString());
	}

}
