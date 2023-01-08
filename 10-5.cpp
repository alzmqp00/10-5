#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//建立結構
typedef struct {
	int x, y, z, m;
	char name[10];
}address_t;
//set functions
int scan_address(address_t IP[100]);
void print_address(char source[10], char target[10]);
int local_address(address_t, address_t);

int main(void)
{	
	int count=0;
	address_t IP[100];
	count = scan_address(IP);
	for (int i = 0; i < count; i++) {
		for (int j = i + 1; j < count; j++) {

			//if IP[k]'s first two components of the address are the same as IP[j], print them
			if (local_address(IP[j], IP[i]) == 1)
				print_address(IP[i].name, IP[j].name);
		}
	}
	system("pause");
	return 0;
}

int scan_address(address_t IP[100])
{	
	FILE* inp;
	int count = 0;
	int state;
	inp = fopen("data.txt", "r");
	for (int i = 0; i < 100; i++) {
		state = fscanf(inp, "%d.%d.%d.%d %s", &IP[i].x, &IP[i].y, &IP[i].z, &IP[i].m,&IP[i].name);
		if (state == EOF) {
			count = i;
			break;
		}
	}
	printf("SEARCHING THE SAME LOCAL NETWORK\n");
	for (int i = 0; i < count; i++) {
	
		printf("%d.%d.%d.%d.%s\n", IP[i].x, IP[i].y, IP[i].z, IP[i].m, IP[i].name);
	}
	fclose(inp);
	return count;//儲存數目
}
//print
void print_address(char source[10], char target[10]) {
	
	printf("Machines %s and %s are on the same local network.\n", source, target);
}
//comparsion
int local_address(address_t list1, address_t list2) {
	if (list1.x == list2.x and list1.y == list2.y) {
		return 1;
	}
	else
		return 0;
}
