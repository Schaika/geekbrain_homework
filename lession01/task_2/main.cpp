#include <iostream>
#include <cstdint>
using namespace std;

class RGBA{
	uint8_t m_red;
	uint8_t m_green;
	uint8_t m_blue;
	uint8_t m_alpha;
public:
	RGBA():m_red(0),m_green(0),m_blue(0),m_alpha(255){};
	RGBA(uint8_t r,uint8_t g,uint8_t b,uint8_t a){
		m_red=r;
		m_green=g;
		m_blue=b;
		m_alpha=a;
		};
	void print(){
			//без приведения типов не работает правильный вывод в консоль
		cout << "Red \t" <<(int) m_red << endl;
		cout << "Green \t" <<(int) m_green << endl;
		cout << "Blue \t" <<(int) m_blue << endl;
		cout << "Alpha \t" <<(int) m_alpha << endl;

		};
};

int main()
	{
RGBA my_color;
my_color.print();
cout<<" "<<endl;
RGBA my_color2(128,65,7,255);
my_color2.print();
return 0;
	}
