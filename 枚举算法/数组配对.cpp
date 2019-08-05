#include<iostream>
#include<memory.h>
using namespace std;

//问题：
//输入数组和整数k，在数组中两数之和能够被k整除的数对个数

#define LL long long

int n,k;
int a[1000011];
//method 1 不太好用， 
void work1(){
	memset(a,0,sizeof(a));
	for(int i = 0;i<n;i++){
		int t;
		cin>>t;
		a[i] = t;
	}
	LL ans;
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<n;j++){
			if((a[i]+a[j]) %k == 0){
				ans++;
			}
		}
	}
	cout<< ans;
}
//method 2
void init(){
	memset(a,0,sizeof(a));
	cin>>n>>k;
	for(int i = 0;i<n;i++){
		int t;
		cin>>t;
		a[t%k]++;
	}
}
void work(){
	LL ans = 0;
	for(int i = 0;i<k;i++){
		int j = (k-i)%k;
		if(j<i)
			break;
		else if( j==i)
			ans += 1LL*a[i]*(a[i]-1)/2;
		else
			ans +=1LL*a[i]*a[j];
	}
	cout<<ans<<endl;
}
