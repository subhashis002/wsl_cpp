#include<bits/stdc++.h>

using namespace std;

bool comp(const string &left,const string &right){
	if(left.size()==right.size()){
		return left < right;	
	}else {
		return left.size() < right.size(); 
	}
}

void SortingBigInteger(string arr[],int n){
	vector<string> sortArr(arr,arr+n);
	sort(sortArr.begin(),sortArr.end(),comp);

	for(auto &ele: sortArr){
		cout<<ele<<" ";
	}
}

int main(){
	string arr[] = {"54","724523015759812365462", 
	                    "870112101220845", "8723","9000"};
	int n = sizeof(arr)/sizeof(arr[0]);
	SortingBigInteger(arr,n);
	return 0;
}
