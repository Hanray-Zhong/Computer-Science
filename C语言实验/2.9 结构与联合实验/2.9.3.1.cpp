#include<stdio.h>
struct bits
{
    unsigned char bit0:1, bit1:1, bit2:1, bit3:1, bit4:1, bit5:1, bit6:1, bit7:1;
}b;
union Bits{
    unsigned char c;
    struct bits b;
    }B;
void f0(struct bits b)  {
    printf("the 1 function %d is called!\n", b.bit0); }
void f1(struct bits b) {
    printf("the 2 function %d is called!\n", b.bit1);}
void f2(struct bits b) {
    printf("the 3 function %d is called!\n", b.bit2); }
void f3(struct bits b){
    printf("the 4 function %d is called!\n", b.bit3);}
void f4(struct bits b){
    printf("the 5 function %d is called!\n", b.bit4);}
void f5(struct bits b){
    printf("the 6 function %d is called!\n", b.bit5);}
void f6(struct bits b){
    printf("the 7 function %d is called!\n", b.bit6);}
void f7(struct bits b){
    printf("the 8 function %d is called!\n", b.bit7);}
int main()
{
    void (*p_fun[8])(struct bits b);
    p_fun[0] = f0;
    p_fun[1] = f1;
    p_fun[2] = f2;
    p_fun[3] = f3;
    p_fun[4] = f4;
    p_fun[5] = f5;
    p_fun[6] = f6;
    p_fun[7] = f7;
    printf("input char: ");
    B.c=getchar();
    getchar();
    if(B.b.bit0) p_fun[0](B.b);
    if(B.b.bit1) p_fun[1](B.b);
    if(B.b.bit2) p_fun[2](B.b);
    if(B.b.bit3) p_fun[3](B.b);
    if(B.b.bit4) p_fun[4](B.b);
    if(B.b.bit5) p_fun[5](B.b);
    if(B.b.bit6) p_fun[6](B.b);
    if(B.b.bit7) p_fun[7](B.b);
    getchar();
    return 0;
}
