#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<cmath>
using namespace std;


struct score{
	int k;
	int s;
}; 
int cmp(score s1,score s2){
	if(s1.s == s2.s)
		return s1.k < s2.k;
	return s1.s > s2.s;
}
int main(){
	score ss[5010];
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		cin>>ss[i].k>>ss[i].s;
	}
	sort(ss,ss+n,cmp);
	m= floor(m *1.5);
	for(int i = m;i<n;i++){
		if(ss[i].s == ss[i-1].s)
			m++;
		else
			break;
	}
	cout<<ss[m-1].s<<" "<<m<<endl;
	for(int i = 0;i<m;i++)
		cout<<ss[i].k<<" "<<ss[i].s<<endl;
	return 0;
}
