/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 03:27:35 by ahanaf            #+#    #+#             */
/*   Updated: 2023/12/08 08:58:27 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_putnbr_fd(int n, int fd)
{
    if (n == -2147483648)
    {
        ft_putchar_fd('-', fd);
        ft_putchar_fd('2', fd);
        n = 147483648;
    }
    if (n < 0)
    {
        ft_putchar_fd('-', fd);
        n = -n;
    }
    if (n > 9)
    {
        ft_putnbr_fd(n / 10, fd);
    }
    ft_putchar_fd(n % 10 + '0', fd);
	return (1);
}

// int	ft_putnbr_fd(int n, int fd)
// {
// 	static int lenght = 0;
// 	if (fd < 0)
// 		return lenght;
// 	else if (n == -2147483648)
// 		lenght += write(fd, "-2147483648", 11);
// 	else if (n < 0)
// 	{
// 		n *= -1;
// 		lenght += ft_putchar_fd('-', fd);
// 		ft_putnbr_fd(n, fd);
// 	}
// 	else
// 	{
// 		if (n > 9)
// 		{
// 			ft_putnbr_fd(n / 10, fd);
// 			ft_putnbr_fd(n % 10, fd);
// 		}
// 		else
// 			lenght += ft_putchar_fd(n + 48, fd);
// 	}
// 	return (lenght);
// }
