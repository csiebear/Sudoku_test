#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

//parameter
bool cols[10][10];
bool rows[10][10];
bool blocks[10][10];
int board[10][10];
//record the blank should be solved
struct blank{
	int b_row;
	int b_col;
};//must end with ;
//at most 81 digits
blank blanks[81];
//function declaration
int sudoku(int);
int topBlock[10][10];
int remaining;//the number remaining(equal 0)
int remain;
int solveTimes;
bool solved;//the status solved(true)/unsolved(false)
bool no_solve;//mean no solution
void init();
void ReadIn();
void PrintData();
void Solve();
int subSolve(int);

int main(){
	init();
	ReadIn();
	PrintData();
	Solve();
}

void init(){
	remaining=0;
	solved=false;
	no_solve=false;
	solveTimes=0;
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			cols[i][j]=false;
			rows[i][j]=false;
			blocks[i][j]=false;
			topBlock[i][j]= ( (i-1)/3*3+ (j-1)/3 )+1;
		}
	}
}

void ReadIn(){
	int temp;
	int B;

	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			cin>>board[i][j];
			temp=board[i][j];
			if(board[i][j]==0){
				blanks[remaining].b_row=i;
				blanks[remaining].b_col=j;
				remaining++;
			}else if(!no_solve){
				B=topBlock[i][j];
				if(!rows[i][temp]&&!cols[j][temp]&&!blocks[B][temp]){	
					rows[i][temp]=true;
					cols[j][temp]=true;
					blocks[B][temp]=true;
				}else{
					no_solve=true;
				}
			}
		
		}
	}
}
void PrintData(){
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			cout<<board[i][j]<<" ";
			if(j==9)
				cout<<endl;
		}
	}
}
void Solve(){
	remain=remaining;
	if(no_solve==true){
		cout<<"0"<<endl;
	}
	else if(remain==0){
		solved=true;
		cout<<"1"<<endl;
		PrintData();
	}else{
		subSolve(remain);
		
	}
}

int subSolve(int remain){
	if(solved){
		return 0;
	}
	if(remain==0){
		solved=true;
		solveTimes++;
		cout<<"1"<<endl;
		PrintData();	
	}
	for(int k=1;(k<=9 && !solved) ; k++){
        int B=topBlock[blanks[remaining-remain].b_row][blanks[remaining-remain].b_col];
        if(!rows[blanks[remaining-remain].b_row][k]&&!cols[blanks[remaining-remain].b_col][k]&&!blocks[B][k])
		{        
			rows[blanks[remaining-remain].b_row][k]=true;
			cols[blanks[remaining-remain].b_col][k]=true;
			blocks[B][k]=true;
			board[blanks[remaining-remain].b_row][blanks[remaining-remain].b_col]=k;
	        subSolve(remain-1);
	        rows[blanks[remaining-remain].b_row][k]=false;
		    cols[blanks[remaining-remain].b_col][k]=false;
			blocks[B][k]=false;
			board[blanks[remaining-remain].b_row][blanks[remaining-remain].b_col]=0;
		}
	}
}
