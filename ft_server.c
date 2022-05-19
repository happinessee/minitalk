/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:10:37 by hyojeong          #+#    #+#             */
/*   Updated: 2022/05/20 06:07:57 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void	check_bit(int pid)
{
	kill(pid, SIGUSR1);
	ft_putstr("signal to client, ok\n");
}

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
	(void)info;
	(void)context;

	gather_bit(signo, &tmp);
	usleep(100);
	idx++;
	if (idx == 8)
	{
		ft_putchar(tmp);
		check_bit(info->si_pid);
		ft_putnbr(info->si_pid);
		idx = 0;
	}
}

void	check_handler(int signo, siginfo_t *info, void *context)
{

}

int	main()
{
	put_pid();
	t_server.sa_sigaction = check_handler;
	t_server.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &t_server, NULL) != 0)
		error("Sigactioin Error : Please retry.\n");
	if (sigaction(SIGUSR2, &t_server, NULL) != 0)
		error("Sigaction Error : Please retry.\n");
	while (1)
		pause();
	return (0);
}
