/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 12:07:34 by dclark            #+#    #+#             */
/*   Updated: 2021/06/04 16:05:44 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sig_receive_2(int num)
{
	static int	binary;
	static int	result;
	static int	count;

	if (count == 0)
		binary = 32768;
	if (num == SIGUSR2)
		result += binary;
	binary /= 2;
	count++;
	if (count == 16)
	{
		if (result == 0)
			write(1, "\nFIN\n", 5);
		else
			write(1, &result, 1);
		count = 0;
		binary = 32768;
		result = 0;
	}
}

int	main(void)
{
	printf("pid:%d\n", getpid());
	signal(SIGUSR1, sig_receive_2);
	signal(SIGUSR2, sig_receive_2);
	while (1)
		pause();
}
