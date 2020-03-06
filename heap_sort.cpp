#include<iostream>
#include<stdio.h>
#include<fstream>
#include<chrono>

#define NU 100001
using namespace std;

void heapsort(int arr[],unsigned int N){
	if(N==0)
		return;

	int t;
	unsigned int n=N, parent=N/2, index,child;
	while(1){
		if(parent>0){
			t=arr[--parent];
		}else {
			n--;
			if(n==0)
				return;

			t=arr[n];
			arr[n]=arr[0];
		}

		index= parent;
		child= index * 2 + 1;
		while(child<n){
			if(child +1 <n && arr[child+1] > arr[child])
				child++;

			if(arr[child] > t){
				arr[index] = arr[child];
				index = child;
				child = index * 2 + 1;
			}else {
				break;
			}
		}
		arr[index] = t;
	}
}

int main(){
	//int arr[]={0,7,5,4,3,2,19,201,22};
	int arr[NU]={0};
	ifstream in("random.txt");
	ofstream out("random.out");
	if(!in.is_open()){
		cout<<"Can not open the random.txt file"<<endl;
		exit(1);
	}
	if(!out.is_open()){
		cout<<"Can not open the random.out file"<<endl;
		exit(1);		
	}
	auto start =chrono::high_resolution_clock::now();

	for(int i=0;i<NU && in>>arr[i];i++)
		;

	heapsort(arr,NU); 
	for(int i=0;i<NU;i++)
		out<<arr[i]<<" ";
	cout<<endl;
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end-start).count(); 
	cout<<duration<<endl;

	return 0;
}
