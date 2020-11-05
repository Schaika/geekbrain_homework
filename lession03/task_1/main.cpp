#include <iostream>

using namespace std;

class Figure{
		static int count;
public:
	Figure(){count++;};
	static int GetCount() {
			return count;
		};
	virtual double  area() const =0;
	virtual void print() const =0;
	virtual ~Figure(){count--;};
};

class Circle : public Figure{
protected:
	double radius;
public:
	Circle(double r):radius(r){};
	double area() const override{
			return 3.14159265*radius*radius;
		};
	void print() const override{
		cout<<"Circle:\n\tRadius = " << radius << "; Area = "<<area()<<endl;
		};
};

class Parallelogram : virtual public Figure{
protected:
	double length;
	double height;
public:
	Parallelogram(double a,double b):length(a),height(b){};
	virtual double area() const override{
			return length*height;
		};
	virtual void print() const override{
		cout<<"Parallelogram:\n\tBase = " << length << ", Height = " <<height<< "; Area = "<<area()<<endl;
		};
};

class Rectangle : virtual public Parallelogram{
public:
	Rectangle(double a,double b) : Parallelogram(a,b){};
	double area() const override{
			return length*height;
		};
	void print() const override{
		cout<<"Rectangle:\n\tLength = " << length << ", Height = " <<height<< "; Area = "<<area()<<endl;
		};
};
class Square : virtual public Parallelogram{
public:
	Square(double a) : Parallelogram(a,0){};
	double area() const override{
			return length*length;
		};
	void print() const override{
		cout<<"Square:\n\tSide length = " << length << "; Area = "<<area()<<endl;
		};
};
class Rhombus : virtual public Parallelogram{
public:
	Rhombus(double a,double b) : Parallelogram(a,b){};
	double area() const override{
			return length*height*0.5;
		};
	void print() const override{
		cout<<"Rhombus:\n\tFirst diagonal = " << length << ", Second diagonal = " <<height<< "; Area = "<<area()<<endl;
		};
};
int Figure::count=0;
int main()
	{
		Figure *shapes[5];
		shapes[0] = new Parallelogram(7,2);
		shapes[1] = new Circle(3.989422);
		shapes[2] = new Rectangle(13,2.5);
		shapes[3] = new Square(4);
		shapes[4] = new Rhombus(10,5);
		for (int i=0;i<Figure::GetCount();i++){
			shapes[i]->print();
		};
		return 0;
	}
