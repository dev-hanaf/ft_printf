/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:33:44 by ahanaf            #+#    #+#             */
/*   Updated: 2023/12/11 08:45:47 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/printf.h"
#include "../libft/libft.h"

 int ft_putnbr(unsigned int num, int lenght)
{
    if (num >= 0 && num <= 9)
        lenght += ft_putchar_fd(num + 48, 1);
    else
    {
        lenght = ft_putnbr(num / 10, lenght);
        lenght += ft_putchar_fd((num % 10) + 48, 1);

    }
    return (lenght); 
}
int ft_unsigned(int num)
{
    int lenght = 0;

    lenght = ft_putnbr(num, lenght);
    return (lenght);
}
