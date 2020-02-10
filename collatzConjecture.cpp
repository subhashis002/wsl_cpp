//Kattis: Collatz Conjecture
#include<string>
#include<iostream>
#include<algorithm>
#include<map>

using namespace std;
int collatzConjecture(int num1,int num2){
    //std::multimap<int,int> mmap_num1;
    //std::multimap<int,int> mmap_num2;
    map<int,int> mmap_num1;
    map<int,int> mmap_num2;
    map<int,int>::iterator itr1,itr2;
    int step1=0, step2 = 0;
    int orig_num1 = num1;
    int orig_num2 = num2;
    mmap_num1.insert({num1,step1++});
    
    while(num1 != 1){
        if(num1% 2 ==0){
            num1 = num1 / 2;
        }else{
            num1 = 3*num1 + 1;
        }
        //(mmap_num1.find(num1) == mmap_num1.end()) ? mmap_num1.insert({num1,step1++}) : break;
        // mmap_num1.insert({num1,step1++});

        if(mmap_num1.find(num1) == mmap_num1.end()){
            mmap_num1.insert({num1,step1++}) ;
        }else{
            break;
        }
    }
	
    if(orig_num1 == 1){
            mmap_num1.insert({num1,1});

    }else if(num1 == 1){
            mmap_num1.insert({num1,step1});
    }
    itr1 = mmap_num1.find(num2);
    if(itr1 != mmap_num1.end()){
        cout<<orig_num1<<" needs "<<itr1->second<<" steps, "<<orig_num2<<" needs "<<step2<<" steps, they meet at "<<num2<<endl;
        return 1;
    }else{
        mmap_num2.insert({num2,step2++});
    }

    while(num2 != 1){
        if(num2% 2 ==0){
            num2 = num2 / 2;

        }else{
            num2 = 3*num2 + 1;
        }
        itr1 = mmap_num1.find(num2);
        if(itr1 != mmap_num1.end()){
            // cout<<orig_num1<<" steps "<<mmap_num1.find(num2)->second<<endl;
            cout<<orig_num1<<" needs "<<itr1->second<<" steps, "<<orig_num2<<" needs "<<step2<<" steps, they meet at "<<num2<<endl;
            return 1;
        }
        mmap_num2.insert({num2,step2++});
    }
    return 1;
}

int main(){
    int a1,b1;
    cin>>a1>>b1;
    while(a1 && b1){
        collatzConjecture(a1,b1);
        cin>>a1>>b1;
    }
    
    return 0;
}
