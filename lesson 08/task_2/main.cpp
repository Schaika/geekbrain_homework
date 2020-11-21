#include <iostream>

using namespace std;

class Ex{
	public:
	double x;
	Ex(double in):x(in){};
	~Ex(){}
};

class Bar{
	double y;
public:
	Bar():y(0){};
	void Set(double a){
			if (a + y > 100) throw Ex(a*y);
			y = a;
		};
	~Bar(){}
};

int main()
	{
		Bar cMain;
		try {
			int n;
			do{
				cout<<"Input number: ";
				cin>>n;
				cMain.Set(n);

			}while(n!=0);
		}  catch (Ex &exception) {
			cerr<<"Exception: "<<exception.x<<endl;
		}
		return 0;
	}
