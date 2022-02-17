/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenry <mhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 01:54:19 by martin            #+#    #+#             */
/*   Updated: 2022/02/17 14:54:07 by mhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	build_str_to_print(t_phi *phi, char *str_to_print, char *status_str)
{
	size_t	i;

	i = 0;
	ft_bzero(str_to_print, 60);
	phi->elapsed_time = get_current_time() - phi->vars->chrono_start;
	i += timetostr(str_to_print + i, phi->elapsed_time / 1000);
	i += ft_strcpy(str_to_print + i, " ");
	i += timetostr(str_to_print + i, phi->id);
	i += ft_strcpy(str_to_print + i, " ");
	i += ft_strcpy(str_to_print + i, status_str);
	i += ft_strcpy(str_to_print + i, "\n");
}

void	ft_print(t_phi *phi, char *status_str)
{
	char	str_to_print[60];

	build_str_to_print(phi, str_to_print, status_str);
	write(1, str_to_print, ft_strlen(str_to_print));
}

int	print_status(t_phi *phi, char *status_str, int status)
{
	t_vars	*vars;

	vars = phi->vars;
	pthread_mutex_lock(&vars->death);
	if (vars->is_dead)
		return (unlock_and_return(&vars->death, NULL));
	if (status == 1)
	{
		pthread_mutex_lock(&vars->time);
		phi->last_meal = get_current_time();
		pthread_mutex_unlock(&vars->time);
	}
	phi->elapsed_time = get_current_time() - vars->chrono_start;
	ft_print(phi, status_str);
	pthread_mutex_unlock(&vars->death);
	return (0);
}
