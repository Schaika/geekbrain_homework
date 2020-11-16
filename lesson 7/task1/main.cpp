#include <iostream>
#include <iomanip>
#include <memory>

using namespace std;

void swap(int &A,int &B){
		//XOR int swap
		if (A != B)
		{
		  A ^= B;
		  B ^= A;
		  A ^= B;
		}
	}

class Date{
	friend ostream &operator<< (ostream &out, const Date &date);
	friend void swap_date(unique_ptr<Date> &a, unique_ptr<Date> &b);

	int day;
	int month;
	int year;
public:
	Date(){};
	Date(int d, int m, int y):day(d), month(m), year(y){};
	int getYear() const{
			return year;
		}
	int getMonth()const{
			return month;
		}
	int getDay(){
			return day;
		}

};
ostream &operator<< (ostream &out, const Date &date){
		out<<"Date: "<<date.day<<"."<<date.month<<"."<<date.year;
		return out;
	}

Date &compare(unique_ptr<Date> &a, unique_ptr<Date> &b){
		if (a->getYear()>b->getYear()){
			return *a;
		}else if (a->getYear()<b->getYear()){
			return *b;
		}

		if (a->getMonth()>b->getMonth()){
			return *a;
		}else if (a->getMonth()<b->getMonth()){
			return *b;
		}

		if (a->getDay()>b->getDay()){
			return *a;
		}else if (a->getDay()<b->getDay()){
			return *b;
		}

		return *a;
	};
void swap_date(unique_ptr<Date> &a, unique_ptr<Date> &b){
		swap(a->year,b->year);
		swap(a->month,b->month);
		swap(a->day,b->day);
	};


int main()
	{


			//TASK 1
		{
			auto today = make_unique<Date>(13,11,2020);
			cout<<today->getDay()<<endl;
			cout<<today->getMonth()<<endl;
			cout<<today->getYear()<<endl;
			cout<<*today.get()<<endl;
			auto date (move(today));
			if(today){
				cout<<"Today not null"<<endl;
			}else{
				cout<<"Today null"<<endl;
			}
			if(date){
				cout<<"Date not null"<<endl;
			}else{
				cout<<"Date null"<<endl;
			}
		}


			//TASK 2
		{
			auto date1 = make_unique<Date>(13,11,2020);
			auto date2 = make_unique<Date>(17,12,2021);
			cout<<compare(date1, date2)<<endl;

			if(date1){
				cout<<"date1 not null"<<endl;
			}else{
				cout<<"date1 null"<<endl;
			}
			if(date2){
				cout<<"date2 not null"<<endl;
			}else{
				cout<<"date2 null"<<endl;
			}

			swap_date(date1, date2);
			cout<<*date1.get()<<endl;
			cout<<*date2.get()<<endl;
		}
	}

