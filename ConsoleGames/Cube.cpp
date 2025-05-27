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
int sort = 0; //��ǰ�������ת�Ƕ�����
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
//��¼��ǰ�����λ����Ϣ
int row = 1;
int col = 25;
//������ҵĵ�ǰ����
char keyWords;
bool canWriteNext = true;//�����ж��ܷ�д����һ��cube
int main()
{
	//��ʼ�����еķ������ͣ�
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
	view[12].append("    *    .                             ����ʼ��Ϸ                                .   *              ");
	view[13].append("    *    .                               ��    ��                                .   *              ");
	view[14].append("    *    .                               ��ʷ�÷�                                .   *              ");
	view[15].append("    *    .                                                                       .   *              ");
	view[16].append("    *    .........................................................................   *              ");
	view[17].append("    *                                                                                *              ");
	view[18].append("    *          *����:    w  s  Enter                                                 *              ");
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
	//��Ϸ��ʼ��ѡ��˵�
	for (int i = 0; i < 26; i++)
	{
		cout << view[i] << endl;
	}
	//system("cls");
	ChangeArray();
	gameMode();
	//���ú����ı����鲼��
	
}
void gameMode()
{
	//ͨ�����Ʒ��򰴼�ʵ�ֹ�������ѭ���ƶ�
	int index = 0;
	int realIndex = index + 12;
	while (true) {
		keyWords = _getch();
		if (keyWords == 's')
		{
			view[index + 12].replace(39, 2, "  ");
			index = (index + 1) % 3;
			realIndex = index + 12;
			view[realIndex].replace(39, 2, "��");
		}
		else if (keyWords == 'w')
		{
			view[index + 12].replace(39, 2, "  ");
			index = (index + 3 - 1) % 3;
			realIndex = index + 12;
			view[realIndex].replace(39, 2, "��");
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
				//��ʼ��������������
				cubeCodeNext = CreateCubeCode();
				DisplayGameView();
				//ִ�п�ʼ�µ���Ϸ����
				break;
			case 1:
				//�ر���Ϸ����
				break;
			case 2:
				//��ʾ��ʷ������߷��� 
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
			WriteNextCube();//����д��ÿһ���µ�cube��ֻ��canWriteNextΪtrue��ִ�У�
			cout << "ִ����һ��" << endl;
		}
		if (gameOver) 
		{
			break;
		}
		//���������
		for (int i = 0; i < 2; i++)
		{
			GameFram();
			keyWords = _getch();
			switch (keyWords)
			{
			case 'e'://������ת
				//��ײ���ͨ������ת
				if (CubeCollider(3, (sort + 1) % 4)) {
					sort = (sort + 1) % 4;//cube����ת��������һ��
					DrawCube(sort);
				}
				break;
			case 'q'://������ת
				//ͬ������ײ���Ȼ����������ת����
				if (CubeCollider(3, (sort + 4 - 1) % 4))
				{
					sort = (sort + 4 - 1) % 4;
					DrawCube(sort);
				}
				break;
			case 'd'://�����ƶ�
				cout << CubeCollider(2, sort) << endl;
				if (CubeCollider(2, sort))
				{
					col++;
					DrawCube(sort);
				}
				break;
			case 'a'://�����ƶ�
				cout << CubeCollider(1, sort) << endl;
				if (CubeCollider(1, sort))
				{
					col--;
					DrawCube(sort);
				}
				break;
			case 's'://�����ƶ�
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
	//����Ϸ������д��ÿһ��cube��������һ��cube�ı�ţ�

	//����һ��cube��Ÿ�ֵ����ǰ��cube��ţ�Ȼ�󴴽���һ��cube��ţ�
	cubeCodeNow = cubeCodeNext;
	cubeCodeNext = CreateCubeCode();
	cube = cubes[cubeCodeNow].c_str();
	DrawNextCube(cubeCodeNext);
	//�ж��Ƿ����ܹ���������
	ClearCube();
	//�ź���canWrite(�ж�Ϊ��ʱ���д��һ��cube)
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
//д�뷽��ķ�ʽ
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
//д��ϴһ��cube
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
//д�����
void DrawScore()
{
	//������ת�����ַ���Ȼ��д�뻭����
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
//��ʼ���׶���Ҫ��string���͵�����ת����char���͡�
void ChangeArray()
{
	girt = new char[26][100];
	//����Ϸ�ĳ�ʼ���׶Σ����ַ����������Ȼ��д��girt�У�
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
//������Ϸ�ĵ÷�
void Score()
{
    //��ʼ�÷�
	int base = 15;//�����÷�
	int uper = 3;//����
	score = score + base * uper;//���յ÷�
}
void GameOver()
{
	//��Ļ��ӡgame over������ҵ�ǰ��Ϸ�ĵ÷�;
	system("cls");
	cout << "Game Over!!!" << endl;
	cout << " Your Score��" + score << endl;
	//�ڴ��ͷ�
	gameOver = true;
	delete []girt;
	//����������س�����һ���µ���Ϸ��B���˳���Ϸ
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
//cube�����ƶ�
void CubeDown()
{
	//����ײ������д������Ҫд��ķ����Ƿ�Ϊ�ո������һ����Ϊ�ո����ײ�������ƶ���
	//�޸�canWriteCubeΪtrue
	//����row ��col;
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
	//��ײ��ⷽ��
		switch (direction)
		{
		case 0://�����ƶ�
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
		case 1://�����ƶ�
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
		case 2://�����ƶ�
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
		case 3://��ת����ײ���Ӧ����Ҫ�����֮ǰcube���ڷ�Χ�ڵ�Ԫ�أ�������ײ�����������жϡ�
			//��һ�������ԭ��Ԫ��
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
		case 4://�����µ�cubeʱ�����ײ���
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
	//ÿ���һ��ʱ��ˢ��һ����Ϸ����
		std::this_thread::sleep_for(50ms);//һ֡����
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
	//���ÿһ���Ƿ��ܹ�����������ܾ����������ո񣬴�ӡ������Ļ��棬ͣ��һ�룬
	//Ȼ�����ڵ�ÿһ��Ԫ�������ƶ�һ��������Ԫ�ص�����һ�У�
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
		//д��'
		if (canClear) 
		{
			for (int x =12; x < 36; x++) 
			{
				girt[i][x] = ' ';
				//cout << "����û������" << endl;
			}
			//�ȴ�400ms�������е���������Ԫ�������ƶ�һ��
			GameFram();
			//�޸ķ�������ӡ����
			Score();
			DrawScore();
			//�����ƶ�cube
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