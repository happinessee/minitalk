/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:17:36 by hyojeong          #+#    #+#             */
/*   Updated: 2022/05/16 14:32:29 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include <unistd.h>
#include <stddef.h>

static void    ft_putchar_fd(char c, int fd)
{
        write(fd, &c, 1);
}

void    ft_putnbr(int n)
{
        long long       num;

        num = (long long)n;
        if (num < 0)
        {
                num *= -1;
                ft_putchar_fd('-', 1);
        }
        if (num >= 10)
                ft_putnbr(num / 10);
        ft_putchar_fd(num % 10 + 48, 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (s[cnt])
		cnt++;
	return (cnt);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

void	put_pid()
{
	ft_putstr("Server's PID : [");
	ft_putnbr(getpid());
	ft_putstr("]\n");
}