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
	//ͷ�巨 
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
	//β�巨 rΪ ���һ��
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
	//ָ�뷴ת 
	linklist pre,p = head->next,r = p->next;
	p->next = NULL;
	//pre p r ǰ������������Ԫ�ء��ƶ������ʵ�λ�ã���pָ��pre���ɡ� 
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
	//head �ź���ġ� 
	linklist p,q = NULL;
	p = head->next;
	q = (linklist)malloc(sizeof(node));
	if(p->info>x){//���ڵ�һ���ڵ�֮ǰ 
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
	if(!p->next){//�������һ���ڵ�֮�� 
		q->info = x;
		q->next = NULL;
		p->next = q;
		return head;
	}
	//�����м� 
	q->info = x;
	q->next = p->next;
	p->next = q;
	return head;
}
linklist delallx(linklist head,datatype x){
	linklist p,q;
	while(head->next){
		//ɾ����ǰ����ͬ��x 
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
	//���ҵ���С�ķ��ڵ�һ��λ�ã��Դ����ơ� 
	//pre->info�ŵ��ǣ�ÿ��ѭ������С��һ���� 
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
	//��ֵΪ�����Ľڵ���ǰŲ
	linklist p,s,pre;
	pre = head;
	p = head->next;
	while(p){
		if(p->info %2 != 0){
			s = p;
			pre->next = p->next;
			p = pre->next;
			//�������� �� pre�� p ����Ų��p ֮��pre Ϊp��next�� 
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
	//���ص�����k���ڵ�
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






