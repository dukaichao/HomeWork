#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3
char ch[ROW][COL];
/*
	1..初始化   全部为' '空格
	2..人棋子标记为 'p'
	3..机器棋子标记为 'a'
	4..人成功返回  'p'
	5..机器成功返回 'a'
	6..平局返回 'e'
	7..other返回 ' '空格

*/
//检验是否棋盘满
int isFull(){
	for (int row = 0; row < ROW; row++){
		for (int col = 0; col < COL; col++){
			if (ch[row][col] == ' '){
				return 0;
			}
		}
	}
	return 1;
}
//初始化
void init(){
	for (int row = 0; row < ROW; row++){
		for (int col = 0; col < COL; col++){
			ch[row][col] = '\0';
		}
	}
}
//打印棋盘
void print(){
	for (int row = 0; row < ROW; row++){
		printf("| %c | %c | %c |\n", ch[row][0], ch[row][1],ch[row][2]);
		if (row < 2){
			printf(" --- --- ---\n");
		}
	}
}
//人落棋
void PresonMoveChess(){
	//1.提示
	printf("请输入坐标:> \n");
	int row = 0;
	int col = 0;
	while (1){
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= ROW || col < 0 || col >= COL){
			printf("输入有误，请重新输入:> \n");
			continue;
		}
		ch[row][col] = 'p';
		break;
	}
}
//机器落棋
void AlMoveChess(){
	int row = 0;
	int col = 0;
	while (1){
		row = rand() % ROW;
		col = rand() % COL;
		if (row < 0 || row >= ROW || col < 0 || col >= COL){
			continue;
		}
		if (ch[row][col] != ' '){
			continue;
		}
		ch[row][col] = 'a';
		break;
	}
}
//检验是否成功
char checkIsSuccess(){
	//1.检查列
	for (int row = 0; row < ROW; row++){
		if (ch[row][0] == ch[row][1] && ch[row][0] == ch[row][2] && ch[row][0] != ' '){
			return ch[row][0];
		}
	}
	//2.检查列
	for (int col = 0; col < COL; col++){
		if (ch[0][col] == ch[1][col] && ch[0][col] == ch[2][col] && ch[0][col] != ' '){
			return ch[col][0];
		}
	}
	//3.检查对角线
	if (ch[0][0] == ch[1][1] && ch[0][0] == ch[2][2] && ch[0][0] != ' '){
		return ch[0][0];
	}
	if (ch[0][2] == ch[1][1] && ch[0][2] == ch[2][0] && ch[2][0] != ' '){
		return ch[0][2];
	}
	//4.检查是否为平局
	if (isFull()){
		return 'e';
	}
	return ' ';
}

int main(){
	srand((unsigned int)time(0));
	//1.初始化棋盘
	init();
	print();
	char winner = 'k';
	while (1){
		//2.人落棋
		PresonMoveChess();
		//3.检查人是否成功
		winner = checkIsSuccess();
		if (winner != ' '){
			break;
		}
		//4.机器落棋
		AlMoveChess();
		//5.检验机器是否成功
		winner = checkIsSuccess();
		if (winner != ' '){
			break;
		}
		system("cls");
		print();
	}
	if (winner == 'p'){
		printf("nice\n");
	}
	else if (winner == 'a'){
		printf("lowbbbbbbb\n");
	}
	else {
		printf("lowb\n");
	}

	system("pause");
	return 0;
}