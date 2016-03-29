#include <stdlib.h>
#include <stdio.h>
#include <math.h> 
#define N 9
 
typedef struct{
	               char c[9];
				                  int lenth;
								                           }element;
int count=0;
int ans=0;
 
void printx(char a[N][N]);
void print(char a[N][N]);
int row(char a[N][N],char x,int i);
int column(char a[N][N],char x,int j);
int block(char a[N][N],char x,int i,int j);
void ele(char a[N][N],element b[N][N]);
void sudu(char a[N][N],element b[N][N],int i,int j);
 
int main()
{  
	    int i,j,r,s;
		    char check;
			    char a[N][N]={'n','n','n','n','n','n','n','n','n',
					                  'n','n','n','n','n','n','n','n','n',
									                    'n','n','n','n','n','n','n','n','n',
														                  'n','n','n','n','n','n','n','n','n',
																		                    'n','n','n','n','n','n','n','n','n',
																							                  'n','n','n','n','n','n','n','n','n',
																											                    'n','n','n','n','n','n','n','n','n',
																																                  'n','n','n','n','n','n','n','n','n',
																																				                    'n','n','n','n','n','n','n','n','n'};
				    printf("*********歡迎使用數獨解答程式1.0版，作者Ewestein**********\n");
					    printf("*                                                        *\n");          
						    printf("*1.請開始輸入數字(1 ~ 9)，由左而右，由上到下(Row Major)。*\n");
							    printf("*2.若為空白請鍵入'n'(null)。                             *\n");  
								    printf("*3.若要更改前次數值請鍵入'b'(back)。                     *\n");  
									    printf("*4.若要直接開始請鍵入's'(start)。                        *\n");
										    printf("*5.若要直接結束程式請鍵入'e'(exit)。                     *\n");
											    printf("*                                                        *\n");
												    printf("**********************************************************\n\n\n");
													    for(i=0;i<N;i++)
															       for(j=0;j<N;)
																	          { a[i][j+1]='\0';           
																				           printf("請輸入第(%d,%d)格數字:",i+1,j+1);             
																						            scanf("%s",&check);
																									         if(check=='e')
																												             exit(0);
																											          if(check!='n' && check!='b' && check!='s')
																														             if(check>'9' || check<'1')
																																		               {
																																						                    system("cls"); 
																																											                 printx(a);       
																																															                  printf("請輸入1~9之數字!\n");     
																																																			                   continue;
																																																							                 }         
																													          
																													            if(row(a,check,i))
																																	            if(column(a,check,j)) 
																																					              if(block(a,check,i,j))  
																																									                  {   a[i][j]=check;
																																														                      if(a[i][j]=='s')
																																																				                      { 
																																																										                         for(r=i+1;r<N;r++)
																																																																	                            for(s=0;s<N;s++)
																																																																									                             a[r][s]='n';
																																																																                        for(s=j;s<N;s++)
																																																																							                             a[i][s]='n';     
																																																																						                            
																																																																						                       goto start;            
																																																																											                       }
																																																			                      if(a[i][j]=='b')
																																																									                        {  
																																																																                       for(r=i+1;r<N;r++)
																																																																						                            for(s=0;s<N;s++)
																																																																														                           a[r][s]='n';
																																																																					                          for(s=j;s<N;s++)
																																																																												                           a[i][s]='n';  
																																																																											                           if(j>0)
																																																																																		                              j=j-2;
																																																																																	                            else
																																																																																									                          {
																																																																																																                             i=i-1;
																																																																																																							                            j=(N-2)   ;
																																																																																																														                          }    
																																																																																								                          a[i][j+1]='\0';
																																																																																														                        }
																																																								                      system("cls"); 
																																																													                      printx(a);
																																																																		                      j++;
																																																																							                   }
																																            else { system("cls"); printx(a); printf("不好意思，此數值在同一個九宮格已經使用過\n");}
																																           else { system("cls"); printx(a); printf("不好意思，此數值在同行已經使用過\n");} 
																																         else  { system("cls"); printx(a); printf("不好意思，此數值在同列已經使用過\n");}
																																		       }
														        
														      
														          
														    start:         
														    printf("\n\n這是你輸入的原始數據:\n");           
															    print(a);
																    printf("若正確請按Enter開始分析:\n\n");
																	    system("pause");
																		 
																		    
																		    element b[N][N];
																			    ele(a,b);
																				 
																				    sudu(a,b,0,0);
																					   
																					    if(ans==0)
																							      printf("\n\n***非常抱歉，此題無解****\n\n");
																						   system("pause");
																						      return 0; 
}
 
void sudu(char a[N][N],element b[N][N],int i,int j)
{   
	     count++;
		      int next_i,next_j,v,q,flag=1,space=0;
			       int p;
				        char r;
						     char c[N][N];
							      int copy_i,copy_j;
								       for(copy_i=0;copy_i<N;copy_i++)
										           for(copy_j=0;copy_j<N;copy_j++)
													             c[copy_i][copy_j]=a[copy_i][copy_j];   
									       
									        if(i==N)   
												       {
														             printf("\n\n電腦一共計算了%d種組合\n\n",count);
																	           for(v=0;v<N;v++)
																				                for(q=0;q<N;q++)
																									               if(c[v][q]=='n')
																													                   {
																																		                     flag=0;      
																																							                   space++;
																																											                   }  
																			             if(flag==1)
																							           { 
																										                ans++;         
																														         
																														             printf("解答%d:\n",ans);       
																																	              print(c);
																																				             } 
																						          
																						        }  
											     else
													      {
															                if(j<(N-1))
																				                {
																									                  next_i=i;
																													                    next_j=j+1;
																																		                }
																			               else
																							                   {
																												                     next_i=i+1;
																																	                   next_j=0;
																																					                   }   
																						       
																						            if(c[i][j]=='n')
																										         {
																													             for(p=0;p<b[i][j].lenth;p++)
																																	             {
																																					               r=b[i][j].c[p];                        
																																								                  if(row(c,r,i))
																																													                   if(column(c,r,j))
																																																		                      if(block(c,r,i,j))
																																																								                     { 
																																																														                        c[i][j]=r;
																																																																				                        sudu(c,b,next_i,next_j); 
																																																																										                   }
																																												                   
																																												                    
																																												              }
																																          }
																									        else
																												         sudu(c,b,next_i,next_j);
																											     }
												                        
}
 
void ele(char a[N][N],element b[N][N])
{
	 
	    int i,j,k,r,s,t,u;            
		    char l;
			    int flag=1;
				   
				    while(flag==1)
						    {
								        flag=0;         
										        for(i=0;i<N;i++) 
													          for(j=0;j<N;j++)
																            {
																				             for(k=0,l='1';k<N;k++,l++)
																								                 b[i][j].c[k]=l;
																							              b[i][j].lenth=0;    
																										            }          
												        for(i=0;i<N;i++) 
															          for(j=0;j<N;j++)
																		              for(k=0;k<N;k++)
																						                if(a[i][k]!='n')
																											              b[i][j].c[a[i][k]-49]='0';
														        for(i=0;i<N;i++) 
																	          for(j=0;j<N;j++)
																				              for(k=0;k<N;k++)
																								                if(a[k][j]!='n')
																													              b[i][j].c[a[k][j]-49]='0';
																         for(i=0;i<N;i++) 
																			           for(j=0;j<N;j++)
																						             {
																										               if(i>2)
																														                   if(i>5)
																																			                      r=6;
																													                   else r=3;
																													                 else r=0;
																																	    
																																	               if(j>2)
																																					                   if(j>5)
																																										                      s=6;
																																				                   else s=3;
																																				                 else s=0;  
																																								          
																																								              for(t=r;t<r+3;t++)
																																												                 for(u=s;u<s+3;u++)
																																																	                 if(a[t][u]!='n')
																																																						                  b[i][j].c[a[t][u]-49]='0';                 
																																											            }              
																		      
																		      
																		          for(i=0;i<N;i++) 
																					             for(j=0;j<N;j++)
																									            {
																													              for(k=0;k<N-1;k++)
																																	                {int p=1;
																																						                while(b[i][j].c[k]=='0')
																																											                 {                                      
																																																                   b[i][j].c[k]= b[i][j].c[k+p];
																																																				                     b[i][j].c[k+p]='0';
																																																									                   p++;
																																																													                     if((k+p)>8)
																																																																			                    break;
																																																																		                  }
																																										              }
																																             }               
																				     
																				          for(i=0;i<N;i++) 
																							            for(j=0;j<N;j++)
																											             for(k=0;k<N;k++)
																															                 if(b[i][j].c[k]!='0')
																																				                  b[i][j].lenth++;
																						        
																						          for(i=0;i<N;i++) 
																									            for(j=0;j<N;j++)
																													             for(k=0;k<N;k++)
																																	                   if(b[i][j].lenth==1)   
																																						                        if(a[i][j]=='n')
																																													                     {
																																																			                         a[i][j]=b[i][j].c[0];
																																																									                         flag=1;
																																																															                      }
																								      }              
					      
					 
					      printf("\n\n\n各位置的可能元素有:\n")    ;
						         for(i=0;i<N;i++) 
									           for(j=0;j<N;j++)
												                {
																	             printf("(%d,%d)={",i+1,j+1);            
																				              for(k=0;k<N;k++)
																								                   printf("%c",b[i][j].c[k]) ;
																							               printf("}  可能元素有=%d種",b[i][j].lenth); 
																										               printf("\n");
																													                } 
								         
}    
 
int row(char a[N][N],char x,int i)
{
	    int j,flag=1;
		    if(x=='n')
				     return flag;
			    for(j=0;j<N;j++)
					     if(x==a[i][j])
							        flag=0;
				    return flag;  
}
 
int column(char a[N][N],char x,int j)
{
	    int i,flag=1;
		    if(x=='n')
				     return flag;
			    for(i=0;i<N;i++)
					     if(x==a[i][j])
							        flag=0;
				    return flag;  
}
 
int block(char a[N][N],char x,int i,int j)
{
	    int r,s,flag=1;
		    if(x=='n')
				     return flag;
			    if(i>2)
					      if(i>5)
							          i=6;
				      else i=3;
				    else i=0;
					   
					    if(j>2)
							      if(j>5)
									          j=6;
						      else j=3;
						    else j=0;  
							         
							 
							   
							    for(r=i;r<(i+3);r++)
									      for(s=j;s<(j+3);s++)
											         if(x==a[r][s])
														         flag=0;
								    return  flag; 
}   
 
void print(char a[N][N])
{
	     int i,j;
		     
		       for(i=0;i<N;i++)
				       {
						        printf(" ");              
								     for(j=0;j<N;j++)
										      {         
												         if(j==(N)/sqrt(N) || j==2*(N)/sqrt(N) )
															        printf("  ");             
														        printf("---");
																       
																     }
									      if(i==(N)/sqrt(N) || i==2*(N)/sqrt(N) )
											       {
													         printf("\n");
															       printf(" ");          
																         for(j=0;j<N;j++)
																			        {
																						        if(j==(N)/sqrt(N) || j==2*(N)/sqrt(N) )
																									       printf("  ");   
																								       printf("---");              
																									          }
																		      }  
										       printf("\n");
											     
											                       
											        for(j=0;j<N;j++)
														     {
																         if(j==(N)/sqrt(N) || j==2*(N)/sqrt(N) )
																			        printf("｜");         
																		        if(a[i][j]!='n')   
																					       printf("｜%c",a[i][j]);
																				       else
																						          printf("｜ ");
																					        } 
													     printf("｜\n");
														     } 
			          printf(" ");
					        for(i=0;i<N;i++)
								      {
										          if(i==(N)/sqrt(N) || i==2*(N)/sqrt(N) )              
													         printf("  ");
												         printf("---");
														       }
							       printf("\n");
}
 
void printx(char a[N][N])
{
	     int i,j;
		     
		       for(i=0;i<N;i++)
				       {
						        printf(" ");              
								     for(j=0;j<N;j++)
										      {         
												         if(j==(N)/sqrt(N) || j==2*(N)/sqrt(N) )
															        printf("  ");             
														        printf("---");
																       
																     }
									      if(i==(N)/sqrt(N) || i==2*(N)/sqrt(N) )
											       {
													         printf("\n");
															       printf(" ");          
																         for(j=0;j<N;j++)
																			        {
																						        if(j==(N)/sqrt(N) || j==2*(N)/sqrt(N) )
																									       printf("  ");   
																								       printf("---");              
																									          }
																		      }  
										       printf("\n");
											     
											                       
											        for(j=0;j<N;j++)
														     {
																         if(j==(N)/sqrt(N) || j==2*(N)/sqrt(N) )
																			        printf("｜");         
																		        if(a[i][j]!='n')   
																					       printf("｜%c",a[i][j]);
																				       else
																						          printf("｜x");
																					        } 
													     printf("｜\n");
														     } 
			          printf(" ");
					        for(i=0;i<N;i++)
								      {
										          if(i==(N)/sqrt(N) || i==2*(N)/sqrt(N) )              
													         printf("  ");
												         printf("---");
														       }
							       printf("\n");
}
