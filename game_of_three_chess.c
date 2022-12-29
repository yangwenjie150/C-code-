#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
void menu()
{
	printf("****************************\n");
	printf("**** 1.play      2.exit ****\n");
	printf("****************************\n");
}
void  InitBoard(char board[ROW][COL], int row, int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			board[i][j]=' ';
		}
	}
}
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int p;
	for(p=0;p<row;p++)
	{
		//1.打印一行的数据 
		//printf(" %c | %c | %c \n",board[p][0],board[p][1],board[p][2]);
		//2.打印分割行 
		//if(p<row-1)
		//printf("---|---|---\n");
		/*优化后*/
		int q;
		for(q=0;q<col;q++) 
		{
			//1.打印一行的数据 
			printf(" %c ",board[p][q]);
			if(q<col-1)
			printf("|");
		}
		printf("\n");
		//2.打印分割行
		if(p<row-1)
		for(q=0;q<col;q++)
		{
			printf("---");
			if(q<col-1)
			printf("|");
		}
		printf("\n");
	}

}
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x=0;
	int y=0;
	printf("玩家走：>\n");
	while(1)
	{
		printf("请输入要下的坐标：>");
		scanf("%d%d",&x,&y);
		//判断坐标的合法性
		if(x>=1&&x<=row&&y>=1&&y<=col)
		{
			if(board[x-1][y-1]==' ')
			{
				board[x-1][y-1]='*';
				break; 
			}
			else
			{
				printf("此坐标被占用"); 
			}
		} 
		else
		{
			printf("坐标非法，请重新输入"); 
		}
	}
}
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x;
	int y;
	printf("电脑下棋：>\n");
	while(1)
	{
		x=rand()%ROW;
	    y=rand()%COL;
		if(board[x][y]==' ')
			{
				board[x][y]='#';
				break; 
			}
	}
}
//判断棋盘是否满了 
int Isfull(char board[ROW][COL], int row, int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(board[i][j]==' ')
			{
				return 0;//未满 
			}
		}
	}
	return 1;//满了 
}

char IsWin(char board[ROW][COL], int row, int col)    
//可以显示4种游戏状态----->  1.玩家赢                   '*'
//                           2.电脑赢                   '#
//                           3.平局                     'Q'
//                           4.继续                     'C'
{
	int i;
	for(i=0;i<row;i++)//横3行 
	{
		if(board[i][0]==board[i][1]&&board[i][0]==board[i][2]&&board[i][0]!=' ')
		{
			return board[i][0];
		}
	} 
	for(i=0;i<col;i++)//纵3列 
	{
		if(board[0][i]==board[1][i]&&board[0][i]==board[2][i]&&board[0][i]!=' ')
		{
			return board[0][i];
		}
	}
	//两条对角线
	if(board[0][0]==board[1][1]&&board[0][0]==board[2][2]&&board[1][1]!=' ') 
	{
		return board[1][1];
	}
	if(board[2][0]==board[1][1]&&board[2][0]==board[0][2]&&board[1][1]!=' ') 
	{
		return board[1][1];
	}
	//判断是否平局
	if(1==Isfull(board, ROW, COL)) 
	{
		return 'Q';
	}
	return 'C';
} 
void game()
{
	int ret;
	//数组--存放棋盘走出信息 
	char board[ROW][COL]={0};//全部为空格
	//初始化棋盘 
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL); 
	//下棋
	while(1)
	{
		//玩家先下棋
		PlayerMove(board, ROW, COL); 
		//打印棋盘
	    DisplayBoard(board, ROW, COL);
	    //判断玩家是否赢
	    ret=IsWin(board, ROW, COL); 
		if(ret!='C')
		{
			break;
		}
	    //电脑下棋
		ComputerMove(board, ROW, COL);
		//打印棋盘
	    DisplayBoard(board, ROW, COL);
	     //判断电脑是否赢
			ret=IsWin(board, ROW, COL); 
		if(ret!='C')
		{
			break;
		}
	} 
	if(ret='*')
	{
		printf("恭喜你，你赢了\n "); 
	}
	else if(ret='#')
	{
		printf("很遗憾，电脑赢\n"); 
	}
	   else
	    {
		    printf("平局\n"); 
	    }
}
void test()
{
	int input=0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d",&input);
		switch(input)
		{
			case 1:
				printf("三子棋\n");
				game();
				break;
			case 2:
				printf("退出游戏\n");
				break;
			default:
				printf("请输入0或1\n") ;
			    break;
		}
	}while(input);
}
int main()
{
	test();
	return 0;
}
