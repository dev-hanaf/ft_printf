/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:49:27 by ahanaf            #+#    #+#             */
/*   Updated: 2023/12/11 09:09:09 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/printf.h"
#include "libft/libft.h"

static int ft_hashtag(char *check_x,char *check_X)
{
    int lenght;

    lenght = 0;
    if(check_x)
    {
     lenght =  write(1, "0x",2);
    }
    else if(check_X)
    {
        lenght = write(1, "0X",2);
    }
    return lenght;
}

static int ft_printf_char(int c)
{
    int lenght;
    
    lenght = 0;
    lenght =  write (1, &c, 1);
    return (lenght);
}

static int ft_printf_hexa(int n, char fomrat)
{
    static int lenght = 0;
    char *x = "0123456789abcdef";
    char *X = "0123456789ABCDEF";

    if (fomrat == 'x')
    {
        if (n < 16)
            lenght += ft_putchar_fd(x[n],1);   
        else
        {
            ft_printf_hexa(n / 16, fomrat);
            lenght += ft_putchar_fd(x[n % 16],1);   
        }
    }
    else if (fomrat == 'X')
    {
        if (n < 16)
        {
            lenght += ft_putchar_fd(X[n],1);   
        }
        else
        {
            ft_printf_hexa(n / 16, fomrat);
            lenght += ft_putchar_fd(X[n % 16],1);
        }
    }
    return (lenght);
}

static int ft_print_dot(int num, int hashtag)
{
  
    int len = 0;
    if (hashtag < 0)
        hashtag = -hashtag;

    int num2 =  num  - hashtag  ;
    num = num -num2;
    while(num-- > 0)
    
    { ptr = ft_split_foramts(str);
        len += ft_putchar_fd('0',1);
    }
    return (len);
} 




// char *set_word(const char *str, char *sep)
// {
//     char *word;
//     int i =0;
//     int count_words = count_words(str);
//     int lenght_array[count_words];
//     while (str[i])
//     {
//         if (str[i] == '%')
//         {

//         }
//     }
//     word = ft_calloc(sizeof(char),);
//     if (!word)
//         return (NULL);
// }
// static void lenght_word(const char *str, int *start, int *end, int *i)
// {
//     int 
//     while(str[i])
//     {

//     }
// }

// static char **split(const char *str)
// {
//     char **res;
//     int start = 0;
//     int end = 0;
//     int i  = 0;
//     int wc = count_words(str);
//     res = ft_calloc(sizeof(char *), wc + 1);
//     if (!res)
//         return (NULL);HEXA
//     int j = 0;
//     while (j < wc)
//     {
//             printf("hello world\n");

//         res[j] = parser(str,&i);
//         j++;
//     }
//     printf("%s\n",res[0]);
//     return (res);
// }
// char *parser(const char *str , int *i)
// {
//     //int i = 0;
//     int j = 0;
//     int index = 0;
//     char *flags = "csidpuxX#.+- 0123456789%";
//     char *res = (char *)ft_calloc(ft_strlen(str) + 1, sizeof(char *));
//     if (res == NULL)
//         return NULL;
//     while(str[*i])
//     {
//         if (str[*i] == '%')
//         {
//             printf("%d\n",*i);
//             *i++;
//             while (str[*i])
//             {
//                 j = 0;
//                 while (flags[j])
//                 {        
//                     if (str[*i] == flags[j])
//                     {
//                         res[index] = str[*i];
//                                     printf("%d\n",*i);

//                         index++;
//                         break;
//                     }
//                     j++;
//                 }
//                 if (flags[j] == '\0')
//                     break;
//                 *i++;
//             }
//             if (index > 0)
//             {
//                 res[index] = '\0';
//                 return res;
//             }
//         }
//         *i++;
//     }
//     free(res);
//     return NULL;
// }
char *parser(const char *str, int *i)
{
    int start = *i;
    while (str[*i] && str[*i + 1] != '%')
    {
        (*i)++;
    }
    (*i)++; // include the last character in the substring
    char *res = (char *)calloc(*i - start + 1, sizeof(char));
    if (res == NULL)
    {
        return NULL;
    }
    strncpy(res, str + start, *i - start);
    return res;
}

static char **split(const char *str)
{
    char **res;
    int i = 0;
    int wc = count_words(str);
    res = (char **)calloc(wc + 1, sizeof(char *));
    if (!res)
    {
        return NULL;
    }
    int j = 0;
    while (j < wc)
    {
        res[j] = parser(str, &i);
        if (res[j] == NULL)frei
        {
            for (int k = 0; k < j; k++)
            {
                free(res[k]);
            }
            free(res);
            return NULL;
        }
        if (str[i] == '%')
        {
            i++; // skip '%'
        }
        j++;
    }
    return res;
}
int main()
{
    char ** str = split("dayali => %.+d %% %d");
    printf("%s\n",str[0]);
        printf("%s\n",str[1]);

    printf("%s\n",str[2 ]);

}

static int check_douplicate_parser(const char *str)
{
    int i = 0;
    int cheack = 0;
    int j = 0;
    while (str[i])
    {
        j = 0;
        cheack = 0;
        while (str[j])
        {
            if (str[i] == str[j])
            {
                cheack++;
                if (cheack > 1)
                    return (1);
            }
            j++;
        }
        i++;
    }
    return (0);
}

static int plus(const char *str, int number, int *len)
{
    int is_ok = 0;
    if (number >= 0)
    {
        ft_putchar_fd('+',1);
        len += ft_putnbr_fd(number, 1) + 1 ;
    }
    return (is_ok);
}
// int ft_printf(const char *str, ...)
// {
//     va_list ap;
//     va_start(ap, str);
//     ///////////////////
//     int i = 0;
//     int lenght_printf = 0;
//     char *after_parsing;
//     ///////////////////
//    while (str[i])
//    {
//         after_parsing = parser(str);
//         printf("%s/n",after_parsing);
//         if (!check_douplicate_parser(str))
//         {
//             plus(after_parsing, va_arg(ap, int),&lenght_printf);
//         }
//         i++;
//     }
//     va_end(ap);
//     return (lenght_printf);
// }

