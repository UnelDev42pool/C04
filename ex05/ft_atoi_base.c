/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-iori <edi-iori@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:47:48 by edechena          #+#    #+#             */
/*   Updated: 2023/07/08 22:09:06 by edi-iori         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_pos(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != c)
	{
		i++;
	}
	return (i);
}

int	ft_pow(int base, int exp)
{
	int	i;
	int	final;

	i = 0;
	final = 1;
	while (i < exp)
	{
		final *= base;
		i++;
	}
	return (final);
}

int	ft_is_valid_base(char *str)
{
	const int	strlen = ft_strlen(str);
	int			i;
	int			j;

	if (strlen <= 1)
	{
		return (0);
	}
	i = 0;
	while (i < strlen)
	{
		if (str[i] == '+' || str[i] == '-')
			return (0);
		j = i;
		while (j < strlen)
		{
			if (i != j && str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	final;
	int	i;
	int	len;

	if (!ft_is_valid_base(base))
		return (0);
	len = ft_strlen(base);
	i = 0;
	final = 0;
	while (str[i] != '\0')
	{
		final += ft_pos(str[i], base) * ft_pow(len, ft_strlen(str) - i - 1);
		i++;
	}
	return (final);
}
