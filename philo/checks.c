/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martin <martin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 01:51:44 by martin            #+#    #+#             */
/*   Updated: 2022/02/17 01:57:11 by martin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg(char *str)
{
	size_t	i;

	i = 0;
	while (is_digit(str[i]))
		i++;
	return (str[i] != '\0');
}

int	check_satiated(t_phi *phi)
{
	t_vars *vars;

	vars = phi->vars;
	pthread_mutex_lock(&vars->meal);
	if (vars->stop)
		return (unlock_and_return(&vars->meal, NULL));
	pthread_mutex_unlock(&vars->meal);
	return (0);
}

int	check_philo_satiated(t_phi *phi, t_vars *vars)
{
	(void)phi;
	pthread_mutex_lock(&vars->meal);
	if (vars->satiated == vars->philo_count)
	{
		vars->stop = 1;
		pthread_mutex_unlock(&vars->meal);
		return (1);
	}
	pthread_mutex_unlock(&vars->meal);
	return (0);
}

int	check_philo_death(t_phi *phi, t_vars *vars)
{
	pthread_mutex_lock(&vars->death);
	pthread_mutex_lock(&vars->time);
	if ((get_current_time() - phi->last_meal) / 1000 > (size_t)vars->ttd)
	{
		phi->elapsed_time = get_current_time() - vars->chrono_start;
		ft_print(phi, "died");
		vars->is_dead = 1;
		pthread_mutex_unlock(&vars->time);
		pthread_mutex_unlock(&vars->death);
		return (1);
	}
	pthread_mutex_unlock(&vars->time);
	pthread_mutex_unlock(&vars->death);
	return (0);
}

int	check_philo_status(t_vars *vars)
{
	t_phi	*phi;
	int		i;

	phi = vars->phi;
	while (1)
	{
		i = 0;
		if (check_philo_satiated(&phi[i], vars))
			return (1);
		while (i < vars->philo_count)
		{
			if (check_philo_death(&phi[i], vars))
				return (1);
			i++;
		}
	}
}
