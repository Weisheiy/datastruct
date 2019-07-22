#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<deque>
#include<stack>

using namespace std;
const int STACK_INIT_SIZE = 100;
const int STACK_INCREMENT = 50;

typedef int SElemType;

typedef struct{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

bool InitSqStack(SqStack &sq){
	sq.base = (SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!sq.base)
		return false;
	sq.top = sq.base;
	sq.stacksize = STACK_INIT_SIZE;
	return true;
}

bool GetTop(SqStack &s,SElemType &e){
	if(s.top == s.base)
		return false;
	e = *(s.top - 1);
	return true;
}
bool Push(SqStack &s,SElemType e){
	if(s.top - s.base >= s.stacksize){
		s.base = (SElemType *)realloc(s.base,
		(s.stacksize+STACK_INCREMENT)*sizeof(SElemType));
		if(!s.base)
			return false;
		s.top = s.base+s.stacksize;
		s.stacksize += STACK_INCREMENT;
	}
	*s.top = e;
	s.top++;
	return true;
}
bool Pop(SqStack &s,SElemType &e){
	if(s.base == s.top)
		return false;
	e = *(s.top - 1);
	s.top --;
	return true;
}

bool IsEmpty(SqStack &s){
	return s.base == s.top;
}
int main(){
	SqStack s;
	int n,x;
	while(cin>>n){
		InitSqStack(s);
		int e;
		cout<<"想要转换的进制(2-9):"<<endl;
        cin>>x;
        while(n>0){
        	Push(s,n%x);
        	n/=x;
		}
		while(!IsEmpty(s)){
			Pop(s,e);
			cout<<e;
		}
		cout<<endl;
	}
	return 0;
}













