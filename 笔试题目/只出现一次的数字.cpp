/*
位操作
1.判断奇偶   i&1
2.交换两数 
void swap(int &a,int &b){
	if(a!=b){
		a^=b;// a= (a^b)
		b^=a;// b = b^(a^b) = b^b^a
		a^=b;//
	}
}
3.变换符号 ~a+1; 
4.求绝对值 
		(1)	int i = a>>31; 取符号位 
			i==0?a:(~a+1);
		(2)	int i = a>>31;
			(a^i)-i;
5.
*/
/*
在一个数组中，除两个数字只出现了1次外，其他数字都出现了2次，找出这两个数字。 
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
void findTwo(int *a,int n,int *pn1,int *pn2){
	int i ,j,temp;
	
	temp = 0;
	for(i = 0;i<n;i++)
		temp^=a[i];
	for(j = 0;j<sizeof(int)*8;j++){
		if((temp>>j)&1)
			break;
	}
	*pn1 = 0,*pn2=0;
	for(i = 0;i<n;i++)
		if((a[i]>>j)&1)
			*pn1 ^= a[i];
		else
			*pn2 ^=a[i];
}
void print(int a[],int n){
	for(int i = 0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}

int main_01(){
	int a[10] = {1, 2, 3, 4, 1,  2, 3, 4, 0, 5};
	print(a,10);
	int n1,n2;
	findTwo(a,10,&n1,&n2);
	printf("%d  %d\n",n1,n2);
	return 0;
}
/*
找到3个只出现一次的数字 
*/
int xorArr(int *arr,int len){
	if(arr != NULL && len>0){
		int result = arr[0];
		for(int i = 1;i<len;i++)
			result ^= arr[i];
		return result;
	}
	return 0;
}

int findFirstBit1Index(int a){
	return a&(-a);
}
bool isBit1(int a,int b){
	return a&b;
}
void findTwoNumber(int *arr,int len,int *n1,int *n2){
	if(arr == NULL || len <2)
		return;
	*n1 = 0;*n2 = 0;
	int xorResult = xorArr(arr,len);
	int index = findFirstBit1Index(xorResult);
	for(int i = 0;i<len;i++){
		if(isBit1(arr[i],index)){
			*n1 ^= arr[i];
		}
		else{
			*n2 ^= arr[i];
		}
	}
}
bool isBit1In_i(int a,int i){
	return a&(1<<i);
}
int isOdd(int a){
	return a%2;
}
void findThreeNum(int *arr,int len,int *n1,int *n2,int *n3){
	if(arr == NULL || len<3)
		return;
	*n1 = 0; *n2 = 0;*n3 = 0;
	int countBit = sizeof(int)*8;
	int count1,count0;
	int temp1,temp0;
	for(int i = 0;i<countBit;i++){
		count1 = count0 = temp1 = temp0 = 0;
		for(int j = 0;j<len;j++){
			if(isBit1In_i(arr[j],i)){
				count1++;
				temp1 ^=arr[j];
			}
			else{
				count0++;
				temp0 ^= arr[j];
			}
		}
		//0 0 1 # 1 1 1 #  0 1 1
		if(isOdd(count1)){
			if(temp0 != 0){
				*n1 = temp1;
				arr[len] = temp1;
				findTwoNumber(arr,len+1,n2,n3);
				return;
			}
		}
		else{
			if(temp1 != 0){
				*n1 = temp0;
				arr[len] = temp0;
				findTwoNumber(arr,len+1,n2,n3);
				return ;
			}
		}
	}
}
int main_021(){
	int a[12] = {1, 2, 3, 4, 1, 2, 7, 4, 5, 7,8};
	print(a,11);
	int n1,n2,n3;
	findThreeNum(a,11,&n1,&n2,&n3);
	printf("%d  %d %d\n",n1,n2,n3);
	return 0;
}
/*
数组中，一个数字出现1次，其余数字出现3次，找出出现一次的数字 
*/
int findNumber(int a[],int n){
	int bits[32];
	int i,j;
	memset(bits,0,32*sizeof(int));
	
	for(i = 0;i<n;i++){
		for(j = 0;j<32;j++)
			bits[j] +=(a[i] >> j)&1;
	}
	int result = 0;
	for(j = 0;j<32;j++){
		if(bits[j] %3 !=0)
		//出现一次的数字，会导致j位上 1 的个数不能被三整除。 
			result += (1<<j);
	}
	return result;
}

int main(){
	int a[10] = {2, 3, 1, 2, 3, 4, 1, 2, 3, 1};
	printf("%d \n",findNumber(a,10));
	return 0;
}







