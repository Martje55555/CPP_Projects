// C++ program to implement Binary Search
#include <iostream>
#include <vector>

using namespace std;

// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int recursiveBinarySearch(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;

		// If the element is present at the middle
		// itself
		if (arr[mid] == x)
			return mid;

		// If element is smaller than mid, then
		// it can only be present in left subarray
		if (arr[mid] > x)
			return recursiveBinarySearch(arr, l, mid - 1, x);

		// Else the element can only be present
		// in right subarray
		return recursiveBinarySearch(arr, mid + 1, r, x);
	}

	// We reach here when element is not
	// present in array
	return -1;
}


int binarySearch(vector<int> v, int To_Find)
{
	int lo = 0, hi = v.size() - 1;
	int mid;
	// This below check covers all cases , so need to check
	// for mid=lo-(hi-lo)/2
	while (hi - lo > 1) {
		int mid = (hi + lo) / 2;
		if (v[mid] < To_Find) {
			lo = mid + 1;
		}
		else {
			hi = mid;
		}
	}
	if (v[lo] == To_Find) {
		cout << "Found"
			<< " At Index " << lo << endl;
	}
	else if (v[hi] == To_Find) {
		cout << "Found"
			<< " At Index " << hi << endl;
	}
	else {
		cout << "Not Found" << endl;
	}
    return -1;
}

int main(void)
{
	int arr[] = { 2, 3, 4, 10, 40 };
	int x = 10;
	int n = sizeof(arr) / sizeof(arr[0]);
	int result = recursiveBinarySearch(arr, 0, n - 1, x);
	(result == -1)
		? cout << "Element is not present in array"
		: cout << "Element is present at index " << result;

    cout << "\n";

    vector<int> v = { 1, 3, 4, 5, 6 };
	int To_Find = 1;
	binarySearch(v, To_Find);
	To_Find = 6;
	binarySearch(v, To_Find);
	To_Find = 10;
	binarySearch(v, To_Find);
	return 0;
}
