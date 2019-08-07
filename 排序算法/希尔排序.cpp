/*
先将整个待排序元素序列分割成若干个子序列（由相隔某个增量的元素组成）
分别进行插入排序，然后依次缩减增量再进行排序，待整个序列中的元素基本有序时，
再进行一次直接插入排序， 
*/
#include<iostream>

using namespace std;
int a[10] = {2,7,1,5,4,3,6,9,8,0};
/*			 a b c d e a b c d e
			 2 6 1 5 0 3 7 9 8 4	
			 a b c a b c a b c a
			 0 3 1 4 2 5 7 6 8 4 
			 0 1 2 3 4 5 6 7 8 9				


*/
void Shellsort1(int a[],int n){
	int i,j,gap;
	for(gap = n/2;gap>0;gap /=2){
		for(i = 0;i<gap;i++){
			for(j = i+gap;j<n;j+=gap){
				if(a[j]<a[j-gap]){
					int temp = a[j];
					int k = j-gap;
					while(k>=0 && a[k]>temp){
						a[k+gap] = a[k];
						k-=gap;
					}
					a[k+gap] = temp;
				}
			}
		}
	//	for(int c = 0;c<10;c++)
	//		cout<<a[c]<<" ";
	//	cout<<endl;
	}
}
void Shellsort2(int a[],int n){
	int  j,gap;
	
	for(gap = n/2;gap>0;gap/=2){
		for(j =gap;j<n;j++){
			if(a[j]<a[j-gap]){
				int temp = a[j];
				int k = j-gap;
				while(k>=0 && a[k]>temp){
					a[k+gap] = a[k];
					k -=gap;
				}
				a[k+gap] = temp;
			}
		}
	}
}
void Shellsort3(int a[],int n){
	int i,j,gap;
	for(gap = n/2;gap>0;gap/=2){
		for(i = gap;i<n;i++){
			for(j = i-gap;j>=0 && a[j]>a[j+gap];j-=gap)
				swap(a[j],a[j+gap]);
		}
	}
}
int main(){
	Shellsort3(a,10);
	for(int i = 0;i<10;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}







