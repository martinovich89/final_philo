/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenry <mhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 01:49:47 by martin            #+#    #+#             */
/*   Updated: 2022/02/17 14:58:18 by mhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_all_mutex(t_vars *vars)
{
	size_t	i;

	i = 0;
	while (i < (size_t)vars->philo_count)
	{
		pthread_mutex_destroy(vars->mutex + i);
		i++;
	}
	pthread_mutex_destroy(&vars->death);
	pthread_mutex_destroy(&vars->meal);
	pthread_mutex_destroy(&vars->time);
}

int	join_all_threads(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->amount_of_threads_to_join)
	{
		if (pthread_join(vars->phi[i].philo, NULL))
			return (1);
		i++;
	}
	return (0);
}

int	clear_all(t_vars *vars)
{
	if (vars->phi)
	{
		if (join_all_threads(vars))
			return (write(1, "FATAL\n", 6));
		free(vars->phi);
		vars->phi = NULL;
	}
	if (vars->mutex)
	{
		destroy_all_mutex(vars);
		free(vars->mutex);
		vars->mutex = NULL;
	}
	return (0);
}
