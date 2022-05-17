/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:10:37 by hyojeong          #+#    #+#             */
/*   Updated: 2022/05/17 18:34:23 by hyojeong         ###   ########.fr       */
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

void	handler(int signo, siginfo_t *info, void *context)
{
	static unsigned char	tmp;
	static int				idx;
	(void)info;
	(void)context;

	gather_bit(signo, &tmp);
	idx++;
	if (idx == 8)
	{
		ft_putchar(tmp);
		idx = 0;
	}
}

int	main()
{
	put_pid();
	t_server.sa_sigaction = handler;
	t_server.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &t_server, NULL) != 0)
	{
		ft_putstr("Sigaction Error");
		exit(1);
	}
	if (sigaction(SIGUSR2, &t_server, NULL) != 0)
	{
		ft_putstr("Sigaction Error");
		exit(1);
	}
	while (1)
	{
		;
	}
	return (0);
}
