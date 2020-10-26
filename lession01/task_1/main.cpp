#include <iostream>
#include <math.h>
using namespace std;

class Power{
	double digit_a;
	double digit_b;

public:
	Power(): digit_a(2),digit_b(2) {}
	void set(double a, double b){
			digit_a=a;
			digit_b=b;
		}
	void calculate(){
			cout << digit_a <<"^" << digit_b << "=" << pow (digit_a, digit_b) << endl;
		}
};

int main()
	{
		Power my_thing;
		my_thing.calculate();
		my_thing.set(3.141592,2.72);
		my_thing.calculate();
		return 0;
	}
