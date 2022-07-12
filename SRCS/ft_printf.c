/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:32:05 by afrolova          #+#    #+#             */
/*   Updated: 2022/07/12 14:53:09 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	return_value(va_list ptr, char const *str, int *we)
{
		if (*str == '%')
			return (ft_write(1,"%", 1, we));
		if (*str == 'd' || *str == 'i')
			return (ft_putnbr(va_arg(ptr, int), we));
		if (*str == 'c')
			return (my_putchar(va_arg(ptr, int), we));
		if (*str == 'u')
			return (ft_putnbr_unsigned(va_arg(ptr, unsigned int), we));
		if (*str == 's')
			return (ft_strlen_print(va_arg(ptr, char *), we));
		if (*str == 'x' || *str == 'X')
			return (to_hexadecimal(va_arg(ptr, unsigned int), *str, we));
		if (*str == 'p')
			return (ft_write_pointer(va_arg(ptr, unsigned long long), we));
		return (0);
}

int ft_printf(char const *str, ...)
{
	int		len;
//	int		resp;
	va_list	ptr;
	int		we;
	
	va_start (ptr, str);

	we = 0;
	len = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{ 
//			resp = return_value(ptr, ++str, &we);
			len += return_value(ptr, ++str, &we);
			if (we)
				return (-1);
		//	len += resp;
		}
		else
		{
			if (write(1, str, 1) != 1)
				return (-1);
			len++;
		}
		str++;
	}
	va_end (ptr);
	if(we)
		return(-1);
	return (len);
}

/*int	main(void)
{
	char const	*str = "\nCom\no estas %d\n %i %u\n %s %c %X %c %x\n";
//	char const	*str = "\nCom\no estas %d\n %i %u\n %s %c %p\n";
	int			p;
	int			f;
	int			g;
	int			*ptr;

	g = 3;
	ptr = &g;

//	f = ft_printf(str, 111, -22, -44, "alissia", 'c', 252, 'd', -251, ptr);
//	p = printf("\nCom\no estas %d\n %i %u\n %s %c %X %c %x %p\n", 222, -33, -44, "alissia", 'c', 252, 'd', -251, ptr);
	f = ft_printf(str, 111, -22, -44, "alissia", 1, 252, 'd', -251);
	p = printf("\nCom\no estas %d\n %i %u\n %s %c %X %c %x\n", 222, -33, -44, "alissia", 1, 252, 'd', -251);
	printf("ft_printf_retorn: %d\n", f);
	printf("Printf_retorn: %d", p);
	return (0);
}*/
