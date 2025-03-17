/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chquinde <chquinde@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:02:49 by jquinde-          #+#    #+#             */
/*   Updated: 2025/03/15 23:28:16 by chquinde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_valid_number(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

// Checks for duplicates in an array
int	has_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	validate_and_convert(t_stack *a, char *arg)
{
	long	num;

	if (!is_valid_number(arg))
	{
		write(STDERR_FILENO, "Error\nNumero invalido\n", 23);
		free(a->stack);
		exit(EXIT_FAILURE);
	}
	num = atol(arg);
	if (num < INT_MIN || num > INT_MAX)
	{
		write(STDERR_FILENO, "Error\nNumero fuera de rango\n", 28);
		free(a->stack);
		exit(EXIT_FAILURE);
	}
	stk_push(a, (int)num);
}

void	parse_input(t_stack *a, int argc, char **argv)
{
	int	i;

	i = argc -1;
	if (argc < 2)
		exit(write(STDERR_FILENO, "Error\nParametros erroneos\n", 27));
	*a = stk_new(argc - 1);
	if (!a->stack)
		exit(write(STDERR_FILENO, "Error\nMemoria fallida\n", 23));
	while (i > 0)
		validate_and_convert(a, argv[i--]);
	if (has_duplicates(a->stack, a->capacity))
	{
		write(STDERR_FILENO, "Error\nNumero duplicado\n", 24);
		free(a->stack);
		exit(EXIT_FAILURE);
	}
}
