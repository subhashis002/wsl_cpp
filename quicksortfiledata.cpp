#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
	ifstream input;
	time_t start,end;
	time(&start);
	input.open("random.txt");
	vector<int> array(1000010);
	int i=0;
	while (input>>array[i]) {
		i++;
	}
	cout<<"Value of i :"<<i<<endl;
	sort(array.begin(), array.end());
	time(&end);
	double time_taken = (double)(end - start);
	cout<<"Sorting is completed"<<endl;
	cout<<"Time taken by normal sorting is :"<<time_taken<<setprecision(6)<<endl;
	input.close();
	return 0;


}
