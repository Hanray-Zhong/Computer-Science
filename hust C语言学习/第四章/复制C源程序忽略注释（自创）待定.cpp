#include <stdio.h>
enum step{copy,stop,cancel,again};
int main(void)
{
	char c;
	enum step i;
	printf("Input  C program end with ctrl+z:\n");
	c=getchar();
	while(c!=EOF)
	{
		if((c!='/')&&(c!='*'))
		i=copy;
		else if(c=='/')
		{
			c=getchar();
			if(c!='*')
			{
			    putchar('/');
			    i=copy;
		    }
		    else
		        i=stop;
		}
		else
		{
			c=getchar();
			if(c!='/')
				i=cancel;
			else
			    i=again;
		}
		
		switch(i)
		{
			case copy:
			    putchar(c);
				break;
			case stop:
			    c=getchar();
			    i=cancel;
			case cancel:
			    c=getchar();
			    i=cancel;
			case again:
				break;
		}
		c=getchar();
	}
	return 0;
}
