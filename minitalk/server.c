/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharley <xcharley@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:52:24 by xcharley          #+#    #+#             */
/*   Updated: 2022/02/14 21:03:45 by xcharley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sigusr_handler(int sig)
{
	static int	i = 0;
	static int	c = 0;
	static int	power = 128;
	char		ch;

	if (i < 8)
	{
		if (sig == SIGUSR2)
		{
			c = c + (1 * power);
		}
		power = power / 2;
		i++;
	}
	if (i == 8)
	{
		ch = (char)c;
		write(1, &ch, 1);
		i = 0;
		c = 0;
		power = 128;
	}
}

int	main(void)
{
	write(1, "PID: ", 5);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR1, &sigusr_handler);
		signal(SIGUSR2, &sigusr_handler);
		pause();
	}
	return (1);
}
