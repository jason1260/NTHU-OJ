#ifndef SHAPE_H
#define SHAPE_H

namespace oj
{
	class Shape3D
	{	
		double volume;

	public:
		double getVolume();
	
	protected:
		void setVolume(double volume);
	};

	class Sphere : public Shape3D
	{
		double radius;
		double pi;
	
	public:
		Sphere(double r, double p);
	};
	Sphere::Sphere(double r, double p) {
		if (r > 0 && p > 0) setVolume(4.0 / 3.0 * p * r * r * r);
		else setVolume(0);
	}

	class Cone : public Shape3D
	{
		double radius;
		double height;
		double pi;

	public:
		Cone(double r, double h, double p);
	};
	Cone::Cone(double r, double h, double p) {
		if (r > 0 && h > 0 && p > 0) 
			setVolume(p * r * r * h / 3.0);
		else setVolume(0);
	}

	class Cuboid : public Shape3D
	{
		double length;
		double width;
		double height;
	
	public:
		Cuboid(double, double, double);
	};
	Cuboid::Cuboid(double l, double w, double h) {
		if (l > 0 && w > 0 && h > 0)
			setVolume(l * w * h);
		else setVolume(0);
	}

	class Cube : public Cuboid
	{
	public:
		Cube(double);
	};
	Cube::Cube(double l) : Cuboid::Cuboid(l, l, l) {};
}


#endif
