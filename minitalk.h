/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:10:18 by hyojeong          #+#    #+#             */
/*   Updated: 2022/05/17 12:42:45 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>

struct sigaction	t_server;
struct sigaction	t_client;

/* server */


/* client */


/* utils */
void	ft_putchar(char c);
void    ft_putnbr(int n);
void	ft_putstr(char *str);
void	put_pid();
int		ft_atoi(const char *str);

#endif