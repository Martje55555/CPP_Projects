/*********************************************************************
* Binary Search                                                      *
*********************************************************************/
#include <iostream>

int binarySearchRecursive(int arr[], int l, int r, int x) {
	if (r >= l) {
		int mid = l + (r - l) / 2;

		if (arr[mid] == x)
			return mid;

		if (arr[mid] > x)
			return binarySearchRecursive(arr, l, mid - 1, x);

		return binarySearchRecursive(arr, mid + 1, r, x);
	}

	return -1;
}

int binarySearch(int arr[], int target, int size) {
	int l = 0;
	int r = size;
	int mid;

	while (l <= r) {
		mid = l + ((r - l) / 2);

		if (arr[mid] == target) {
			std::cout << "Found at Index " << mid << std::endl;
			return 1;
		}
		if (arr[mid] < target)
			l = mid+1;
		else
			r = mid-1;
	}
	std::cout << "Not Found" << std::endl;
    return -1;
}

int main(void) {
	int arr[] = { 2, 3, 4, 5, 7, 8, 10, 40, 44, 56 };
	int target = 10;
	int n = sizeof(arr) / sizeof(arr[0])-1;

	int result = binarySearchRecursive(arr, 0, n, target);
	(result == -1)
		? std::cout << "Element is not present in array\n"
		: std::cout << "Element is present at index " << result << std::endl;

	target = 41;
	binarySearch(arr, target, n);
	target = 2;
	binarySearch(arr, target, n);
	target = 9;
	binarySearch(arr, target, n);
	return 0;
}
