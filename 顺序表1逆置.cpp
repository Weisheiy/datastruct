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
	printf("ÊäÈëÊý×Ö£º");
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
int main(){
	sequence_list L;
	input(&L);
	print(&L);
	reverse(&L);
	print(&L);
	return 0;
}
