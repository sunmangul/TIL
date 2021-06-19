#include <stdio.h>

int main(int argc, char *argv[])
{
	char buf[16];
	if (argc != 2)
		return -1;
	strcpy(buf, argv[1]);
	return 0;
}
