#include<iostream>
#include<string.h>
using namespace std;
typedef char elemtype;
class LinkNode{
	public:
		elemtype data;
		LinkNode* next;
	
		LinkNode(elemtype d = 0,LinkNode* n = NULL){
			data =d;
			next = n;
		}
		
};
class LinkStack{
	private:
		LinkNode *top;
	public:
		LinkStack(){
			top = NULL;
		}
		~LinkStack(){
			while(top!= NULL){
				LinkNode *ln = top->next;
				delete top;
				top = ln;
			}
		}
		void Push(const elemtype& e){
			LinkNode *ln = new LinkNode(e);
			ln->next = top;
			top = ln;
		}
		bool Pop(elemtype& e){
			if(top == NULL){
				
				return false;
			}
			e = top->data;
			top = top->next;
			return true;
		}
		bool GetTop(elemtype &e){
			if(top == NULL){
				printf("Empty!");
				return false;
			}
			e = top->data;
			return true;
		}
		bool IsEmpty() const{
			return top == NULL;
		}
		int GetSize()const{
			LinkNode *ln = top;
			int len = 0;
			while(ln!= NULL){
				len++;
				ln = ln->next;
			}
			return len;
		}
		friend ostream& operator<<(ostream& os,const LinkStack& s);
};
ostream& operator<<(ostream& os,const LinkStack& s){
		LinkNode *ln = s.top;
		while(ln != NULL){
			os<<ln->data<<" ";
			ln = ln->next;
		}
		return os;
}
bool MatchedPairs(char *exp){
	LinkStack ls;
	char c;
	for(int i = 0;i<strlen(exp);i++){
		if(exp[i] =='('){
			ls.Push(exp[i]);
		}
		else if(exp[i]==')'){
			if(!ls.Pop(c)){
				return false;
			}
		}
	}
	if(ls.IsEmpty())
		return true;
	else
		return false;
		
}
int main(){
	LinkStack ls;
/*	int a[10] = {0,1,2,3,4,5,6,7,8,9};
	
	for(int i = 0;i<10;i++){
		ls.Push(a[i]);
	}
	while(!ls.IsEmpty()){
		int n;
		ls.Pop(n);
		cout<<n<<" ";
	}
*/
	char* exp = "(((((())))";
	if(MatchedPairs(exp))
		printf("matched!");
	else
		printf("not match!");
	//cout<<ls;
	return 0;
}
















