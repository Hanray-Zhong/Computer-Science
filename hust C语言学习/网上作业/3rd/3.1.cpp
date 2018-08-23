#include <stdio.h>
int main(void)
{
	int N,i;
	char ch;
	
	scanf("%d",&N);
	getchar();
	for(i=1;i<=N;i++)
	{
	    scanf("%c",&ch);
	    getchar();
		if(ch>='0'&&ch<='9')
	    printf("%c\n",ch);
	    else if((ch>='a'&&ch<='f')||(ch>='A')&&(ch<='F')){
		    switch(ch)
		    {
			    case 'a':printf("10\n");break;
			    case 'b':printf("11\n");break;
			    case 'c':printf("12\n");break;
			    case 'd':printf("13\n");break;
			    case 'e':printf("14\n");break;
			    case 'f':printf("15\n");break;
			    case 'A':printf("10\n");break;
			    case 'B':printf("11\n");break;
			    case 'C':printf("12\n");break;
			    case 'D':printf("13\n");break;
			    case 'E':printf("14\n");break;
			    case 'F':printf("15\n");break;
		    }
	    }
	    else
	    printf("%d\n",ch);
	}
	return 0;
}
