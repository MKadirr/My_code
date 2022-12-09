#include <unistd.h>
#include <stdlib.h>


int my_putchar(char c)
{
	write(1, &c, 1);
	return 0;
}

int my_putstr(char* str)
{
	for(int i = 0; str[i] != '\0'; i++) write(1, &str[i], 1);
	return 0;
}

int my_strlen(char* str)
{
	int l = 0;
	while(str[l] != '\0') l++;
	return l;
}

int my_faststr(char* str)
{
	write(1, str, my_strlen(str));
	return 0;
}

int my_putnbr(int nb)
{
	if(nb < 0)
	{
		my_putchar('-');
		nb = -nb;
	}
	if(nb < 10) my_putchar(nb+48);
	else
	{
		my_putnbr(nb/10);
		my_putchar(nb%10+48);
	}

	return 0;
}

int my_putnbr_base(long nb, char* str)
{
	if(nb < 0)
        {
                my_putchar('-');
                nb = -nb;
        }
	if(nb < my_strlen(str)) my_putchar(str[nb]);
        else
        {
                my_putnbr(nb/my_strlen(str));
                my_putchar(str[nb%my_strlen(str)]);
        }
}

long my_getnbr(char* const str)
{
	long nb = 0;
	char neg = 1;
	int d;
	int l = my_strlen(str);
	int i = 0;
	while(i < l)
	{
		if(str[i] <= '9' && str[i] >= '0' && nb != 0)
                        nb = nb*10+str[i]-48;
		if(str[i] <= '9' && str[i] >= '0' && nb == 0)
		{
			d = i;
			nb = str[i]-48;
		}
		if((str[i] > '9' || str[i] < '0') && nb > 0)
			i = l;
		i++;
	}
	for(int j = d-1; 0 < d && str[j] == '-'; j--) neg = (neg+1)%2;
	return neg?nb:-nb;
}

char *my_strcpy(char *dest, const char *src)
{
	if(dest && src)
		for(int i = 0; i <= my_strlen(src); i++)
			dest[i] = src[i];
	return dest;
}

char *my_strdup(char *src)
{
	char * dest = (char *)malloc(sizeof(char) * my_strlen(src));
	for(int i = 0; i <= my_strlen(src); i++) dest[i] = src[i];
	return dest;
}

char *my_strcat(char *dest, const char *src)
{
	int len = my_strlen(dest);
	int len2 = my_strlen(src);
	if(dest && src)
                for(int i = 0; i <= len2; i++)
                        dest[i+len] = src[i];
        return dest;
}

char *my_strncat(char *dest, const char *src, size_t n)
{
        int len = my_strlen(dest);
        int len2 = my_strlen(src);
	len2 = len2 < n ? len2 : n;
        if(dest && src)
                for(int i = 0; i < len2; i++)
                        dest[i+len] = src[i];
	dest[len + len2] = '\0';
        return dest;
}

char *my_strncpy(char *dest, const char *src, size_t n)
{
	n = n > my_strlen(src) ? my_strlen(src) : n;
        if(dest && src)
                for(int i = 0; i < n; i++)
                        dest[i] = src[i];
	dest[n] = '\0';
        return dest;
}

int main(int argc, char** argv)
{
	char c[100];
	for(int i = 1;  i < argc; i++)
	{
		my_strncpy(c, argv[i], 2);
		my_putstr(c);
		my_putchar('\n');
	}
	free(c);
	return 0;
}
