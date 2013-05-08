#include <iostream>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>       
#include <algorithm>    // std::swap
using namespace std;

int random_partition(int* A, int start, int end)
{
    srand(time(NULL));
    int pivotIdx = start + rand()%(end-start+1);
    int pivot = A[pivotIdx];
    std::swap(A[pivotIdx], A[end]); // move pivot element to the end
    pivotIdx = end;
    int i = start -1;
 
    for(int j = start; j <= end-1; ++j){
		if(A[j] <= pivot){
            i = i+1;
            std::swap(A[i], A[j]);
        }
    }
 
    std::swap(A[i+1], A[pivotIdx]);
    return i+1;
}
 
int randomized_select(int* A, int start, int end, int i)
{
    if(start == end)
        return A[start];
 
    if(i == 0) return -1;
 
    if(start < end){
		int mid = random_partition(A, start, end);
		int k = mid - start + 1;
    if(i == k)
        return A[mid];
    else if(i < k)
        return randomized_select(A, start, mid-1, i);
    else 
        return randomized_select(A, mid+1, end, i-k);
    }
 
}
int main()
{
	int n = rand()%500 + 1;//size of Array. See README for sizes
	int A[n];

	for(int i=0; i<n; ++i){
		A[i]=rand();
	}

	time_t current, total;
	time_t start_time, end_time;

	start_time = time(&start_time);
	
	for(int j = 0; j < 25000; ++j){//increase up to 250,000
		int i = rand()%n;
		int location = randomized_select(A,0,n,i);//(A,p,r,i)	
	}
	
	end_time = time(&end_time);
	current = difftime(end_time, start_time);
	cout << current/25000.0 << endl;//change with j in for loop above
}
