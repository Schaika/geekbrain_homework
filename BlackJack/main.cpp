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
	friend ostream& operator<<(ostream& os, const Card& aCard);
public:
	Card(int r,int s, bool IFU): m_Rank(static_cast<enum::rank>(r)), m_Suit(static_cast<enum::suit>(s)), m_IsFaceUp(IFU) {}
	int GetValue(){
			return static_cast<int>(m_Rank)>9 ? 10 : static_cast<int>(m_Rank)+1;
		}
	void Flip(){
			m_IsFaceUp=!m_IsFaceUp;
		}

};
ostream& operator<<(ostream& os, const Card& aCard)
{
	const string RANKS[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9","10", "J", "Q", "K" };
	const string SUITS[] = { "C", "D", "H", "S" };

	if (aCard.m_IsFaceUp)
	{
		os << RANKS[static_cast<int>(aCard.m_Rank)] << SUITS[static_cast<int>(aCard.m_Suit)];
	}
	else
	{
		os << "XX";
	}

	return os;
}


class Hand{
protected:
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
	int GetTotal() const{
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
	virtual ~Hand(){
			Clear();
		}

};

class GenericPlayer : public Hand{
	friend ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);
protected:
	string m_Name;
public:
	GenericPlayer(const string& name) : m_Name(name){};

	virtual bool IsHitting() const = 0;

	bool IsBoosted() const{
			return this->GetTotal()>21;
		}
	void Bust() const{
				cout<<m_Name<<" is busted."<<endl;
	}
	virtual ~GenericPlayer(){};
	};
ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer)
{
	os << aGenericPlayer.m_Name << ":\t";

	vector<Card*>::const_iterator pCard;
	if (!aGenericPlayer.m_Cards.empty())
	{
		for (pCard = aGenericPlayer.m_Cards.begin(); pCard != aGenericPlayer.m_Cards.end(); pCard++)
		{
			os << *(*pCard) << "\t";
		}


		if (aGenericPlayer.GetTotal() != 0)
		{
			cout << "(" << aGenericPlayer.GetTotal() << ")";
		}
	}
	else
	{
		os << "<empty>";
	}

	return os;
}

class Player : public GenericPlayer
{
public:
	Player(const string& name = "");

	// показывает, хочет ли игрок продолжать брать карты
	bool IsHitting() const
		{
			cout << m_Name << ", do you want a hit? (Y/N): ";
			char response;
			cin >> response;
			return (response == 'y' || response == 'Y');
		}


	// объявляет, что игрок победил
	void Win() const{
			cout << m_Name << " wins.\n";
		}

	// объявляет, что игрок проиграл
	void Lose() const{
			cout << m_Name << " loses.\n";
		}

	// объявляет ничью
	void Push() const{
			cout << m_Name << " pushes.\n";
		}

	~Player();
};

class House : public GenericPlayer
{
public:
	House(const string& name = "House");

	virtual ~House();

	// показывает, хочет ли дилер продолжать брать карты
	bool IsHitting() const{
			return (GetTotal() <= 16);
		}

	// переворачивает первую карту
	void FlipFirstCard(){
			if (!(m_Cards.empty()))
			{
				m_Cards[0]->Flip();
			}
			else
			{
				cout << "No card to flip!\n";
			}
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
	return 0;
}
