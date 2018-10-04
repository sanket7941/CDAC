package Circle;

public class Circle 
{
	private int radius;
	private int diameter;
	private float circumference;
	private float area;
	

	public int getRadius() {
		return radius;
	}

	public void setRadius(int radius) {
		this.radius = radius;
	}
	
	
	public int getDiameter() {
		diameter = radius * 2;
		return diameter;
	}
	
	public float getCircumference() {
		circumference= (float) (2 * Math.PI * radius);
		return circumference;
	}

	public float getArea() {
		area=(float) (Math.PI * Math.pow(radius, 2)); 
		return area;
	}

	
}
