#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main(){
	ofstream outfile;
	outfile.open("random.txt");
	if(!outfile){
		cout<<"Notbale to open the file"<<endl;
		exit(0);
	}
	
	srand(static_cast<unsigned int>(std::time(nullptr)));
	for(int i=0;i<=100000;i++){
		//cout<<rand()<<"\t";
		outfile<<rand()<<" ";
		/*
		if(i%5==0)
			cout<<"\n";
			*/
	}
	outfile.close();
	return 0; 
}
