#include <stdio.h>
#include <stdlib.h>
#include <iostream>

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

int main()
{
	int x, y;
	for (x=0;x<9;x++)
		for (y=0;y<9;y++){
			cin>>board[x][y];
			if (board[x][y]==0)
				Sol[Cnt++] = (x<<8)+(y<<4);
		}
		Show(board);
		Promising(board, 0);
		if (Ans==1){
			cout<<"1"<<endl;
			Promising(board,0);
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
			cout<<board[x][y]<<endl;
		else	cout<<board[x][y]<<" ";
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
		if (n<Cnt) return Tracking(b, n);

//when we have at least one we go into this function
	if (++Ans>=1){
			rule1=true;
					if(++Ans2>=2){
								rule2=true;
										}
											}
												if(rule2==true && rule2==false){
														Show(b);
															}	
																return 1;
																}
