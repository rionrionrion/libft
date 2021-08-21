
#include "libft.h"

void	*ft_memchr(const void *s, int ch, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)ch)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
