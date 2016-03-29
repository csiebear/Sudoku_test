#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>

using namespace std;

void Show(int b[][9]);
int Promising(int b[][9], int n);
int Tracking(int b[][9], int n);
int board[9][9];
int Sol[9*9];
int Cnt=0;
int Ans=0;
int Ans2=0;
bool rule1=false;
bool rule2=false;//not exactly one
int Solve[9][9];
clock_t start,end;

int main()
{
	int x, y;
	for (x=0;x<9;x++)
		for (y=0;y<9;y++){
			cin>>board[x][y];
			Solve[x][y]=board[x][y];
			if (board[x][y]==0)
				Sol[Cnt++] = (x<<8)+(y<<4);
		}
		Show(board);
		start=clock();
		Promising(board, 0);
		end=clock();
		double diff=(end-start);
		cout<<(diff/CLOCKS_PER_SEC)<<endl;

		if (Ans==1){
			cout<<"1"<<endl;
			Show(Solve);
		}
		else if (Ans==0) cout<<"0";
		else cout<<"2";
		return 0;
}

void Show(int b[][9])
{
	for(int x=0; x<9; x++)
		for(int y=0; y<9; y++){
		if(y==8)
			cout<<b[x][y]<<endl;
		else	cout<<b[x][y]<<" ";
	}
}
int Tracking(int b[][9], int n)
{
	int xx, yy, m, num, r;
    int x = Sol[n]>>8;
	int y = (Sol[n]>>4)&0x0F;
	for(num=1, r=0; num<=9; num++)
	{
	b[x][y] = num;
	Sol[n] = (Sol[n]&0xFF0) + num;
	for(m=0; m<9; m++)
	{
		xx = x/3*3+m%3;
		yy = y/3*3+m/3;
		if ((m!=y && b[x][m]==b[x][y]) || (m!=x && b[m][y]==b[x][y])|| (x!=xx && y!=yy && b[xx][yy]==b[x][y]))
			break;
	}if (m==9 && Promising(b, n+1)) r=1;
	}
	b[x][y]=0;
	Sol[n]&=0xFF0;
	return r;
}

int Promising(int b[][9], int n)
{
	if(Ans2<=2){
		if (n<Cnt) return Tracking(b, n);
	}else return 1;
//when we have at least one we go into this function
	if (++Ans==1){
			rule1=true;
			int x,tempx,tempy,tempnum;
			for(int x=0;x<81;x++){
				if(Solve[x/9][x%9]==0)
					Solve[x/9][x%9]=(Sol[x]&0x0F);
			}
	}
	if(++Ans2>=2)
		rule2=true;
	return 1;
}
