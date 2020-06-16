#include<bits/stdc++.h>

using namespace std;

void Printksubstring(string str,int n,int k){
	int total = (n*(n+1))/2;

	if(k>total){
		cout<<"-1"<<endl;
		return;
	}

	int substring[n+1];
	substring[0] = 0;

	int temp = n;
	for(int i=1;i<=n;i++){
		substring[i] = substring[i-1] + temp;
		temp--;
	}

	int l=1;
	int h=n;
	int start = 0;

	while(l<=h){
		int m = (l+h)/2;

		if(substring[m] > k){
			start = m;
			h = m-1;
		}
		else if(substring[m]<k){
			l = m+1;
		}
		else{
			start = m;
			break;
		}
	}

	int end = n -(substring[start] -k);

	for(int i=start-1; i<end; i++)
		cout<<str[i];
}

int main(){
	string str = "abca";
	int k=5;
	int n = str.length();

	Printksubstring(str,n,k);

	return 0;
}
