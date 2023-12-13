/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:33:44 by ahanaf            #+#    #+#             */
/*   Updated: 2023/12/13 02:01:21 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/printf.h"
#include "../libft/libft.h"

int res2 = 0;
int plus2 = 0;
int minus2 = 0 ;
int zero2= 0;

 int ft_putnbr(unsigned int num)
{
    static int lenght = 0 ;
    if (num >= 0 && num <= 9)
        lenght += ft_putchar_fd(num + 48, 1);
    else
    {
        lenght = ft_putnbr(num / 10);
        lenght += ft_putchar_fd((num % 10) + 48, 1);

    }
    return (lenght); 
}
int cheack_plus2_or_minus2(char *splited)
{
    int i;
    i = 0;
    int flag = 0;

    while (splited[i])
    {
        if(splited[i] == '-' || splited[i] == '+' || splited[i] == '0')
            {
                        if (splited[i] == '+')
                            plus2 =1;
                        if (splited[i] == '-')
                            minus2 =1;
                        if (splited[i] == '0' || splited[i + 1] == '0')
                            zero2=1;
                while (ft_isdigit(splited[i + 1]))
                {
                    res2 = res2 * 10 + (splited[i + 1] - 48);
                    i++;
                }
            }        

        i++;
    }
    return flag;
}
int unsigned_lenght(unsigned int num)
{
    int lenght = 0;
    if (num == 0)
        lenght++;
    if (num < 0)
    {
        lenght++;
        num = -num;
    }
    while (num  > 0)
    {
        num /= 10;
        lenght++;
    }
    return (lenght);
}

int ft_unsigned(unsigned int  num, char f, char *splited)
{
    int lenght = 0;
    cheack_plus2_or_minus2(splited);
    res2 = res2 - unsigned_lenght(num);

     if (plus2 && zero2)
    {
           if (num >= 0)
           {
                lenght += ft_putchar_fd('+', 1);
                res2--;
           }
            if(num < 0)
            {
                lenght += ft_putchar_fd('-', 1); 
                num *= -1;
            }
                while(res2 > 0)
                {
                    lenght += ft_putchar_fd('0', 1);
                    res2--;
                }
        lenght = ft_putnbr(num );
    }
    else if (plus2 && minus2)
    {
           if (num >= 0)
            {

                lenght += ft_putchar_fd('+', 1);
            }
                    lenght = ft_putnbr(num );

        if(num >= 0 )
         {   
            res2--;
                while(res2 > 0)
                {
                    lenght += ft_putchar_fd(' ', 1);
                    res2--;
                }
        }
        if (num < 0 )
        {
                while(res2 > 0)
                {
                    lenght += ft_putchar_fd(' ', 1);
                    res2--;
                }
        } 
    }
    
    else if (minus2 && !plus2)
    {
        lenght = ft_putnbr(num );
        while(res2 > 0)
        {
            lenght += ft_putchar_fd(' ', 1);
            res2--;
        }
    }
    else if (plus2 )
    {

        if (num >= 0 )
        {
            res2--;
            while(res2 > 0)
            {
                lenght += ft_putchar_fd(' ', 1);
                res2--;
            }
            lenght += ft_putchar_fd('+', 1);
        }
        if (num < 0 )
        {
            while(res2 > 0)
            {
                lenght += ft_putchar_fd(' ', 1);
                res2--;
            }
        }
            lenght = ft_putnbr(num );
    }
    else if(zero2)
    {
           if (num >= 0)
            {
            res2--;
            lenght += ft_putchar_fd('0', 1);
            while(res2 > 0)
            {
                lenght += ft_putchar_fd('0', 1);
                res2--;
            }
            }
        lenght = ft_putnbr(num );
    }
    return (lenght);
}