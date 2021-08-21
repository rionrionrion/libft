/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manabe <rmanabe@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 19:52:17 by manabe            #+#    #+#             */
/*   Updated: 2021/08/16 22:55:01 by rmanabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	d_size;
	size_t	s_size;
	size_t	i;

	s_size = ft_strlen(src);
	d_size = 0;
	if (size == 0)
		return (s_size);
	while (d_size < size && dest[d_size] != '\0')
		d_size++;
	if (size <= d_size)
		return (s_size + size);
	i = 0;
	while ((src[i] != '\0') && (size - d_size - 1 > i))
	{
		dest[d_size + i] = src[i];
		i++;
	}
	dest[d_size + i] = '\0';
	return (d_size + s_size);
}
