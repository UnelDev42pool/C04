/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-iori <edi-iori@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:52:39 by edi-iori          #+#    #+#             */
/*   Updated: 2023/07/08 16:21:37 by edi-iori         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
int	char_is_numeric(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	total;
	int	negative;

	i = 0;
	negative = 0;
	total = 0;
	while (str[i] != '\0')
	{
		if ((!char_is_numeric(str[i]) && total >= 1))
		{
			break ;
		}
		if (str[i] == '-')
			negative++;
		else if (char_is_numeric(str[i]))
		{
			total *= 10;
			total += str[i] - 48;
		}
		i++;
	}
	if (negative % 2)
		total = -total;
	return (total);
}
// int main()
// {
// 	printf("%d", ft_atoi("  ---+--+1234ab567"));
// }
