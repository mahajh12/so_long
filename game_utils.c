/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhamel <malhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:42:23 by malhamel          #+#    #+#             */
/*   Updated: 2023/05/18 14:29:11 by malhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strrchr(const char *s, int c)
{
	size_t		len;
	char		*alt;
	char		str;

	alt = (char *)s;
	str = (char)c;
	len = ft_strlen(alt);
	if (c == 0)
		return ((char *)(s + len));
	while (len--)
	{
		if (alt[len] == str)
			return (&alt[len]);
	}
	return (NULL);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = nbr * (-1);
	}
	if (nbr < 10)
	{
		ft_putchar(nbr + '0');
	}
	else
	{
		ft_putnbr(nbr / 10);
		ft_putchar(nbr % 10 + '0');
	}
}
