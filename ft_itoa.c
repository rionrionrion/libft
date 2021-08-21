/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 13:31:34 by marvin            #+#    #+#             */
/*   Updated: 2021/08/16 22:55:31 by rmanabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	get_nb_digit(long n_l, int mark)
{
	unsigned int	nb_digit;

	if (n_l == 0)
		return (1);
	nb_digit = 0;
	while (n_l > 0)
	{
		n_l = n_l / 10;
		nb_digit++;
	}
	if (mark == -1)
		nb_digit++;
	return (nb_digit);
}

static void	convert_nb(char *dest, long n_l, unsigned int nb_digit, int mark)
{
	dest[nb_digit] = '\0';
	dest[--nb_digit] = n_l % 10 + '0';
	n_l = n_l / 10;
	while (n_l > 0)
	{
		dest[--nb_digit] = n_l % 10 + '0';
		n_l = n_l / 10;
	}
	if (mark == -1)
		dest[0] = '-';
}

char	*ft_itoa(int n)
{
	char			*dest;
	long			n_l;
	unsigned int	nb_digit;
	int				mark;

	mark = 1;
	if (n < 0)
	{
		n_l = (long)n * -1;
		mark = -1;
	}
	else
		n_l = n;
	nb_digit = get_nb_digit(n_l, mark);
	dest = malloc(sizeof(char) * (nb_digit + 1));
	if (dest == NULL)
		return (NULL);
	convert_nb(dest, n_l, nb_digit, mark);
	return (dest);
}
