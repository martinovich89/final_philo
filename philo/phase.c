/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenry <mhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 01:55:08 by martin            #+#    #+#             */
/*   Updated: 2022/02/17 15:36:32 by mhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eat_phase(t_phi *phi)
{
	pthread_mutex_lock(phi->first_fork);
	if (print_status(phi, "has taken a fork", 1))
		return (unlock_and_return(phi->first_fork, NULL));
	if (phi->first_fork == phi->last_fork)
		return (wait_for_death(phi));
	pthread_mutex_lock(phi->last_fork);
	if (print_status(phi, "has taken a fork", 1))
		return (unlock_and_return(phi->last_fork, phi->first_fork));
	if (print_status(phi, "is eating", 2))
		return (unlock_and_return(phi->last_fork, phi->first_fork));
	if (++phi->meal_counter == phi->vars->maxmeal)
	{
		pthread_mutex_lock(&phi->vars->meal);
		(*phi->satiated)++;
		pthread_mutex_unlock(&phi->vars->meal);
	}
	if (sleep_until(phi, get_current_time() + (size_t)phi->vars->tte * 1000))
		return (unlock_and_return(phi->last_fork, phi->first_fork));
	pthread_mutex_unlock(phi->last_fork);
	pthread_mutex_unlock(phi->first_fork);
	return (0);
}

int	sleep_phase(t_phi *phi)
{
	if (print_status(phi, "is sleeping", 3))
		return (1);
	usleep(10);
	if (sleep_until(phi, get_current_time() + (size_t)phi->vars->tts * 1000))
		return (1);
	return (0);
}

int	think_phase(t_phi *phi)
{
	if (print_status(phi, "is thinking", 3))
		return (1);
	usleep(10);
	return (0);
}

int	launch_phases(t_phi *phi)
{
	while (1)
	{
		if (check_satiated(phi))
			return (1);
		if (eat_phase(phi))
			return (1);
		if (sleep_phase(phi))
			return (1);
		if (think_phase(phi))
			return (1);
	}
	return (0);
}
