/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 01:51:45 by ahanaf            #+#    #+#             */
/*   Updated: 2023/12/13 01:57:43 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
# define HEXA "0123456789abcdef"
# define HEXA_CAP "0123456789ABCDEF"
# define DECIMAL "0123456789"
# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define FT_FLAGS "csdixXpu%.+-#0 "

typedef struct s_format_split {
    char **ptr;
    int *arr_start;
    int *arr_end;
} t_format_split;

int ft_printf(const char *str, ...);
int ft_hexa(unsigned int num, char f);
t_format_split ft_split_foramts(const char *str);
int ft_dicimal(int num, char f, char *splited);
int ft_adresse(void *ptr);
int ft_unsigned(unsigned int  num, char f, char *splited);


#endif 