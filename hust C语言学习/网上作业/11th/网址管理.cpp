#include<stdio.h>
int main(void)
{
	int N,i,j;
	char c;
	scanf("%d",&N);
	struct Web
    {
	    char simple_name[20];
	    char full_name[40];
	    char URL[80];
    }t,name[N];
	for(i=0;i<N;i++)
		scanf("%s %s %s",name[i].simple_name,name[i].full_name,name[i].URL);
	for(i=0;i<N;i++) 
	    printf("%-20s%-40s%s\n",name[i].simple_name,name[i].full_name,name[i].URL); 
	printf("\n");
	
	char first_letter[N];
    for(i=0;i<N;i++)
    {
    	if(name[i].simple_name[0]>='a'&&name[i].simple_name[0]<='z')
    	    first_letter[i]=name[i].simple_name[0]-'a'+'A';
    	else
    	    first_letter[i]=name[i].simple_name[0];
	}
	
	j=0;
	while(j<=N-1)                      //Ã°ÅÝ·¨ÅÅÐò  
    {
        for(i=0;i<=N-2;i++)
        {
	        if(first_letter[i]>first_letter[i+1])
    	    {
                t=name[i];
                name[i]=name[i+1];
                name[i+1]=t;
                c=first_letter[i];
                first_letter[i]=first_letter[i+1];
                first_letter[i+1]=c;
            }
	    }
        j++;
    }
	for(i=0;i<N;i++) printf("%-20s%-40s%s\n",name[i].simple_name,name[i].full_name,name[i].URL);
	return 0;
}
