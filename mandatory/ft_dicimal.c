/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dicimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:52:41 by ahanaf            #+#    #+#             */
/*   Updated: 2023/12/11 11:11:57 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/printf.h"
#include "../libft/libft.h"

int ft_dicimal(int num, char f)
{
    int lenght = 0;
    if (f == '+')
    {
        if (num >= 0)
            lenght += ft_putchar_fd('+', 1);
    }
    lenght = ft_putnbr_fd(num ,1);
    return (lenght);
}
