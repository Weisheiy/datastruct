#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(string i,string j){
	return (i+j)>(j+i);
}
int main(){
	int n;
	while(cin>>n){
		vector<string> tmp(n,"");
		for(int i = 0;i<n;i++){
			cin>>tmp[i];
		}
		sort(tmp.begin(),tmp.end(),cmp);
		for(int i = 0;i<n;i++){
			cout<<tmp[i];
		}
		cout<<endl;
	}
}
