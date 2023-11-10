/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:03:34 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/03 11:06:55 by geraudtsers      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_format(va_list args, const char *format)
{
	int	print_length;

	print_length = 0;
	if (*format == 'c')
		print_length += ft_print_char(va_arg(args, int));
	else if (*format == '%')
		print_length += ft_print_char(*format);
	else if (*format == 's')
		print_length += ft_print_str(va_arg(args, char *));
	else if (*format == 'p')
		print_length += ft_print_address(va_arg(args, unsigned long long),
				"0123456789abcdef");
	else if (*format == 'd' || *format == 'i')
		print_length += ft_print_nbrbase(va_arg(args, int), "0123456789");
	else if (*format == 'u')
		print_length += ft_print_nbrbase(va_arg(args, unsigned int),
				"0123456789");
	else if (*format == 'x')
		print_length += ft_print_nbrbase(va_arg(args, unsigned int),
				"0123456789abcdef");
	else if (*format == 'X')
		print_length += ft_print_nbrbase(va_arg(args, unsigned int),
				"0123456789ABCDEF");
	return (print_length);
}

int	ft_printf(const char *format, ...)
{
	int		print_length;
	va_list	args;

	if (!format || *format == '\0')
		return (0);
	va_start(args, format);
	print_length = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			print_length += ft_print_format(args, format);
		}
		else
			print_length += ft_print_char(*format);
		format++;
	}
	va_end(args);
	return (print_length);
}

/*
#include <stdio.h>
int	main(void)
{
	int				count_printf;
	int				count_ft_printf;
	int			c;
	char			*s;
	int			*p;
	int				d;
	int				i;
	int				u;
	unsigned int	x;
	unsigned int	X;

	count_printf = 0;
	count_ft_printf = 0;
	c = -40000;
	s = "";
	p = &c;
<<<<<<< HEAD
	d = 14137;
	i = 14137561;
	u = -141375;
	x = 1413756;
	X = -14137;
=======
	d = 1413756;
	i = 141375;
	u = -141;
	x = 1413756;
	X = -141375;
>>>>>>> 074a4be4e08e56148f71951409a40111cc1ff6f3
	printf("Fonction printf original:\n");
	//count_printf = printf("%s", s);
	count_printf += printf("%c", c);
	count_printf += printf("NULL %s NULL", s);
	count_printf += printf(" %p", p);
	count_printf += printf(" %d ", d);
	count_printf += printf("%i ", i);
	count_printf += printf("%u ", u);
	count_printf += printf("%x", x);
	count_printf += printf(" %X", X);
	count_printf += printf(" %%%% ");
	printf("\n");
	printf("Ma fonction printf:\n");
	//count_ft_printf = ft_printf("%s", s);
	count_ft_printf = ft_printf("%cNULL %s NULL %p %d %i %u %x %X %%%% ",
			c, s, p, d, i, u, x, X);
	printf("\n");
	printf("Count de printf: %d\n", count_printf);
	printf("Count de ft_printf: %d\n", count_ft_printf);
	return (0);
}
*/
