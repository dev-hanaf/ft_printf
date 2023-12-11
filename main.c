/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:39:44 by ahanaf            #+#    #+#             */
/*   Updated: 2023/12/11 13:33:43 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/printf.h"
#include "libft/libft.h"
#include <limits.h>

void foramts(va_list ap, char f,char end, int *len)
{   
    //printf("%c\n",end);
    if ((f == '+' || f == '-' || f == 'd' || f == 'i' ) && ( end == 'd' || end == 'i'))
    {
        *len += ft_dicimal(va_arg(ap, int), f);
    }
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
    int i;
    i  = 0;
    char **ptr;
    if (str)
        ptr = ft_split_foramts(str);
    int x = 0;
    while(ptr[i])
    {
        x = 0;
        while(ptr[i][x])
        {
            printf("%c",ptr[i][x]);
            x++;
        }
        int j = 0;
        // while(ptr[i][j])
        // {
        //     foramts(ap,ptr[i][j],ptr[i][x-1],&lenght);
        //     j++;
        // }
        printf("\n");
        i++;
    }
    va_end(ap);
    return (lenght);
}


int main()
{                   
    ft_printf("hello => %-+Xsd  %+0.d ",-100);
}