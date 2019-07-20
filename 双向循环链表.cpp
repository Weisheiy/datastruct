#include<stdio.h>
#include<stdlib.h>

typedef struct DuLNode{
	int data;
	struct DuLNode *prior,*next;
}DuLNode,*DuLinkList;

void InitList(DuLinkList *dl){
	*dl = (DuLinkList)malloc(sizeof(DuLNode));
	if(*dl){
		(*dl)->next = (*dl)->prior= *dl;
	}
	else
		exit(-1);
}
void DestroyList(DuLinkList *dl){
	DuLinkList q,p = (*dl)->next;
	while(p != (*dl)){
		q = p->next;
		free(p);
		p=q;
	}
	free(*dl);
	*dl = NULL;
}
void ClearList(DuLinkList dl){
	DuLinkList q,p = dl->next;
	while(p!= dl){
		q = p->next;
		free(p);
		p = q;
	}
	dl->next = dl->prior = dl;
}

int ListEmpty(DuLinkList dl){
	if(dl->next == dl && dl->prior == dl)
		return 1;
	else
		return 0;
}
int ListLength(DuLinkList dl){
	int i = 0;
	DuLinkList p = dl->next;
	while(p!=dl){
		i++;
		p = p->next;
	}
	return i;
}

int GetElem(DuLinkList dl,int i,int* val){
	int j = 1;
	DuLinkList p = dl->next;
	while(p!=dl&& j<i){
		j++;
		p=p->next;
	}
	if(p == dl || j>i)
		return -1;
	*val = p->data;
	return 1;
}
int LocateElem(DuLinkList dl,int val, int (*compare)(int ,int)){
	int i = 0;
	DuLinkList p = dl->next;
	while(p != dl){
		i++;
		if(compare(p->data,val))
			return i;
		p = p->next;
	}
	return -1;
}

int PriorElem(DuLinkList dl,int cur_e,int *val){
	DuLinkList p =dl->next->next;
	while(p != dl){
		if(p->data == cur_e){
			*val = p->prior->data;
			return 1;
		}
		p = p->next;
	}
	return -1;
}
int NextElem(DuLinkList dl,int cur_e,int *val){
	DuLinkList p = dl->next->next;
	while(p!= dl){
		if(p->prior->data = cur_e){
			*val = p->data;
			return 1;
		}
		p = p->next;
	}
	return -1;
}
DuLinkList GetElemP(DuLinkList dl,int i){
	int j;
	DuLinkList p = dl;
	if(i< 0 || i> ListLength(dl))
		return NULL;
	for(j = 1;j<=i;j++)
		p = p->next;
	return p;
}
int ListInsert(DuLinkList dl,int i,int e){
	DuLinkList p,s;
	if(i<1 || i>ListLength(dl)+1)
		return -1;
	p = GetElemP(dl,i-1);
	if(!p)
		return -1;
	s = (DuLinkList)malloc(sizeof(DuLNode));
	if(!s)
		return -1;
	s->data = e;
	s->prior = p;
	s->next = p->next;
	p->next->prior = s;
	p->next = s;
	return 1;
}

int ListDelete(DuLinkList dl,int i,int *val){
	DuLinkList p;
	if(i<1)
		return -1;
	p = GetElemP(dl,i);
	if(!p)
		return -1;
	*val = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	return 1;
}

void ListTraverse(DuLinkList dl, void(*visit)(int)){
	DuLinkList p = dl->next;
	while(p != dl){
		visit(p->data);
		p = p->next;
	}
	printf("\n");
}
void ListTraverseBack(DuLinkList dl,void (*visit)(int)){
	DuLinkList p = dl->prior;
	while(p != dl){
		visit(p->data);
		p = p->prior;
	}
	printf("\n");
}

void print(int d){
	printf("%d ",d);
}
int main(){
	DuLinkList dl;
	DuLinkList* d2;
	d2 = &dl;
	InitList(d2);
	int i;
	for(i = 1;i<=10;i++){
		ListInsert(dl,i,i*2);
	}
	ListTraverse(dl,print);
	return 0;
}







