/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martin <martin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:30:49 by martin            #+#    #+#             */
/*   Updated: 2022/02/17 02:04:21 by martin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *ptr)
{
	t_phi			*phi;

	phi = (t_phi *)ptr;
	set_phi(phi);
	make_delay(phi);

	launch_phases(phi);
	return (NULL);
}

int main(int argc, char **argv)
{
    t_vars vars;

    if (argc < 5 || argc > 6)
	    return (ft_error(&vars, "wrong argument : refer to README\n", 1));
	if (set_vars(argc, argv, &vars))
	    return (ft_error(&vars, "wrong argument : refer to README\n", 1));
	if (alloc_philo_and_mutex(&vars))
        return (ft_error(&vars, "fatal error: malloc failed\n", -1));
	if (init_philo_and_mutex(&vars))
        return (ft_error(&vars, "fatal error: pthread failed\n", -1));
	wait_all_philos(&vars);
	check_philo_status(&vars);
	clear_all(&vars);
	return (0);
}