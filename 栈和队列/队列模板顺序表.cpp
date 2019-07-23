#include<stdio.h>
#include<iostream>

using namespace std;

const int maxn = 100;
const int queuesize = 100;
const int stacksize = 100;

typedef char elemtype;

typedef struct{
	elemtype data[queuesize];
	int front,rear;
}queue;

typedef struct{
	elemtype data[stacksize];
	int top;
}stack;

void InitQueue(queue &q){
	q.front = 0;
	q.rear = 0;
}
bool QueueEmpty(queue &q){
	return q.rear == q.front;
}
void EnQueue(queue &q,elemtype x){
	if((q.rear+1)%queuesize == q.front){
		printf("queue overflow");
	}
	else{
		q.data[q.rear] = x;
		q.rear = (q.rear+1)%queuesize;
	}
}

elemtype DeQueue(queue &q){
	if(q.front == q.rear){
		printf("queue overflow");
		return '#';
	}
	else{
		elemtype c = q.data[q.front];
		q.front = (q.front+1)%queuesize;
		return c;
	}
}
void InitStack(stack &s){
	s.top = -1;
}
void Push(stack &s,elemtype x){
	if(s.top == stacksize-1){
		printf("stack overflow");
	}
	else{
		s.top ++;
		s.data[s.top] = x;
	}
}
void Pop(stack &s,elemtype &x){
	if(s.top  == -1){
		printf("stack underflow");
	}
	else{
		x = s.data[s.top--];
	}
}
elemtype Gettop(stack &s){
	if(s.top == -1){
		printf("stack empty");
	}
	return s.data[s.top];
}
int priority(elemtype op){
	switch(op){
		case '(':
		case ')':
		case '#':
			return 0;
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
	}
}

void ctpostexp(queue &q){
	stack os;
	char c,t;
	InitStack(os);
	Push(os,'#');
	do{
		c = getchar();
		switch(c){
			case ' ':break;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				EnQueue(q,c);break;
			case '(':
				Push(os,c);break;
			case ')':
			case '#':
				do{
					Pop(os,t);
					if(t != '#'&& t!='(')
						EnQueue(q,t);
				}while(t != '(' && os.top != -1);
				break;
			case '+':
			case '-':
			//1	
			case '*':
			case '/':
			//2
			//0
				while(priority(c) <= priority(Gettop(os))){
					Pop(os,t);
					EnQueue(q,t);
				}
				Push(os,c);
				break;
		}
	}while(c!='#');
}

void print(queue &q){
	while(!QueueEmpty(q)){
		printf("%c ",DeQueue(q));
	}
	printf("\n");
}
bool cal(queue &q){
	stack s;
	InitStack(s);
	char e,d;
	while(!QueueEmpty(q)){
		char ch = DeQueue(q);
		if(isdigit(ch)){
			Push(s,ch);
		}
		else{
			switch(ch){
				case '+':Pop(s,e);e -='0';Pop(s,d);d-='0';Push(s,e+d+'0');break;
				case '-':Pop(s,e);e -='0';Pop(s,d);d-='0';Push(s,d-e+'0');break;
				case '*':Pop(s,e);e -='0';Pop(s,d);d-='0';Push(s,e*d+'0');break;
				case '/':Pop(s,e);e -='0';Pop(s,d);d-='0';
					if(e!=0)
						Push(s,d/e+'0');
					else
						return -1;
					break;
				default:break;
			}
		}
	}
	int f;
	Pop(s,d);
	f = d-'0';
	printf("The answer is %d\n",f);
	return true;
}

int main(){
	freopen("in.txt","r",stdin);
	queue q,p;
	InitQueue(q);
	ctpostexp(q);
	p = q;
	print(q);
	cal(p);
	return 0;
}










