#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

const int maxn = 100;

typedef char elemtype;

#define STACK_INIT_SIZE 10
#define STACK_INCREMENT 2

typedef struct stack{
	elemtype *base;
	elemtype *top;
	int stacksize;
}sqstack;


void InitStack(sqstack *s){
	s->base = (elemtype*)malloc(STACK_INIT_SIZE*sizeof(elemtype));
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
}
void DestroyStack(sqstack *s){
	free(s->base);
	s->base = NULL;
	s->top = NULL;
	s->stacksize = 0;
}
bool IsEmpty(sqstack s){
	return s.top == s.base;
}

bool GetTop(sqstack s,elemtype *e){
	if(s.top > s.base){
		*e = *(s.top - 1);
		return 1;
	}
	else
		return 0;
}

void Push(sqstack *s,elemtype e){
	if(s->top - s->base >= s->stacksize){
		s->base = (elemtype*)realloc(s->base,(s->stacksize+STACK_INCREMENT)*sizeof(elemtype));
		s->top = s->base+ s->stacksize;
		s->stacksize+=STACK_INCREMENT;
	}
	*(s->top++) = e;
}


bool Pop(sqstack *s,elemtype *e){
	if(s->top == s->base)
		return 0;
	*e =* (-- s->top);
	return 1;
}
int main(){
	freopen("in.txt","r",stdin);
	char str[maxn];
	sqstack s;
	int n,x;
	while(cin>>str){
		InitStack(&s);
		bool flag = true;
		for(int i = 0;i<strlen(str);i++){
			if(str[i] =='(')
				Push(&s,str[i]);
			else{
				if(IsEmpty(s)){
					flag = false;
					break;
				}
				else{
					char e;
					Pop(&s,&e);
				}
			}
		}
		if(!IsEmpty(s) || flag == false)
			cout<<"no"<<endl;
		else
			cout<<"yes"<<endl;
	}
	return 0;
}










