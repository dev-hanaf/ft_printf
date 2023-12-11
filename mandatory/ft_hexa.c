/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:06:43 by ahanaf            #+#    #+#             */
/*   Updated: 2023/12/11 06:40:29 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/printf.h"
#include "../libft/libft.h"

int ft_hexa(unsigned int num, char f)
{
    int length = 0;
    if (num == 0)
    {
        length += ft_putchar_fd('0', 1);
        return length;
    }
    if (num >= 16)
        length += ft_hexa(num / 16, f);
    if (f == 'x')
        length += ft_putchar_fd(HEXA[num % 16], 1);
    else if (f == 'X')
        length += ft_putchar_fd(HEXA_CAP[num % 16], 1);
    return length;
}