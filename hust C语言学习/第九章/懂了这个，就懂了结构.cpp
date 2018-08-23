#include <stdio.h>
struct motion
{
	double size;
	char dimension[12];
};

struct motion get_motion(void);
struct motion add_motion(struct motion u,struct motion v);

double get_motion_size(struct motion u);
double add_motion_size(double, double);
int cmp_dimension(char *,char *);
void mystrcpy(char *,char *);
int main(void)
{
	struct motion b={12.5,"m/s"}, c={26.7,"m/s"},d;
	b=get_motion();
	printf("b.size=%lf\t",b.size);
	printf("b.dimension is %s",b.dimension);
	d=add_motion(b,c);
	printf("d.size=%lf\t",d.size);
	printf("d.dimension is %s",d.dimension);
	d.size=get_motion_size(b);
	printf("d is %lf%s\n",d.size,d.dimension);
	d.size=add_motion_size(d.size, c.size);
	printf("d is %lf%s\n",d.size,d.dimension);
	return 0;
} 

struct motion get_motion(void)
{
	struct motion a;
	printf("input the value of member size and dimension\n");
	scanf("%lf",&a.size);
	scanf("%s",a.dimension);
	return a;
}

struct motion add_motion(struct motion u,struct motion v)
{
	struct motion a;
	if(!cmp_dimension(a.dimension,u.dimension))
	{
		a.size=u.size+v.size;
		mystrcpy(a.dimension,u.dimension);
	}
	else
	{ 
		printf("dimension of the member is conflicting! can't adding...\n");
		a.size=0;
		mystrcpy(a.dimension,"");
	}
	return a;
}

int cmp_dimension_size(char *s,char *t)
{
	while(*s==*t && *s!='\0')
	    s++,t++;
	return *s-*t;
}

void mystrcpy(char *s,char *t)
{
	char *p=s,*q=t;
	while(*p++=*q++);
}

double get_motion_size(struct motion u)
{
	return u.size;
}

double add_motion_size(double x,double y)
{
	return x+y;
}
