#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int elemtype;
typedef struct QNode{
	elemtype data;
	struct QNode *next;
}QNode,*QueuePtr;

class LinkQueue{
	private:
		QueuePtr front;
		QueuePtr rear;
	public:
		LinkQueue(){
			front = rear = (QueuePtr)malloc(sizeof(QNode));
			front->next = NULL;
			front->data = 0;
		}
		int DestroyQueue(){
			while(front){
				rear = front->next;
				free(front);
				front = rear;
			}
			return 0;
		}
		int QueueEmpty(){
			return front == rear;
		}
		int QueueLength(){
			return front->data;
		}
		int getHead(elemtype *e){
			if(front->next == NULL){
				return -1;
			}
			*e = front->next->data;
			return 0;
		}
		int insertQueue(elemtype e){
			QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
			if(p == NULL){
				return -1;
			}
			p->data= e;
			p->next = NULL;
			rear->next = p;
			rear = p;
			front->data++;
			return 0;
		}
		int delQueue(elemtype *e){
			if(front == rear)
				return -1;
			QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
			p = front->next;
			*e = p->data;
			front->next = p->next;
			//出队列需要考虑队空 
			if(rear == p)
				rear = front;
			free(p);
			front->data --;
			return 0;
		}
		int printQueue(){
			QueuePtr p = front->next;
			while(p != NULL){
				printf("%d  ",p->data);
				p = p->next;
			}
			return 0;
		}
};
int main(){
	freopen("in.txt","r",stdin);
	int a;
	LinkQueue lq;
	scanf("%d",&a);
	while(a!=0){
		lq.insertQueue(a);
		scanf("%d",&a);
	}
	lq.printQueue();
	return 0;
}



















