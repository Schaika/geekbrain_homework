#include <iostream>

using namespace std;
class Car{
protected:
	string company;
	string model;
public:
	Car(string a, string b) : company(a), model(b){
			cout << "Company '" << a << "', Model '" << b << "'\n\r";
		};

};
class PassengerCar : virtual public Car{
protected:
	string Type;
public:
	PassengerCar(string a, string b): Car(a,b),Type("Passenger Car"){
			cout << Type << endl;
		}
};
class Bus : virtual public Car{
protected:
	string Type;
public:
	Bus(string a, string b): Car(a,b),Type("Bus"){
			cout << Type << endl;
		}
};
class Minivan : public Bus, public PassengerCar{
protected:
	string Type;
public:
	Minivan(string a, string b): Car(a,b),Bus(a,b),PassengerCar(a,b),Type("Minivan"){
			cout << Type << endl;
		}
};

int main()
	{
		Car a("Basic","Generic");
		PassengerCar b("VAZ","2001");
		Bus c("Mercedes","Citaro");
		cout<<"------------------"<<endl;
		Minivan("VolksWagen","Transporter");
		return 0;
	}
