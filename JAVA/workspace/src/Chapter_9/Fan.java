package Chapter_9;

public class Fan {
	static int SLOW = 1;
	static int MEDIUM = 2;
	static int FAST = 3;
	
    private int speed;
    public int GetSpeed() {
        return this.speed;
    }
    public void SetSpeed(int speed) {
        this.speed = speed;
    }

    private boolean on;
    public boolean GetSOn() {
        return this.on;
    }
    public void SetOn(boolean on) {
        this.on = on;
    }

    private double radius;
    public double GetRadius() {
        return this.radius;
    }
    public void SetRadius(double radius) {
        this.radius = radius;
    }

    String color = "blue";
    public String GetColor() {
        return this.color;
    }
    public void SetColor(String color) {
        this.color = color;
    }

    public Fan() {
        this.speed = SLOW;
        this.on = false;
        this.radius = 5;
        this.color = "blue";
    }

    @Override
    public String toString() {
        StringBuffer result = new StringBuffer();
        if (on == true) {
        	result.append("Speed: " + speed + "\n");
            result.append("Color: " + color + "\n");
            result.append("Radius: " + radius + "\n");
        }
        else {
        	result.append("fan is off\n");
        }
        
        String output = result.toString();
        return output;
    }
}
