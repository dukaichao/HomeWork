#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1.实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB

void anticlockwise(char ch[], int k){
	if (k > strlen(ch) || k == 0){
		printf("输入错误:\n");
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
//2.判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1，给定s1 = abcd和s2 = ACBD，返回0.
//
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//
//AABCD右旋一个字符得到DAABC
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