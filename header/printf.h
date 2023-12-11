/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 01:51:45 by ahanaf            #+#    #+#             */
/*   Updated: 2023/12/11 06:46:20 by ahanaf           ###   ########.fr       */
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

int ft_printf(const char *str, ...);
int ft_hexa(unsigned int num, char f);
char **ft_split_foramts(const char *str);
int ft_dicimal(int num, char f);
int ft_adresse(void *ptr);

#endif 