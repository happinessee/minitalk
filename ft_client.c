/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:10:31 by hyojeong          #+#    #+#             */
/*   Updated: 2022/05/25 16:16:43 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include <unistd.h>
#include <stdlib.h>

int	bit_cnt;

void	check_connection_handler(int signo, siginfo_t *info, void *context)
{
	static int	tmp;
	static int	idx;

	(void)info;
	(void)context;
	gather_bit(signo, &tmp);
	idx++;
	if (idx == 32)
	{
		ft_putstr("bits send / receive : ");
		ft_putnbr(bit_cnt);
		ft_putstr(" / ");
		ft_putnbr(tmp);
		ft_putstr("\n");
	}
}

int	main(int argc, char **argv)
{
	int	idx;

	idx = -1;
	t_client.sa_sigaction = check_connection_handler;
	t_client.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &t_client, NULL);
	sigaction(SIGUSR2, &t_client, NULL);
	if (!(argc == 3))
		error("Usage : ./client [PID] [texts]\n");
	if (ft_atoi(argv[1]) < 100 && ft_atoi(argv[1]) > 99998)
		error("pid must be 100 < pid < 99999\n");
	bit_cnt = 8;
	while (argv[2][++idx])
	{
		make_bit(argv[2][idx], ft_atoi(argv[1]), 8);
		usleep(300);
		bit_cnt += 8;
	}
	make_bit(127, ft_atoi(argv[1]), 8);
	while (1)
		pause();
	return (0);
}
