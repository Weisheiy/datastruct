/*
���ݷ�Ϊ����������������
ֱ�Ӳ������򣺽��������ĵ�һ��Ԫ�ز��뵽��������
�γɸ����������
ѡ�����򣺴���������ѡȡ��С��Ԫ��ֱ�ӷ������������ 

*/
#include<iostream>

using namespace std;
int a[10] = {2,7,1,5,4,3,6,9,8,0};
void swap1(int &a,int &b){
	int temp = a;
	a = b;
	b = temp;
}
void swap2(int &a,int &b){
	if(a!=b){
		a^=b;
		b^=a;
		a^=b;
	}
}
void Selectsort(int a[],int n){
	int i,j,min;
	for(i = 0;i<n;i++){
		min = i;
		for(j = i+1;j<n;j++){
			if(a[j] < a[min])
				min = j;
		}
		swap(a[i],a[min]);
	}
}
int main(){
	Selectsort(a,10);
	for(int i = 0;i<10;i++)
		cout<<a[i]<<" ";
	return 0;
}
