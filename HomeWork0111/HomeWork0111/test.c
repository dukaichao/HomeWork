#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//1.һ��������ֻ�����������ǳ���һ�Σ�
//�����������ֶ����������Ρ�
//�ҳ����������֣����ʵ�֡�
void print(int arr[],int length){
	int i = 0;
	int j = 0;
	for (i = 0; i < length; i++){
		for (j = 0; j < length; j++){
			if (arr[i] == arr[j] && i != j){
				break;
			}
		}
		if (j == length){
			printf("%d ", arr[i]);
		}
		
	}
}
//
//
//2.����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ��
//��20Ԫ�����Զ�����ˮ��
//���ʵ�֡�

int countQiShui(int money){
	int count1 = money;
	int count2 = money;
	while (count1 != 1){
		count2 += count1 / 2;
		count1 /= 2;
	}
	return count2;
}
//3.ģ��ʵ��strcpy
char * Strcpy(char *str1, char *str2){
	assert(str1);
	assert(str2);
	int i = 0;
	for (; i < strlen(str2); i++){
		str1[i] = str2[i];
	}
	str1[i] = '\0';
	return str1;
}
//4.ģ��ʵ��strcat
char * Strcat(char *str1, char *str2){
	assert(str1);
	assert(str2);
	int i = strlen(str1);
	int j = 0;
	for (; j < strlen(str2);j++, i++){
		str1[i] = str2[j];
	}
	str1[i] = '\0';
	return str1;
}

int main(){

	/*int arr[] = { 1, 1, 2, 3, 4, 4 };
	int length = 6;
	print(arr, length);*/

	printf("%d\n", countQiShui(10));


	/*char str1[] = "abcdef";
	char str2[] = "abcdefg";
	printf("%s\n", Strcpy(str1, str2));*/

	/*char str1[] = "abcdef";
	char str2[] = "abcdefg";
	printf("%s\n",Strcat(str1, str2));*/
	system("pause");
	return 0;
}