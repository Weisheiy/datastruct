#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
using namespace std;
int a[1010];
int get_last_n(int n,int num){
	int ans = 0;
	for(int i = 0;i<n;i++){
		ans +=  num %10 * pow(10,i);
		num/=10;
	}
	return ans;
}
int main(){
	int n,q;
	cin>>n>>q;

	for(int i= 0 ;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i = 0;i<q;i++){
		int len,num;
		cin>>len>>num;
		int j = 0;
		for(j = 0;j<n;j++){
			int s = get_last_n(len,a[j]);
			if(s == num){
				cout<<a[j]<<endl;
				break;
			}
		}
		if(j == n)
			cout<<"-1"<<endl;
	}
	return 0;
} 
