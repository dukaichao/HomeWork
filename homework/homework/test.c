#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <math.h>

//1.编写函数：
//unsigned int reverse_bit(unsigned int value);
//这个函数的返回值value的二进制位模式从左到右翻转后的值。
//
//如：
//在32位机器上25这个值包含下列各位：
//00000000000000000000000000011001
//翻转后：（2550136832）
//10011000000000000000000000000000
//程序结果返回：
//2550136832

unsigned int reverse_bit(unsigned int value)
{
	//将提出的第一位左移31位，第二位左移30位……依次类推，将左移后的结果进行按位或运算即可得到最终结果。
	int i = 0;
	int ret = 0;
	for (i = 0; i < 32; i++)
	{
		if (value >> i & 1)
		{
			ret |= (value >> i & 1) << (31 - i);
		}
	}
	return ret;
}


unsigned int reverse_bit1(unsigned int value)
{
	/*首先将整数的每一位提取出来，乘以该位的权值，在依次相加即可得到结果。
	例如第一次提出的1的权值为2^31,相乘的结果即为2^32，接下来每提出一次0或1，
	其权值在原来的基础上除以2。而要将求第i位的值，只需将这个整数的二进制序列向右移i - 1位，
	再和1进行按位与操作，即（value >> i - 1） & 1*/
	int i = 0;
	int sum = 0;
	int b = 0;
	for (i = 0; i < 32; i++)
	{
		b = ((value >> i) & 1)*pow(2, 31 - i);
		sum += b;
	}
	return sum;
}
//2.不使用（a + b） / 2这种方式，求两个数的平均值。
//
double Average(int a, int b){
	return (double)(b - a) / 2 + a;
}
//3.编程实现：
//一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。
//请找出这个数字。（使用位运算）
int func(int arr[], int length){
	int i = 0;
	haha:while(i<length){
		int j = 0;
		while(j<length){
			if ((arr[i] & arr[j]) == arr[i] &&i != j){
				i++;
				goto haha;
			}
			j++;
		}
		return arr[i];
	}
	return -1;
}
//4.
//有一个字符数组的内容为:"student a am i",
//			请你将数组的内容改为"i am a student".
//			要求：
//			不能使用库函数。
//			只能开辟有限个空间（空间个数和字符串的长度无关）。
//
//			student a am i
//			i ma a tneduts
//			i am a student
//逆序
char * fanzhuan(char *str)
{
	char *l = str;
	char *r = str;

	while (*r != '\0')
	{
		r++;
	}
	while (l < r - 1)
	{
		char tmp = *l;
		*l = *(r - 1);
		*(r - 1) = tmp;
		l++;
		r--;
	}
	l = str;
	r = str;
	while (*r != '\0')
	{
		while (*r != 32 && *r != '\0')
		{
			r++;
		}
		char *p = r;
		while (l < r - 1)
		{
			char tmp = *l;
			*l = *(r - 1);
			*(r - 1) = tmp;
			l++;
			r--;
		}
		if (*p == '\0')
		{
			return str;
		}
		l = p + 1;
		r = p + 1;
	}
	return str;
}



int main(){
	
	printf("%u\n", reverse_bit(25));


	/*int a = 0;
	int b = 0;
	printf("请输入a,b:>\n");
	scanf("%d %d",&a,&b);
	printf("%f", Average(a,b));*/


	/*int arr[] = { 1, 2, 3, 4, 5, 6, 6, 4, 2, 3, 1 };
	int length = sizeof(arr) / sizeof(arr[0]);
	printf("%d\n", func(arr,length));*/

	/*char ch[] = "i";
	int length = Length(ch);
	change(ch, length);
	printf("%s\n", ch);*/
	char ch[] = "student a am i";
	printf("%s\n", fanzhuan(ch));

	system("pause");
	return 0;
}