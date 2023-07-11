/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-iori <edi-iori@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:52:39 by edi-iori          #+#    #+#             */
/*   Updated: 2023/07/10 12:03:32 by edi-iori         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_isnum(char c)
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
	int	final;
	int	sign;

	i = 0;
	final = 0;
	sign = 0;
	while (str[i] != '\0')
	{
		if (!ft_isnum(str[i]) && str[i] != '+'
			&& str[i] != '-' && str[i] != ' ')
			return (0);
		if (str[i] == '-')
			sign++;
		if (ft_isnum(str[i]))
		{
			while (ft_isnum(str[i]))
				final = final * 10 + str[i++] - 48;
			if (sign % 2)
				final = -final;
			return (final);
		}
		i++;
	}
	return (final);
}
// #include <stdio.h>
// int main()
// {
// 	printf("%d", ft_atoi("  -- -+--+D2147483648ab567"));
// }
