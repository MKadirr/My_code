#include <unistd.h>

int my_putstr(char* str)
{
	for(int i = 0; str[i] != '\0'; i++) write(1, &str[i], 1);
}

int main(int argc, char** argv)
{
	if(argc > 1) my_putstr(argv[1]);
	return 0;
}
