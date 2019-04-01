package NO_12_异常处理_自定义异常类;

public class InvalidRadiusException extends Exception {
	private double radius;
	
	public InvalidRadiusException(double radius) {
		super("Invalid radius " + radius);
		this.radius = radius;
	}
	
	public double getRadius() {
		return radius;
	}
}
