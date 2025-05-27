#include<iostream>
#include<string>
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<chrono>
#include<thread>
#include<stdlib.h>
#include<WinUser.h>
#include<time.h>

using namespace std;
string view[26];
string playView[26];
string cubes[7];
bool gameOver = false;
int maxScore;
void DisplayGameView();
void gameMode();
void WriteNextCube();
int cubeCodeNow = 0;
int cubeCodeNext;
const char* cube;
int CreateCubeCode();
int sort = 0; //当前方块的旋转角度类型
void DrawCube(int sort);
char (*girt)[100] = NULL;
int score = 0;
void Score();
void InitGame();
void ChangeArray();
int Rotation(int x,int y,int sort);
void CubeDown();
bool CubeCollider(int direction,int sort);
void DrawNextCube(int cubeCodeNext);
void DrawScore();
void MoveAtom(int row);
void ClearCube();
void GameOver();
void DeleteCube();
void GameFram();
bool canWrite = true;
//记录当前方块的位置信息
int row = 1;
int col = 25;
//保存玩家的当前输入
char keyWords;
bool canWriteNext = true;//用于判断能否写入下一个cube
int main()
{
	//初始化所有的方块类型：
	cubes[0].append("  x ");
	cubes[0].append(" xx ");
	cubes[0].append(" x  ");
	cubes[0].append("    ");

	cubes[1].append(" x  ");
	cubes[1].append(" x  ");
	cubes[1].append(" x  ");
	cubes[1].append(" x  ");

	cubes[2].append(" xx ");
	cubes[2].append(" xx ");
	cubes[2].append("    ");
	cubes[2].append("    ");

	cubes[3].append(" xx ");
	cubes[3].append("  x ");
	cubes[3].append("  x ");
	cubes[3].append("    ");


	cubes[4].append("  x ");
	cubes[4].append(" xx ");
	cubes[4].append("  x ");
	cubes[4].append("    ");

	cubes[5].append(" x  ");
	cubes[5].append(" xx ");
	cubes[5].append("  x ");
	cubes[5].append("    ");

	cubes[6].append(" xx ");
	cubes[6].append(" x  ");
	cubes[6].append(" x  ");
	cubes[6].append("    ");
	//tetris
	view[00].append("    **********************************************************************************              ");
	view[01].append("    *    .........................................................................   *              ");
	view[02].append("    *    .                                                                       .   *              ");
	view[03].append("    *    .     XxxxxxxxxX XxxxxxX XxxxxxxxxX  xxxxxx     XxxxxxxX   xxxxxX       .   *              ");
	view[04].append("    *    .         xx     xx          xx     Xx    xx       xx     x             .   *              ");
	view[05].append("    *    .         xx     xx          xx     xx    xx       xx     x             .   *              ");
	view[06].append("    *    .         xx     xxxxxX      xx     xxxxxxxx       xx      xxxxxx       .   *              ");
	view[07].append("    *    .         xx     xx          xx     xxxxx          xx            x      .   *              ");
	 view[8].append("    *    .         xx     xx          xx     xx  xx         xx            x      .   *              ");
	 view[9].append("    *    .         XX     XxxxxxX     XX     XxX   xxxX XxxxxxxxxX Xxxxxxx       .   *              ");
	view[10].append("    *    .                                                                       .   *              ");
	view[11].append("    *    .                                                                       .   *              ");
	view[12].append("    *    .                             》开始游戏                                .   *              ");
	view[13].append("    *    .                               离    开                                .   *              ");
	view[14].append("    *    .                               历史得分                                .   *              ");
	view[15].append("    *    .                                                                       .   *              ");
	view[16].append("    *    .........................................................................   *              ");
	view[17].append("    *                                                                                *              ");
	view[18].append("    *          *操作:    w  s  Enter                                                 *              ");
	view[19].append("    *                                                                                *              ");
	view[20].append("    *                                                                                *              ");
	view[21].append("    *                                                                                *              ");
	view[22].append("    *                                                                                *              ");
	view[23].append("    *                                                                                *              ");
	view[24].append("    *                                                                                *              ");
	view[25].append("    **********************************************************************************              ");

	 playView[0].append("           **************************                                                               ");
	 playView[1].append("           *                        *    > next cube:                                               ");
	 playView[2].append("           *                        *                                                               ");
	 playView[3].append("           *                        *                                                               ");
	 playView[4].append("           *                        *                                                               ");
	 playView[5].append("           *                        *                                                               ");
	 playView[6].append("           *                        *    > your score:                                              ");
	 playView[7].append("           *                        *                                                               ");
	 playView[8].append("           *                        *                                                               ");
	 playView[9].append("           *                        *                                                               ");
	playView[10].append("           *                        *                                                               ");
	playView[11].append("           *                        *                                                               ");
	playView[12].append("           *                        *                                                               ");
	playView[13].append("           *                        *                                                               ");
	playView[14].append("           *                        *                                                               ");
	playView[15].append("           *                        *                                                               ");
	playView[16].append("           *                        *                                                               ");
	playView[17].append("           *                        *                                                               ");
	playView[18].append("           *                        *                                                               ");
	playView[19].append("           *                        *                                                               ");
	playView[20].append("           *                        *                                                               ");
	playView[21].append("           *                        *                                                               ");
	playView[22].append("           *                        *     *esc exit game!*                                          ");
	playView[23].append("           **************************                                                               ");
	playView[24].append("                                                                                                    ");
	playView[25].append(" -------------------------------------------------------------                                      ");
	InitGame();
	return 0;
}
void InitGame() 
{
	//游戏开始的选择菜单
	for (int i = 0; i < 26; i++)
	{
		cout << view[i] << endl;
	}
	//system("cls");
	ChangeArray();
	gameMode();
	//调用函数改变数组布局
	
}
void gameMode()
{
	//通过控制方向按键实现光标的上下循环移动
	int index = 0;
	int realIndex = index + 12;
	while (true) {
		keyWords = _getch();
		if (keyWords == 's')
		{
			view[index + 12].replace(39, 2, "  ");
			index = (index + 1) % 3;
			realIndex = index + 12;
			view[realIndex].replace(39, 2, "》");
		}
		else if (keyWords == 'w')
		{
			view[index + 12].replace(39, 2, "  ");
			index = (index + 3 - 1) % 3;
			realIndex = index + 12;
			view[realIndex].replace(39, 2, "》");
		}
		system("cls");
		for (int i = 0; i < 26; i++)
		{
			cout << view[i] << endl;
		}
		if (keyWords == 13) {
			switch (index) {
			case 0:
				system("cls");
				//初始化两个方块类型
				cubeCodeNext = CreateCubeCode();
				DisplayGameView();
				//执行开始新的游戏画面
				break;
			case 1:
				//关闭游戏窗口
				break;
			case 2:
				//显示历史游玩最高分数 
				break;
			}
		}
	}

}
void DisplayGameView()
{
	DrawScore();
	while (!gameOver)
	{
		
		if (canWriteNext) {
			WriteNextCube();//用于写入每一个新的cube，只在canWriteNext为true是执行；
			cout << "执行了一次" << endl;
		}
		if (gameOver) 
		{
			break;
		}
		//玩家输入检测
		for (int i = 0; i < 2; i++)
		{
			GameFram();
			keyWords = _getch();
			switch (keyWords)
			{
			case 'e'://向右旋转
				//碰撞检测通过后旋转
				if (CubeCollider(3, (sort + 1) % 4)) {
					sort = (sort + 1) % 4;//cube的旋转类型向后加一；
					DrawCube(sort);
				}
				break;
			case 'q'://向左旋转
				//同理先碰撞检测然后再做出旋转操作
				if (CubeCollider(3, (sort + 4 - 1) % 4))
				{
					sort = (sort + 4 - 1) % 4;
					DrawCube(sort);
				}
				break;
			case 'd'://向右移动
				cout << CubeCollider(2, sort) << endl;
				if (CubeCollider(2, sort))
				{
					col++;
					DrawCube(sort);
				}
				break;
			case 'a'://向左移动
				cout << CubeCollider(1, sort) << endl;
				if (CubeCollider(1, sort))
				{
					col--;
					DrawCube(sort);
				}
				break;
			case 's'://向下移动
				cout << CubeCollider(0, sort) << endl;
				if (CubeCollider(0, sort))
				{
					row++;
					DrawCube(sort);
				}
				break;
		}
		
		
		}
		CubeDown();
	}
}
void WriteNextCube()
{
	//向游戏棋盘中写入每一个cube并产生下一个cube的编号，

	//将下一个cube编号赋值给当前的cube编号，然后创建下一个cube编号；
	cubeCodeNow = cubeCodeNext;
	cubeCodeNext = CreateCubeCode();
	cube = cubes[cubeCodeNow].c_str();
	DrawNextCube(cubeCodeNext);
	//判断是否有能够消除的行
	ClearCube();
	//信号量canWrite(判断为真时随机写入一个cube)
	if (CubeCollider(4, sort)) 
	{
		DrawCube(sort);
		canWriteNext = false;
	}
	else 
	{
		GameOver();
	}
}
//写入方块的方式
void DrawCube( int sort)
{
		for (int i = row; i < row + 4; i++)
		{
			for (int j = col; j < col + 4; j++)
			{
				if (*(cube + Rotation(i - row, j - col, sort)) == 'x')
				{
					girt[i][j] = *(cube + Rotation(i - row, j - col, sort));
				}
			}
		}
}
//写入洗一个cube
void DrawNextCube(int cubeCodeNext)
{
	for (int i = 2; i < 2 + 4; i++)
	{
		for (int j = 53; j < 53 + 4; j++)
		{
			girt[i][j] = *(cubes[cubeCodeNext].c_str() + Rotation(i - 2, j - 53, sort));
		}
	}
}
//写入分数
void DrawScore()
{
	//将分数转换成字符串然后写入画面中
	string s = to_string(score);
	for (int i = 54; i < 54 +s.size() ; i++)
	{
		girt[7][i] =s.at(i-54);
	}
}
void DeleteCube()
{

		for (int i = row; i < row + 4; i++)
		{
			for (int j = col; j < col + 4; j++)
			{
				if (*(cube + Rotation(i - row, j - col, sort)) == 'x')
				{
					girt[i][j] = ' ';
				}
			}
		}
}
//初始化阶段需要将string类型的数组转换成char类型。
void ChangeArray()
{
	girt = new char[26][100];
	//在游戏的初始化阶段，将字符串逐个便利然后写入girt中；
	for (int i = 0; i < 26; i++)
	{
		const char* x = playView[i].c_str();
		//cout << *(x + 25) << endl;
		for (int j = 0; j < 100; j++)
		{
			girt[i][j] = *(x + j);
		}
	}

}
//计算游戏的得分
void Score()
{
    //初始得分
	int base = 15;//基础得分
	int uper = 3;//倍率
	score = score + base * uper;//最终得分
}
void GameOver()
{
	//屏幕打印game over！和玩家当前游戏的得分;
	system("cls");
	cout << "Game Over!!!" << endl;
	cout << " Your Score：" + score << endl;
	//内存释放
	gameOver = true;
	delete []girt;
	//检测玩家输入回车键下一局新的游戏，B键退出游戏
}
int Rotation(int x, int y, int sort) 
{
	switch (sort)
	{
	case 0:
		return y*4+x;
	case 1:
		return 12+y-(x*4);
	case 2:
		return 15-x - (y * 4);
	case 3:
		return 3-y + (x * 4);
	}
	return 0;
}
int CreateCubeCode()
{
	time_t now;
	srand(time(&now));
	return rand() % 6;
}
//cube向下移动
void CubeDown()
{
	//做碰撞检测便利写入点和需要写入的符号是否都为空格，如果有一个不为空格就碰撞，则不能移动，
	//修改canWriteCube为true
	//重置row 和col;
	if (CubeCollider(0,sort))
	{
		row++;
		DrawCube(sort);
	}
	else {
		canWriteNext = true;
		row = 1;
		col = 25;
	}

}
bool CubeCollider(int direction,int sort)
{
	//碰撞检测方向
		switch (direction)
		{
		case 0://向下移动
			DeleteCube();
			for (int i = row + 1; i < row + 5; i++)
			{
				for (int j = col; j < col + 4; j++)
				{
					if ((girt[i][j] == '*' || girt[i][j] == 'x') && (*(cube + Rotation(i - row - 1, j - col, sort)) == 'x'))
					{
						DrawCube(sort);
						return false;
					}
				}
			}
			break;
		case 1://向左移动
			DeleteCube();
			for (int i = row; i < row + 4; i++)
			{
				for (int j = col - 1; j < col + 5; j++)
				{
					if ((girt[i][j] == '*' || girt[i][j] == 'x') && (*(cube + Rotation(i - row, j - col + 1, sort)) == 'x'))
					{
						DrawCube(sort);
						return false;
					}
				}
			}
			break;
		case 2://向右移动
			DeleteCube();
			for (int i = row; i < row + 4; i++)
			{
				for (int j = col + 1; j < col + 5; j++)
				{
					if ((girt[i][j] == '*' || girt[i][j] == 'x') && (*(cube + Rotation(i - row, j - col - 1, sort)) == 'x'))
					{
						DrawCube(sort);
						return false;
					}
				}
			}
			break;
		case 3://旋转的碰撞检测应该需要先清空之前cube所在范围内的元素，在做碰撞检测以免干扰判断。
			//第一步：清除原有元素
			DeleteCube();
			for (int i = row; i < row + 4; i++)
			{
				for (int j = col; j < col + 4; j++)
				{
					if ((girt[i][j] == '*' || girt[i][j] == 'x') && (*(cube + Rotation(i - row, j - col - 1, sort)) == 'x'))
					{
						DrawCube(sort);
						return false;
					}
				}
			}
			break;
		case 4://插入新的cube时候的碰撞检测
			for (int i = row; i < row + 4; i++)
			{
				for (int j = col; j < col + 4; j++)
				{
					if ((girt[i][j] == '*' || girt[i][j] == 'x') && (*(cube + Rotation(i - row, j - col - 1, sort)) == 'x'))
					{
						return false;
					}
				}
			}
			break;
		}
	
	return true;
}
void GameFram()
{
	//每间隔一段时间刷新一下游戏画面
		std::this_thread::sleep_for(50ms);//一帧画面
		system("cls");
		for (int i = 0; i < 26; i++)
		{
			//cout << playView[i] << endl;
			for (int j = 0; j < 100; j++)
			{
				cout << girt[i][j];
			}
			cout << ' ' << endl;
		}
}
void ClearCube()
{
	//检测每一行是否能够消除，如果能就消除，填充空格，打印消除后的画面，停顿一秒，
	//然后画面内的每一个元素向下移动一个（消除元素的上面一行）
	bool canClear = false;
	int i = 22;
	while(i>0)
	{
		for (int j =12; j < 36; j++)
		{
			if (girt[i][j] == ' ')
			{
				canClear = false;
				break;
			}
			else if (j == 35 && girt[i][j] == 'x') 
			{
				canClear = true;
			}
		}
		//写入'
		if (canClear) 
		{
			for (int x =12; x < 36; x++) 
			{
				girt[i][x] = ' ';
				//cout << "这里没有问题" << endl;
			}
			//等待400ms；消除行的上面所有元素向下移动一格，
			GameFram();
			//修改分数，打印分数
			Score();
			DrawScore();
			//向下移动cube
			MoveAtom(i);
			i++;
		}
		i--;
	}
}
void MoveAtom(int row)
{
	int i = row;
	for (i; i > 1; i--) 
	{
		//cout << "run" + i << endl;
		//printf("%d", i);
		//GameFram();
		for (int j = 12; j < 36; j++)
		{
			girt[i][j] = girt[i - 1][j];
		}
	}
}