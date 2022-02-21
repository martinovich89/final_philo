/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martin <martin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 01:45:29 by martin            #+#    #+#             */
/*   Updated: 2022/02/20 17:26:57 by martin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_digit(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

int	ft_atoi(char *str)
{
	size_t	i;
	int		sign;
	size_t	nb;

	if (ft_strcmp(str, "-2147483648") == 0)
		return (-2147483648);
	nb = 0;
	sign = (str[0] != '-') * 2 - 1;
	i = (str[0] == '-');
	while (str[i])
	{
		if (nb > 2147483647)
			return (-1);
		nb *= 10;
		nb += str[i] - '0';
		i++;
	}
	return ((int)nb * sign);
}

int	unlock_and_return(pthread_mutex_t *mutex1, pthread_mutex_t *mutex2)
{
	if (mutex1)
		pthread_mutex_unlock(mutex1);
	if (mutex2)
		pthread_mutex_unlock(mutex2);
	return (1);
}

void	wait_all_philos(t_vars *vars)
{
	pthread_mutex_lock(&vars->time);
	while (!vars->phi[vars->philo_count - 1].last_meal)
	{
		pthread_mutex_unlock(&vars->time);
		usleep(100);
		pthread_mutex_lock(&vars->time);
	}
	pthread_mutex_unlock(&vars->time);
}
