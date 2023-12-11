/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:59:49 by ahanaf            #+#    #+#             */
/*   Updated: 2023/12/10 12:05:28 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/printf.h"
#include "../libft/libft.h"

int ft_string(char *str)
{
    int lenght;

    lenght = ft_putstr_fd(str, 1);
    return (lenght);
}
