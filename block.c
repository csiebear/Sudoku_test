#include <stdio.h>
int main(){
	int m,x,y;
	for(m=0;m<9;m++)
    {
		for(x=0;x<9;x++){
			for(y=0;y<9;y++){
			printf("X=%dY=%d :",x,y);
			int xx = x/3*3+m%3;
			int yy = y/3*3+m/3;
			printf("%d%d ",xx,yy);
			}
			printf("\n");
		}
	}		
	
	return 0;
}
