#include<stdio.h>
int main(){
	static int x[5] = {10,11,12,13,14};
	int i;
	for (i = 0 ; i < 5 ; ++i ){
		printf("\n i = %d x[i] = %d*(x+i) = %d &x[i] = %X x+i =%X " , i , x[i] , *(x+i) , &x[i] , x+i);
	}
	
	
}