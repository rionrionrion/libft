
#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*ptr;

	if (!number || !size)
	{
		number = 1;
		size = 1;
	}
	if (number > ((size_t) - 1) / size)
		return (NULL);
	ptr = malloc(number * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, number * size);
	return (ptr);
}
