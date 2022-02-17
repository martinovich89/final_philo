/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenry <mhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 01:50:47 by martin            #+#    #+#             */
/*   Updated: 2022/02/17 14:55:39 by mhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(t_vars *vars, char *err_msg, int ret)
{
	clear_all(vars);
	write(1, err_msg, ft_strlen(err_msg));
	return (ret);
}
