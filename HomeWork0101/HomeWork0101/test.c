#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//1.
//5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ��������
//Aѡ��˵��B�ڶ����ҵ�����
//Bѡ��˵���ҵڶ���E���ģ�
//Cѡ��˵���ҵ�һ��D�ڶ���
//Dѡ��˵��C����ҵ�����
//Eѡ��˵���ҵ��ģ�A��һ��
//����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�//

//�����ж�
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
//�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4��
//���ɷ���һ��������Ϊ4�����ɷ��Ĺ��ʡ�
//A˵�������ҡ�
//B˵����C��
//C˵����D��
//D˵��C�ں�˵
//��֪3����˵���滰��1����˵���Ǽٻ���
//�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�
void IsTrue(){
	int i;
	char people[] = { 'A', 'B', 'C', 'D' };
	char kill;
	for (i = 0; i < 4; i++)
	{
		kill = people[i];
		if ((people[0] != kill) + (people[2] == kill) + (people[3] == kill) + (people[3] != kill) == 3)
		{
			printf("������:%c\n", kill);
		}
	}
}
//3.����Ļ�ϴ�ӡ������ǡ�
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