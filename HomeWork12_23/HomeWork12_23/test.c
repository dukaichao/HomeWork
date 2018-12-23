#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3
char ch[ROW][COL];
/*
	1..��ʼ��   ȫ��Ϊ' '�ո�
	2..�����ӱ��Ϊ 'p'
	3..�������ӱ��Ϊ 'a'
	4..�˳ɹ�����  'p'
	5..�����ɹ����� 'a'
	6..ƽ�ַ��� 'e'
	7..other���� ' '�ո�

*/
//�����Ƿ�������
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
//��ʼ��
void init(){
	for (int row = 0; row < ROW; row++){
		for (int col = 0; col < COL; col++){
			ch[row][col] = '\0';
		}
	}
}
//��ӡ����
void print(){
	for (int row = 0; row < ROW; row++){
		printf("| %c | %c | %c |\n", ch[row][0], ch[row][1],ch[row][2]);
		if (row < 2){
			printf(" --- --- ---\n");
		}
	}
}
//������
void PresonMoveChess(){
	//1.��ʾ
	printf("����������:> \n");
	int row = 0;
	int col = 0;
	while (1){
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= ROW || col < 0 || col >= COL){
			printf("������������������:> \n");
			continue;
		}
		ch[row][col] = 'p';
		break;
	}
}
//��������
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
//�����Ƿ�ɹ�
char checkIsSuccess(){
	//1.�����
	for (int row = 0; row < ROW; row++){
		if (ch[row][0] == ch[row][1] && ch[row][0] == ch[row][2] && ch[row][0] != ' '){
			return ch[row][0];
		}
	}
	//2.�����
	for (int col = 0; col < COL; col++){
		if (ch[0][col] == ch[1][col] && ch[0][col] == ch[2][col] && ch[0][col] != ' '){
			return ch[col][0];
		}
	}
	//3.���Խ���
	if (ch[0][0] == ch[1][1] && ch[0][0] == ch[2][2] && ch[0][0] != ' '){
		return ch[0][0];
	}
	if (ch[0][2] == ch[1][1] && ch[0][2] == ch[2][0] && ch[2][0] != ' '){
		return ch[0][2];
	}
	//4.����Ƿ�Ϊƽ��
	if (isFull()){
		return 'e';
	}
	return ' ';
}

int main(){
	srand((unsigned int)time(0));
	//1.��ʼ������
	init();
	print();
	char winner = 'k';
	while (1){
		//2.������
		PresonMoveChess();
		//3.������Ƿ�ɹ�
		winner = checkIsSuccess();
		if (winner != ' '){
			break;
		}
		//4.��������
		AlMoveChess();
		//5.��������Ƿ�ɹ�
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