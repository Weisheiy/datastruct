#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<deque>


#define N 100

using namespace std;

const int maxn = 110;
const int STACK_INIT_SIZE = 110;
const int STACK_INCREMENT = 10;
typedef char elemtype;

typedef struct node{
	elemtype data;
	struct node* lchild,*rchild;
}BiNode;

typedef BiNode *BiTree;

typedef struct queue{
	int front, rear;
	BiTree data[maxn];
}queue;

typedef struct stack{
	BiTree* base;
	BiTree* top;
	int stacksize;
}stack;

bool InitStack(stack &s){
	s.base = (BiTree *)malloc(STACK_INIT_SIZE*sizeof(BiTree));
	if(!s.base)
		return false;
	s.top = s.base;
	s.stacksize = STACK_INIT_SIZE;
	return true;
}
bool IsStackEmpty(stack &s){
	return s.top == s.base;
}
bool GetTop(stack &s,BiTree &e){
	if(s.top == s.base)
		return false;
	e = *(s.top-1);
	return true;
}

bool Push(stack &s,BiTree e){
	if(s.top - s.base >= s.stacksize){
		s.base = (BiTree *)realloc(s.base,
		(s.stacksize+STACK_INCREMENT)*sizeof(BiTree));
		if(!s.base)
			return false;
		s.top = s.base +s.stacksize;
		s.stacksize+= STACK_INCREMENT;
	}
	*(s.top++ )= e;
	return true;
}
bool Pop(stack &s,BiTree &e){
	if(s.base == s.top)
		return false;
	e = *(--s.top);
	return true;
}


void InitQueue(queue &q){
	q.front = q.rear = 0;
}
void EnQueue(queue &q,BiTree x){
	q.data[q.rear] = x;
	q.rear = (q.rear+1)%maxn;
}
bool IsQueueEmpty(queue &q){
	return q.front == q.rear;
}

BiTree DeQueue(queue &q){
	BiTree ch = q.data[q.front];
	q.front = (q.front+1)%maxn;
	return ch;
}

BiTree createBiTree(){
	char ch;
	BiTree t;
	freopen("in.txt","r",stdin);
	scanf("%c",&ch);
	if(ch == '#')
		t = NULL;
	else{
		t = (BiTree)malloc(sizeof(BiNode));
		t->data = ch;
		t->lchild = createBiTree();
		t->rchild = createBiTree();
	}
	return t;
}
void preoder(BiTree t){
	if(t){
		printf("%c ",t->data);
		preoder(t->lchild);
		preoder(t->rchild);
	}
}

void preoder_nonrecursive(BiTree t){
	BiTree p =t;
	stack s;
	InitStack(s);
	while(!IsStackEmpty(s) || p){
		if(p){
			Push(s,p);
			printf("%c ",p->data);
			p = p->lchild;
		}
		else{
			Pop(s,p);
			p = p->rchild;
		}
	}
}

void preorder_nonrecursive_1(BiTree t){
	BiTree p = t;
	stack s;
	InitStack(s);
	while(!IsStackEmpty(s) || p){
		while(p){
			Push(s,p);
			printf("%c ",p->data);
			p = p->lchild;
		}
		if(!IsStackEmpty(s)){
			Pop(s,p);
			p = p->rchild;
		}
	}
}


void inorder(BiTree t){
	if(t){
		inorder(t->lchild);
		printf("%c ",t->data);
		inorder(t->rchild);
	}
}

void inorder_nonrecursive(BiTree t){
	BiTree p = t;
	stack s;
	InitStack(s);
	
	while(!IsStackEmpty(s)||p){
		if(p){
			Push(s,p);
			p = p->lchild;
		}
		else{
			Pop(s,p);
			printf("%c ",p->data);
			p = p->rchild;
		}
	}
}


void inorder_nonrecursive_1(BiTree t){
	BiTree p = t;
	stack s;
	InitStack(s);
	while(!IsStackEmpty(s) || p){
		while(p){
			Push(s,p);
			p = p->lchild;
		}
		if(!IsStackEmpty(s)){
			Pop(s,p);
			printf("%c ",p->data);
			p = p->rchild;
		}
	}
}

void postorder(BiTree t){
	if(t){
		postorder(t->lchild);
		postorder(t->rchild);
		printf("%c ",t->data);
	}
}

void postorder_nonrecursive(BiTree t){
	stack s1,s2;
	BiTree  cur;
	InitStack(s1);
	InitStack(s2);
	Push(s1,t);
	while(!IsStackEmpty(s1)){
		Pop(s1,cur);
		Push(s2,cur);
		if(cur->lchild)
			Push(s1,cur->lchild);
		if(cur->rchild)
			Push(s1,cur->rchild);
	}
	while(!IsStackEmpty(s2)){
		Pop(s2,cur);
		printf("%c ",cur->data); 
	}
}

void postorder_nonrecursive_1(BiTree t){
	stack s;
	InitStack(s);
	BiTree cur,pre = NULL;
	Push(s,t);
	while(!IsStackEmpty(s)){
		GetTop(s,cur);
		if((!cur->lchild && !cur->rchild) || (pre &&(pre == cur->lchild || pre == cur->rchild))){
			//当前节点没有左右节点，或者左右孩子均访问过、 
			printf("%c ",cur->data);
			Pop(s,cur);
			pre = cur;
		}
		else{
			if(cur->rchild)
				Push(s,cur->rchild);
			if(cur->lchild)
				Push(s,cur->lchild);
		}
	}
}


void leverorder(BiTree t){
	BiTree p = t;
	queue q;
	char str[maxn];
	InitQueue(q);
	int k = 0;
	EnQueue(q,p);
	while(!IsQueueEmpty(q)){
		BiTree now = DeQueue(q);
		str[k++] = now->data;
		if(now->lchild)
			EnQueue(q,now->lchild);
		if(now->rchild)
			EnQueue(q,now->rchild);
	}
	for(int i = 0;i<k;i++){
		printf("%c ",str[i]);
	}
	printf("\n");
}

void leverorder_nonrecursive(BiTree t){
	BiTree q[100];
	if(t == NULL)
		return 	;
	int front,rear;
	front = rear = 0;
	q[rear++]  =t;
	while(front != rear){
		printf("%c ",q[front]->data);
		if(q[front]->lchild != NULL){
			q[rear] = q[front]->lchild;
			rear++;
		}
		if(q[front]->rchild != NULL){
			q[rear] = q[front]->rchild;
			rear ++;
		}
		front++;
	}
}

BiTree Search_Tree(BiTree t,elemtype x){
	if(!t)
		return NULL;
	if(t->data == x)
		return t;
	else{
		if(!Search_Tree(t->lchild,x))
			return Search_Tree(t->rchild,x);
		return t;
	}
}

int CountNode(BiTree t){
	if(t)
		return CountNode(t->rchild)+CountNode(t->lchild) + 1;
}

int depth(BiTree t){
	if(!t)
		return 0;
	int left,right;
	left = depth(t->lchild);
	right = depth(t->rchild);
	return left> right?left+1:right+1;
}

bool Is_equal(BiTree t1,BiTree t2){
	if(!t1 && !t2)
		return true;
	else{
		if(t1 && t2 && t1->data == t2->data){
			if(Is_equal(t1->lchild,t2->lchild))
				if(Is_equal(t1->rchild,t2->rchild))
					return true;
		}
	}
	return false;
}

int  main(){
	BiTree t = NULL;
	printf("preorder..:");
	t = createBiTree();
	
	printf("递归前序:");
	preoder(t);
	printf("非递归前序:");
	preoder_nonrecursive(t);
	printf("\n\n");
	
	printf("递归中序:");
	inorder(t);
	printf("非递归中序:");
	inorder_nonrecursive(t);
	printf("\n\n");
	
	printf("递归后序:");
	postorder(t);
	printf("非递归后序:");
	postorder_nonrecursive(t);
	printf("\n\n");
	
	
	printf("递归层次遍历:");
	leverorder(t);
	printf("非递归层次遍历:");
	leverorder_nonrecursive(t);
	printf("\n\n");
	
	printf("节点个数:");
	printf("%d",CountNode(t));
	printf("\n\n");
	
	printf("二叉树的深度:");
	printf("%d",depth(t));
	printf("\n\n");
	return 0;
}

