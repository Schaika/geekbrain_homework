#include <iostream>

using namespace std;

class OffTheField{
	int x;
	int y;
	char name;
	int Direction;
public:
	OffTheField(int xCoord, int yCoord, char n, int Dir){
			x=xCoord;
			y=yCoord;
			name=n;
			Direction=Dir;
		}
	friend ostream &operator<< (ostream &out, const OffTheField &OTF);
	~OffTheField(){};
};
ostream &operator<< (ostream &out, const OffTheField &OTF){
		out<<"Class Robot Exception: 'OffTheField'\ntried to move coord '"<<OTF.name<<"'"<<" with current pos x("<<OTF.x<<") y("<<OTF.y<<")";
		if (OTF.Direction>0){
			out<<" in PLUS direction";
		}else{
			out<<" in MINUS direction";
		}
		return out;
	}

class IllegalCommand{
	int input;
public:
	IllegalCommand(int in){
			input=in;
		};
	friend ostream &operator<< (ostream &out, const IllegalCommand &IC);
};
ostream &operator<< (ostream &out, const IllegalCommand &IC){
		out<<"Class Robot Exception: 'IllegalCommand'\n";
		out<<"Received unknown command: '"<<IC.input<<"' ";
		out<<"Expected: (0, 1, 2, 3)";
		return out;
	}

class Robot{
	int x;
	int y;
	void pMoveX(int xDir){
			if (x+xDir>9 || x+xDir<0) throw OffTheField(x,y,'X',xDir);
			x+=xDir;
		}
	void pMoveY(int yDir){
			if (y+yDir>9 || y+yDir<0) throw OffTheField(x,y,'Y',yDir);
			y+=yDir;
		}
public:
	Robot():x(4),y(4){};
	void mPrintCurPos(){
			cout<<"Current position: X("<<x<<") Y("<<y<<")"<<endl;
		};
	void MoveTo(int direction){
			switch (direction) {
			case 0:
				pMoveX(1);
				break;
			case 1:
				pMoveY(1);
				break;
			case 2:
				pMoveX(-1);
				break;
			case 3:
				pMoveY(-1);
				break;
			default:
				throw IllegalCommand(direction);
			}
		mPrintCurPos();
		}
	~Robot(){}
};

int main()
	{		
		Robot myRobot;
		int user_input;
		cout<<"Move robot cycle:\n\tDirections: 0 1 2 3\n";
		cout<<"\t      1(Y+)\n\t2(X-)       0(X+)\n\t      3(Y-)";
		cout<<"\n\tInput -1 to break"<<endl;
		myRobot.mPrintCurPos();
while(true){
	cout<<"\t:";
	cin >> user_input; //Строгой проверки пользовательского ввода нет, реализация только для отладки
	if (user_input == -1)break;
	try {
		myRobot.MoveTo(user_input);
	}  catch (const OffTheField &OTF) {
			cerr<<OTF<<endl;
	} catch(const IllegalCommand &IC){
			cerr<<IC<<endl;
	}

}
		return 0;
	}
