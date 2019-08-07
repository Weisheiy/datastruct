#include<iostream>
#include<string>
using namespace std;
int a[10] = {2,7,1,5,4,3,6,9,8,0};
void swap(int &a,int &b){
	int temp= a;
	a = b;
	b = temp;
}
void Bubble1(int a[],int n){
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(a[j-1]>a[j]){
				swap(a[j-1],a[j]);
			}
		}
		/*
		for(int j = i+1;j<n;j++){
			if(a[i]]>a[j]){
				swap(&a[i],&a[j]);
			}
		}
		*/
		for(int k = 0;k<n;k++){
			cout<<a[k]<<" ";
		}
		cout<<endl;
	}
}
void Bubble2(int a[],int n){
	
	for(int i = 0;i<n;i++){
		bool flag = false;
		for(int j = 0;j<n;j++){
			if(a[j-1]>a[j]){
				swap(a[j-1],a[j]);
				flag = true;
			}
		}
		if(!flag)
			break;
		cout<<boolalpha<<flag<<":";
		for(int k = 0;k<n;k++){
			cout<<a[k]<<" ";
		}
		cout<<endl;
	}
}
void Bubble3(int a[],int n){
	int j,k;
	int flag;
	flag = n;
	while(flag >0){
		k = flag;
		flag = 0;
		for(j = 1;j<k;j++){
			if(a[j-1]>a[j]){
				swap(a[j-1],a[j]);
				flag = j;//排好序的第一个元素 
			}
			
		}
		cout<<flag<<endl;
	}
}
int main(){
	Bubble3(a,10);
	return 0;
}
