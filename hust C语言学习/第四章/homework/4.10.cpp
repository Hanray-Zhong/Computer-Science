#include <stdio.h>
int main(void)
{
	double i=1.0;
	double a_quater_pi=0;
	
	
	do {
		if(!((int)i%2))
		    a_quater_pi=a_quater_pi-1.0/(2.0*i-1.0);
		else
		    a_quater_pi=a_quater_pi+1.0/(2.0*i-1.0);
		i++;
	}while((1.0/(2.0*i-1.0))>=1e-5);
	if(!((int)i%2))
		a_quater_pi=a_quater_pi-1.0/(2.0*i-1.0);
	else
		a_quater_pi=a_quater_pi+1.0/(2.0*i-1.0);
	printf("%.9lf",(double)4.0*a_quater_pi);
	return 0;
}
