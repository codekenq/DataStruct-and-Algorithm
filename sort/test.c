#include <stdlib.h>

typedef char (*Item)[3];

int main()
{
	Item b = (Item)malloc(3 * 8);
	*((char *)b + 22)= ' ';
}
