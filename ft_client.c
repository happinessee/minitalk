/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:10:31 by hyojeong          #+#    #+#             */
/*   Updated: 2022/05/17 19:09:47 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include <unistd.h>

void	make_bit(int tmp, int pid)
{
	int	cnt;

	cnt = 8;
	while (--cnt != -1)
	{
		if ((tmp & (1 << cnt)) >> cnt)
		{
			ft_putchar('1');
			kill(pid, SIGUSR1);
		}
		else
		{
			ft_putchar('0');
			kill(pid, SIGUSR2);
		}
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	tmp;
	int	idx;

	idx = 0;
	sigaction(SIGUSR1, &t_client, NULL);
	sigaction(SIGUSR2, &t_client, NULL);
	if (!(argc == 3))
		ft_putstr("Usage : ./client [PID] [texts]\n");
	else
	{
		tmp = (int)argv[2][idx];
		make_bit(tmp, ft_atoi(argv[1]));
	}
	return (0);
}