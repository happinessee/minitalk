/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:48:12 by hyojeong          #+#    #+#             */
/*   Updated: 2022/05/26 12:50:19 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

#include <signal.h>
#include <unistd.h>

void	gather_bit(int signo, int *tmp)
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

void	make_bit(int tmp, int pid, int cnt)
{
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
