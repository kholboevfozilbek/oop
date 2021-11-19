#include <iostream>
#include <stdexcept>

using namespace std;

void get(int **arr, size_t rows, size_t cols)
{
	for(size_t i=0; i<rows; ++i)
	{
		for(size_t j=0; j<cols; ++j)
		{
			cout << ": ";
			cin >> arr[i][j];
		}
	}

}

void print(int **arr, size_t rows, size_t cols)
{
        for(size_t i=0; i<rows; ++i)
        {
                for(size_t j=0; j<cols; ++j)
                {
                        cout << arr[i][j] << " ";
                }
		cout << endl;
        }

}


int main()
{
	int n;
	cout << "Enter the size of n*n 2d array:  ";
	cin >> n;

	if( n <= 0)
		throw runtime_error("Negative size is not ok!");
	int** arr = new int*[n];
	for(size_t i=0; i<n; ++i)
	{
		arr[i] = new int[n];
	}
	
	cout << "\nGive the elements of the 2D array: ";
	get(arr, n, n);

	cout << "\n2D array elements:  \n";
	print(arr, n, n);

	return 0;
}
