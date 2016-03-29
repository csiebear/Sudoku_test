#include <cstdlib>
#include <cstdio>
#include <iostream>
#define M 9
using namespace std;

bool cols[9][9];
bool rows[9][9];
bool blocks[9][9];
int now_map[9][9];
struct blank{
	       int b_row;
		          int b_col;
				         };
blank blanks[81];
int sudoku(int);

int block_j(int, int, int);
int remaining;
bool solved;
bool no_solve;
int main()
{
	    remaining=0;
		    solved=false;
			    no_solve=false;
				    for(int i=0; i<9; i++){
								for(int j=0; j<9; j++){
												cols[i][j]=false;
															rows[i][j]=false;
																		blocks[i][j]=false;
																				}
									}//9*9 cols rows blocks all false
					    for(int i=0; i<9; i++)
									for(int j=0; j<9; j++)
										        {
																cin>>now_map[i][j];  
																			if(now_map[i][j]==0){
																								blanks[remaining].b_row=i;
																												blanks[remaining].b_col=j;                    
																																remaining++;
																																			}
																						else if(!no_solve)
																										{
																														int B=block_j(i, j, 9); 
																																	if(!rows[i][now_map[i][j]-1]&&!cols[j][now_map[i][j]-1]&&!blocks[B][now_map[i][j]-1]){        
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
										    
										    else
												    {
														    int temp;
															    scanf("%d", &temp);
																    printf("1\n");
																	    }
    return 0;
	}

int sudoku(int remain)
{

	    if(solved)
			    {
					    return 0;
							}
		    if(remain==0)
				    {
						    for(int i=0; i<9; i++){
										for(int j=1; j<9; j++){
														printf("%d", now_map[i][j]);
																	if(j==8)
																						printf("\n");
																			}
											}
							    solved=true;
								    return 0;
										}
			        for(int k=0; k<9 && !solved; k++)
						        {
									        int B=block_j(blanks[remaining-remain].b_row, blanks[remaining-remain].b_col, 3);    

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
															}
						}

int block_j(int row, int col, int len)
{
	    int block;
		    block=((row/len)*len)+col/len;
			    return block;
}
/*refer:http://www.student.tw/topic/84400-%E3%80%90%E5%95%8F%E9%A1%8C%E3%80%91%E8%AB%8B%E5%95%8F%E6%95%B8%E7%8D%A8%E7%9A%84c%E6%80%8E%E9%BA%BC%E5%AF%AB/*/
