#include<iostream>
#include<cstdlib>
using namespace std;

const int LEN = 10;
int a[LEN] ;
int adjustArray(int s[],int l,int r){
	int i = l, j = r;
	int x = s[l];
	while(i<j){
		while(i<j && s[j] >= x)
			j--;
		if(i<j){
			s[i] = s[j];
			i++;
		}
		while(i<j && s[i] < x)
			i++;
		if(i<j){
			s[j] = s[i];
			j--;
		}
	}
	s[i] = x;
	return i;
}
void quick_sort1(int s[],int l,int r){
	if(l<r){
		int i = adjustArray(s,l,r);
		quick_sort1(s,l,i-1);
		quick_sort1(s,i+1,r);
	}
}

void quick_sort(int s[],int l,int r){
	if(l<r){
		int i = l,j = r,x = s[l];
		while(i<j){
			while(i<j && s[j] >= x)
				j--;
			if(i<j)
				s[i++] = s[j];
			while(i<j && s[i] < x)
				i++;
			if(i<j)
				s[j--] = s[i];
		}
		s[i] = x;
		quick_sort(s,l,i-1);
		quick_sort(s,i+1,r);
	}
}


int main(){		
	for(int i = 0;i<LEN;i++)
		a[i] = rand()% 10;
	for(int i = 0;i<LEN;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	quick_sort(a,0,LEN-1);
	for(int i = 0;i<LEN;i++)
		cout<<a[i]<<" ";
	return 0;
}
