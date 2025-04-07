/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:31:33 by ncolomer          #+#    #+#             */
/*   Updated: 2019/10/18 22:53:10 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	putnubr(long int n, int base, int lenght)
{
	if (lenght > 1)
		putnubr(n / base, base, lenght - 1);
	n = n % base + 48 + (n % base > 9) * 39;
	write(1, &n, 1);
}

/*
static void rev_putnubr(long int n, int base, int lenght)
{
	long cp;

	cp = n;
	n = n % base + 48 + (n % base > 9) * 39;
	write(1, &n, 1);
	if (lenght > 1)
		rev_putnubr(cp / base, base, lenght - 1);
}
*/

static void	puthex(unsigned char *addr, int bytes)
{
	int	i;

	i = 0;
	while (bytes > 0 && i < 16)
	{
		putnubr(*addr, 16, 2);
		addr++;
		bytes--;
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
	while (i < 16)
	{
		write(1, "  ", 2);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
}

static void	puttext(unsigned char *addr, int bytes)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (bytes > 0)
		{
			if (31 < *addr && *addr < 127)
				write(1, addr, 1);
			else
				write(1, ".", 1);
		}
		bytes--;
		addr++;
		i++;
	}
}

void	ft_print_memory(void *addr, unsigned int bytes)
{
	unsigned char	*charaddr;

	charaddr = (unsigned char *) addr;
	while (bytes != 0)
	{
		putnubr((long int) charaddr, 16, 16);
		write(1, " ", 1);
		puthex(charaddr, bytes);
		puttext(charaddr, bytes);
		if (bytes < 16)
			bytes = 0;
		else
			bytes -= 16;
		charaddr += 16;
		write(1, "\n", 1);
	}
}
