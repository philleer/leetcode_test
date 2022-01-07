#include "mysort.h"

void quickSort(int nums[], int left, int right)
{
	if (left>=right)
		return ;
	
	int pivot = nums[left];

	int i = left;
	int j = right;
	while (i<j)
	{
		while (i<j && nums[j]>pivot)
			--j;

		if (i<j)
		{
			nums[i] = nums[j];
			++i;
		}

		while (i<j && nums[i]<pivot)
			++i;
		
		if (i<j)
		{
			nums[j] = nums[i];
			--j;
		}
	}
	nums[i] = pivot;
	quickSort(nums, left, i-1);
	quickSort(nums, i+1, right);
}
