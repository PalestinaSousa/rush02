/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_names.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 20:08:11 by anagomez          #+#    #+#             */
/*   Updated: 2024/07/28 22:43:28 by jose-ang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#define MAX_ENTRIES 1000
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
void ft_print(char *str);

struct Entry
{
	long double	key;
	char	value[100];
}dictionary[MAX_ENTRIES];

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
void	ft_decenas(int nb, int order)
{
	int index;
	int recorrer;

	index = 0;
	recorrer = 0;
	FILE *file;
	file = fopen("Dictionary/numbers.dict", "r");
	if (file == NULL)
       	{
		printf("Error al abrir el archivo.\n");
		return ;
	}

	while (fscanf(file, "%Lf: %s", &dictionary[index].key, dictionary[index].value) == 2)
	{
		index++;
		if (index >= MAX_ENTRIES)
		{
			break;
		}
	}

	if (nb / 10 == 1 || nb % 10 == 0)
	{
		while (recorrer <= MAX_ENTRIES)
                {
			if (nb * 1.0 == dictionary[recorrer].key)
			{
				ft_print(dictionary[recorrer].value);
				break;
			}
			recorrer++;
		}
	}
	else
	{
		while (recorrer <= MAX_ENTRIES)
                {
			if ((nb / 10) * 10.0 == dictionary[recorrer].key)
			{
				ft_print(dictionary[recorrer].value);
				break;
			}
			recorrer++;
		}
		recorrer = 0;
		while (recorrer <= MAX_ENTRIES)
		{
			if ((nb % 10) * 1.0 == dictionary[recorrer].key && nb % 10 != 0)
			{
				ft_print(dictionary[recorrer].value);
				break;
			}
			recorrer++;

		}
	}
}

void	ft_centenas(int nb, int order)
{
	int	 index;
	int	 recorrer;

	index = 0;
	recorrer = 0;
	FILE *file;
	file = fopen("Dictionary/numbers.dict", "r");
	if (file == NULL)
       	{
		printf("Error al abrir el archivo.\n");
		return ;
	}

	while (fscanf(file, "%Lf: %s", &dictionary[index].key, dictionary[index].value) == 2)
	{
		index++;
		if (index >= MAX_ENTRIES)
		{
			break;
		}
	}

	if (nb != 0) // que no imprima zero hundred
	{
		while (recorrer <= MAX_ENTRIES)
		{
			if (nb * 1.0 == dictionary[recorrer].key)
				ft_print(dictionary[recorrer].value);
			if (100.0 == dictionary[recorrer].key)
			{
				ft_print(dictionary[recorrer].value);
			}
			recorrer++;
		}
	}
}

void	ft_unidades(int nb, int order, int i)
{
   	int index = 0;

	FILE *file = fopen("Dictionary/numbers.dict", "r");
    	if (file == NULL) {
        printf("Error al abrir el archivo.\n");
        return ;
    }

    while (fscanf(file, "%Lf: %s", &dictionary[index].key, dictionary[index].value) == 2)
    {
        index++;
        if (index >= MAX_ENTRIES) {
            break;
        }
    }

	int recorrer = 0;
	if (nb != 0 || (order == 0 && i == 0))
	{
		while (recorrer <= MAX_ENTRIES)
		{
			if (nb * 1.0 == dictionary[recorrer].key)
			{
				ft_print(dictionary[recorrer].value);
				break;
			}
			recorrer++;
		}	
	}
}

long double	ft_pow(int order)
{
	long double	result;
	int	iter;

	result = 1;
	iter = 0;
	while (iter < order)
	{
		result = result * 10;
		iter++;
	}
	return (result);
}

void	ft_blocks(int *order, int all_zero)
{
	int	index;
	int	recorrer;
	long double	i;

	index = 0;
	recorrer = 0;
	FILE *file;
	file = fopen("Dictionary/numbers.dict", "r");
	if (file == NULL)
       	{
		printf("Error al abrir el archivo.\n");
		return ;
	}

	while (fscanf(file, "%Lf: %s", &dictionary[index].key, dictionary[index].value) == 2)
	{
		index++;
		if (index >= MAX_ENTRIES)
		{
			break;
		}
	}
	if (*order != 0)
	{
		i = ft_pow(*order);
	}
	if (all_zero)
		write(1, " ", 1);
	else if (*order != 0)
	{
		while (recorrer <= MAX_ENTRIES)
		{
			if (i == dictionary[recorrer].key)
			{
				ft_print(dictionary[recorrer].value);
				break;
			}
			recorrer++;
		}
	}
}

void	ft_print(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, " ", 1);
}
