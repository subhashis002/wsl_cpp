#include<iostream>

using namespace std;

int main(){
	int N;
	cin>>N;
	int result = 3;
	for(int i=2;i<=N;i++){
		result += (result-1);
	}
	cout<<result*result;
	return 0;
}
