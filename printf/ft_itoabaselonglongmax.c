#include "libftprintf.h"

static	char	*remplimoitoucalong(char *s1, unsigned long long n, size_t size, int base)
{
	size_t			index;
	unsigned long long lol;

	index = 0;
	lol = 0;
	lol = n;
	while (size > index && size)
	{
		if((s1[size - 1] = lol % base + '0') > 57)
			s1[size - 1] = lol % base + '0' + 7;
		lol = lol / base;
		size--;
	}
	return (s1);
}

char			*ft_itoabase_long_long_max(unsigned long long n, int base)
{
	unsigned long long	test;
	size_t	taille;
	char	*ret;

	ret = NULL;
	taille = 1;
	test = n;
	while (test / base != 0)
	{
		taille++;
		test = test / base;
	}
	ret = ft_strnew(taille);
	if (ret)
		ret = remplimoitoucalong(ret, n, taille, base);
	else
		return (NULL);
	return (ret);
}
