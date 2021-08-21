/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manabe <rmanabe@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 19:52:30 by manabe            #+#    #+#             */
/*   Updated: 2021/08/16 23:02:43 by rmanabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s) || len <= 0)
		return (ft_strdup("\0"));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (dest == NULL )
		return (NULL);
	while (i < len && i < ft_strlen(s) && ((char *)s)[start] != '\0')
	{
		dest[i] = ((char *)s)[(size_t)start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
