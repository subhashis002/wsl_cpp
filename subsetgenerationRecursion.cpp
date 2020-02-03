//This program intends to generate subset using recursion
#include<iostream>
#include<vector>

using namespace std;

//str: Stores the input string
//curr: Stores the current subset
//index: Index in current subset, curr

void powerSet(string str,int index= -1,string curr=""){
    int n = str.length();

    if(index == n)
        return;

    cout<<curr<<endl;

    for(int i=index+1; i<n; i++){
        curr += str[i];
        powerSet(str,i,curr);
        curr.erase(curr.size()-1);
    }
    return ;
}

int main(){
    string str = "abc";
    powerSet(str);
    return 0;
}