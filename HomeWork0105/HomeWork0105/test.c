#include <stdio.h>
#include <stdlib.h>
//1.调整数组使奇数全部都位于偶数前面。
//
//题目：
//
//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分。
//
void adjustment(int arr[], int length){
	for (int i = 0; i < length; i++){
		if (arr[i] % 2 == 0){
			for (int j = i + 1; j < length; j++){
				if (arr[j] % 2 != 0){
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
					break;
				}
				
			}
		}
	}
}
//2.
////杨氏矩阵 
//有一个二维数组.
//数组的每行从左到右是递增的，每列从上到下是递增的.
//在这样的数组中查找一个数字是否存在。
//时间复杂度小于O(N);
//
//数组：
//1 2 3
//2 3 4
//3 4 5
//
//
//1 3 4
//2 4 5
//4 5 6
//
//1 2 3
//4 5 6
//7 8 9
int fand(int arr[][3], int target, int row, int col)
{
	
	int j = col;
	for (int i = 0; i < row;)
	{
		for (j--; j >= 0;)
		{
			if (arr[i][j] == target)
			{
				return 1;
			}
			else if (arr[i][j] > target)
			{
				j--;
			}
			else if (arr[i][j] < target)
			{
				i++;
			}
		}
	}
	return 0;
}
int main(){

	/*int arr[] = { 3, 2, 4, 6, 1, 5, 8, 10, 12,3 };
	int length = sizeof(arr) / sizeof(arr[0]);
	adjustment(arr, length);
	for (int i = 0; i < length; i++){
		printf("%d ", arr[i]);
	}*/
	int arr[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int ret = fand(arr, 10, 3, 3);
	printf("%d \n", ret);
	system("pause");
	return 0;
}