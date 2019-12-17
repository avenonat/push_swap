/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenonat <avenonat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 14:51:36 by avenonat          #+#    #+#             */
/*   Updated: 2019/12/17 16:43:04 by avenonat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

int		main(int argc, char **argv)
{
	int i;
	char **new;
	t_folder *stack_a;
	t_folder *stack_b;
	t_num ssl;

	ssl.count_a = 0;
	ssl.count_b = 0;
	stack_b = NULL;
	stack_a = NULL;
	i = 1;
	if (argc == 1)
		return (0);
	else if (argc >= 2)
	{
		while (argc > i)
		{
			new = ft_strsplit(argv[i], ' ');
			if (check_str(new))
			{
				write(1, "Error\n", 6);
				return (0);
			}
			ssl.count_a += push_swap(new, &stack_a);
			if (ssl.count_a < 0)
				return (-1);
			i++;
		}
		major(&stack_a, &stack_b, &ssl);
		free(new);
	}
	return (0);
}