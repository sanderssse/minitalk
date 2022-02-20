/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharley <xcharley@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:52:17 by xcharley          #+#    #+#             */
/*   Updated: 2022/02/14 21:02:51 by xcharley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	is_numeric(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (!ft_isdigit(pid[i]))
			return (0);
		i++;
	}
	return (1);
}

void	send_bit(int bit, int pid)
{
	if (bit == 0)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			write(1, "Could not send signal! Make sure PID is valid\n", 46);
			exit(EXIT_FAILURE);
		}
		usleep(100);
	}
	if (bit == 1)
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			write(1, "Could not send signal! Make sure PID is valid\n", 46);
			exit(EXIT_FAILURE);
		}
		usleep(100);
	}
}

void	convert(char c, int pid)
{
	int	i;
	int	binary[8];

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			binary[i] = 1;
		else
			binary[i] = 0;
		i--;
	}
	i = 7;
	while (i >= 0)
	{
		send_bit(binary[i], pid);
		i--;
	}
}

int	main(int argc, char **argv)
{
	static int	i = 0;
	int			pid;

	if (argc != 3 || (!is_numeric(argv[1])))
	{
		write(1, "Correct format: ./client.c <PID_SERVER> <MESSAGE>\n", 50);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		convert(argv[2][i], pid);
		i++;
	}
	return (1);
}
