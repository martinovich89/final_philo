/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martin <martin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 01:50:47 by martin            #+#    #+#             */
/*   Updated: 2022/02/17 01:50:56 by martin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_error(t_vars *vars, char *err_msg, int ret)
{
    clear_all(vars);
    write(1, err_msg, ft_strlen(err_msg));
    return (ret);
}
