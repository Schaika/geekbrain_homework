#include <iostream>

using namespace std;
class Fruit{
protected:
	string name;
	string color;
public:
	Fruit(): name("*unknown*"), color("*unknown*"){};
	Fruit(string n, string c) : name(n), color(c){}
	string getName(){return name;}
	string getColor(){return color;}
};

class Apple : public Fruit{
public:
	Apple():Fruit("apple","*unknown*"){};
	Apple(string c):Fruit("apple",c){};
	Apple(string n,string c):Fruit(n + " apple",c){};
};

class Banana : public Fruit{
public:
	Banana():Fruit("banana","yellow"){};
};

class GrannySmith : public Apple{
public:
	GrannySmith(): Apple("Granny Smith","green"){};
};

int main()
	{

		Apple a("red");
		Banana b;
		GrannySmith c;

		std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
		std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
		std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

		return 0;
	}
