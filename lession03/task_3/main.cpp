#include <iostream>
using namespace std;

int GCD (int, int);

class Fraction{
	int Numerator;
	int Denominator;
public:
	Fraction(){Numerator=0; Denominator=0;};
	Fraction(int a,int b){
				if (b==0  || b<0){
					cout<<"Not a valid denominator! Program will be terminated."<<endl;
					exit(1);
				}else{
					Numerator=a;
					Denominator=b;
				}
		};
	void Print() const{
			cout<<Numerator<<"/"<<Denominator;
		}
	void Printl() const{
			cout<<Numerator<<"/"<<Denominator<<endl;
		}
	void PrintDec() const{
			cout<<(double)Numerator/Denominator<<endl;
		}
	void PrintSimple() const{
			int a,b,c,d;
			a = Numerator/Denominator;
			b = Numerator%Denominator;
			c = Denominator;
			d = GCD(b,c); //greatest common divisor
			if (a!=0) cout<<a<<" ";
			if (b!=0) cout<<b/d<<"/"<<c/d;
			cout<<endl;
		}
	// least common denominator
	friend void toLCD(Fraction &a, Fraction &b);


	//NOT
	Fraction operator- () const
	{
		return Fraction(-Numerator,Denominator);
	}
	// +
	friend Fraction operator+ (Fraction value1,Fraction value2);
	// -
	friend Fraction operator- (Fraction value1,Fraction value2);
	// *
	friend Fraction operator* (Fraction value1,Fraction value2);
	// /
	friend Fraction operator/ (Fraction value1,Fraction value2);
	// == !=
	bool operator== (Fraction &value) const{
			return (this->Numerator * value.Denominator) == (value.Numerator * this->Denominator) ? true : false;
		}
	bool operator!= (Fraction &value) const{
			return !(*this==value);
		}
	// > <=
	bool operator> (Fraction &value) const{
			return (this->Numerator * value.Denominator) > (value.Numerator * this->Denominator) ? true : false;
		}
	bool operator<= (Fraction &value) const{
			return !(*this>value);
		}
	// < >=
	bool operator< (Fraction &value) const{
			return (this->Numerator * value.Denominator) < (value.Numerator * this->Denominator) ? true : false;
		}
	bool operator>= (Fraction &value) const{
			return !(*this<value);
		}
};
//greatest common divisor
int GCD (int a, int b) {
	return (b == 0) ? a : GCD (b, a % b);
}

void toLCD(Fraction &a, Fraction &b){


		if (a.Denominator % b.Denominator == 0 || b.Denominator % a.Denominator == 0){
			if (a.Denominator % b.Denominator == 0){
				b.Numerator = b.Numerator * a.Denominator / b.Denominator;
				b.Denominator = a.Denominator;
			}else{
				a.Numerator = a.Numerator * b.Denominator / a.Denominator;
				a.Denominator = b.Denominator;
			}
		}else{
			a.Numerator *= b.Denominator;
			b.Numerator *= a.Denominator;
			a.Denominator *= b.Denominator;
			b.Denominator = a.Denominator;
		}


	}

Fraction operator+ (Fraction value1,Fraction value2){
	toLCD(value1, value2);

	return Fraction(value1.Numerator+value2.Numerator,value1.Denominator);
}
Fraction operator- (Fraction value1,Fraction value2){
	toLCD(value1, value2);

	return Fraction(value1.Numerator-value2.Numerator,value1.Denominator);
}
Fraction operator* (Fraction value1,Fraction value2){
	return Fraction(value1.Numerator*value2.Numerator,value1.Denominator*value2.Denominator);
}
Fraction operator/ (Fraction value1,Fraction value2){
	return Fraction(value1.Numerator*value2.Denominator,value1.Denominator*value2.Numerator);
}

int main()
	{
		using fraction = Fraction;
		fraction array[5];
		array[0]=fraction(1,2);
		array[1]=fraction(16,9);
		array[2]=fraction(15,8);
		array[3]=fraction(4,7);
		array[4]=fraction(1,2);
		cout<<"Fractions are (simplified):\n";
		for (int i=0;i<5;i++){
			cout<<i<<": "; array[i].PrintSimple();
		}
		cout << "---------------" << endl;
		array[0].Print(); cout << " > "; array[3].Print();cout << " is "; (array[0]>array[3]) ? cout<<"true\n" : cout<<"false\n";
		array[2].Print(); cout << " <= "; array[3].Print();cout << " is "; (array[2]<=array[3]) ? cout<<"true\n" : cout<<"false\n";
		array[0].Print(); cout << " == "; array[4].Print();cout << " is "; (array[0]==array[4]) ? cout<<"true\n" : cout<<"false\n";
		array[0].Print(); cout << " != "; array[4].Print();cout << " is "; (array[0]!=array[4]) ? cout<<"true\n" : cout<<"false\n";
		cout << "---------------" << endl;
		array[4].Print(); cout << " + "; array[2].Print();cout << " is ";
		array[4]=array[4]+array[2];
		array[4].Print(); cout<<" or ";
		array[4].PrintDec();

		array[4].Print(); cout << " - "; array[2].Print();cout << " is ";
		array[4]=array[4]-array[2];
		array[4].PrintSimple();
		cout << "---------------" << endl;
		array[1].Print(); cout << " * "; array[3].Print();cout << " is ";
		array[1]=array[1]*array[3];
		array[1].Printl();

		array[1].Print(); cout << " / "; array[0].Print();cout << " is ";
		array[1]=array[1]/array[0];
		array[1].Printl();
		cout << "---------------" << endl;
		cout<<"Final fractions are:\n";
		for (int i=0;i<5;i++){
			cout<<i<<": "; array[i].Printl();
		}
		return 0;
	}
