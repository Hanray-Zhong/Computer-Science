package NO_13_抽象类和接口;

public class Circle extends GeometricObject{
	
	private double radius;
	
	public Circle() {
		
	}
	
	public Circle (double radius) {
		this. radius = radius;
	}
	
	public Circle (double radius ,String color , boolean filled) {
		this.radius = radius;
		setColor(color) ;
		setFilied(filled) ;
	}
	
	/** Return radius */
	public double getRadius() {
		return radius;
	}
	
	/** Set a new radius */
	public void setRadius(double radius) {
		this. radius = radius;
	}
	
	
	@Override
	public double getArea() {
		return radius * radius * Math .PI ;
	}

	@Override
	public double getPerimeter() {
		// TODO Auto-generated method stub
		return 2 * radius * Math .PI ;
	}

}
