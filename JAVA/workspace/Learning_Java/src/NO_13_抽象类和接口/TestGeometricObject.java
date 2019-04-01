package NO_13_抽象类和接口;

public class TestGeometricObject {

	public static void main(String[] args) {
		GeometricObject geoObjectl = new Circle(5) ;

		System.out.println("The object's area? ") ;
		
		displayGeometricObject(geoObjectl) ;
	}

	public static void displayGeometricObject(GeometricObject object) {
		System.out .println() ;
		System.out.println("The area is " + object .getArea()) ;
		System.out.println("The perimeter is " + object.getPerimeter()) ;
	}
}
