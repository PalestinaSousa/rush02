/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 10:48:22 by anagomez          #+#    #+#             */
/*   Updated: 2024/07/28 22:39:06 by jose-ang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "print_names.h"

int	ft_order(char *number)
{
	int	i;

	i = 0;
	while (number[i])
	{
		i++;
	}
	return (i - 1);
}

int	atoi(char *str, int i, int ndigits)
{
	int	n;

	if (ndigits == 2)
		n = (str[i] - '0') * 10 + (str[i + 1] - '0');
	else
		n = str[i] - '0';
	return (n);
}

void	print_decenas(int *i, int *order, char *number, int all_zero)
{
	if (number[*i] != '0')
	{
		ft_decenas(atoi(number, *i, 2), *order);
		if (*order > 3)
		{
			*order = *order - 1;
			i++;
		}
		
		else if (number[*i] == 0)
		{
			*order = *order - 2;
			i += 2;
		}
		else
		{
			*order -= 1;
			i++;
		}
		
	}
	else if (number[*i] == '0')
	{
		*order -= 1;
		i++;
	}
	else
	{
		*order -= 1;
		ft_blocks(order, all_zero);
		i++;
	}
}

void	print_centenas(int *i, int *order, char *number)
{
	ft_centenas(atoi(number, *i, 1), *order);
	*order -= 1;
	i++;
}

void	print_unidades(int *i, int *order, char *number, int all_zero)
{
	if (*order == 0 && *i == 0)
		ft_unidades(atoi(number, *i, 1), *order, *i);

	else if (*order > 0)
	{
		if (number[*i - 1] == '0' || *i == 0)
			ft_unidades(atoi(number, *i, 1), *order, *i);
	}
	else if (*order == 0 && number[*i - 1] == '0')
		ft_unidades(atoi(number, *i, 1), *order, *i);
	ft_blocks(order, all_zero);
	*order -= 1;
	i++;
}


void	ft_print_oneargument(char *number)
{
	int	i;
	int	order;
	int	all_zero;

	i = 0;
	all_zero = 0;
	order = ft_order(number);
	while (number[i] != '\0')
	{
		if (order % 3 == 1)
			print_decenas(&i, &order, number, all_zero);
		else if (order % 3 == 2)
		{
			if (number[i] == '0' && number[i + 1] == '0'&& number[i + 2] == '0')
				all_zero = 1;
			print_centenas(&i, &order, number);
		}
		else if (order >= 0)
		{
			print_unidades(&i, &order, number, all_zero);
		}
		i++;
	}
}
