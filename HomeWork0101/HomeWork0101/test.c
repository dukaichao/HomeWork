#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//1.
//5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果
//A选手说：B第二，我第三；
//B选手说：我第二，E第四；
//C选手说：我第一，D第二；
//D选手说：C最后，我第三；
//E选手说：我第四，A第一；
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。//

//排名判断
void PaiMing(){
	int a, b, c, d, e;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			for (c = 1; c <= 5; c++)
			{
				for (d = 1; d <= 5; d++)
				{
					for (e = 1; e <= 5; e++)
					{
						if ((b == 1) + (a == 3) == 1 &&

							(b == 2) + (e == 4) == 1 &&

							(c == 1) + (d == 2) == 1 &&

							(c == 5) + (d == 3) == 1 && (e == 4) + (a == 1) == 1)
						{
							printf("a:%d b:%d c:%d d:%d e:%d\n", a, b, c, d, e);
							break;
						}
					}
				}
			}
		}
	}
}
//2.
//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个
//嫌疑犯的一个。以下为4个嫌疑犯的供词。
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。
void IsTrue(){
	int i;
	char people[] = { 'A', 'B', 'C', 'D' };
	char kill;
	for (i = 0; i < 4; i++)
	{
		kill = people[i];
		if ((people[0] != kill) + (people[2] == kill) + (people[3] == kill) + (people[3] != kill) == 3)
		{
			printf("凶手是:%c\n", kill);
		}
	}
}
//3.在屏幕上打印杨辉三角。
//1
//1 1
//1 2 1
//1 3 3 1




void Pascal_Triangle(){
	int arr[4][4] = { 0 };
	for (int i = 0; i < 4; i++){
		for (int j = 0; j <= i; j++){
			if (i == j || j == 0){
				arr[i][j] = 1;
			}
			else{
				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
			}
		}
	}
	for (int i = 0; i < 4; i++){
		for (int j = 0; j <= i; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
int main(){
	PaiMing();
	IsTrue();
	//Pascal_Triangle();
	system("pause");
	return 0;
}