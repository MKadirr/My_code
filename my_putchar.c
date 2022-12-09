#include <unistd.h>

int my_putchar(char c)
{
	write(1, &c, 1);
}

int main(int argc, char** argv)
{
	my_putchar(65);
	return 0;
}
