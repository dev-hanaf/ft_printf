/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_foramts.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:18:12 by ahanaf            #+#    #+#             */
/*   Updated: 2023/12/11 14:02:28 by ahanaf           ###   ########.fr       */
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
            // printf("str[%d] %c count %d\n",i,str[i],count);
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

char **ft_split_foramts(const char *str)
{
    char **ptr;
    int i = 0;
    int start = 0;
    int end = 0;
    int wc = count_words(str);
    // printf("wc %d\n",wc);
    ptr = ft_calloc(sizeof(char *),wc + 1 );
    if (!ptr)
        return (NULL);
    while (i < wc)
    {
        lenght_word(str, &start, &end);
        // printf("\033[0;34mstart %d  end %d\033[0;0m\n",start,end);
        
        ptr[i] = set_word(str,start, end);
        i++;
        
        
            
    }
    return (ptr);
}
// hello %+d. rr %% rr %+0i rr %.0d
// int main()
// {
//     char **str = ft_split_foramts("hello %+d. dd %% rr %+0i rr %.0d");
//     int i= 0;
    
//     while(str[i])
//     {
//         printf(":%s:\n",str[i]);
//         i++;
//     }
//     printf("hello %+d. dd %% rr %+0i rr %.0d");
// }
int main()
{
    printf("%%%%%%%+-0d. %0d %s");
}