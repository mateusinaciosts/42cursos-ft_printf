#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
void conversoes(char ind, va_list args);
int ft_printf(char *formart, ...)
{
    va_list args;
    char *str;
    int i = 0;

    va_start(args, formart);
    printf("Printf: %s\n", formart);
    printf("my_function:\n");
    while (*formart)
    {
        if (*formart == '%')
        {
            conversoes(formart[1], args);
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
    char *str = "mateus";
    ft_printf("hello %c%s guys", "World", ", welcome");
}

void conversoes(char ind, va_list arg)
{
    if (ind == 's')
    {
        char *str;
        str = va_arg(arg, char *);
        while (*str)
        {
            write(1, str, 1);
            str++;
        }
    }
    if (ind == 'c')
    {
        char *str;
        str = va_arg(arg, char *);
        write(1, &str[0], 1);
    }
}