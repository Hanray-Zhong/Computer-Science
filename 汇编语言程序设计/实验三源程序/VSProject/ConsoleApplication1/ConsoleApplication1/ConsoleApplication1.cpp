#pragma warning(disable:4996)
#include "stdio.h"
#include "string.h"

typedef struct {
	char name[10] = { 'L', 'I', ' ', 'B', 'O' , 0 };
	char passWord[10] = { '1','2','3','4','5','6', 0 };
	char in_name[10];
	char in_passWord[10];
	char in_good[10];
	char GA1[10] = { 'P','E','N','0','0','0','0','0','0','0' };
	short GA1_inform[7] = { 10,35,56,700,300,0,0 };
	char GA2[10] = { 'B','O','O','K','0','0','0','0','0','0' };
	short GA2_inform[7] = { 9,12,30,2500,1000,0,0 };
	char GA3[10] = { 'B','A','G','0','0','0','0','0','0','0' };
	short GA3_inform[7] = { 6,16,80,1000,20,0,0 };
}Information;

void Option_1(Information inform);

void main() {
	
	Information inform;

	int op = 0;
	int i = 0;
	LOGIN:
	printf("\t\t....SHOPE  NAME....\n");
	printf("提示输入姓名\n");
	scanf("%[^\n]", inform.in_name);
	printf("提示输入密码\n");
	scanf("%s", inform.in_passWord);
	while (true) {
		if (inform.in_name[i] != inform.name[i]) {
			printf("name or password is wrong,go back to main menu!\n");
			goto LOGIN;
		}
		if (inform.name[i] == 0 && inform.in_name[i] == '\0') {
			i = 0;
			break;
		}
		i++;
	}
	while (true) {
		if (inform.in_passWord[i] != inform.passWord[i]) {
			printf("name or password is wrong,go back to main menu!\n");
			goto LOGIN;
		}
		if (inform.passWord[i] == 0 && inform.in_passWord[i] == '\0') {
			i = 0;
			break;
		}
		i++;
	}

	while (op != 6) {
		printf("1=查询商品信息,2=修改商品信息,3=计算推荐度,\n");
		printf("4=计算推荐度排名,5=输出全部商品信息,6=程序退出.\n");
		scanf("%d", &op);
		switch (op) {
		case 1:
			Option_1(inform);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			return;
		case 0:
			break;
		}
	}
}

void Option_1(Information inform) {
	Re_find:
	printf("Please input the goods name:");
	scanf("%s", inform.in_good);
	int i = 0;
	int j = 1;
	while (true) {
		if (inform.in_good[i] != inform.GA1[i] && inform.GA1[i] != '0') {
			i = 0;
			j++;
			break;
		}
		if (inform.GA1[i] == '0' && inform.in_good[i] == '\0') {
			i = 0;
			goto Find;
		}
		i++;
	}
	while (true) {
		if (inform.in_good[i] != inform.GA2[i] && inform.GA2[i] != '0') {
			i = 0;
			j++;
			break;
		}
		if (inform.GA2[i] == '0' && inform.in_good[i] == '\0') {
			i = 0;
			goto Find;
		}
		i++;
	}
	while (true) {
		if (inform.in_good[i] != inform.GA3[i] && inform.GA3[i] != '0') {
			i = 0;
			j++;
			break;
		}
		if (inform.GA3[i] == '0' && inform.in_good[i] == '\0') {
			i = 0;
			goto Find;
		}
		i++;
	}
	printf("do not find the goods!please input the goods name again!\n");
	goto Re_find;
	Find:
	switch (j) {
	case 1 :
		printf("%d -- %d -- %d -- %d -- %d -- %d -- %d\n", inform.GA1_inform[0], inform.GA1_inform[1], inform.GA1_inform[2], inform.GA1_inform[3], inform.GA1_inform[4], inform.GA1_inform[5], inform.GA1_inform[6]);
		break;
	case 2 :
		printf("%d -- %d -- %d -- %d -- %d -- %d -- %d\n", inform.GA2_inform[0], inform.GA2_inform[1], inform.GA2_inform[2], inform.GA2_inform[3], inform.GA2_inform[4], inform.GA2_inform[5], inform.GA2_inform[6]);
		break;
	case 3 :
		printf("%d -- %d -- %d -- %d -- %d -- %d -- %d\n", inform.GA3_inform[0], inform.GA3_inform[1], inform.GA3_inform[2], inform.GA3_inform[3], inform.GA3_inform[4], inform.GA3_inform[5], inform.GA3_inform[6]);
		break;
	}
	return;
}