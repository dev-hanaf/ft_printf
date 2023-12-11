/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adresse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:36:29 by ahanaf            #+#    #+#             */
/*   Updated: 2023/12/11 08:54:21 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/printf.h"
#include "../libft/libft.h"
 
int ft_hexaa(unsigned long long num, char f)
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
int	ft_putnbr_x(unsigned long long nbr, char c)
{
	char	*base;
	int		count;

	count = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	else if (c == 'u')
		base = "0123456789";
	if (nbr < ft_strlen(base))
	{
		count++;
		write(1, &base[nbr], 1);
	}
	else
	{
		count += ft_putnbr_x(nbr / ft_strlen(base), c);
		count += ft_putnbr_x((nbr % ft_strlen(base)), c);
	}
	return (count);
}
int ft_adresse(void *ptr)
{
    int lenght = 0;
    if (!ptr)
        return (ft_putstr_fd("(nil)", 1));
    else
    {   
        lenght += ft_putstr_fd("0x", 1);
        lenght += ft_putnbr_x((unsigned long long)ptr, 'x');    
    }
    return (lenght);
}
// int main()
// {
//     char *str = "hello";
    
//     printf("%p\n",str); 
//     ft_adresse(ptr);

// }
