#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;
const int maxn = 100;
const int STACK_INIT_SIZE = 100;
const int STACK_INCREMENT = 50;

typedef double elemtype;
class sqstack{
	private:
		elemtype *base;
		elemtype *top;
		int stacksize;
	public:
		sqstack(){
			base = (elemtype*)malloc(STACK_INIT_SIZE * sizeof(elemtype));
			if(!base)
				base = NULL;
			top = base;
			stacksize = STACK_INIT_SIZE;	
		}
		bool getTop(elemtype &e){
			if(base == top)
				return false;
			e = *(top-1);
			return true;
		}
		bool Push(elemtype e){
			if(top - base >= stacksize){
				base = (elemtype*)realloc(base,
				(stacksize+STACK_INCREMENT)*sizeof(elemtype));
				if(!base)
					return false;
				top = base + stacksize;
				stacksize += STACK_INCREMENT;
			}
			*top = e;
			top++;
			return true;
		}
		bool Pop(elemtype &e){
			if(top == base)
				return false;
			e = *(top-1);
			top -- ;
			return true;
		}
		bool IsEmpty(){
			return top == base;
		}
};
int main(){
	freopen("in.txt","r",stdin);
	char c;
	char str[maxn];
	double e1,e2,e3;
	sqstack s;
	scanf("%c",&c);
	while(c!='#'){
		int i = 0;
		while(isdigit(c) || c =='.'){
			str[i++] = c;
			str[i] = '\0';
			scanf("%c",&c);
			if(c == ' '){
				double d = atof(str);
				s.Push(d);
				break;
			}
		}
		switch(c){
			case '+':s.Pop(e1);s.Pop(e2);s.Push(e1+e2);break;
			case '-':s.Pop(e1);s.Pop(e2);s.Push(e1-e2);break;
			case '*':s.Pop(e1);s.Pop(e2);s.Push(e1*e2);break;
			case '/':s.Pop(e1);s.Pop(e2);
			if(e1 != 0)
				s.Push(e2/e1);
			else
				return -1;
			break;
		}
		scanf("%c",&c);
	}
	s.Pop(e3);
	printf("%f\n",e3);
	return 0;
}


