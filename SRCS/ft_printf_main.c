/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:21:42 by afrolova          #+#    #+#             */
/*   Updated: 2022/07/13 16:13:02 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	main(void)
{
	char const	*str = "\nCom\no estas %d\n %i %u\n %s %c %X %c %x\n %p %%%%%%%%\n";
	int			p;
	int			f;
	int			g;



	g = 3;
	printf("%s\n", "<-------------- Mandatory Part --------------->");
	f = ft_printf(str, 111, -22, -44, "alissia", 1, 252, 'd', -251, &g);
	p = printf("\nCom\no estas %d\n %i %u\n %s %c %X %c %x\n %p %%%%%%%%\n", 111, -22, -44, "alissia", 1, 252, 'd', -251, &g);
	printf("ft_printf_retorn: %d\n", f);
	printf("Printf_retorn: %d\n", p);

	printf("%s\n", "<-------------- Bonus Part --------------->");
	printf("%s\n", "Uso del 0");
	f = ft_printf("Uso del 0 ORIGINAL: %08d\n %05d\n", 111, 2);
	p = printf("Uso del 0 FT_PRINTF: %08d\n %05d\n", 111, 2);
	printf("ft_printf_retorn: %d\n", f);
	printf("Printf_retorn: %d\n", p);
	return (0);
}
