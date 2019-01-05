#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <math.h>

//1.��д������
//unsigned int reverse_bit(unsigned int value);
//��������ķ���ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ��
//
//�磺
//��32λ������25���ֵ�������и�λ��
//00000000000000000000000000011001
//��ת�󣺣�2550136832��
//10011000000000000000000000000000
//���������أ�
//2550136832

unsigned int reverse_bit(unsigned int value)
{
	//������ĵ�һλ����31λ���ڶ�λ����30λ�����������ƣ������ƺ�Ľ�����а�λ�����㼴�ɵõ����ս����
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
	/*���Ƚ�������ÿһλ��ȡ���������Ը�λ��Ȩֵ����������Ӽ��ɵõ������
	�����һ�������1��ȨֵΪ2^31,��˵Ľ����Ϊ2^32��������ÿ���һ��0��1��
	��Ȩֵ��ԭ���Ļ����ϳ���2����Ҫ�����iλ��ֵ��ֻ�轫��������Ķ���������������i - 1λ��
	�ٺ�1���а�λ�����������value >> i - 1�� & 1*/
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
//2.��ʹ�ã�a + b�� / 2���ַ�ʽ������������ƽ��ֵ��
//
double Average(int a, int b){
	return (double)(b - a) / 2 + a;
}
//3.���ʵ�֣�
//һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ�
//���ҳ�������֡���ʹ��λ���㣩
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
//��һ���ַ����������Ϊ:"student a am i",
//			���㽫��������ݸ�Ϊ"i am a student".
//			Ҫ��
//			����ʹ�ÿ⺯����
//			ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���
//
//			student a am i
//			i ma a tneduts
//			i am a student
//����
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
	printf("������a,b:>\n");
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