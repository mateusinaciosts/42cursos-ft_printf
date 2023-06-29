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
	if (nbr == 0)
	{
		ft_putstr("(nil)");
		return (0);
	}
	if (flag == 0)
		ft_putstr("0x");
	if (nbr > 15)
		ft_putptr(nbr / 16, 1);
	write(1, &"0123456789abcdef"[nbr % 16], sizeof(char));
	return (1);
}

void	ft_put_hex_lower(unsigned int nbr)
{
	if (nbr > 15)
		ft_put_hex_lower(nbr / 16);
	write(1, &"0123456789abcdef"[nbr % 16], sizeof(char));
}

void	ft_put_hex_upper(unsigned int nbr)
{
	if (nbr > 15)
		ft_put_hex_upper(nbr / 16);
	write(1, &"0123456789ABCDEF"[nbr % 16], sizeof(char));
}

int main(void)
{
    int numb;
    numb = 2468;
    ft_putptr(numb, 0);
	printf("\n");
	ft_put_hex_lower(numb);
	printf("\n");
	ft_put_hex_upper(numb);
}
