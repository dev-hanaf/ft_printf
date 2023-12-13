/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:39:44 by ahanaf            #+#    #+#             */
/*   Updated: 2023/12/13 02:03:20 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/printf.h"
#include "libft/libft.h"
#include <limits.h>

void foramts(va_list ap, char f,char *splited, int *len)
{   
    if (f == 'd' || f == 'i' )
    {
        *len += ft_dicimal(va_arg(ap, int), f, splited);
    }
    else if (f == 'u')
        *len += ft_unsigned(va_arg(ap ,unsigned int) , f, splited);
    else if(f == 'p')
        *len += ft_adresse(va_arg(ap, void *));
    else if(f == '%')
        *len += ft_putchar_fd('%', 1);
   // return *len;  
}

int ft_printf(const char *str, ...)
{
    va_list ap;
    va_start(ap, str);
    int lenght = 0;
    int i = 0;
    int index = 0;
    int start = 0;
    if (str)
    {
        t_format_split res = ft_split_foramts(str);
        int x = 0;
        while (str[index])
        {
            start = 0;
            if(index +1 >= res.arr_start[0] && index <= res.arr_end[0])
            {
                while(res.ptr[i])
                {
                    x = 0;
                    while(res.ptr[i][x])
                        x++;
                    int j = 0;
                    while(res.ptr[i][j])
                    {
                        foramts(ap,res.ptr[i][j],res.ptr[i],&lenght);
                        j++;
                    }
                    i++;
                }
            }
            else
            {
                lenght += ft_putchar_fd(str[index], 1);    
            }
            index++;
        }
    }
    va_end(ap);
    return (lenght);
}


int main()
{                 
    int n = 100;  
    ft_printf("hello => %+010u hello\n",n);
    printf("hello => %+010u hello\n",n);

}