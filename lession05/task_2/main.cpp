#include <iostream>

using namespace std;

template <typename T, typename S>
class Pair{
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

int main()
{
	Pair<int, double> p1(6, 7.8);
	cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair<double, int> p2(3.4, 5);
	cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	return 0;
}

