#include <stdio.h>
#include <stdlib.h>
//1.�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲���������
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
	int x = 1;    // ��i-1��
	int y = 1;    // ��i-2��
	int result = 0;
	while (i<=n){
		result = x + y;
		y = x;
		x = result;
		i++;
	}
	return result;
}
//2.��дһ������ʵ��n^k��ʹ�õݹ�ʵ��
int Pow(int n, int k){
	if (k == 0)
		return 1;
	return n*Pow(n, k - 1);
}
//3. дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ�
//���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19
int DigitSum(int n){
	static int ret = 0;
	if (n > 9){
		DigitSum(n / 10);
	}
	ret += n % 10;
	return ret;
}
//4. ��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�
//ʵ�֣��������ַ����е��ַ��������С�
//Ҫ�󣺲���ʹ��C�������е��ַ�������������
void reverse_string(char * string){
	if (*string == '\0')
		return;
	reverse_string(string + 1);
	printf("%c", *string);
}
//5.�ݹ�ͷǵݹ�ֱ�ʵ��strlen
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
//6.�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳�
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
//7.�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ
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