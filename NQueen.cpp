#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;
#define N 10 
void printSolution(int board[N][N]){
	for(int i=0; i<N; i++){
		for(int j=0;j<N;j++)
			cout<<board[i][j]<<" ";
		cout<<endl;
	}
}

bool isSafe(int board[N][N],int row,int col){
	int i,j;
	//check this row on left side
	for(i=0;i<col;i++)
		if(board[row][i])
			return false;

	//check upper diagonal on left side
	for(i=row,j=col;i>=0 && j>=0;i--,j--)
		if(board[i][j])
			return false;

	//check lower diagonal on left side
	for(i=row,j=col;i>=0 && j>=0; i--,j--)
		if(board[i][j])
			return false;
	return true;
}

bool solveNQUtil(int board[N][N],int col){
	if(col>=N)
		return true;

	for(int i=0; i<N;i++){
		if(isSafe(board,i,col)){
			board[i][col]=1;
			if(solveNQUtil(board,col+1))
				return true;
			board[i][col]=0;
		}
	}
	return false;
}

bool solveNQ(){
	/*
	int board[N][N] = {
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}
	};
	*/
	int board[N][N] = {0};
	if(solveNQUtil(board,0)==false){
		cout<<"Solution does not exist";
		cout<<endl;
		return false;
	}

	printSolution(board);
	return true;
}

int main(){
	solveNQ();
	return 0;
}
