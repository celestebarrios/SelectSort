# SelectSort
MCS 360
#include <iostream>
using namespace std;

void selectionSort(int* a, int start, int end)
{
	if(start == end)
		return;
	cerr<<"Current Array: ";
	for(int i = 0; i<=end; i++) cerr<<a[i]<<" ";
	cerr<<endl;
	//search for the smallest entry in a[start..end]
	int minimum = a[start];
	int min_index = start;
	for(int i=start;i<=end;i++)
	{
		if(minimum>a[i])
		{
			minimum = a[i];
			min_index = i;
		}
	}
	//swap out the minimum with a[start]
	int temp = a[start];
	a[start] = minimum;
	a[min_index] = temp;
	
	selectionSort(a,start+1,end);
}

int main()
{
	cout<<"How many numbers do you want to input?  ";
	int size; cin>>size;
	cout<<"Enter the array:\n";
	int arr[size];
	for(int i = 0; i<size; i++) cin>>arr[i];
	
	selectionSort(arr,0,size-1);
	cout<<"Sorted array:\n";
	for(int i = 0; i<size; i++) cout<<arr[i]<<" ";
	
	return 0;
}
