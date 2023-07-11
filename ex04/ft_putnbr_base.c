/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-iori <edi-iori@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:10:19 by edechena          #+#    #+#             */
/*   Updated: 2023/07/10 22:08:43 by edi-iori         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
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

void	ft_printbuffer(char *str, int size)
{
	int		i;

	i = size - 1;
	while (i >= 0)
	{
		write(1, &str[i], 1);
		i--;
	}
}

int	check_bad_case(int nbr, char *base)
{
	if (nbr == 0)
	{
		write(1, &base[0], 1);
		return (1);
	}
	if (!ft_is_valid_base(base))
	{
		return (1);
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		len;
	char	buffer[100];
	int		i;
	int		negative;
	int		temp;

	if (check_bad_case(nbr, base))
		return ;
	negative = 0;
	if (nbr < 0)
		negative = 1;
	len = ft_strlen(base);
	i = 0;
	while (nbr != 0)
	{
		temp = nbr % len;
		if (temp < 0)
			temp = -temp;
		buffer[i] = base[temp];
		nbr /= len;
		i++;
	}
	if (negative)
		write(1, "-", 1);
	ft_printbuffer(buffer, i);
}
