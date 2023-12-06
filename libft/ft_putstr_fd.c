/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 03:23:30 by ahanaf            #+#    #+#             */
/*   Updated: 2023/12/06 08:26:31 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	size_t	i;
	int lenght = 0;
	if (fd < 0 || !s)
		return 0;
	i = 0;
	while (s[i])
		lenght += ft_putchar_fd(s[i++], fd);
	return (lenght);
}
