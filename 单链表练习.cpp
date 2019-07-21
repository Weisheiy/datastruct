#include<iostream>
#include<cctype>
using namespace std;
typedef int elem;
struct node{
	elem data;
	node* next;
	node(elem d){
		data = d;
		next = NULL;
	}
	node(){
		next = NULL;
	}
};
class LinkList{	
	node* head;	
	public:
		
		node* get_i(int n){
			node* p = head->next;
			while(n>0){
				p = p->next;
				n--;
			}
			return p;
		}
		LinkList(elem a[],int len){
			head = new node();
			node* q = head;
			for(int i = 0;i<len;i++){
				node *p = new node(a[i]);
				q->next = p;
				q = p;
			}
		}
		LinkList(){
			head = new node();
		}
		void print(){
			node* p =head->next;
			while(p != NULL){
				cout<<p->data<<" ";
				p = p->next;
			}
		}
		node* Locate(int i){
			node* p = head->next;
			while(i>0){
				i--;
				p = p->next;
			}
			return p;
		}
		node* getMax(){
			node* p =head->next;
			node* max;
			max->data = -1;
			while(p!=NULL){
				if(p->data > max->data)
					max = p;
				p = p->next;
			}
			return max;
		}
		int number(int x){
			node* p = head->next;
			int ans = 0;
			while(p!= NULL){
				if(p->data == x)
					ans++;
			}
			return ans;
		}
		void tidyup(){
			node *p,*q;
			p = head->next;
			q= p->next;
			while(q!= NULL ){
				while(q!= NULL && p->data == q->data ){
					node* temp = q;
					q= q->next;
					delete temp;
				}
				if(q == NULL){
					p->next = NULL;
				}
				else{
					p->next = q;
					p = q;
					q = p->next;
				}
				
			}
		}
		void Union(LinkList *hb){
			node* b = hb->head->next;
			node* h = head;
			node* a = head->next;
			while(a!=NULL && b!= NULL){
				if(a->data < b->data){
					node* temp = a->next;
					h->next = a;
					h = a;
					a = temp;	
				}
				else{
					node* temp = b->next;
					h->next = b;
					h = b;
					b = temp;
				}
			}
			h->next = a?a:b;
		}
		void reverse_right(){
			node* p = head->next;
			node* pr = head;
			node* end = p;
			while(p!= NULL){
				node* temp = p->next;
				p->next = pr;
				pr = p;
				p = temp;
			}
			head->next = pr;
			end->next =NULL;
			node* h = head->next;
			while(h!= NULL){
				cout<<h->data<<" ";
				h = h->next;
			}
		}
		void move_k_right(node* p,node *pr,int k){
			while(k>0 ){
				node* temp = p;
				p = p->next;
				temp->next = pr;
				pr = temp;
				k--;
				if(p == NULL){
					p = 0;
					break;
				}
			}
		}
		void move_k_left(node* p,node* pr,int k){
			while(k>0){
				node* temp = pr;
				pr = pr->next;
				temp->next = p;
				p = temp;
				k--;
				if(pr == head){
					pr= 0;
					break;
				}
			}
		}
		void div_num(LinkList *hodd,LinkList *heven){
			node* h = head->next;
			node* he = NULL,*ho = NULL ;
			
			while(h!=NULL){
				elem n = h->data;
				node* p = new node(n);
				
				if(n %2 == 0){	
					p->next = he;
					he = p;
				}
				else{
					p->next = ho;
					ho = p;
				}
				h = h->next;
			}
			hodd->head->next = ho;
			heven->head->next = he;
		}
		void div_char(LinkList *num,LinkList *ch,LinkList *other){
			num->head = new node();
			ch->head = new node();
			other->head = new node();
			node *h = head->next;
			while(h){
				elem c = h->data;
				node* p = new node(c);
				if(isdigit(c)){
					p->next = num->head->next;
					num->head->next = p;
				}else if(isalpha(c)){
					p->next = ch->head->next;
					ch->head->next = p;
				}else{
					p->next = other->head->next;
					other->head->next = p;
				}
				h = h->next;
			}
		}
		void dele_max_min_sort(int min,int max){
			node* h=  head->next;
			node* p = head;
			if(h!= NULL){
				while(h != NULL && h->data < min  ){
					h = h->next;
					p = h;
				}
				if(h == NULL){
					head->next = NULL;
					return ;
				}
				while( h != NULL && h->data < max ){
					h = h->next;	
				}
				if(h == NULL){
					p->next = NULL;
					return;
				}else{
					p->next = h;	
				}	
			}
		}
		void dele_max_min(int min,int max){
			node *h = head->next;
			node *p = head;
			while(h != NULL){
				if(h->data > min && h->data<max){
					node* temp = h->next;
					p->next = h->next;
					delete h;
					h = temp;
				}else{
					h = h->next;
					p = p->next;
				}
			}
		}
		friend ostream& operator<<(ostream& os,const LinkList & ll);
};
 ostream& operator<<(ostream& os,const LinkList& ll){
	node* p = ll.head->next;
	while(p!= NULL){
		os<<p->data<<" ";
		p = p->next;
	}
	return os;
	
}
int main(){
	elem a[100] = {21,12,30,4,51,106,227,18,92};
	elem b[10] = {2,3,6,8,12};
	LinkList l1(a,9);
	l1.dele_max_min(50,100);
	cout<<l1<<endl;
//	cout<<l1;
	return 0;
}
