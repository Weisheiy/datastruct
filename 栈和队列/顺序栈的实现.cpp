#include<iostream>
#include<string.h>
using namespace std;


const int stackIncrement = 30;
typedef int elemtype;
class SeqStack{
	private:
		elemtype *data;
		int top;
		int maxSize;
		void overflow(){
			elemtype *d = new elemtype[maxSize+stackIncrement];
			for(int i = top;i>=0;i--){
				d[i] = data[i];
			}
			delete[] data;
			data = d;
			maxSize = maxSize + stackIncrement;
		}
	public:
		SeqStack(){
			data = new elemtype[stackIncrement];
			top = 0;
			maxSize = stackIncrement;
		}
		~SeqStack(){
			delete[] data; 
		}
		void Push(const elemtype &e){
			if(top == maxSize){
				overflow();
			}
			data[top] = e;
			top++;
		}
		bool Pop(elemtype& e){
			if(top == 0)
				return false;
			top--;
			e = data[top];
			return true;
		}
		bool getTop(elemtype &e){
			if(top == 0)
				return false;
			e = data[top-1];
			return true;
		}
		bool isEmpty(){
			return top == 0;
		}
		bool isFull() const{
			return top == maxSize;
		}
		int getSize(){
			return maxSize;
		}
		void makeEmpty(){
			top = 0;
		}
		friend ostream& operator<<(ostream &os,SeqStack &s);
		
}; 
class DouStack{
	private:
		elemtype *data;
		int length;
		int x ,y;
		void overflow(){
			elemtype *newdata = new elemtype[length+stackIncrement];
			for(int i = 0;i<x;i++){
				newdata[i] = data[i];
			}
			for(int j = length-1;j>=y;j--){
				newdata[j] = data[j];
			}
			length += stackIncrement;
		}
	public:
		DouStack(){
			data = new elemtype[stackIncrement];
			memset(data,0,stackIncrement);
			length = stackIncrement;
			x = 0;
			y = length - 1;
		}
		void Push(int d,const elemtype &e){
			if(x==y){
				overflow();
			}
			if(d == 0){//d=0 前一个栈 d=0 表示后一个栈 
				data[x++] = e;
			}
			else{
				data[y--] = e;
			}
		}
		bool Pop(int d,elemtype &e){
			if(y - x == length){
				printf("Empty");
				return false;
			}
			if(d == 0){
				x--;
				e = data[x];
				
			}else{
				y++;
				e = data[y];
				
			}
			return true;
			
		}
		bool isEmpty(){
			return x==y || x == 0 || y == length-1;
		}
		void print(){
			for(int i = 0;i<length;i++)
				cout<<data[i]<<" ";
			
		}
};
ostream& operator<<(ostream &os,SeqStack &s){
	elemtype e;
	for(int i = s.top-1;i>=0;i--){
		os<<s.data[i]<<" ";
	}
}

int main(){
	int a[10] = {0,1,2,3,4,5,6,7,8,9};
	DouStack s;
	for(int i = 0;i<10;i++){
		s.Push(0,a[i]);
	}
	for(int i = 9;i>=0;i--){
		s.Push(1,a[i]);
	}
	while(!s.isEmpty()){
		int e;
		s.Pop(0,e);
		cout<<e<<" ";
	}
	return 0;
}














