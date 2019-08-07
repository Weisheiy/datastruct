/*
每次将一个待排序的记录，按其关键字大小插入到前面已经排好序的子序列中的适当位置， 
*/
#include<iostream>
using namespace std;
int a[10] = {2,7,1,5,4,3,6,9,8,0};
void swap(int &a,int &b){
	int temp = a;
	a = b;
	b = temp;
}
void Insertsort1(int a[],int n){
	int j,k;
	for(int i = 1;i<n;i++){
		for(j = i-1;j>=0;j--){
			if(a[j]<a[i])//找到合适的插入位置 j 
				break;
		}
		if(j != i-1){
			int temp = a[i];
			for(k = i-1;k>j;k--)
				a[k+1] = a[k];
			a[k+1] = temp;
		}
		for(int c = 0;c<n;c++)
			cout<<a[c]<<" ";
		cout<<endl;
	}
}
void Insertsort2(int a[],int n){
	int i,j;
	for(i = 1;i<n;i++){
		if(a[i]<a[i-1]){
			int temp = a[i];
			for(j = i-1;j>=0 && a[j] > temp;j--)
				a[j+1] = a[j];
			a[j+1] = temp;
		}
		for(int c = 0;c<n;c++)
			cout<<a[c]<<" ";
		cout<<endl;
	}
}
void Insertsort3(int a[],int n){
	int i,j;
	for(i = 1;i<n;i++){
		for(j = i-1;j>=0 && a[j]>a[j+1];j--)
			swap(a[j],a[j+1]);
		for(int c = 0;c<n;c++)
			cout<<a[c]<<" ";
		cout<<endl;
	}
}
int main(){
	Insertsort3(a,10);
	return 0;
}
