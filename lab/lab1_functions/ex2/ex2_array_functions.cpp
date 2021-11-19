#include <iostream>
#include <stdexcept>
using namespace std;

void get(int* arr, int  n);
void display(int* arr, int n);
float avg(int* arr, int n);
int min(int* arr, int n);
int max(int* arr, int n);

int main()
{
	int n;

	cout << "Enter the size of the array:  ";
	cin >> n;

	if(n <= 0)
		throw runtime_error("Size can not be 0");
	int* arr = new int[n];

	get(arr, n);

	display(arr, n);
	
	cout << "\n\nMin: " << min(arr, n) << endl;
	cout << "max: " << max(arr, n) << endl;
	cout << "avgg: " << avg(arr, n) << endl;
	return 0;
}

void get(int* arr, int n)
{
	for(size_t i=0; i<n; ++i)
	{
		cout << ": ";
		cin >> arr[i];
	}	
}

void display(int* arr, int n)
{
	cout << "\n\nElements of the array: ";
	for(size_t i=0; i<n; ++i)
		cout << arr[i] << " ";
}

float avg(int* arr, int n)
{
	float avg=0.0;
	for(int i=0; i<n; ++i)
		avg += arr[i];
	return avg/n;
}
int min(int* arr, int n)
{
	int m = arr[0];
	for(size_t i=0; i<n; ++i)
	{
		if(arr[i] < m)
			m = arr[i];
	}
	return m;
}
int max(int* arr, int n)
{
	int maxx = arr[0];
	for(size_t i=0; i<n; ++i)
		if(arr[i] > maxx)
			maxx = arr[i];
	return maxx;

}

