#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

typedef int datatype;

typedef struct link_node{
	datatype info;
	struct link_node* next;
}node;

typedef node* linklist;

linklist creat1(){
	//头插法 
	linklist head,s;
	datatype x;
	head =  (linklist)malloc(sizeof(node));
	head->next = NULL;
	cin>>x;
	while(x!= 0){
		s = (linklist)malloc(sizeof(node));
		s->info = x;
		s->next = head->next;
		head->next = s;
		cin>>x;
	}
	return head;
}

linklist creat2(){
	//尾插法 r为 最后一个
	linklist head,s,r;
	datatype x;
	head = r = (linklist)malloc(sizeof(node));
	head->next = NULL;
	cin>>x;
	while(x!=0){
		s = (linklist)malloc(sizeof(node));
		s->info = x;
		r->next = s;
		r = s;
		cin>>x;
	}
	r->next = NULL;
	return head;
}

void print(linklist head){
	linklist p;
	p = head->next;
	while(p){
		cout<<p->info<<" ";
		p = p->next;
	}
	cout<<endl;
}
void deletes(linklist head ){
	linklist p;
	p = head;
	while(p != NULL){
		head = p->next;
		free(p);
		p = head;
	}
} 

linklist delx(linklist head,datatype x){
	linklist p,q;
	p = head->next;
	if(p->info == x){
		head = p->next;
		free(p);
		p = head;
	}
	while(p->next->info != x)
		p = p->next;
	q = p->next;
	p->next = q->next;
	free(q);
	return head;
}
linklist reverse1(linklist head){
	//指针反转 
	linklist pre,p = head->next,r = p->next;
	p->next = NULL;
	//pre p r 前后相连的三个元素。移动到合适的位置，让p指向pre即可。 
	while(r != NULL){
		pre = p;
		p = r;
		r = r->next;
		p->next = pre;
	}
	head->next = p;
	return head;
}
linklist insert1(linklist head,datatype x){
	//head 排好序的。 
	linklist p,q = NULL;
	p = head->next;
	q = (linklist)malloc(sizeof(node));
	if(p->info>x){//插在第一个节点之前 
		q->info = x;
		q->next = p;
		head->next = q;
		return head;
	}
	while(p->next){
		if(p->next->info>x)
			break;
		p = p->next;
	}
	if(!p->next){//插在最后一个节点之后 
		q->info = x;
		q->next = NULL;
		p->next = q;
		return head;
	}
	//插在中间 
	q->info = x;
	q->next = p->next;
	p->next = q;
	return head;
}
linklist delallx(linklist head,datatype x){
	linklist p,q;
	while(head->next){
		//删除掉前面相同的x 
		if(head->next->info == x){
			p = head->next;
			head->next = head->next->next;
			free(p);
		}
		else
			break;
	}
	if(head->next){
		p = head->next;
		while(p->next){
			if(p->next->info == x){
				q = p->next;
				p->next = q->next;
				free(q);
			}
			else
				p = p->next;
			
		}
	}
	return head;  
}
linklist sort1(linklist head){
	//先找到最小的放在第一个位置，以此类推。 
	//pre->info放的是，每轮循环中最小的一个。 
	int temp;
	linklist p,pre;
	p = pre= head->next;
	while(pre){
		p = pre->next;
		while(p){
			if(pre->info > p->info){
				temp = pre->info;
				pre->info = p->info;
				p->info = temp;
			}
			p = p->next;
		}
		pre = pre->next;
	}
	return head;
}

linklist mergeAscend(linklist L1,linklist L2){
	linklist L3,pc;
	L3 = (linklist)malloc(sizeof(node));
	linklist pa = L1->next;
	linklist pb = L2->next;
	pc = L3;
	while(pa && pb){
		if(pa->info > pb->info){
			pc->next = pa;
			pc = pa;
			pa=pa->next;
		}
		else{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa?pa:pb;
	free(pb);
	return L3;
}
linklist intetSection(linklist L1,linklist L2){
	linklist L3,pc,s;
	linklist pa = L1->next;
	linklist pb = L2->next;
	L3 = (linklist)malloc(sizeof(node));  
	L3->next = NULL;
	pc = L3;
	while(pa){
		pb = L2->next;
		while(pb){
			if(pb->info == pa->info){
				pc->next = pa;
				pc = pa;
				pa = pa->next;
				break;
			}
			pb = pb->next;
		}
		pa = pa->next;
	}
	pc->next = NULL;
	return L3;
}
void partion(linklist head){
	//将值为奇数的节点往前挪
	linklist p,s,pre;
	pre = head;
	p = head->next;
	while(p){
		if(p->info %2 != 0){
			s = p;
			pre->next = p->next;
			p = pre->next;
			//上面两句 将 pre和 p 往后挪到p 之后，pre 为p的next。 
			s->next = NULL;
			s->next = head->next;
			head->next = s;
		}
		else{
			pre = p;
			p = p->next;
		}
	} 
}
linklist search(linklist head,int k){
	//返回倒数第k个节点
	linklist p,q,r;
	int num = 0;
	p = head->next;
	if(head == NULL)
		return NULL;
	while(p->next){
		p = p->next;
		num ++;
	} 
	if(num < k)
		return NULL;
	int i = 0;
	q = head->next;
	while(i<num -k){
		i++;
		q = q->next;
	}
	return q;
}
int main(){
	linklist a,b,c;
	a = creat1();
	b = creat1();
	print(a);
	print(b);
	c = intetSection(a,b);
	print(c);
   	
	return 0;
}






