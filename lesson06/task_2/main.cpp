#include <iostream>

using namespace std;

	ostream& endll(ostream &out){
			out<<"\n\r\n\r"<<flush;
			return out;
		};

int main()
	{
		cout << "Hello World!" << endll;
		cout << "Hello World!" << endl;
		return 0;
	}
