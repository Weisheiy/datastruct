#include<stdio.h>
#include<iostream>
using namespace std;
int main_n2(){
	const int MAXN = 8;
	int a[MAXN] = {1,7,2,9,6,4,5,3};
	
	int nCount = 0;
	int i,j;
	for(i = 0;i<MAXN;i++){
		for(j = i+1;j<MAXN;j++){
			if(a[i] > a[j])
				nCount++;
		}
	}
	printf("count= %d\n",nCount);
	return 0;
}
/*
good method!!!
*/
int g_nCount;
void mergearray(int a[],int first,int mid,int last,int temp[]){
	int i = first,j = mid+1;
	int m = mid,n = last;
	int  k = 0;
	
	while(i<=m && j<=n){
		if(a[i] <a[j])
			temp[k++] = a[i++];
		else{
			temp[k++] = a[j++];
			g_nCount += m-i+1;//very important....
		}
	}
	while(i<=m)
		temp[k++] = a[i++];
	while(j<=n)
		temp[k++] = a[j++];
	for(i = 0;i<k;i++)
		a[first+i] = temp[i];
}

void mergesort(int a[],int first,int last,int temp[]){
	if(first < last){
		int mid = (first + last) / 2;
		mergesort(a,first,mid,temp);
		mergesort(a,mid+1,last,temp);
		mergearray(a,first,mid,last,temp);
	}
}
bool MergeSort(int a[],int n){
	int *p = new int[n];
	if(p == NULL)
		return false;
	mergesort(a,0,n-1,p);
	delete[] p;
	return true;
}
int main(){
	
	int a[8] = {1,7,2,9,6,4,5,3};
	MergeSort(a,8);
	cout<<g_nCount<<endl;
	return 0;
}





