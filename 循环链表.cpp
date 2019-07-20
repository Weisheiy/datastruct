#include<stdio.h>
#include<stdlib.h>
typedef struct CLNode{
	int data;
	struct CLNode* next;
}CLNode,*CLinkList;

void InitCL(CLinkList CL){
	if(CL != NULL)
		CL->next = CL;
	else
		CL = (CLinkList)malloc(sizeof(CLNode));
}
void InsertFront(CLinkList cl,int val){
	CLinkList p;
	p = (CLinkList)malloc(sizeof(CLNode));
	p->data = val;
	p->next = cl->next;
	cl->next = p;
}
void InsertEnd(CLinkList cl,int val){
	CLinkList p,q;
	p = (CLinkList)malloc(sizeof(CLNode));
	p->data = val;
	q = cl;
	while(q->next != cl){
		q = q->next;
	}
	p->next = q->next;
	q->next = p;
}
void Print(CLinkList cl){
	CLinkList p;
	p = cl;
	while(p->next != cl){
		printf("%d\t",p->data);
		p=p->next;
	}
	printf("%d\t",p->data);
	printf("\n");
}

void DeleteFront(CLinkList cl,int* val){
	CLinkList p;
	p = cl->next;
	if(p!=cl){
		cl->next = p->next;
		*val = p->data;
	}
	else
		printf("LinkList is empty!");
}
void DeleteEnd(CLinkList cl,int* val){
	CLinkList p,q;
	q = cl;
	p = cl->next;
	
	if(p != cl){
		//当p是最后一个节点时，q是它前面一个节点， 
		while(p->next != cl){
			q = p;
			p = p->next;
		}
		*val = p->data;
		q->next = p->next;
	}
	else{
		printf("LinkList is empty!");
	}
}
void Joseph(int total,int step,int start){
	CLinkList cl,q,p;
	int i;
	if(total <= 1){
		return ;
	}
	InitCL(cl);
	cl->data = 1;
	p = cl->next;
	for(i = 2;i<=total;i++){
		q = (CLinkList)malloc(sizeof(CLNode));
		q->data = i;
		
		q->next = cl;
		p->next = q;
		p = q;
		
	}
	Print(cl);
	q = cl;
	while(start !=1 ){
		q = q->next;
		start--;
	}	
	while(total != 0){
		int s = step;
		while(s != 2){
			q = q->next;
			s--;
		}
		p = q->next;
		q->next = p->next;
		printf("%d ",p->data);
		q = q->next;
		free(p);
		total--;
	}

}
int main(){
	Joseph(6,5,1);	
	return 0;
}




