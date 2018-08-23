#include<stdio.h>
#define I 2
#define J 3
#define K 4
int main(void)
{
	int v[I][J][K],*p,n=1;
	int i,j,k;
	p=&v[0][0][0];
	for(i=0;i<I;i++)
	    for(j=0;j<J;j++)
	        for(k=0;k<K;k++)
	            *(p+i*J*K+j*K+k)=n++;                   //指针多维数组的表示方式 
	for(i=0;i<I;i++){
	    for(j=0;j<J;j++){
	        for(k=0;k<K;k++)
	            printf("%4d",*(v[i][j]+k));            //*(v[i][j]+k) 等价于 v[i][j][k]
     	    printf("\n");
     	}
     	printf("\n");
    }
    return 0; 
}
