#include "header/libftprintf.h"
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

static int cheack_flags(char str)
{
    if (str == '-'  || str == '+' || str == '-' || str == '#' || str == '.' || str == ' ' ||
        str == 'i' || str == 'd' || str == 's' || str == 'c' || str == 'x' || str == 'X' ||
        str == 'p' || str == 'u' ||ft_isdigit(str))
        return 1;
    return 0;
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
    
    {
        len += ft_putchar_fd('0',1);
    }
    return (len);
} 

static int check_flags2(char c)
{
    char *flags = "csidpuxX#.+- 0123456789%";
    while (*flags)
    {
        if (c == *flags)
            return 1;
        flags++;
    }
    return 0;
}
static int count_words(const char *str)
{
    size_t i = 0;
    int count = 0;
    while (str[i])
    {
        if (str[i] == '%')
        {
            i++;
            if (check_flags2(str[i]))
                count++;
        }
        i++;
    }
    return count;
}

char *set_word(const char *str, char *sep)
{
    char *word;
    int i =0;
    word = ft_calloc(sizeof(char),);
    if (!word)
        return (NULL);
}

static char **split(const char *str, char *sep)
{
    char **res;
    int start = 0
    int end = 0;
    int i  = 0;
    int count_words = count_words(str);
    res = ft_calloc(sizeof(char *), count_words + 1);
    if (!res)
        return (NULL);
    while (i < count_words)
    {
        res[i] = set_word(str,sep);
        i++;
    }
    return (res);
}
char *parser(const char *str)
{
    int i = 0;
    int j = 0;
    int index = 0;
    char *flags = "csidpuxX#.+- 0123456789%";
    char *res = (char *)ft_calloc(ft_strlen(str) + 1, sizeof(char *));
    if (res == NULL)
        return NULL;
    while(str[i])
    {
        if (str[i] == '%')
        {
            i++;
            while (str[i])
            {
                j = 0;
                while (flags[j])
                {        
                    if (str[i] == flags[j])
                    {
                        res[index] = str[i];
                        index++;
                        break;
                    }
                    j++;
                }
                if (flags[j] == '\0')
                    break;
                i++;
            }
            if (index > 0)
            {
                res[index] = '\0';
                return res;
            }
        }
        i++;
    }
    free(res);
    return NULL;
}
int main()
{
    printf("%d\n", count_words("dyali => %s|| %s%x %d %% %p %s %f" ));

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

