#include <stdio.h>
#include <stdlib.h>
//1.递归和非递归分别实现求第n个斐波那契数。
int Fib1(int n){
	if (n == 1 || n == 2){
		return 1;
	}
	return Fib1(n - 1) + Fib1(n - 2);
}
int Fib2(int n){
	if (n == 1 || n == 2){
		return 1;
	}
	int i = 3;
	int x = 1;    // 第i-1项
	int y = 1;    // 第i-2项
	int result = 0;
	while (i<=n){
		result = x + y;
		y = x;
		x = result;
		i++;
	}
	return result;
}
//2.编写一个函数实现n^k，使用递归实现
int Pow(int n, int k){
	if (k == 0)
		return 1;
	return n*Pow(n, k - 1);
}
//3. 写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和，
//例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
int DigitSum(int n){
	static int ret = 0;
	if (n > 9){
		DigitSum(n / 10);
	}
	ret += n % 10;
	return ret;
}
//4. 编写一个函数 reverse_string(char * string)（递归实现）
//实现：将参数字符串中的字符反向排列。
//要求：不能使用C函数库中的字符串操作函数。
void reverse_string(char * string){
	if (*string == '\0')
		return;
	reverse_string(string + 1);
	printf("%c", *string);
}
//5.递归和非递归分别实现strlen
int Strlen1(char ch[]){
	if (*ch == '\0')
		return 0;
	return 1 + Strlen1(ch + 1);
}

int Strlen2(char ch[]){
	int i = 0;
	while(ch[i] != '\0')
		i++;
	return i;
}
//6.递归和非递归分别实现求n的阶乘
int Fac1(int n){
	if (n == 1 || n == 0){
		return 1;
	}
	return n * Fac1(n - 1);
}

int Fac2(int n){
	if (n == 1 || n == 0){
		return 1;
	}
	int ret = 1;
	for (int i = 2; i <= n; i++){
		ret *= i;
	}
	return ret;
}
//7.递归方式实现打印一个整数的每一位
void PrintNum(int n){
	if (n > 9){
		DigitSum(n / 10);
	}
	printf("%d ", n % 10);
}
int main(){
	//printf("%d \n", Fib2(5));
	//printf("%d \n", Pow(15,2));
	//printf("%d \n", DigitSum(5));
	char ch[] = "hehe";
	reverse_string(ch);
	system("pause");
	return 0;
}