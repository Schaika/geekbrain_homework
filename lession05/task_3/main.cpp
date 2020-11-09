#include <iostream>

using namespace std;

template <typename T, typename S>
class Pair{
protected:
		T f;
		S s;
public:
		Pair(T a, S b){
				f = a;
				s = b;
			}
		T first() const{
				return f;
			}
		S second() const{
				return	s;
			}
	};

template <typename U>
class StringValuePair : public Pair<string, U>{
public:
	StringValuePair(string str, U c):Pair<string, U>(str,c){};
};


int main()
{
	StringValuePair<int> svp("Amazing", 7);
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
	return 0;
}

