#include <stdio.h>
int main(void)
{
	int kind[12]={0,0,0,0,0,0,0,0,0,0,0,0};
	char c;
	c=getchar();
	while(c!='#')
	{
		if(c=='0') kind[0]++; 
		else if(c=='1') kind[1]++;
		else if(c=='2') kind[2]++;
		else if(c=='3') kind[3]++;
		else if(c=='4') kind[4]++;
		else if(c=='5') kind[5]++;
		else if(c=='6') kind[6]++;
		else if(c=='7') kind[7]++;
		else if(c=='8') kind[8]++;
		else if(c=='9') kind[9]++;
		else if((c>='a'&&c<='z')||(c>='A'&&c<='Z')) kind[10]++;
		else kind[11]++;
		c=getchar();
	}
	printf("Number 0: %d\nNumber 1: %d\nNumber 2: %d\nNumber 3: %d\nNumber 4: %d\nNumber 5: %d\nNumber 6: %d\nNumber 7: %d\nNumber 8: %d\nNumber 9: %d\ncharacters: %d\nother: %d\n",kind[0],kind[1],kind[2],kind[3],kind[4],kind[5],kind[6],kind[7],kind[8],kind[9],kind[10],kind[11]);
	return 0;
}
