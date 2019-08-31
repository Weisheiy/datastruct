#include<iostream>
#include<string.h>

using namespace std;
int n;
int a[201000]; 
int cmp(const void * a,const void *b){
	return *(int*)a - *(int*)b;
}
int main(){
	cin>>n;
	memset(a,0,sizeof(a));
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	qsort(a+1,n,sizeof(int),cmp);
	int cnt = 0,s = 0;
	for(int i = 1;i<=n;i++){
		if(i == 1){
			s=a[i];
			cnt++;
			continue;
		}
		if(s!=a[i]){
			cout<<s<<cnt<<endl;
			s = a[i];
			cnt = 1;
		}else if(s == a[i])
			cnt++;
	}
	cout<<s<<cnt<<endl;
	return 0;
}
