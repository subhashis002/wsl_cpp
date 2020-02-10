//Kattis: Cross

#include<iostream>
#include<string>
#include<vector>
#include<fstream>

#define INF 9999
using namespace std;

int main(){
	ifstream inputfile("cross_input2.txt");
	string line;
	char matrix_original[10][10];
	int matrix[10][10];
	bitset<10> matrix_bitset;
	int row=0,col=0;
	if(inputfile.is_open()){
		while(getline(inputfile,line)){
			col=0;
			for(int i=0; i< line.size(); i++){
				cout<<line[i]<<" ";			
				matrix_original[row][col] = line[i];
				if(matrix_original[row][col] != '.'){
					matrix[row][col] = matrix_original[row][col] - '0';
					matrix_bitset[row][col].set(matrix[row][col],1);
				}else{
					matrix[row][col] = INF;
				}
				col++;
			}
			cout<<endl;
			row++;
		}
	}
	inputfile.close();	
	return 0;
}


int validateMatrix(int matrix[][10]){
	//validate the box 0-9
	bitset<10> temp;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(matrix[i][j]!=INF){
				if(temp.test(matrix[i][j])){
					cout<<"ERROR";
					exit(1);
				}
			}
							
		}
	}
}
