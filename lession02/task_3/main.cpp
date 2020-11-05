#include <iostream>

using namespace std;

class basePlayer{
protected:
	int score=0;
};

class Dealer : public basePlayer{

};


class CPUplayer : public basePlayer{

};

class Player : public basePlayer{

};

class Card{
	char cardRank; //A K Q J 10 9 8 7 6 5 4 3 2
	string suitName;
	char suitLogo;
	int number; // 2-10
	int ID;
	static int count;
};


int main()
	{
		return 0;
	}
