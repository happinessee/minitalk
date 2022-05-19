/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:51:26 by hyojeong          #+#    #+#             */
/*   Updated: 2022/05/18 16:05:02 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include <stdlib.h>

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	is_space(int c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int		idx;
	int		sign;
	int		result;

	result = 0;
	idx = 0;
	sign = 1;
	while (str[idx] && is_space(str[idx]))
		idx++;
	if (str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
			sign *= -1;
		idx++;
	}
	while (str[idx] && ft_isdigit(str[idx]))
	{
		result = result * 10 + str[idx] - '0';
		idx++;
	}
	return (result * sign);
}

void	error(char *error_message)
{
	ft_putstr(error_message);
	exit(1);
}
