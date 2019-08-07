/*
数据分为有序区和无序区，
直接插入排序：将无序区的第一个元素插入到有序区，
形成更大的有序区
选择排序：从无序区中选取最小的元素直接放在有序区最后。 

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
