#include <stdio.h>
#include <stdlib.h>
//1.��������ʹ����ȫ����λ��ż��ǰ�档
//
//��Ŀ��
//
//����һ���������飬ʵ��һ��������
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
//����ż��λ������ĺ�벿�֡�
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
////���Ͼ��� 
//��һ����ά����.
//�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����.
//�������������в���һ�������Ƿ���ڡ�
//ʱ�临�Ӷ�С��O(N);
//
//���飺
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