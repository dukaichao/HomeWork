#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//1.实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定，
//输入9，输出9 * 9口诀表，输入12，输出12 * 12的乘法口诀表。
void Mul(int n){
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= i; j++){
			printf("%d*%d=%d ", i, j, i*j);
		}
		printf("\n");
	}
}
//2.使用函数实现两个数的交换。
void Swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}
//3.实现一个函数判断year是不是润年。
int isLeap(int year){
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return 1;
	return 0;
}

//4.
//创建一个数组，
//实现函数init（）初始化数组、
//实现empty（）清空数组、
//实现reverse（）函数完成数组元素的逆置。
//要求：自己设计函数的参数，返回值。
void init(int arr[],int len){
	for (int i = 0; i < len; i++)
		arr[i] = rand() % 100 + 1;
}
void empty(int arr[],int len){
	for (int i = 0; i < len; i++)
		arr[i] = 0;
}
void reverse(int arr[], int len){
	int start = 0;
	int end = len - 1;
	while (start <= end){
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}

//5.实现一个函数，判断一个数是不是素数。
int isPrime(int n){
	for (int i = 2; i <= sqrt(n); i++){
		if (n%i == 0)
			return 0;
	}
	return 1;
}
int main(){
	srand(time(0));
	/*int n = 0;
	scanf("%d",&n);
	int a = 10; int b = 20;
	Swap(&a, &b);
	printf("%d %d", a, b);*/
	/*for (int i = 100; i <= 200; i++){
		if (isPrime(i))
			printf("%d ", i);
	}*/
	int arr[10] = { 0 };
	init(arr, 10);
	for (int i = 0; i < 10; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	reverse(arr, 10);
	for (int i = 0; i < 10; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	empty(arr, 10);
	for (int i = 0; i < 10; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}