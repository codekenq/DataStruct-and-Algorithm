#include <stdio.h>
#include <stdlib.h>

#define MAX_BUF_NUM	16

int writeInx = 0;
int readInx = 0;
char buf[MAX_BUF_NUM] = {0};
int cnt = 0;

void write(char *data, int len)
{
	int i;
	if(cnt + len > 16)
		printf("data too big\n"), exit(-1);
	cnt += len;
	for(i = 0; i < len; i++, writeInx++)
	{
		if(writeInx > 15)
			writeInx = 0;
		buf[writeInx] = data[i];
	}
}

void read(char *data, int len)
{
	int i;
	if(cnt - len < 0)
		printf("have no more data\n"), exit(-1);
	cnt -=len;
	for(i = 0; i < len; i++, readInx++)
	{
		if(readInx > 15)
			readInx = 0;
		data[i] = buf[readInx];
	}
}

int main()
{
	char data1[] = "1234567890123456";
	char data2[] = "abcdefghij";
	char data3[] = "654321";

	char print[17];
	write(data1, sizeof(data1) - 1);
	read(print, sizeof(data1) - 1);
	print[sizeof(data1) - 1] = 0;
	printf("%s\n", print);

	write(data2, sizeof(data2) - 1);
	read(print, sizeof(data2) - 1);
	print[sizeof(data2) - 1] = 0;
	printf("%s\n", print);	
	
	write(data3, sizeof(data3) - 1);
	read(print, sizeof(data3) - 1);
	print[sizeof(data3) - 1] = 0;
	printf("%s\n", print);
	
	write(data2, sizeof(data2) - 1);
	write(data3, sizeof(data3) - 1);
	read(print, sizeof(data2) - 1 + sizeof(data3) -1);
	print[sizeof(data2) - 1 + sizeof(data3) - 1] = 0;
	printf("%s\n", print);
}
