
#include "libft.h"

static int	ft_atoi_sub(char *str, int mark, size_t i)
{
	unsigned long	num;
	unsigned long	ov_div;
	unsigned long	ov_mod;

	num = 0;
	ov_div = (unsigned long)LONG_MAX / 10;
	ov_mod = (unsigned long)LONG_MAX % 10;
	if (mark == -1)
		ov_mod += 1;
	while ('0' <= str[i] && str[i] <= '9')
	{
		if (num > ov_div && mark == -1)
			return ((int)LONG_MIN);
		if (num > ov_div && mark == 1)
			return ((int)LONG_MAX);
		if (num == ov_div
			&& ov_mod <= (unsigned long)str[i] - '0' && mark == -1)
			return ((int)LONG_MIN);
		if (num == ov_div
			&& ov_mod <= (unsigned long)str[i] - '0' && mark == 1)
			return ((int)LONG_MAX);
		num = 10 * num + (str[i++] - '0');
	}
	return (mark * (int)num);
}

int	ft_atoi(const char *s)
{	
	size_t	i;
	int		mark;
	char	*str;

	i = 0;
	mark = 1;
	str = (char *)s;
	while (str[i] == ' ' || ('\t' <= str[i] && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mark *= -1;
		i++;
	}
	return (ft_atoi_sub(str, mark, i));
}
