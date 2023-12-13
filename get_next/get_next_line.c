/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 21:03:43 by ahanaf            #+#    #+#             */
/*   Updated: 2023/12/13 02:10:24 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft/libft.h"


char *get_next_line(int fd)
{
    static char *reminder_buffer = NULL;
    //long int xx = BUFFER_SIZE - 1;
    char* buffer = (char*)malloc((size_t)(BUFFER_SIZE + 1) * sizeof(char));
     if(!buffer)
         return (NULL);
    ssize_t read_size;
    read_size = read(fd,buffer,BUFFER_SIZE);
    while ()aread;    
     if (read_size == -1)
     {
        free(buffer);
        free(reminder_buffer);
        return (NULL);
     }
    buffer[read_size] = '\0';
    if (!reminder_buffer)
        reminder_buffer = buffer;
    // printf("\nafter\n%s\n",reminder_buffer);
    static size_t i = 0;
    while ( reminder_buffer[i] != '\n')
        i++;
    i++;
    char *line = (char*)malloc((i + 1) * sizeof(char));
    if (!line)
    {
        free(buffer);
        return NULL;
    }
    ft_strlcpy(line,reminder_buffer, i + 1);
    size_t len = ft_strlen(reminder_buffer);
    reminder_buffer =  ft_substr(reminder_buffer,i,len);
    // printf("\nafter substr\n%s\n",reminder_buffer);

    // printf("\n---------------------------\n");

    return (line);
}


int main()
{
    int fd;
    
    fd = open("text.txt",O_RDWR);
    if(fd == -1)
        return (0);

    printf("%s",get_next_line(fd));
     printf("%s",get_next_line(fd));

    // printf("%s",get_next_line(fd));
    // printf("%s",get_next_line(fd));
    // printf("%s",get_next_line(fd));

    close(fd);
    return (0);
}