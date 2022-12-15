// C++ program to implement Binary Search
#include <iostream>
#include <vector>

// A recursive binary search function. It returns
// location of x in given array[l...r] is present,
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

	// target is not present in the array
	return -1;
}

int binarySearch(std::vector<int> v, int To_Find)
{
	int l = 0, r = v.size() - 1;
	int mid;
	// This below check covers all cases , so need to check
	// for mid=lo-(hi-lo)/2
	while (r - l > 1) {
		int mid = (r + l) / 2;
		if (v[mid] < To_Find) {
			l = mid + 1;
		}
		else {
			r = mid;
		}
	}
	if (v[l] == To_Find) {
		std::cout << "Found"
			<< " At Index " << l << std::endl;
	}
	else if (v[r] == To_Find) {
		std::cout << "Found"
			<< " At Index " << r << std::endl;
	}
	else {
		std::cout << "Not Found" << std::endl;
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
		? std::cout << "Element is not present in array\n"
		: std::cout << "Element is present at index " << result << std::endl;

    std::vector<int> v = { 1, 3, 4, 5, 6 };
	int To_Find = 1;
	binarySearch(v, To_Find);
	To_Find = 6;
	binarySearch(v, To_Find);
	To_Find = 10;
	binarySearch(v, To_Find);
	return 0;
}
