/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:10:31 by hyojeong          #+#    #+#             */
/*   Updated: 2022/05/26 17:34:29 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int	g_bit_cnt;

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
		ft_putnbr(g_bit_cnt);
		ft_putstr(" / ");
		ft_putnbr(tmp);
		ft_putstr("\n");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	int					idx;
	struct sigaction	t_client;

	idx = -1;
	t_client.sa_sigaction = check_connection_handler;
	t_client.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &t_client, NULL) != 0)
		error("Sigactioin Error : Please retry.\n");
	if (sigaction(SIGUSR2, &t_client, NULL) != 0)
		error("Sigactioin Error : Please retry.\n");
	if (!(argc == 3))
		error("Usage : ./client [PID] [texts]\n");
	if (ft_atoi(argv[1]) < 100 && ft_atoi(argv[1]) > 99998)
		error("pid must be 100 < pid < 99999\n");
	g_bit_cnt = 8;
	while (argv[2][++idx])
	{
		make_bit(argv[2][idx], ft_atoi(argv[1]), 8);
		usleep(300);
		g_bit_cnt += 8;
	}
	make_bit(127, ft_atoi(argv[1]), 8);
	while (1)
		pause();
	return (0);
}
