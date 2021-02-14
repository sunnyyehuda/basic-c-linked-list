#include"data_types.h"
#include<stdio.h>

typedef struct node {
    int value;
    struct node* next;
}Node;

/// <summary>
/// Binary search function get the pointer to the cell(if exist otherwise return NULL) with the given value
/// </summary>
/// <param name="size"> the array size</param>
/// <param name="head"> the first cell pointer</param>
/// <param name="searchVal"> the value to search for</param>
/// <returns> pointer to the cell with the given search value</returns>
Node* BinarySearch(int size, Node* head, int searchVal)
{
	printf("get into binarysearch with array size %d\n", size);
	if (head[size / 2].value > searchVal && size > 1)
		return BinarySearch(size / 2 , head, searchVal);
	else if (head[size / 2].value < searchVal && size > 1)
		return BinarySearch(size / 2 + 1, head + (size / 2), searchVal);
	else
	{
		if (searchVal == head[size / 2].value)
			return head + (size / 2);
		else
			return NULL;
	}
}
