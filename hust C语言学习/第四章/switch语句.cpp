#include <stdio.h>
int main(void)
{
	float x;
	printf("input the score x(0<=x<=100)\n");
	scanf("%f",&x);
	if(x>100||x<0)
	    printf("input error!");
	else
	    switch ((int)(x/10))
	    {
	    	case 10:printf("excellent!\n");break;
	    	case 9 :printf("excellent!\n");break;
	    	case 8 :printf("good!\n");break;
	    	case 7 :printf("middle.\n");break;
	    	case 6 :printf("middle.\n");break;
	    	case 5 :printf("Bad!\n");break;
	    	case 4 :printf("Bad!\n");break;
	    	case 3 :printf("Bad!\n");break;
		    case 2 :printf("Bad!\n");break;
		    case 1 :printf("Bad!\n");break;
		    case 0 :printf("Bad!\n");break;
		}
	return 0;
}
