/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:10:37 by hyojeong          #+#    #+#             */
/*   Updated: 2022/05/24 19:41:16 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void	gather_bit(int signo, unsigned char *tmp)
{
	if (signo == SIGUSR1)
	{
		*tmp = (*tmp << 1) + 1;
	}
	else
	{
		*tmp = (*tmp << 1);
	}
}

void	receive_handler(int signo, siginfo_t *info, void *context)
{
	static unsigned char	tmp;
	static int				idx;
	static int				bit_cnt;
	static int				pre_pid;
	
	if (pre_pid == 0)
		pre_pid = info->si_pid;
	if (!(info->si_pid == pre_pid))
	{
		ft_putnbr(info->si_pid);
		error("it is not client's PID\n");
	}
	// (void)info;
	(void)context;
	gather_bit(signo, &tmp);
	idx++;
	bit_cnt++;
	if (idx == 8)
	{
		ft_putchar(tmp);
		idx = 0;
	}
	if (tmp == 127)
	{
		pre_pid = 0;
	}
}

int	main(void)
{
	put_pid();
	t_server.sa_sigaction = receive_handler;
	t_server.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &t_server, NULL) != 0)
		error("Sigactioin Error : Please retry.\n");
	if (sigaction(SIGUSR2, &t_server, NULL) != 0)
		error("Sigaction Error : Please retry.\n");
	while (1)
		pause();
	return (0);
}
