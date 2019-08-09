/*
随机生成和为S的N个正整数 
*/
#include<cstdio>
#include<ctime>
#include<set>
#include<algorithm>
using namespace std;
//在[s，e]区间上随机取n个数并存放在a[]中 
void GetRandomNum(int* a,int n,int s,int e){
	set<int> set_a;
	srand(time(NULL));
	int i;
	for(int i = e-n;i<e;i++){
		int num = (rand() %i) + s;
		if(set_a.find(num) == set_a.end())
			set_a.insert(num);
		else
			set_a.insert(i);
	}
	i = 0;
	set<int>::iterator pos;
	for(pos = set_a.begin();pos!=set_a.end();pos++)
		a[i++] = *pos;
}
int main(){
	int a[4];
	GetRandomNum(a,3,0,20);
	sort(a,a+3);
	a[3] = 20;
	printf("%d ",a[0]);
	for(int i = 1;i<4;i++){
		printf("%d ",a[i] - a[i-1]);
	}
}
