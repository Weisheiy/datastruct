#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef int datatype;

typedef struct{
	datatype a[MAXSIZE];
	int size;
}sequence_list;

void initseqlist(sequence_list *L){
	L->size = 0;
}

void input(sequence_list *L){
	datatype x;
	initseqlist(L);
	printf("输入数字：");
	scanf("%d",&x);
	while(x){
		L->a[L->size++] = x;
		scanf("%d",&x);
	}
}

void inputfromfile(sequence_list *L,char *f){
	int i,x;
	FILE *fp = fopen(f,"r");
	L->size = 0;
	if(fp){
		while(!feof(fp)){
			fscanf(fp,"%d",&L->a[L->size++]);
		}
		fclose(fp);
	}
}
void print(sequence_list *L){
	int i;
	for(i = 0 ;i<L->size;i++){
		printf("%5d",L->a[i]);
		if((i+1)%10 == 0)
			printf("\n");
	}
	printf("\n");
}
void reverse(sequence_list *L){
	for(int i = 0;i<(L->size)/2;i++){
		int temp = L->a[i];
		L->a[i] = L->a[L->size-i-1];
		L->a[L->size-i-1] = temp;
	}
}
void sprit(sequence_list *L1,sequence_list *L2,sequence_list *L3){
	initseqlist(L2);
	initseqlist(L3);
	for(int i = 0;i<L1->size;i++){
		if(L1->a[i] %2 == 0){
			L2->a[L2->size++] = L1->a[i];
		}else{
			L3->a[L3->size++] = L1->a[i];
		}
	}
}
void merge(sequence_list *L1,sequence_list *L2,sequence_list *L3){
	initseqlist(L3);
	int i=0,j=0;
	while(L1->size - i && L2->size - j){
		if(L1->a[i] < L2->a[j]){
			L3->a[L3->size++] = L1->a[i++];
		}else{
			L3->a[L3->size++] = L2->a[j++];
		}
	}
	while(i<L1->size){
		L3->a[L3->size++] = L1->a[i++];
	}
	while(j<L1->size){
		L3->a[L3->size++] = L2->a[j++];
	}
}
void  inter(sequence_list *la,sequence_list *lb,sequence_list *lc){
	initseqlist(lc);
	for(int i = 0;i<la->size;i++){
		int t = la->a[i];
		bool find = false;
		for(int j = 0;j<lb->size;j++){
			if(t == lb->a[j]){
				find  = true;
				continue;
			}
		}
		if(find)
			lc->a[lc->size++] = t;
	}
}
void partion(sequence_list *L){
	int i = 0,j = L->size-1;
	while( i != j){
		while(L->a[i] % 2 !=0&& i!=j)
			i++;
		while(L->a[j] %2 == 0&& i!=j)
			j--;
		int temp = L->a[i];
		L->a[i] = L->a[j];
		L->a[j] = temp;
	}
}
int main(){
    sequence_list L;
    inputfromfile(&L,"3.txt");
    print(&L);  						/*输出表L*/
    partion(&L);
    print(&L);  						/*输出新表*/
    return 0;
}
