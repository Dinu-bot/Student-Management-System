#include<stdio.h>
int add(int a ,int b);

int main(){

int sum = add(4,5);
printf("%d" , sum);

return 0;
}

int add( int a ,int b){



int sum = a + b;

return sum;
}