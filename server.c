/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 11:37:12 by dclark            #+#    #+#             */
/*   Updated: 2021/06/04 11:50:34 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sig_receive_2(int num)
{
	static int	binary;
	static int	result;
	static int	count;
	char		c;

	if (count == 0)
		binary = 128;
	if (num == SIGUSR2)
		result += binary;
	binary /= 2;
	count++;
	if (count == 8)
	{
		c = result;
		write(1, &c, 1);
		count = 0;
		binary = 128;
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
