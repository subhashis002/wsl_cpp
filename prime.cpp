#include<iostream>
#include<algorithm>

using namespace std;

bool isPrime(int n){
    if(n==1||n==2)
        return false;
    for(int i=2; i*i <= n ; i++){
        if(n%i==0)
            return false;
    }
    return true;
}

int main(){
    int prime_range;
    cout<<"Please enter a range of prime number :";
    cin>>prime_range;
    for(int i=1; i<=prime_range;i+=2){
        if(isPrime(i))
            cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}