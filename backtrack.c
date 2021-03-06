#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void Show(int b[][9]);
int Promising(int b[][9], int n);
int Tracking(int b[][9], int n);

int Sol[9*9];
int Cnt=0;
int Ans=0;
int board[9][9];

int main()
{
	int x, y;
	for (x=0;x<9;x++)
		for (y=0;y<9;y++){
		cin>>board[x][y];
		if (board[x][y]==0){
        	Sol[Cnt++] = (x<<8)+(y<<4);} 
	}  
	printf( "\n數獨題目為 --\n" );
	Show(board);
	Promising(board, 0);
	if (Ans==1) printf( "\n這是唯一解的標準數獨題目!!\n" );
	else if (Ans==0) printf( "\n此題無解!!\n" );
	else printf( "\n此題有 %d組多重解!!\n", Ans );
	return 0;
}

void Show(int b[][9])
{
	for(int x=0; x<9; x++)
		for(int y=0;y<9;y++){
			if(y==8){
				cout<<board[x][y]<<endl;
			}else
				cout<<board[x][y]<<" ";
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
      if ((m!=y && b[x][m]==b[x][y]) || (m!=x && b[m][y]==b[x][y])
          || (x!=xx && y!=yy && b[xx][yy]==b[x][y]))
        break;
    }
    if (m==9 && Promising(b, n+1)) r=1;
  }
     b[x][y]=0;
       Sol[n]&=0xFF0;
         return r;
         }

int Promising(int b[][9], int n)
{
	if (n<Cnt) return Tracking(b, n);
	//-- solution is found
    if (++Ans<2) // 限制只顯示第一組解答
	{
    printf("\n得到第 %d組解答:\n", Ans);
    Show(b);
	cout<<Cnt<<endl;
    for(n=0; n<Cnt; n++)
		cout<<((Sol[n]>>8)+1)<<(((Sol[n]>>4)&0x0F)+1)<<(Sol[n]&0x0F)<<" ";
	}
    return 1;
}
