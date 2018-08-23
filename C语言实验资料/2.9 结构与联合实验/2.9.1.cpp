 #include<iostream>
char u[]="UVWXYZ";
char v[]="xyz";
struct T{
	int x;
	char c;
	char *t;
}a[]={{11,'A',u},{100, 'B',v}},*p=a;
int main(void)
{
	printf("(++p)->x=%d\n",(++p)->x);
	p=a;
	p++;
	printf("p++,p->c=%c\n",p->c);
	p=a;
	printf("*p++->t=%c ",*p++->t);
	printf("*p->t=%c\n",*p->t);
	p=a;
	printf("*(++p)->t=%c\n",*(++p)->t);
	p=a;
	printf("*++p->t=%c\n",*++p->t);
	p=a;
	char u[]="UVWXYZ";
    char v[]="xyz";
    struct T{
	int x;
	char c;
	char *t;
    }a[]={{11,'A',u},{100, 'B',v}},*p=a;
	printf("++*p->t=%c\n",++*p->t);
	getchar();
	return 0;
}
