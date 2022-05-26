/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:10:18 by hyojeong          #+#    #+#             */
/*   Updated: 2022/05/26 12:51:11 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

/* server */
void	gather_bit(int signo, int *tmp);

/* client */
void	make_bit(int tmp, int pid, int cnt);

/* utils */
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char *str);
void	put_pid(void);
int		ft_atoi(const char *str);
void	error(char *error_message);

#endif