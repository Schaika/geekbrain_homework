#include <iostream>

using namespace std;

class Card{
	enum eSuit{
		clubs,
		diamonds,
		hearts,
		spades
	}Suit;
	enum eNumber{
		two = 2,
		three = 3,
		four = 4,
		five = 5,
		six = 6,
		seven = 7,
		eight = 8,
		nine = 9,
		ten = 10,
		king = 10,  //Они никогда не будут активны, пока не понял что с ними делать
		queen = 10, //
		jack = 10,  //
		ace = 1
	}Number;
	bool status=false;

public:
	Card(int eS,int eN,bool s) : Suit(static_cast<eSuit>(eS)), Number(static_cast<eNumber>(eN)), status(s){}
	Card(eSuit eS,eNumber eN,bool s) : Suit(eS), Number(eN), status(s){}
	int GetValue() const{
			return Number;
		}
	int GetStatus() const{
			return status;
		}
	void Flip(){
			status=!status;
		}
};

int main()
	{
		//Card test2(Card::clubs,Card::seven,false);	// работает только если объявлять поля в области public
		Card test(2,10,false);							// Иначе приходится делать через static_cast
		cout<<test.GetValue()<<endl;
		cout<<test.GetStatus()<<endl;
		test.Flip();
		cout<<test.GetStatus()<<endl;
		test.Flip();
		cout<<test.GetStatus()<<endl;
		return 0;
	}
