#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
using namespace std;
#define  maxn 300

struct stu{
	int no;
	int a;
	int b;
	int c;
	int total;
};
int cmp(stu s1,stu s2){
	if(s1.total == s2.total){
		if(s1.a == s2.a){
			return s1.no < s2.no;
		}else{
			return s1.a > s2.a;
		}
	}
	return s1.total > s2.total;
}
int main(){
	stu stus[maxn] ;
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		int a1,b1,c1;
		cin>>a1>>b1>>c1;
		stus[i] = {i+1,a1,b1,c1,a1+b1+c1};
	}
	for(int i = 0;i<n;i++){
		printf("%d %d \n",stus[i].no,stus[i].total);
	}
	cout<<"after sort"<<endl;
	sort(stus,stus+n,cmp);
	for(int i = 0;i<n;i++){
		printf("%d %d \n",stus[i].no,stus[i].total);
	}
	cout<<"top 5"<<endl;
	for(int i = 0;i<5;i++){
		cout<<stus[i].no<<" "<<stus[i].total<<endl;
		
	}

	return 0;
} 
