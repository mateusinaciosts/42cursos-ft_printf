#include <unistd.h>
#include <stdio.h> 

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
int	ft_putstr(char *str)
{
	int	n;

	n = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[n] != '\0')
	{
		ft_putchar(str[n]);
		n++;
	}
	return (1);
}
int	ft_putptr(unsigned long nbr, int flag)
{
    char HEX[] = "0123456789ABCDEF"; 
	if (nbr == 0)
	{
		ft_putstr("(nil)");
		return (0);
	}
	if (flag == 0)
		ft_putstr("0x");
	if (nbr > 15)
		ft_putptr(nbr / 16, 1);
	write(1, &HEX[nbr % 16], sizeof(char));
	return (1);
}

int main(void)
{
    char *str2;
    str2 = "gato";
    unsigned long ulong_str = (unsigned long)str2;
    ft_putptr(ulong_str, 0);
    printf("\nPrintf:%p", str2);
}
