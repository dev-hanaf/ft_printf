/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:39:18 by ahanaf            #+#    #+#             */
/*   Updated: 2023/12/11 13:55:34 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdarg.h>
#include <stdio.h>
void count_args(int args, ...)
{
    va_list ap;
    
    va_start(ap, args);
    int i = 0;
    while(va_arg(ap, int))
    {
        i++;
        
    }
    printf("%d",i);
}

int main()
{
    count_args(5, 1,2,3,4,5,6,7,8,9);
}