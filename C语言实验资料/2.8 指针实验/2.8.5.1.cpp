#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int reverse(char);
void calculate(int [],int []);
int main(void)
{
    char num1[32],num2[32];          //�������� 
    int Num1[30],Num2[30];           //������� 
    int i,j;
    for(i=0;i<30;i++) 
	{
	    Num1[i]=0;
	    Num2[i]=0;
	}                               //ȫ����ʼ��Ϊ 0 
	char *p1=num1,*p2=num2;
	printf("�������һ������");
	scanf("%s",p1);
	getchar();
	printf("������ڶ�������");
	scanf("%s",p2);
	getchar();
	int l1=strlen(p1)-1,l2=strlen(p2)-1;
	int num_xs1,num_xs2,dot1,dot2;       //��¼С�����ֵ����ָ�����С�����λ�� 
	for(i=0;*(p1+i)!='.';i++);
	dot1=i;
	i++,num_xs1=0;
	while(*(p1+i)!='\0')
	{
		num_xs1++;
		Num1[19+num_xs1]=reverse(*(p1+i));
		i++;
	}
	for(i=0;*(p2+i)!='.';i++);
	dot2=i;
	i++,num_xs2=0;
	while(*(p2+i)!='\0')
	{
		num_xs2++;
		Num2[19+num_xs2]=reverse(*(p2+i));
		i++;
	}                                              //����¼��С������ 
	for(i=dot1-1,j=19;i>=0;i--,j--)
	    Num1[j]=reverse(*(p1+i));                 //¼���������� 
	for(i=dot2-1,j=19;i>=0;i--,j--)
	    Num2[j]=reverse(*(p2+i));
	calculate(Num1,Num2);
	getchar(); 
    return 0;
} 

int reverse(char c)
{
	int num;
	num=c-'0';
	return num;
}

void calculate(int Num1[],int Num2[])
{
	int i,j;
	int result[31];
	for(i=0;i<31;i++) 
        result[i]=0;                    //��result[] ��ʼ��Ϊ 0 
	for(i=29;i>=1;i--)
	{
		j=Num1[i]+Num2[i];
		if(j>=10) 
		{
		    result[i+1]+=j%10;
		    result[i]=1;
		}
		else 
			result[i+1]+=j%10;
	}
	j=0;
	while(result[j]==0) 
	    j++;            //������� 0ȥ�� 
	for(i=j;i<=20;i++) printf("%d",result[i]);          //�����������
	printf(".");                         //���С����
	for(i=21;i<=30;i++) printf("%d",result[i]);         //���С������
	return ; 
}
