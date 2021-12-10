#include <iostream>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <fstream>
#include <limits.h>
#include <tchar.h>

using namespace std;
int main(int argc, _TCHAR* argv[]){
	fstream f;
	f.open("output.txt", ios::out); //what does the ios::out mean
	clock_t start;
	long int freeBytes;
	int freePage;
	int freevm;

	MEMORYSTATUS MemoryInfo;
	GlobalMemoryStatus(&MemoryInfo);	
	freeBytes = MemoryInfo.dwAvailPhys;
	freePage = MemoryInfo.dwAvailPageFile;
	freevm = MemoryInfo.dwAvailVirtual;
	cout << "Available Physical Memory: " << MemoryInfo.dwAvailPhys << endl;
	cout << "Available Page File: " << MemoryInfo.dwAvailPageFile << endl;
	cout << "Available Virtual Memory" << MemoryInfo.dwAvailVirtual << endl;
	f << "Avaiable Physical Memory: " << MemoryInfo.dwAvailPhys << endl;
	f << "Available Page File: " << MemoryInfo.dwAvailPageFile << endl;
	f << "Available Virtual Memory" << MemoryInfo.dwAvailVirtual << endl;

	double cache_size[15] = { 05, 0.6, 0.7, 0.8, 0.9, 0.95, 0.99, 1.0, 1.01, 1.1, 1.5 , 2, 5, 10, 50 };
	long int num_of_bytes;
	int* arr;

	for (int i = 0; i < 15; i++) {
		cout << "--------------------\n\n";
		cout << "Cache Size: " << cache_size[i] << "*M\n"
		f << "--------------------\n\n";
		f << " Cache Size: " << cache_size[i] << "*M\n";

		start = clock();
		num_of_bytes = abs((int)(cache_size[i] * (freeBytes)));

		int size = num_of_bytes / sizeof(int);
		arr = new int[size];

		GlobalMemoryStatus(&MemoryInfo);
		cout << "Available Physical Memory: " << MemoryInfo.dwAvailPhys << endl;
		cout << "Available Page File: " << MemoryInfo.dwAvailPageFile << endl;
		cout << "Available Virtual Memory" << MemoryInfo.dwAvailVirtual << endl;
		f << "Avaiable Physical Memory: " << MemoryInfo.dwAvailPhys << endl;
		f << "Available Page File: " << MemoryInfo.dwAvailPageFile << endl;
		f << "Available Virtual Memory" << MemoryInfo.dwAvailVirtual << endl;
	

		for (int i = 0; i < size; i++) {
			arr[i] = i;
		}
		for (int i = 0; i < size; i++) {
			arr[i] += i;
		}

		delete[] arr;
		cout << "Time elapsed: " << ((double)(clock() - startTime) / (double)CLOCKS_PER_SEC) << "seconds " << endl;
		f << "Time elapsed: " << ((double)(clock() - startTime) / (double)CLOCKS_PER_SEC) << "seconds " << endl;
	}
	system("pause");
	return 0;

}