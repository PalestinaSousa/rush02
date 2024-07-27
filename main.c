/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 10:05:28 by anagomez          #+#    #+#             */
/*   Updated: 2024/07/27 15:47:52 by jose-ang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac == '2')
	{
		if (ft_is_numeric(*av[1]) == 0)
		{
			write(1, "Error\n", 6);
			return (1);
		}
		else
		{
			// Aquí llamamos a la función principal con un argumento
			ft_print_oneargument(*av[1]);
			return (0);
		}
	}
	else if (ac == '3')
	{
		if (ft_is_numeric(*av[2]) == 0)
		{
			write(1, "Error\n", 6);
			return (1);
		}
		else
		{
			//Comentario en el de ana
			//Aquí llamamos a la función principal con dos argumentos
			ft_print_twoargument(*av[1], *av[2]);
			return (1);
		}
	}
	else
		write(1, "Argumento(s) no válidos\n", 24);
		return (0);
}
