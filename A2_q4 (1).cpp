#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;
int main(){
	int n[] = {16,64,256,1024,4096,16394}; //array size
	size_t m1 = 1677721600;
	size_t m2 = 13421772800;
	int x,row,col;
	int count=0; 
	while(count < 6){
		int i,j,x; //reading the tuple
		int** M = new int* [n[count]];
		for(unsigned int a=0; a<n[count]; a++){
			M[a] = new int[a];
		} //initialize matrix
		
		for(int k=0; k< n[count];k++){
			for(unsigned int m=0;m<n[count];m++){
				M[k][m] = 0; //initializing a zero matrixx
			}
		}
		time_t timer = clock();
		for(unsigned int k=0; k<m1;k++){
			x = rand() % 30 + 1;
			row = rand() % n[count];
			col = rand() % n[count];
			M[row][col] = M[row][col] + x;
		}
		timer = clock() - timer;
		cout << "Time taken for size " << n[count] << " is " << timer/CLOCKS_PER_SEC <<" seconds." << endl;
		count++;
	} 
}