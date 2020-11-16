#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
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
	queen,
	king
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
	friend std::ostream& operator<<(std::ostream& os, const Card& aCard);
public:
	Card(int r,int s): m_Rank(static_cast<enum::rank>(r)), m_Suit(static_cast<enum::suit>(s)), m_IsFaceUp(false) {}
	int GetValue(){
			return static_cast<int>(m_Rank)>9 ? 10 : static_cast<int>(m_Rank)+1;
		}
	void Flip(){
			m_IsFaceUp=!m_IsFaceUp;
		}

};
std::ostream& operator<<(std::ostream& os, const Card& aCard)
{
	const std::string RANKS[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9","10", "J", "Q", "K" };
	const std::string SUITS[] = { "C", "D", "H", "S" };

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
	std::vector<Card*> m_Cards;
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
	friend std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer);
protected:
	std::string m_Name;
public:
	GenericPlayer(const std::string& name) : m_Name(name){};

	virtual bool IsHitting() const = 0;

	bool IsBusted() const{
			return this->GetTotal()>21;
		}
	void Bust() const{
				std::cout<<m_Name<<" is busted."<<std::endl;
	}
	virtual ~GenericPlayer(){};
	};
std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer)
{
	os << aGenericPlayer.m_Name << ":\t";

	std::vector<Card*>::const_iterator pCard;
	if (!aGenericPlayer.m_Cards.empty())
	{
		for (pCard = aGenericPlayer.m_Cards.begin(); pCard != aGenericPlayer.m_Cards.end(); pCard++)
		{
			os << *(*pCard) << "\t";
		}


		if (aGenericPlayer.GetTotal() != 0)
		{
			std::cout << "(" << aGenericPlayer.GetTotal() << ")";
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
	Player(const std::string& name):GenericPlayer(name){};

	// показывает, хочет ли игрок продолжать брать карты
	bool IsHitting() const
		{
			std::cout << m_Name << ", do you want a hit? (Y/N): ";
			char response;
			std::cin >> response;
			return (response == 'y' || response == 'Y');
		}


	// объявляет, что игрок победил
	void Win() const{
			std::cout << m_Name << " wins.\n";
		}

	// объявляет, что игрок проиграл
	void Lose() const{
			std::cout << m_Name << " loses.\n";
		}

	// объявляет ничью
	void Push() const{
			std::cout << m_Name << " pushes.\n";
		}

	virtual ~Player(){};
};

class House : public GenericPlayer
{
public:
	House(const std::string& name = "House"):GenericPlayer(name){};

	virtual ~House(){};

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
				std::cout << "No card to flip!\n";
			}
		}
};

class Deck : public Hand
{
public:
	Deck(){
			m_Cards.reserve(52);
			Populate();
		}
	// создает стандартную колоду из 52 карт
	void Populate()
	{
		Clear();
		// создает стандартную колоду
		for (int s = static_cast<int>(suit::clubs); s <= static_cast<int>(suit::spades); s++)
		{
			for (int r = static_cast<int>(rank::ace) ; r <= static_cast<int>(rank::king); ++r)
			{
				Add(new Card(r, s));
			}
		}
	}


	// тасует карты
	void Shuffle(){
			random_shuffle(m_Cards.begin(), m_Cards.end());
		}

	// раздает одну карту в руку
	void Deal(Hand& aHand){
			if (!m_Cards.empty())
			{
				aHand.Add(m_Cards.back());
				m_Cards.pop_back();
			}
			else
			{
				std::cout << "Out of cards. Unable to deal.";
			}
		}

	// дает дополнительные карты игроку
	void AdditionalCards(GenericPlayer& aGenericPlayer){
			// продолжает раздавать карты до тех пор, пока у игрока не случается
			// перебор или пока он хочет взять еще одну карту
			while (!(aGenericPlayer.IsBusted()) && aGenericPlayer.IsHitting())
			{
				Deal(aGenericPlayer);
				std::cout << aGenericPlayer << std::endl;

				if (aGenericPlayer.IsBusted())
				{
					aGenericPlayer.Bust();
				}
			}

		}
	virtual ~Deck(){};
};


class Game
{
public:
	Game(const std::vector<std::string>& names){
			// создает вектор игроков из вектора с именами
			std::vector<std::string>::const_iterator pName;
			for (pName = names.begin(); pName != names.end(); ++pName)
			{
				m_Players.push_back(Player(*pName));
			}

			// запускает генератор случайных чисел
			srand(static_cast<unsigned int>(time(NULL)));
			m_Deck.Populate();
			m_Deck.Shuffle();
		}


	~Game(){};
	void Play();

private:
	Deck m_Deck;
	House m_House;
	std::vector<Player> m_Players;
};
void Game::Play()
{
	// раздает каждому по две стартовые карты
	std::vector<Player>::iterator pPlayer;
	for (int i = 0; i < 2; ++i)
	{
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		{
			m_Deck.Deal(*pPlayer);
		}
		m_Deck.Deal(m_House);
	}

	// открывает руки всех игроков
	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
	{
		std::cout << *pPlayer << std::endl;
	}
	std::cout << m_House << std::endl;

	// раздает игрокам дополнительные карты
	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
	{
		m_Deck.AdditionalCards(*pPlayer);
	}

	// показывает первую карту дилера
	m_House.FlipFirstCard();
	std::cout << m_House<<std::endl;

	// раздает дилеру дополнительные карты
	m_Deck.AdditionalCards(m_House);

	if (m_House.IsBusted())
	{
		// все, кто остался в игре, побеждают
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		{
			if (!(pPlayer->IsBusted()))
			{
				pPlayer->Win();
			}
		}
	}
	else
	{
		// сравнивает суммы очков всех оставшихся игроков с суммой очков дилера
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end();
			 ++pPlayer)
		{
			if (!(pPlayer->IsBusted()))
			{
				if (pPlayer->GetTotal() > m_House.GetTotal())
				{
					pPlayer->Win();
				}
				else if (pPlayer->GetTotal() < m_House.GetTotal())
				{
					pPlayer->Lose();
				}
				else
				{
					pPlayer->Push();
				}
			}
		}

	}

	// очищает руки всех игроков
	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
	{
		pPlayer->Clear();
	}
	m_House.Clear();
}





int main()
{
	std::cout << "\t\tWelcome to Blackjack!\n\n";

	int numPlayers = 0;
	while (numPlayers < 1 || numPlayers > 7)
	{
		std::cout << "How many players? (1 - 7): ";
		std::cin >> numPlayers;
	}

	std::vector<std::string> names;
	std::string name;
	for (int i = 0; i < numPlayers; ++i)
	{
		std::cout << "Enter player name: ";
		std::cin >> name;
		names.push_back(name);
	}
	std::cout << std::endl;

	// игровой цикл
	Game aGame(names);
	char again = 'y';
	while (again != 'n' && again != 'N')
	{
		aGame.Play();
	   std::cout << "\nDo you want to play again? (Y/N): ";
		std::cin >> again;
	}

	return 0;
}
