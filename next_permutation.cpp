#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	int n = 5;
	vector<int> perm(n);
	for(int i=0;i<n;i++) perm[i]=i+1;

	do{
		for(int i=0;i<n; i++){
			cout<<perm[i]<< " ";
		}
		cout<<endl;

	}while(next_permutation(perm.begin(),perm.end()));
}
