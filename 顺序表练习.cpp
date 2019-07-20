#include<iostream>
using namespace std;

class CNode{
public:
	int data;
	CNode* next;

	CNode(int d){
		data = d;
		next = NULL;
	}	

};
void print(CNode *cl){
	CNode *q = cl;
	while(q->next != cl){
		printf("%d ",q->data);
		q = q->next;
	}
	printf("%d ",q->data);	
}

void Joseph(int total,int step,int start){
	if(total <=1 || step <1 || start > total)
		return ;
	CNode *cl,*q,*p;
	cl = new CNode(1);
	
	p = cl;
	for(int i = 2;i<=total;i++){
		q = new CNode(i);
		q->next = cl;
		
		p->next = q;
		p = q;
	}
	p = cl;
	while(start != 1){
		p = p->next;
		start --;
	}
	while(total != 1){
		int s = step;
		while(s != 2){
			p = p->next;
			s--;
		}
		q = p->next;
		p->next = q->next;
		printf("%d ",q->data);
		free(q);
		p = p->next;
		total --;
	}
	printf("%d ",p->data);
}
class SeqList{
	public:
	//逆置数组 
	void ReverserArray(){
		int mid = (len+1)/2;
		for(int i = 0;i<mid;i++){
			int temp = a[i];
			a[i] = a[len - i-1];
			a[len-i-1] = temp;
		}
	}
	
	//将非零元素依次移到数组a的前端 
	void MoveNotZero(){
		int n = 0;
		for(int i = 0;i<len;i++){
			if(a[i] == 0){
				n++;
			}
			else{
				int temp = a[i];
				a[i] = a[i-n];
				a[i-n] = temp;
		
			
			}
		}
	}
	//将a中大于0的元素放在b中，小于0的元素放在c中 
	void DivByZero(int b[],int c[]){
		int j=0,k=0;
		for(int i = 0;i<len;i++){
			if(a[i]>0){
				b[j++] = a[i];
			}
			else
				c[k++] = a[i];
		}
	}
	//将数组前m个元素和后n个元素 调换位置 
	void reverse(int m,int n){
		for(int i = m;i<m+n;i++){
			int l = m;
			int temp = a[i];
			while(l>0){
				a[l+i-m]=a[l-1+i-m];
				l--;
			}
			a[i-m] = temp;
		}
	}
	//返回最小的元素
	int getMin(){
		if(len  == 0){
			return 0;
		}
		int min = 10000;
		int index = 0;
		for(int i = 0;i<len;i++){
			if(a[i]<min){
				min = a[i];
				index = i;
			}
		}
		a[index] = a[len-1];
		return min;
	
	} 	
	

	//顺序表删除第i个元素
	int Del_i(int index){
		if(index<0 || index>=len){
			return 0;
		}
		int temp = a[index];
		for(int i = index+1;i<len;i++){
			a[i-1] = a[i];
		}
		len--;
		return temp;
	}
 	//向顺序表第i个位置插入新元素x。
	void Insert(int index,int x){
		for(int i = len;i>index;i--){
			a[i] = a[i-1];
		}
		a[index] = x;
		len++;
	}	 
	//从顺序表中删除值为x的所有元素 
	void dele_all_x(int x){
		int n = 0;
		for(int i = 0;i<len;i++){
			a[i-n] = a[i];
			if(a[i] == x){
				n++;
			}
		}
		len = len- n;
	}
	//删除值在s，t之间的元素
	void dele_s_t(int s,int t){
		int n = 0;
		for(int i = 0;i<len;i++){
			a[i-n] = a[i];
			if(a[i]>s && a[i]<t)
				n++;
		}
		len = len - n;
	} 
	SeqList(int tmp[],int l){
		for(int i = 0;i<l;i++){
			a[i] = tmp[i];
		}
		len = l;
	}
	void print(){
		for(int i = 0;i<len;i++){
			cout<<a[i]<<" ";
		}
	}
	bool IsExist(int n){
		for(int i = 0;i<len;i++){
			if(a[i] == n)
				return true;
		}
		return false;
	}
	void remove_same(){
		
		for(int i = 0;i<len;i++){
			int temp = a[i];
			int n = 0;
			for(int j = i+1;j<len;j++){
				if(a[j] == temp){
					n++;	
				}
			
			}
			for(int k = i+1;k<=len;k++){
				a[k-n] = a[k];
			}
			len = len-n;		
		}	
	}
	int compare(int b[],int lenb){
		int i;
		for(i = 0;i<len && i<lenb;i++){
			if(a[i] != b[i]){
				break;
			}
		}
		if(i == len && i == lenb){
			return 0;
		}else if(i == len && i!= lenb || i!=len &&i!=lenb && a[i]<b[i]){
			return -1;
		}else
			return 1;
	}
	void find_max_min(int& max,int& min){
		min = 100;
		max = -1;
		for(int i = 0;i<len;i++){
			if(a[i]>max){
				max = a[i];
			}
			if(a[i]<min)
				min = a[i];
		}
	}
	friend ostream& operator<<(ostream& os,const SeqList &sq);
	private:
		int a[100];
		int len;
};
ostream& operator<<(ostream& os,const SeqList &sq){
	for(int i = 0;i<sq.len;i++){
		os<<sq.a[i]<<" ";
	}
	return os;
}

void remove_same(int a[],int len){
	int b[100];
	for(int i = 0;i<100;i++){
		b[i] = -1;
	}
	for(int i = 0;i<len;i++){
		b[a[i]] = 1;
	}
	int k = 0;
	for(int i = 0;i<100;i++){
		if(b[i] == 1){
			a[k++] = i;
		}
	}
}
int* Merge(int a[],int b[],int lena,int lenb){
	int* ans = new int[100];
	int j, k;
	j = k = 0;
	int i=0;

	for(i = 0;k!=lenb&&j!= lena;i++){
		if(a[j]<b[k]){
			ans[i] = a[j++];
		}
		else
			ans[i] = b[k++];
	}

	while(k!=lenb){
		ans[i++] = b[k++];
	}
	while(j!=lena){
		ans[i++] = a[j++];
	}

	return ans;
}

int main(){
	int a[100] = {1,4,1,8,11,11,17,17};
	int b[100] = {1,4,2,8,11,11,17,17};
	SeqList *sq = new SeqList(a,8);
	cout<<sq->compare(b,8);
//	int b[100] = {2,3,5,7,9,12};
//	remove_same(a,8);
//	cout<<(*sq);
//	cout<<c<<" "<<b<<endl;
	return 0;
}

