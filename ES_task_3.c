#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int binary(int a[], int element, int left, int right);
int array[] = { 5,3,4,6,8,7 };    // Need to be edited manually
int element;
int main()
{
	printf("Type the element you want to find the index (must be set in array manually): ");
	scanf("%d", &element);

	/*
	int length;
	printf("Type length of array: ");
	scanf("%d", &length);
	int A[length];                      // CANNOT DEFINE USER INPUT ARRAY DUE TO COMPILER
	for (int i = 0; i < length; i++)
	{
		printf("Array[%d]", i);
		scanf("%d", A[i]);
	} */

	int len = sizeof(array) / sizeof(array[0]); // Measuring the size of the array to get its length
	for (int i = 0; i < len - 1; i++)
	{
		int min_num = i;
		for (int j = i + 1; j < len; j++)  // To compare with the right side element
		{
			if (array[j] < array[min_num])
			{
				min_num = j;              // the minimum number took the value of j
			}
		}
		if (min_num != i)
		{
			int temporary = array[i];
			array[i] = array[min_num];       // SWAPPING PROCESS
			array[min_num] = temporary;
		}
	}
	for (int i = 0; i < len; i++)
	{
		printf("Array[%d] = %d\n", i, array[i]); // Printing the sorted Array
	}
	int ind = binary(array, element, 0,len - 1); // Calling the binary search function and store it in ind
	printf("\nIndex of %d: %d\n", element, ind);
}



int binary(int a[], int element, int left, int right)
{
	int mid = left + (right - left ) / 2;
	if (array[mid] == element)
	{
		return mid;
	}
	else if (array[mid] > element) // To cancel out the right side and begin search on the left only
	{
		return binary(array, element, left, mid - 1);
	}
	else if (array[mid] < element)// To cancel out the left side and begin search on the right only
	{
		return binary(array, element, mid + 1, right);
	}
	else
	{
		return -1;
	}
}