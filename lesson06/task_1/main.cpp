#include <iostream>

using namespace std;

int main()
	{
		string user_input;
		bool correct;
		cout<<"Input an integer number\n :";
		do{
			correct=true;
			getline(cin,user_input);
			for(int i = 0; i < static_cast<int>(user_input.size()); i++){
				if ( isdigit(user_input[i])) continue;	else {correct=false; cout<<"Incorrect input!\n :"; break;}
			}

		}while(!correct);
		cout<<user_input<<" is integer"<<endl;

	}
