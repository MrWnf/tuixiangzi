#include<stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<string.h>
#include<conio.h>














void init() {

	//�öδ��빦�������ع�꣬������win32��̽ӿڣ�����Ҫ����
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ���ھ��
	CONSOLE_CURSOR_INFO cci;//ʵ�л�һ������̨�����Ϣ��
	GetConsoleCursorInfo(hOut, &cci);//��ȡ�����Ϣ
	cci.bVisible = FALSE;//���ع��
	SetConsoleCursorInfo(hOut, &cci);//���ù����Ϣ

	system("title ������1.0");//�趨��������
	system("mode con cols=10 lines=12");//�趨���ڴ�С
}





int i, j;
void draw_map(int map[10][12]); //������ͼ����
int main()
{
	char input;
	int count = 0;   //����Ƿֱ���
	//�����ͼ
	int map[10][12] = {
		{2,2,2,2,2,2,2,2,2,2,2,2},
		{2,1,1,1,1,1,0,0,0,1,1,2},
		{1,0,0,1,1,1,0,1,0,0,1,2},
		{1,0,4,3,3,3,3,3,1,0,1,1},
		{1,0,0,1,1,3,3,3,4,0,0,1},
		{1,0,0,0,0,4,1,1,4,1,0,1},
		{1,0,4,1,4,0,0,0,4,0,0,1},
		{1,1,0,6,0,1,1,1,4,1,0,1},
		{2,1,1,1,1,1,2,1,0,0,0,1},
		{2,2,2,2,2,2,2,1,1,1,1,1}
	};
	while (1)
	{
		system("CLS");
		for (i = 0; i < 12; i++)
		{
			printf("%d", i);
		}
		printf("\n");


		draw_map(map);
		printf("��ǰ�÷֣�%d\n", count);
		//�ҳ�ʼλ��
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 12; j++)
			{
				if (map[i][j] == 6 || map[i][j] == 9)
					break;
			}
			if (map[i][j] == 6 || map[i][j] == 9)
				break;
		}
		printf("���ĵ�ǰ���꣨%d��%d��", i, j);
		input = _getch();
		switch (input)
		{
		case 'w':
			//0����յ�  6������  //3����Ŀ�ĵ�
			if (map[i - 1][j] == 0)
			{
				map[i - 1][j] = 6 + 0;
				if (map[i][j] == 9)
					map[i][j] = 3;
				else
					map[i][j] = 0;
			}

			else if ((map[i - 1][j] == 3) || (map[i - 1][j] == 9))
			{
				map[i - 1][j] = 6 + 3;
				if (map[i][j] == 9)
					map[i][j] = 3;
				else
					map[i][j] = 0;
			}
			//�����ǰ�������ӡ�//4��������   //7���ӽ���Ŀ�ĵ�
			else if (map[i - 1][j] == 4)
			{

				if (map[i - 2][j] == 0)
				{
					map[i - 2][j] = 4; //����������ǰ��һ�����ѿյ�ID�޸�Ϊ����ID����
					//�����Ƕ�����ԭ�ؽ����ж�
					if (map[i - 1][j] == 7)
						map[i - 1][j] = 9;
					else
						map[i - 1][j] = 6;
					//�����Ƕ���ԭ�ؽ����ж�
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
				//����˵�ǰ�������ӣ�������ǰ����Ŀ�ĵء�
				else if (map[i - 2][j] == 3)
				{
					map[i - 2][j] = 7;
					count++;
					//�����Ƕ�����ԭ��λ�õ��ж�
					if (map[i - 1][j] == 7)
						map[i - 1][j] = 9;
					else
						map[i - 1][j] = 6;
					//�����Ƕ���ԭ��λ�ý����ж�
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
			}
			//�����ǰ�����Ѿ�����ĳĿ�ĵص����ӣ�
			else if (map[i - 1][j] == 7)
			{
				//�����ǰ�����Ѿ�����ĳĿ�ĵص�����,������ǰ���ǿյء�
				if (map[i - 2][j] == 0)
				{
					count--;
					map[i - 2][j] = 4;
					map[i - 1][j] = 9;
					//�����Ƕ���ԭ�ȵؽ����ж�
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
				//�����ǰ�����Ѿ�����ĳĿ�ĵص����ӣ�������ǰ������һĿ�ĵء�
				if (map[i - 2][j] == 3)
				{
					map[i - 2][j] = 7;
					map[i - 1][j] = 9;
					//�����Ƕ���ԭ��վ���ؽ����ж�
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
			}
			break;
		case 's':
			//�����ǰ���ǿյء�
			if (map[i + 1][j] == 0)
			{
				map[i + 1][j] = 6 + 0;
				if (map[i][j] == 9)
					map[i][j] = 3;
				else
					map[i][j] = 0;
			}
			//�����ǰ����Ŀ�ĵء�
			else if (map[i + 1][j] == 3)
			{
				map[i + 1][j] = 6 + 3;
				if (map[i][j] == 9)
					map[i][j] = 3;
				else
					map[i][j] = 0;
			}
			//�����ǰ�������ӡ�
			else if (map[i + 1][j] == 4)
			{
				//�����ǰ�������ӣ�������ǰ���ǿյء�
				if (map[i + 2][j] == 0)
				{
					map[i + 2][j] = 4;
					//�����Ƕ�����ԭ�ؽ����ж�
					if (map[i + 1][j] == 7)
						map[i + 1][j] = 9;
					else
						map[i + 1][j] = 6;
					//�����Ƕ���ԭ�ؽ����ж�
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
				//����˵�ǰ�������ӣ�������ǰ����Ŀ�ĵء�
				else if (map[i + 2][j] == 3)
				{
					map[i - 2][j] = 7;
					count++;
					//�����Ƕ�����ԭ��λ�õ��ж�
					if (map[i + 1][j] == 7)
						map[i + 1][j] = 9;
					else
						map[i + 1][j] = 6;
					//�����Ƕ���ԭ��λ�ý����ж�
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
			}
			//�����ǰ�����Ѿ�����ĳĿ�ĵص�����
			else if (map[i + 1][j] == 7)
			{
				//�����ǰ�����Ѿ�����ĳĿ�ĵص�����,������ǰ���ǿյء�
				if (map[i + 2][j] == 0)
				{
					count--;
					map[i + 2][j] = 4;
					map[i + 1][j] = 9;
					//�����Ƕ���ԭ�ȵؽ����ж�
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
				//�����ǰ�����Ѿ�����ĳĿ�ĵص����ӣ�������ǰ������һĿ�ĵء�
				if (map[i + 2][j] == 3)
				{
					map[i + 2][j] = 7;
					map[i + 1][j] = 9;
					//�����Ƕ���ԭ��վ���ؽ����ж�
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
			}
			break;
		case 'a':
			//�����ǰ���ǿյء�
			if (map[i][j - 1] == 0)
			{
				map[i][j - 1] = 6 + 0;
				if (map[i][j] == 9)
					map[i][j] = 3;
				else
					map[i][j] = 0;
			}
			//�����ǰ����Ŀ�ĵء�
			else if (map[i][j - 1] == 3)
			{
				map[i][j - 1] = 6 + 3;
				if (map[i][j] == 9)
					map[i][j] = 3;
				else
					map[i][j] = 0;
			}
			//�����ǰ�������ӡ�
			else if (map[i][j - 1] == 4)
			{
				//�����ǰ�������ӣ�������ǰ���ǿյء�
				if (map[i][j - 2] == 0)
				{
					map[i][j - 2] = 4;
					//�����Ƕ�����ԭ�ؽ����ж�
					if (map[i][j - 1] == 7)
						map[i][j - 1] = 9;
					else
						map[i][j - 1] = 6;
					//�����Ƕ���ԭ�ؽ����ж�
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
				//����˵�ǰ�������ӣ�������ǰ����Ŀ�ĵء�
				else if (map[i][j - 2] == 3)
				{
					count++;
					map[i][j - 2] = 7;
					if (map[i][j - 1] == 7)
						map[i][j - 1] = 9;
					else
						map[i][j - 1] = 6;
					//�����Ƕ���ԭ��λ�ý����ж�
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
			}
			//�����ǰ�����Ѿ�����ĳĿ�ĵص����ӣ�ID=7����
			else if (map[i][j - 1] == 7)
			{
				//�����ǰ�����Ѿ�����ĳĿ�ĵص�����,������ǰ���ǿյء�
				if (map[i][j - 2] == 0)
				{
					count--;
					map[i][j - 2] = 4;
					map[i][j - 1] = 9;
					//�����Ƕ���ԭ�ȵؽ����ж�
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
				//�����ǰ�����Ѿ�����ĳĿ�ĵص����ӣ�������ǰ������һĿ�ĵء�
				if (map[i][j - 2] == 3)
				{
					map[i][j - 2] = 7;
					map[i][j - 1] = 9;

					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
			}
			break;
		case 'd':
			//�����ǰ���ǿյء�
			if (map[i][j + 1] == 0)
			{
				map[i][j + 1] = 6 + 0;
				if (map[i][j] == 9)
					map[i][j] = 3;
				else
					map[i][j] = 0;
			}
			//�����ǰ����Ŀ�ĵء�
			else if (map[i][j + 1] == 3)
			{
				map[i][j + 1] = 6 + 3;
				if (map[i][j] == 9)
					map[i][j] = 3;
				else
					map[i][j] = 0;
			}
			//�����ǰ�������ӡ�
			else if (map[i][j + 1] == 4)
			{
				//�����ǰ�������ӣ�������ǰ���ǿյء�
				if (map[i][j + 2] == 0)
				{
					map[i][j + 2] = 4;
					//�����Ƕ�����ԭ�ؽ����ж�
					if (map[i][j + 1] == 7)
						map[i][j + 1] = 9;
					else
						map[i][j + 1] = 6;
					//�����Ƕ���ԭ�ؽ����ж�
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
				//����˵�ǰ�������ӣ�������ǰ����Ŀ�ĵء�
				else if (map[i][j + 2] == 3)
				{
					count++;
					map[i][j + 2] = 7;
					//�����Ƕ�����ԭ��λ�õ��ж�
					if (map[i][j + 1] == 7)
						map[i][j + 1] = 9;
					else
						map[i][j + 1] = 6;
					//�����Ƕ���ԭ��λ�ý����ж�
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
			}

			else if (map[i][j + 1] == 7)
			{
				//�����ǰ�����Ѿ�����ĳĿ�ĵص�����,������ǰ���ǿյء�
				if (map[i][j + 2] == 0)
				{
					count--;
					map[i][j + 2] = 4;
					map[i][j + 1] = 9;
					//�����Ƕ���ԭ�ȵؽ����ж�
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
				//�����ǰ�����Ѿ�����ĳĿ�ĵص�����
				if (map[i][j + 2] == 3)
				{
					map[i][j + 2] = 7;
					map[i][j + 1] = 9;
					//�����Ƕ���ԭ��վ���ؽ����ж�
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
			}
			break;
		}
		if (count == 8)   //��������ﵽ��
		{
			system("CLS"); //����
			draw_map(map);
			break;    //�˳���ѭ��
		}
	}
	printf("\n��ϲ�㣬�����ˣ���\n"); //������ʾ
	return 0;
}
void draw_map(int map[10][12])
{

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 12; j++)
		{
			switch (map[i][j])
			{
			case 0:
				printf(" "); //���ִ����·
				break;
			case 1:
				printf("#"); //���ִ���ǽ��
				break;
			case 2:
				printf(" "); //��������Ϸ�߿�Ŀհײ���
				break;
			case 3:
				printf("!"); //���ִ���Ŀ�ĵ�
				break;
			case 4:
				printf("*"); //���ִ�������
				break;
			case 7:
				printf("$"); //���ִ������ӽ���Ŀ�ĵ�
				break;
			case 6:
				printf("@"); //���ִ�����
				break;
			case 9:
				printf("@"); //���ִ����˽���Ŀ�ĵ�

			}
		}
		printf("\n");    //�������
	}
}
