#include <iostream>

using namespace std;

class Stack{
	int array[10];
	int len;
public:
	void reset(){
			for (int i=0;i<10;i++){
				array[i]=0;
			}
			len=0;
		}
	bool push(int user_input){
			if (len==9){
				return false;
			}else{
				array[len]=user_input;
				len++;
				return true;
			}
		}
	void pop(){
			if (len==0){
				cout<<"Array is empty!"<<endl;
			}else{
				//array[len]=0; //по сути эта строчка не нужна, мы контролируем вывод переменной len
				len--;
			}
		}
	void print(){
			cout<<"( ";
			for (int i=0;i<len;i++) cout<<array[i]<<" ";
				cout<<")"<<endl;
			}
};


int main()
{

	Stack stack;
	stack.reset();
	stack.print();
	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();
	stack.print();

	return 0;
}

