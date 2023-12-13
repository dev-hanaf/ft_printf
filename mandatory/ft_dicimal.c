/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dicimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:52:41 by ahanaf            #+#    #+#             */
/*   Updated: 2023/12/13 01:58:25 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/printf.h"
#include "../libft/libft.h"
int res = 0;
int zero = 0;
int plus = 0;
int minus = 0;

int cheack_plus_or_minus(char *splited)
{
    int i;
    i = 0;
    int flag = 0;

    while (splited[i])
    {
        if(splited[i] == '-' || splited[i] == '+' || splited[i] == '0')
            {
                        if (splited[i] == '+')
                            plus =1;
                        if (splited[i] == '-')
                            minus =1;
                        if (splited[i] == '0' || splited[i + 1] == '0')
                            zero =1;
                //flag = (int)splited[i];
                while (ft_isdigit(splited[i + 1]))
                {
                    res = res * 10 + (splited[i + 1] - 48);
                    i++;
                }
            }        

        i++;
    }
    return flag;
}
int dicimal_lenght(int num)
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

int ft_dicimal(int num, char f, char *splited)
{
    int lenght = 0;
    cheack_plus_or_minus(splited);
    res = res - dicimal_lenght(num);

     if (plus && zero )
    {
           if (num >= 0)
           {
                lenght += ft_putchar_fd('+', 1);
                res--;
           }
            if(num < 0)
            {
                lenght += ft_putchar_fd('-', 1); 
                num *= -1;
            }
                while(res > 0)
                {
                    lenght += ft_putchar_fd('0', 1);
                    res--;
                }
        lenght = ft_putnbr_fd(num ,1);
    }
    else if (plus && minus)
    {
           if (num >= 0)
            {
                lenght += ft_putchar_fd('+', 1);
            }
                    lenght = ft_putnbr_fd(num ,1);

        if(num >= 0 )
         {   
            res--;
                while(res > 0)
                {
                    lenght += ft_putchar_fd(' ', 1);
                    res--;
                }
        }
        if (num < 0 )
        {
                while(res > 0)
                {
                    lenght += ft_putchar_fd(' ', 1);
                    res--;
                }
        } 
    }
    
    else if (minus && !plus)
    {
        lenght = ft_putnbr_fd(num ,1);
        while(res > 0)
        {
            lenght += ft_putchar_fd(' ', 1);
            res--;
        }
    }
    else if (plus )
    {

        if (num >= 0 )
        {
            res--;
            while(res > 0)
            {
                lenght += ft_putchar_fd(' ', 1);
                res--;
            }
            lenght += ft_putchar_fd('+', 1);
        }
        if (num < 0 )
        {
            while(res > 0)
            {
                lenght += ft_putchar_fd(' ', 1);
                res--;
            }
        }
            lenght = ft_putnbr_fd(num ,1);
    }
    else if(zero)
    {
           if (num >= 0)
            {
            res--;
            lenght += ft_putchar_fd('0', 1);
            while(res > 0)
            {
                lenght += ft_putchar_fd('0', 1);
                res--;
            }
            }
        lenght = ft_putnbr_fd(num ,1);
    }
    return (lenght);
}
// int main()
// {
//     ft_dicimal(+100,'d',"-+d");
// }