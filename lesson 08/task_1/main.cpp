#include <iostream>

using namespace std;
template <typename T, typename H>
double DIV(T lsh, H rsh){
		if (rsh==0) throw "Division by zero!";
		return lsh / rsh;
	};

int main()
	{
		try {
			cout<<DIV(16,0)<<endl;
		}  catch (const char * ex) {
			cerr<<ex<<endl;
		}

	}
