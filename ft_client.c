/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:10:31 by hyojeong          #+#    #+#             */
/*   Updated: 2022/05/18 13:24:29 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include <unistd.h>
#include <stdlib.h>

void	error(char *error_message)
{
	ft_putstr(error_message);
	exit(1);
}

void	make_bit(int tmp, int pid)
{
	int	cnt;

	cnt = 8;
	while (--cnt != -1)
	{
		if ((tmp & (1 << cnt)) >> cnt)
		{
			kill(pid, SIGUSR1);
		}
		else
		{
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
	if (!(argc == 3))
		error("Usage : ./client [PID] [texts]\n");
	if (ft_atoi(argv[1]) < 100 && ft_atoi(argv[1]) > 99998)
		error("pid must be 100 < pid < 99999\n");
	sigaction(SIGUSR1, &t_client, NULL);
	sigaction(SIGUSR2, &t_client, NULL);
	while (argv[2][idx])
	{
		tmp = (int)argv[2][idx];
		make_bit(tmp, ft_atoi(argv[1]));
		idx++;
	}
	return (0);
}
