#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

typedef struct _LinkNode{
	char name[9];
	char phone[14];
	struct _LinkNode* next;
}LinkNode;

LinkNode* InitList(){
	LinkNode* head = NULL;
	head = (LinkNode*)malloc(sizeof(LinkNode));
	if(head == NULL){
		printf("Error!");
		return NULL;
	}
	memset(head,0,sizeof(LinkNode));
	head->next = NULL;
	return head;
} 


LinkNode* GetElem(LinkNode* ls,int i){
	LinkNode* temp = NULL;
	int j = 0;
	if(ls == NULL){
		return NULL;
	}
	if(i < 1){
		printf("Error index");
		return NULL;
	}
	temp = ls->next;
	j = 1;
	while(ls!= NULL && j<i){
		temp = temp->next;
		j++;
	}
	if(temp == NULL || j != i){
		printf("can not find!");
		return NULL;
	}
	return temp;
}


void InsertElem(LinkNode* ls,int i,LinkNode* elem){
	LinkNode* temp = NULL;
	LinkNode* newnode = NULL;
	int j = 0;
	if(ls == NULL){
		printf("ls is not exist!");
		return ;
	}
	if(i<1){
		printf("Error index!");
		return ;
	}
	if(elem == NULL){
		printf("Node is not exist!");
		return ;
	}
	temp = ls;
	j = 1;
	while(temp != NULL&& j<i){
		temp = temp->next;
		j++;
	}
	if(j<i-1){
		printf("��%d ��Ԫ�ز�����\n", i - 1);
		return ;
	}
	newnode = (LinkNode*)malloc(sizeof(LinkNode));
	if(newnode == NULL){
		printf("malloc error!");
		return;
	}
	memcpy(newnode,elem,sizeof(LinkNode));
	newnode->next = temp->next;
	temp->next = newnode;
}

void DestroyList(LinkNode* ls){
	LinkNode* temp = NULL;
	LinkNode* next = NULL;
	
	if(ls == NULL){
		printf("not exist!");
		return ;
	}
	temp = ls;
	while(temp!= NULL){
		next = temp->next;
		free(temp);
		temp = next;
	}
}
void PrintNode(LinkNode* elem){
	if(elem == NULL)
		return ;
	printf("%8s %13s\n",elem->name,elem->phone);
}
void TravList(LinkNode* ls,void (*f)(LinkNode*)){
	LinkNode* temp = NULL;
	if(ls == NULL){
		printf("not exist!");
		return ;
	}
	temp = ls->next;
	while(temp!= NULL){
		f(temp);
		temp = temp->next;
	}
}

LinkNode DeleteElem(LinkNode* ls,int i){
	LinkNode ret = {"","",NULL};
	LinkNode* temp = NULL;
	LinkNode* del = NULL;
	int j = 0;
	if(ls == NULL){
		printf("ls ������");
		return ret;
	}
	if(i<1){
		printf("��������!");
		return ret;
	}
	temp = ls->next;
	j = 1;
	while(temp != NULL && j<i){
		temp = temp->next;
		j++;
	}
	if(temp == NULL || j!=i){
		printf("û���ҵ�");
		return ret;
	}
	if(temp->next == NULL){
		printf("û���ҵ���");
		return ret;
	}
	
	del = temp->next;
	temp = del->next;
	memcpy(&ret,del,sizeof(del));
	free(del);
	return ret;
}

void ModifyElem(LinkNode* ls,int i,LinkNode* mod){
	LinkNode* temp = NULL;
	int j = 0;
	if(ls == NULL || mod == NULL || i<1){
		printf("error!");
		return;
	}
	temp = ls->next;
	j = 1;
	while(temp != NULL && j<i){
		temp = temp->next;
		j++;
	}
	if(temp == NULL || j!= i){
		printf("error!");
		return;
	}
	strcpy(temp->name,mod->name);
	strcpy(temp->phone,mod->phone);
}
int main()
{
    LinkNode* head = NULL;
    int i = 0;
    LinkNode temp;
    LinkNode* result;
//��ʼ������
    head = InitList();
    if(head == NULL)
        return 1;
//�������
    for(i = 0; i < 20; i++)
    {
        sprintf(temp.name, "stu%03d", i + 1);
        sprintf(temp.phone, "1311122%04d", i + 10);
        InsertElem(head, i + 1, &temp);
    }
    TravList(head,PrintNode);
//���Ҳ�����֤ ����Ԫ��
    printf("\n �ֱ���ҵ� 1,20,10,21 ��Ԫ��\n");
    result = GetElem(head, 1);
    if(result != NULL)
    {
        printf("%8s %13s\n", result->name, result->phone);
    }
    result = GetElem(head, 20);
    if(result != NULL)
    {
        printf("%8s %13s\n", result->name, result->phone);
    }
    result = GetElem(head, 10);
    if(result != NULL)
    {
        printf("%8s %13s\n", result->name, result->phone);
    }
    result = GetElem(head, 21);
    if(result != NULL)
    {
        printf("%8s %13s\n", result->name, result->phone);
    }
    result = GetElem(head, -1);
    if(result != NULL)
    {
        printf("%8s %13s\n", result->name, result->phone);
    }

//ɾ��Ԫ����֤
    printf("\n ɾ��Ԫ����֤\n");
    DeleteElem(head, 1);
    DeleteElem(head, 10);
    DeleteElem(head, 20);
    DeleteElem(head, 21);
    TravList(head,PrintNode);
//�޸�Ԫ����֤
    printf("\n �޸�Ԫ����֤\n");
    strcpy(temp.name, "mod");
    strcpy(temp.phone, "123");
    ModifyElem(head, 0, &temp);
    ModifyElem(head, 1, &temp);
    ModifyElem(head, 10, &temp);
    ModifyElem(head, 18, &temp);
    ModifyElem(head, 21, &temp);
    TravList(head,PrintNode);
//��������
    DestroyList(head);
    return 0;
}
