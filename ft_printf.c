#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
void check_flag(char ind, va_list args);
int ft_printf(char *formart, ...)
{
    va_list args;
    int i;

    i = 0;
    va_start(args, formart);
    while (*formart)
    {
        if (*formart == '%')
        {
            check_flag(formart[1], args);
            formart += 1;
        }
        else
        {
            write(1, formart, 1);
        }
        formart++;
    }
    va_end(args);
    return (0);
}

int main(void)
{
    ft_printf("hello %c%s guys\n", "World", ", welcome");
    ft_printf("%s!!\n", "Hello world");

}

void check_flag(char chr, va_list arg)
{
    if (chr == 's')
    {
        char *str;
        str = va_arg(arg, char *);
        while (*str)
        {
            write(1, str, 1);
            str++;
        }
    }
    if (chr == 'c')
    {
        char *str;
        str = va_arg(arg, char *);
        write(1, &str[0], 1);
    }
}
