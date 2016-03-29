#include <cstdlib>
#include <cstdio>
#define MAX 9
using namespace std;

bool cols[MAX][MAX];
bool rows[MAX][MAX];
//information
bool blocks[MAX][MAX];
//blocks information
int now_map[MAX][MAX];
//map information
struct blank{
	int b_row;
    int b_col;
};
	blank blanks[MAX*MAX];
//blank structure
int sudoku(int);
int block_j(int, int, int);
int N;
int remaining;
bool solved;
bool no_solve;

int main(int argc, char *argv[])
{
    bool P=false;
    while(scanf("%d", &N)!=EOF)
	{
	    if(P)
	    putchar('\n');
	    P=true;
	    if(N!=1){
        remaining=0;
 		solved=false;
        no_solve=false;
        for(int i=0; i<N*N; i++)
        for(int j=0; j<N*N; j++)
        cols[i][j]=false;
        for(int i=0; i<N*N; i++)
        for(int j=0; j<N*N; j++)
        rows[i][j]=false;
        for(int i=0; i<N*N; i++)
        for(int j=0; j<N*N; j++)
        blocks[i][j]=false;
//initialization
        for(int i=0; i<N*N; i++)
        for(int j=0; j<N*N; j++)
        {
        scanf("%d", &now_map[i][j]);  
        if(now_map[i][j]==0){
        blanks[remaining].b_row=i;
        blanks[remaining].b_col=j;
		}
        else if(!no_solve)
        {
        int B=block_j(i, j, N); 
        if(!rows[i][now_map[i][j]-1]&&!cols[j][now_map[i][j]-1]&&!blocks[B][now_map[i][j]-1])
        {        
         rows[i][now_map[i][j]-1]=true;
	     cols[j][now_map[i][j]-1]=true;
	     blocks[B][now_map[i][j]-1]=true;
	    }else{
	    no_solve=true;
        }
		}
        }
		if(!no_solve)
		sudoku(remaining);
			if(!solved||no_solve)
		    printf("NO SOLUTION\n");
		    }
		    else
		    {
		    int temp;
		    scanf("%d", &temp);
		    printf("1\n");
		    }
		    }
	return 0;
}
int sudoku(int remain){
    if(solved)
		    {
				    return 0;
			}
	if(remain==0)
	{

	for(int i=0; i<N*N; i++)
	{
	printf("%d", now_map[i][0]);
    for(int j=1; j<N*N; j++)
	printf(" %d", now_map[i][j]);
	putchar('\n');
	}
    solved=true;

    return 0;
	}
for(int k=0; k<N*N&&!solved; k++)
{
    int B=block_j(blanks[remaining-remain].b_row, blanks[remaining-remain].b_col, N);    

if(!rows[blanks[remaining-remain].b_row][k]&&!cols[blanks[remaining-remain].b_col][k]&&!blocks[B][k])
{        
	rows[blanks[remaining-remain].b_row][k]=true;
	cols[blanks[remaining-remain].b_col][k]=true;
	blocks[B][k]=true;
	now_map[blanks[remaining-remain].b_row][blanks[remaining-remain].b_col]=k+1;

    sudoku(remain-1);
	rows[blanks[remaining-remain].b_row][k]=false;
    cols[blanks[remaining-remain].b_col][k]=false;
	blocks[B][k]=false;
	now_map[blanks[remaining-remain].b_row][blanks[remaining-remain].b_col]=0;
}
}}
int block_j(int row, int col, int len)
{
	int block;
    block=((row/len)*len)+col/len;
    return block;
}
