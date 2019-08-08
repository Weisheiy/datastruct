/*
一个大小为n的数组，里面的数都属于范围[0，n-1]，有不确定的重复元素，
找到至少一个重复元素，，要求：
空间  O(1) ,时间O(n) 
*/
#include<iostream>
using namespace std;
const int no_repeat = -1;
void swap(int &x,int &y){
	int t = x;
	x = y;
	y = t;
} 
int RadixSort(int a[],int n){
	int i;
	for(i = 0;i<n;i++){
		while(i != a[i]){
			if(a[i] == a[a[i]])
				return a[i];
			swap(a[i],a[a[i]]);
		}
	}
	return no_repeat;
}
int main(){
	int a[10] = {2, 4, 1, 5, 7,  6, 1, 9, 0, 2};
	cout<<RadixSort(a,10)<<endl;
	return 0;
}



