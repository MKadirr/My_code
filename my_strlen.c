#include "my.h"

int my_strlen(char* str)
{
	int l = 0;
	while(str[l] == '\0') l++;
	return l;
}

int main(int argc, char** argv)
{
	for(int i = 1; i < argc; i++)
	{
		my_strlen


