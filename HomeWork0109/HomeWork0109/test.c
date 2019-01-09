#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1.ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB

void anticlockwise(char ch[], int k){
	if (k > strlen(ch) || k == 0){
		printf("�������:\n");
		return;
	}
	for (int i = 0; i < k; i++){
		char tmp = ch[0];
		for (int j = 0; j < strlen(ch) - 1; j++){
			ch[j] = ch[j + 1];
		}
		ch[strlen(ch) - 1] = tmp;
	}
	printf("%s\n", ch);
}
//2.�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 = AABCD��s2 = BCDAA������1������s1 = abcd��s2 = ACBD������0.
//
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//
//AABCD����һ���ַ��õ�DAABC
int anticlockwiseIsEqual(char ch1[], char ch2[]){
	for (int i = 0; i < strlen(ch1); i++){
		char tmp = ch1[0];
		for (int j = 0; j < strlen(ch1) - 1; j++){
			ch1[j] = ch1[j + 1];
		}
		ch1[strlen(ch1) - 1] = tmp;
		if (strcmp(ch1, ch2) == 0){
			return 1;
		}
	}
	return 0;
}

int main(){

	/*char ch[] = "ABCD";
	anticlockwise(ch, 5);*/

	char ch1[] = "ABCD";
	char ch2[] = "abcd";
	int ret = anticlockwiseIsEqual(ch1, ch2);

	printf("%d\n", ret);
	system("pause");
	return 0;
}