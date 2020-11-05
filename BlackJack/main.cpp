#include <iostream>
#include <vector>
using namespace std;

enum class rank{
	ace,
	two,
	three,
	four,
	five,
	six,
	seven,
	eight,
	nine,
	ten,
	jack,
	king,
	queen
};

enum class suit{
	clubs,
	diamonds,
	hearts,
	spades
};

class Card{
	enum::rank m_Rank;
	enum::suit m_Suit;
	bool m_IsFaceUp;
public:
	Card(int r,int s, bool IFU): m_Rank(static_cast<enum::rank>(r)), m_Suit(static_cast<enum::suit>(s)), m_IsFaceUp(IFU) {}
	int GetValue(){
			return static_cast<int>(m_Rank)>9 ? 10 : static_cast<int>(m_Rank)+1;
		}
	void Flip(){
			m_IsFaceUp=!m_IsFaceUp;
		}
};

class Hand{
	vector<Card*> m_Cards;
public:
	Hand(){}
	void Add(Card* pCard){
			m_Cards.push_back(pCard);
		}
	void Clear(){
			for (int i=0; i<static_cast<int>(m_Cards.size());i++) delete m_Cards[i];
			m_Cards.clear();
		}
	int GetTotal(){
			int total=0;
			int aces=0;
			for (int i=0; i<static_cast<int>(m_Cards.size());i++){
				if(m_Cards[i]->GetValue()==1){
					aces++;
				}else{
					total+=m_Cards[i]->GetValue();
				}
			}
			if (aces==1){
					if(total+11<=21){
						total+=11;
					}else{
					total+=1;
					}
			}
			if (aces==2 && total==0){
				total=21;
			}
			if (aces>2){
				aces--;
				if(total+11<=21){
					total+=11;
					total+=aces;
				}else{
				total+=1;
				total+=aces;
				}
			}
			return total;
		}
	~Hand(){
			Clear();
		}

};


int main()
{
//    cout << "\t\tWelcome to Blackjack!\n\n";

//    int numPlayers = 0;
//    while (numPlayers < 1 || numPlayers > 7)
//    {
//        cout << "How many players? (1 - 7): ";
//        cin >> numPlayers;
//    }

//    vector<string> names;
//    string name;
//    for (int i = 0; i < numPlayers; ++i)
//    {
//        cout << "Enter player name: ";
//        cin >> name;
//        names.push_back(name);
//    }
//    cout << endl;

//    // игровой цикл
//    Game aGame(names);
//    char again = 'y';
//    while (again != 'n' && again != 'N')
//    {
//        aGame.Play();
//        cout << "\nDo you want to play again? (Y/N): ";
//        cin >> again;
//    }
		Hand h;
		h.Add(new Card(10,1,1));
		h.Add(new Card(5,1,1));
		cout<<h.GetTotal()<<endl;
	return 0;
}
