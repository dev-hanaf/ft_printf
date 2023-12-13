/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_foramts.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:18:12 by ahanaf            #+#    #+#             */
/*   Updated: 2023/12/12 14:52:21 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/printf.h"
#include "libft/libft.h"

int cheack_flags(char c)
{
    char *flags = "csdiupxX+-.0#123456789%";
    while (*flags)
    {
        if (c == *flags)
            return 1;
        flags++;
    }
    return 0;
}

 int count_words(const char *str)
{
    int i = 0;
    int count = 0;
    while (str[i])
    {
        if (str[i] == '%')
        {
            i++;
            if (cheack_flags(str[i]))
               count++;
        }
        i++;
    }
    return count;
}
 void lenght_word(const char *str, int *start, int *end)
{
    static size_t i = 0;    
    while (str[i])
    {
        if (str[i] == '%')
        {
            i++;
            *start = i;
            while(cheack_flags(str[i]))
            {
                if (str[i] == 'd' || str[i] == ' ' || str[i] == '%'  || str[i] == 'i' || str[i] == 's' || str[i] == 'c' || str[i] == 'p' || str[i] == 'u' || str[i] == 'x' || str[i] == 'X')
                 {
                            *end = i;
                            break;
                 }                
                i++;
            }
            return ;
        }
        i++;
    }
}

char *set_word(const char *str,int start, int end)
{
    int len = end - start + 1;
    char *word = ft_calloc(sizeof(char), len + 1);
    if (!word)
       return (NULL);
    int j = 0;
    while(start <= end)
    {
        word[j] = str[start];
        j++;
        start++;
    }
    return (word);
}


t_format_split ft_split_foramts(const char *str)
{
    t_format_split result;
    int i = 0;
    int start = 0;
    int end = 0;
    int wc = count_words(str);
    result.arr_start = malloc(sizeof(int) * (wc - 1));
    result.arr_end = malloc(sizeof(int) * (wc - 1));
    result.ptr = ft_calloc(sizeof(char *), wc + 1);
    if (!result.ptr || !result.arr_start || !result.arr_end)
        return (result);
    while (i < wc)
    {
        lenght_word(str, &start, &end);
        result.arr_start[i] = start;
        result.arr_end[i] = end;
        
        //printf("start=>%d end=>%d\n", result.arr_start[i],result.arr_end[i]);
        result.ptr[i] = set_word(str, start, end);
        i++;
    }
    return (result);
}

//hello %+d. rr %% rr %+0i rr %.0d
// int main()
// {
//     char **str = ft_split_foramts("hello %+d. dd %% rr %+0i rr %.0d");
//     int i= 0;
    
//     // while(str[i])
//     // {
//     //     printf(":%s:\n",str[i]);
//     //     i++;
//     // }
//     // printf("hello %+d. dd %% rr %+0i rr %.0d");
// }
// int main()
// {
//     t_format_split split_result = ft_split_foramts("hello %+d. dd %% rr %+0i rr %.0d");
//     // Now you can use split_result.ptr and split_result.arr_start
// }