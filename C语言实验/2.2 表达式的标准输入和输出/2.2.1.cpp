#include<stdio.h>
#define PI 3.14159                                       //1st        
int main( void )                                        //2nd
{
   int f ;
   short p, k ;
   double c , r , s ;

/* for task 1 */
   printf("Input  Fahrenheit:" ) ;
   scanf("%d", &f ) ;                                   //3rd
   c = 5.0/9*((double)f-32) ;                       //4th
   printf( " \n %d (F) = %.2f (C)\n\n ", f, c ) ;

/* for task 2 */
printf("input the radius r:");                         
scanf("%lf", &r);                                       //5th
s = PI * r * r;
printf("\nThe acreage is %.2f\n\n",s);                 //6th

/* for task 3 */
printf("input hex int k, p :");
scanf("%x %x", &k, &p);                              
short newint;                                            //7th
newint = (p&0xff00)|(k&0xff00)>>8;                    //8th
printf("new int = %x\n\n",newint);
}

