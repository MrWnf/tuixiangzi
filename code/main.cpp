#include<stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<string.h>
#include<conio.h>














void init() {

	//该段代码功能是隐藏光标，调用了win32编程接口，不需要掌握
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//获取窗口句柄
	CONSOLE_CURSOR_INFO cci;//实列化一个控制台光标信息类
	GetConsoleCursorInfo(hOut, &cci);//获取光标信息
	cci.bVisible = FALSE;//隐藏光标
	SetConsoleCursorInfo(hOut, &cci);//设置光标信息

	system("title 推箱子1.0");//设定窗口名称
	system("mode con cols=10 lines=12");//设定窗口大小
}





int i, j;
void draw_map(int map[10][12]); //声明画图函数
int main()
{
	char input;
	int count = 0;   //定义记分变量
	//定义地图
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
		printf("当前得分：%d\n", count);
		//找初始位置
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
		printf("您的当前坐标（%d，%d）", i, j);
		input = _getch();
		switch (input)
		{
		case 'w':
			//0代表空地  6代表人  //3代表目的地
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
			//如果人前面是箱子。//4代表箱子   //7箱子进入目的地
			else if (map[i - 1][j] == 4)
			{

				if (map[i - 2][j] == 0)
				{
					map[i - 2][j] = 4; //人推箱子往前走一步，把空地ID修改为箱子ID（）
					//下面是对箱子原地进行判断
					if (map[i - 1][j] == 7)
						map[i - 1][j] = 9;
					else
						map[i - 1][j] = 6;
					//下面是对人原地进行判断
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
				//如果人的前面是箱子，而箱子前面是目的地。
				else if (map[i - 2][j] == 3)
				{
					map[i - 2][j] = 7;
					count++;
					//下面是对箱子原先位置的判断
					if (map[i - 1][j] == 7)
						map[i - 1][j] = 9;
					else
						map[i - 1][j] = 6;
					//下面是对人原先位置进行判断
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
			}
			//如果人前面是已经进入某目的地的箱子（
			else if (map[i - 1][j] == 7)
			{
				//如果人前面是已经进入某目的地的箱子,而箱子前面是空地。
				if (map[i - 2][j] == 0)
				{
					count--;
					map[i - 2][j] = 4;
					map[i - 1][j] = 9;
					//下面是对人原先地进行判断
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
				//如果人前面是已经进入某目的地的箱子，而箱子前面是另一目的地。
				if (map[i - 2][j] == 3)
				{
					map[i - 2][j] = 7;
					map[i - 1][j] = 9;
					//下面是对人原先站立地进行判断
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
			}
			break;
		case 's':
			//如果人前面是空地。
			if (map[i + 1][j] == 0)
			{
				map[i + 1][j] = 6 + 0;
				if (map[i][j] == 9)
					map[i][j] = 3;
				else
					map[i][j] = 0;
			}
			//如果人前面是目的地。
			else if (map[i + 1][j] == 3)
			{
				map[i + 1][j] = 6 + 3;
				if (map[i][j] == 9)
					map[i][j] = 3;
				else
					map[i][j] = 0;
			}
			//如果人前面是箱子。
			else if (map[i + 1][j] == 4)
			{
				//如果人前面是箱子，而箱子前面是空地。
				if (map[i + 2][j] == 0)
				{
					map[i + 2][j] = 4;
					//下面是对箱子原地进行判断
					if (map[i + 1][j] == 7)
						map[i + 1][j] = 9;
					else
						map[i + 1][j] = 6;
					//下面是对人原地进行判断
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
				//如果人的前面是箱子，而箱子前面是目的地。
				else if (map[i + 2][j] == 3)
				{
					map[i - 2][j] = 7;
					count++;
					//下面是对箱子原先位置的判断
					if (map[i + 1][j] == 7)
						map[i + 1][j] = 9;
					else
						map[i + 1][j] = 6;
					//下面是对人原先位置进行判断
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
			}
			//如果人前面是已经进入某目的地的箱子
			else if (map[i + 1][j] == 7)
			{
				//如果人前面是已经进入某目的地的箱子,而箱子前面是空地。
				if (map[i + 2][j] == 0)
				{
					count--;
					map[i + 2][j] = 4;
					map[i + 1][j] = 9;
					//下面是对人原先地进行判断
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
				//如果人前面是已经进入某目的地的箱子，而箱子前面是另一目的地。
				if (map[i + 2][j] == 3)
				{
					map[i + 2][j] = 7;
					map[i + 1][j] = 9;
					//下面是对人原先站立地进行判断
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
			}
			break;
		case 'a':
			//如果人前面是空地。
			if (map[i][j - 1] == 0)
			{
				map[i][j - 1] = 6 + 0;
				if (map[i][j] == 9)
					map[i][j] = 3;
				else
					map[i][j] = 0;
			}
			//如果人前面是目的地。
			else if (map[i][j - 1] == 3)
			{
				map[i][j - 1] = 6 + 3;
				if (map[i][j] == 9)
					map[i][j] = 3;
				else
					map[i][j] = 0;
			}
			//如果人前面是箱子。
			else if (map[i][j - 1] == 4)
			{
				//如果人前面是箱子，而箱子前面是空地。
				if (map[i][j - 2] == 0)
				{
					map[i][j - 2] = 4;
					//下面是对箱子原地进行判断
					if (map[i][j - 1] == 7)
						map[i][j - 1] = 9;
					else
						map[i][j - 1] = 6;
					//下面是对人原地进行判断
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
				//如果人的前面是箱子，而箱子前面是目的地。
				else if (map[i][j - 2] == 3)
				{
					count++;
					map[i][j - 2] = 7;
					if (map[i][j - 1] == 7)
						map[i][j - 1] = 9;
					else
						map[i][j - 1] = 6;
					//下面是对人原先位置进行判断
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
			}
			//如果人前面是已经进入某目的地的箱子（ID=7）。
			else if (map[i][j - 1] == 7)
			{
				//如果人前面是已经进入某目的地的箱子,而箱子前面是空地。
				if (map[i][j - 2] == 0)
				{
					count--;
					map[i][j - 2] = 4;
					map[i][j - 1] = 9;
					//下面是对人原先地进行判断
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
				//如果人前面是已经进入某目的地的箱子，而箱子前面是另一目的地。
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
			//如果人前面是空地。
			if (map[i][j + 1] == 0)
			{
				map[i][j + 1] = 6 + 0;
				if (map[i][j] == 9)
					map[i][j] = 3;
				else
					map[i][j] = 0;
			}
			//如果人前面是目的地。
			else if (map[i][j + 1] == 3)
			{
				map[i][j + 1] = 6 + 3;
				if (map[i][j] == 9)
					map[i][j] = 3;
				else
					map[i][j] = 0;
			}
			//如果人前面是箱子。
			else if (map[i][j + 1] == 4)
			{
				//如果人前面是箱子，而箱子前面是空地。
				if (map[i][j + 2] == 0)
				{
					map[i][j + 2] = 4;
					//下面是对箱子原地进行判断
					if (map[i][j + 1] == 7)
						map[i][j + 1] = 9;
					else
						map[i][j + 1] = 6;
					//下面是对人原地进行判断
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
				//如果人的前面是箱子，而箱子前面是目的地。
				else if (map[i][j + 2] == 3)
				{
					count++;
					map[i][j + 2] = 7;
					//下面是对箱子原先位置的判断
					if (map[i][j + 1] == 7)
						map[i][j + 1] = 9;
					else
						map[i][j + 1] = 6;
					//下面是对人原先位置进行判断
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
			}

			else if (map[i][j + 1] == 7)
			{
				//如果人前面是已经进入某目的地的箱子,而箱子前面是空地。
				if (map[i][j + 2] == 0)
				{
					count--;
					map[i][j + 2] = 4;
					map[i][j + 1] = 9;
					//下面是对人原先地进行判断
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
				//如果人前面是已经进入某目的地的箱子
				if (map[i][j + 2] == 3)
				{
					map[i][j + 2] = 7;
					map[i][j + 1] = 9;
					//下面是对人原先站立地进行判断
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
			}
			break;
		}
		if (count == 8)   //如果分数达到分
		{
			system("CLS"); //清屏
			draw_map(map);
			break;    //退出死循环
		}
	}
	printf("\n恭喜你，过关了！！\n"); //过关提示
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
				printf(" "); //数字代表道路
				break;
			case 1:
				printf("#"); //数字代表墙壁
				break;
			case 2:
				printf(" "); //数字是游戏边框的空白部分
				break;
			case 3:
				printf("!"); //数字代表目的地
				break;
			case 4:
				printf("*"); //数字代表箱子
				break;
			case 7:
				printf("$"); //数字代表箱子进入目的地
				break;
			case 6:
				printf("@"); //数字代表人
				break;
			case 9:
				printf("@"); //数字代表人进入目的地

			}
		}
		printf("\n");    //分行输出
	}
}
