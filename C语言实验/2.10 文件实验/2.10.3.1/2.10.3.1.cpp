#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp;
    char a[80];
    int i=0;
    fp=fopen("test.txt","w");
    gets(a);
    while(a[i]!='\0'){
        if(a[i]>='a'&&a[i]<='z')
            a[i]='A'+a[i]-'a';
        while(a[i]!=' '&&a[i]!='\0') 
		    i++;
        i++;
    }
    printf("%s",a);
    fputs(a,fp);
    fclose(fp);
    getchar(); 
    return 0;
}
