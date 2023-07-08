/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-iori <edi-iori@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:00:33 by edi-iori          #+#    #+#             */
/*   Updated: 2023/07/08 15:47:10 by edi-iori         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		nb = 147483648;
		ft_putchar('-');
		ft_putchar('2');
	}
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (nb >= 0 && nb < 10)
	{
		ft_putchar(nb + 48);
	}
	if (nb >= 10 && nb < 100)
	{
		ft_putchar((nb / 10) + 48);
		ft_putchar((nb % 10) + 48);
	}
	if (nb > 100)
	{
		ft_putnbr((nb / 10));
		ft_putnbr(nb % 10);
	}
}
