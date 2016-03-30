#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define Size 81
using namespace std;

void Show(int b[81]);
int Promising(int b[81], int n);
int Tracking(int b[81], int n);

int Sol[Size];
int Cnt=0;
int Ans=0;
int board[Size];
int solve[Size];

int main()
{
	int x, row,col;
	for (x=0;x<Size;x++){
		row=x/9;
		col=x%9;
		cin>>board[x];
		if (board[x]==0)
        	Sol[Cnt++] = (row<<8)+(col<<4); 
	}  
//	Show(board);
	Promising(board, 0);
	if (Ans==1){
		cout<<"1"<<endl;
		Show(solve);
		return 0;
	}
	else if (Ans==0) cout<<"0"<<endl;
	else cout<<"2"<<endl;;
	return 0;
}

void Show(int b[81])
{
	for(int x=0; x<Size; x++){
			if((x%9)==8){
				cout<<b[x]<<endl;
			}else
				cout<<b[x]<<" ";

	}
}
  

int Tracking(int b[81], int n)
{
  int xx, yy, m, num, r;
  int x = Sol[n]>>8;
  int y = (Sol[n]>>4)&0x0F;
  for(num=1, r=0; num<=9; num++)
  {
    b[x*9+y] = num;
    Sol[n] = (Sol[n]&0xFF0) + num;
    for(m=0; m<9; m++)
    {
      xx = x/3*3+m%3;
      yy = y/3*3+m/3;
      if ((m!=y && b[x*9+m]==b[x*9+y]) || (m!=x && b[m*9+y]==b[x*9+y])
          || (x!=xx && y!=yy && b[xx*9+yy]==b[x*9+y]))
        break;
    }
    if (m==9 && Promising(b, n+1)) r=1;
  }
     b[x*9+y]=0;
     Sol[n]&=0xFF0;
         return r;
         }

int Promising(int b[81], int n)
{
	int j;
	if(Ans<2){
	if (n<Cnt) return Tracking(b, n);
	//-- solution is found
    if (++Ans<2){
		for(j=0;j<Size;j++)
			solve[j]=b[j];
	}
	else
    	return 1;
	}
}
