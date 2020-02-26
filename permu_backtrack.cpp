#include<iostream>
#include<cstring>
#define N 5
using namespace std;

int perm[N];
bool used[N];
void generate(int at){
	if(at==N){
		for(int i=0;i<N;i++){
			cout<<perm[i]+1;
		}
		cout<<endl;
	}else {
		for(int i=0;i<N;i++){
			if(!used[i]){
				used[i]=true;
				perm[at] = i;
				generate(at+1);
				used[i]=false;
			}
		}
	}
}

int main(){
	memset(used,0,N);
	generate(0);
	return 0;
}
