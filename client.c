/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 11:37:35 by dclark            #+#    #+#             */
/*   Updated: 2021/06/15 13:26:28 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

static int	check_error(int ac, char **av)
{
	int	i_str;

	i_str = -1;
	if (ac != 3)
		return (1);
	while (av[1][++i_str])
		if (av[1][i_str] < '0' || av[1][i_str] > '9')
			return (1);
	return (0);
}

static void	cara_to_binary(unsigned char c, int pid)
{
	unsigned int	binary;

	binary = 128;
	while (binary)
	{
		if (binary <= c)
		{
			c -= binary;
			kill(pid, SIGUSR2);
		}
		else
			kill(pid, SIGUSR1);
		binary /= 2;
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	int	i_str;
	int	pid;

	if (check_error(ac, av))
		exit(EXIT_FAILURE);
	pid = ft_atoi(av[1]);
	i_str = 0;
	while (av[2][i_str])
	{
		cara_to_binary(av[2][i_str], pid);
		usleep(75);
		i_str++;
	}
	exit(EXIT_SUCCESS);
}
