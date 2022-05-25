/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:10:18 by hyojeong          #+#    #+#             */
/*   Updated: 2022/05/25 15:42:59 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>

struct sigaction	t_server;
struct sigaction	t_client;

/* server */
void	gather_bit(int signo, int *tmp);

/* client */
void	make_bit(int tmp, int pid, int cnt);

/* utils */
void	ft_putchar(char c);
void    ft_putnbr(int n);
void	ft_putstr(char *str);
void	put_pid();
int		ft_atoi(const char *str);
void	error(char *error_message);

#endif