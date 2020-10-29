#include <iostream>

using namespace std;

class Person{
protected:
	string name;
	int age;
	double weight;
public:

	Person(string n, int a, double w): name(n), age(a), weight(w) {}
	void setAge(int a){age = a;}
	void setName(string n){name = n;}
	void setWeight(double w){weight	= w;}
	};
class Student : public Person{
int years;
static int count;
	public:

Student(string n, int a, double w, int y):Person(n,a,w), years(y){count++;}
static int getNumberOf(){return count;}
void setYears(int y){years=y;}
void addYears(int y){years+=y;}
void print() const {
		cout<<"Name: " << name<<"; Age: " << age << "; Weight: " << weight << "; Years of Studying: " << years<<endl;
	}
};
int Student::count = 0;
int main()
	{
		Student first("Ivan",22,73.7,2);
		Student second("Anton",25,101.2,4);
		Student third("Sasha",19,56.1,1);
		second.print();
		second.setAge(52);
		second.print();

		cout<<"Number of students: "<<Student::getNumberOf()<<endl;
		return 0;
	}
