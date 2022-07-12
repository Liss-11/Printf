/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:21:42 by afrolova          #+#    #+#             */
/*   Updated: 2022/07/12 15:11:06 by afrolova         ###   ########.fr       */
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
	f = ft_printf(str, 111, -22, -44, "alissia", 1, 252, 'd', -251, &g);
	p = printf("\nCom\no estas %d\n %i %u\n %s %c %X %c %x\n %p %%%%%%%%\n", 111, -22, -44, "alissia", 1, 252, 'd', -251, &g);
	printf("ft_printf_retorn: %d\n", f);
	printf("Printf_retorn: %d\n", p);
	return (0);
}


//que pasa si pongo un numero impar de %%%...?
//porque el printf me devuelve un int% si imprimo el %%?
