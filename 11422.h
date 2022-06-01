#ifndef SHAPE_H
#define SHAPE_H
#include <cmath>
namespace oj
{
	class Shape 
	{	
	public:
		double getArea();
		double getPerimeter();
	
	protected:
		void setArea(double a);
		void setPerimeter(double p);
			
	private:
		double area;
		double perimeter;
	};

	class Triangle : public Shape
	{
	public:
		Triangle(double e1, double e2, double e3);
	private:
		double edge1;
		double edge2;
		double edge3;
	};
	Triangle::Triangle(double e1, double e2, double e3) {
		edge1 = e1; edge2 = e2; edge3 = e3;
		if (edge1 + edge2 > edge3 && edge1 + edge3 > edge2 && edge2 + edge3 > edge1 && edge1 > 0 && edge2 > 0 && edge3 > 0) {
			double s = (edge1 + edge2 + edge3) / 2;
			setArea(sqrt(s * (s - edge1) * (s - edge2) * (s - edge3)));
			setPerimeter(edge1 + edge2 + edge3);
		} 
		else {
			setArea(0.0);
			setPerimeter(0.0);
		}
	};

	class Rectangle : public Shape
	{
	public:
		Rectangle(double w, double h);
	private:
		double width;
		double height;
	};
	Rectangle::Rectangle(double w, double h) {
		width = w;
		height = h;
		if (width > 0 && height > 0) {
			setArea(width * height);
			setPerimeter(2 * (width + height));
		}
		else {
			setArea(0.0);
			setPerimeter(0.0);
		}
	};

	class Circle : public Shape
	{
	public:
		Circle(double rad, double p);
	private:
		double radius;
		double pi;
	};
	Circle::Circle(double rad, double p) {
		radius = rad;
		pi = p;
		if (radius > 0 && pi > 0) {
			setArea(rad * rad * pi);
			setPerimeter(2 * rad * pi);
		}
		else {
			setArea(0.0);
			setPerimeter(0.0);
		}
	};
}

#endif
