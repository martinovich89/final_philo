/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenry <mhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 01:51:10 by martin            #+#    #+#             */
/*   Updated: 2022/02/17 15:40:04 by mhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_current_time(void)
{
	struct timeval	tv;
	struct timezone	tz;

	gettimeofday(&tv, &tz);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

int	sleep_until(t_phi *phi, size_t stop)
{
	t_vars	*vars;
	size_t	time;

	vars = phi->vars;
	time = get_current_time();
	while (time < stop)
	{
		pthread_mutex_lock(&vars->death);
		if (vars->is_dead)
		{
			phi->elapsed_time = get_current_time() - phi->vars->chrono_start;
			return (unlock_and_return(&vars->death, NULL));
		}
		pthread_mutex_unlock(&vars->death);
		usleep(200);
		time = get_current_time();
	}
	return (0);
}

int	wait_for_death(t_phi *phi)
{
	pthread_mutex_unlock(phi->first_fork);
	sleep_until(phi, ~0);
	return (1);
}

void	make_delay(t_phi *phi)
{
	int	n;

	n = phi->vars->tte * 250;
	if (n > phi->vars->ttd * 1000)
		n = phi->vars->ttd * 900;
	if (phi->id % 2 == 0)
		usleep(n);
}
