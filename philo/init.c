/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martin <martin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 01:52:49 by martin            #+#    #+#             */
/*   Updated: 2022/02/17 01:56:37 by martin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_phi(t_phi *phi)
{
	t_vars *vars;

	vars = phi->vars;
	phi->left_fork = &vars->mutex[phi->id - 1];
	phi->right_fork = vars->mutex + ((int)phi->id != phi->philo_count) * (phi->id);
	if (phi->id % 2 != 0)
	{
		phi->first_fork = phi->left_fork;
		phi->last_fork = phi->right_fork;
	}
	else
	{
		phi->first_fork = phi->right_fork;
		phi->last_fork = phi->left_fork;
	}
	pthread_mutex_lock(&vars->time);
	if (!vars->chrono_start)
		vars->chrono_start = get_current_time();
	phi->last_meal = get_current_time();
	phi->elapsed_time = get_current_time() - vars->chrono_start;
	pthread_mutex_unlock(&vars->time);
}

int	set_vars(int argc, char **argv, t_vars *vars)
{
	size_t	i;

	i = 1;
	while ((int)i < argc - 1)
	{
		if (check_arg(argv[i]))
			return (-1);
		i++;
	}
	ft_memset(vars, sizeof(t_vars), 0);
	vars->philo_count = ft_atoi(argv[1]);
	vars->ttd = ft_atoi(argv[2]);
	vars->tte = ft_atoi(argv[3]);
	vars->tts = ft_atoi(argv[4]);
	vars->maxmeal = -1;
	if (argc == 6)
		vars->maxmeal = ft_atoi(argv[5]);
	if (vars->philo_count < 1 || vars->ttd < 0
		|| vars->tte < 0 || vars->tts < 0 || (argc == 6 && vars->maxmeal < 0))
		return (-1);
	return (0);
}

int alloc_philo_and_mutex(t_vars *vars)
{
	vars->phi = malloc(sizeof(t_phi) * (vars->philo_count));
	if (!vars->phi)
		return (-1);
	vars->mutex = malloc(sizeof(pthread_mutex_t) * (vars->philo_count));
	if (!vars->mutex)
		return (-1);
	return (0);
}

int	init_mutex(t_vars *vars)
{
	size_t	i;

	pthread_mutex_init(&vars->meal, NULL);
	pthread_mutex_init(&vars->time, NULL);
	pthread_mutex_init(&vars->death, NULL);
	i = 0;
	while (i < (size_t)vars->philo_count)
	{
		if (pthread_mutex_init(&vars->mutex[i], NULL))
			return (-1);
		i++;
	}
	return (0);
}

int	init_philo_and_mutex(t_vars *vars)
{
	int i;

	i = 0;
	if (init_mutex(vars))
		return (-1);
	while (i < vars->philo_count)
	{
		ft_memset(&vars->phi[i], sizeof(t_phi), 0);
		vars->phi[i].philo_count = vars->philo_count;
		vars->phi[i].vars = vars;
		vars->phi[i].id = i + 1;
		vars->phi[i].satiated = &vars->satiated;
		if (pthread_create(&vars->phi[i].philo,
				NULL, &routine, (void *)(vars->phi + i)) != 0)
		{
			vars->amount_of_threads_to_join = ++i;
			return (-1);
		}
		i++;
	}
	vars->amount_of_threads_to_join = i;
	return (0);
}
