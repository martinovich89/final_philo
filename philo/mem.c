/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martin <martin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 01:48:34 by martin            #+#    #+#             */
/*   Updated: 2022/02/17 01:49:02 by martin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_bzero(char *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	ft_memset(void *ptr, size_t n, char value)
{
	unsigned char	*recup;
	size_t			i;

	recup = (unsigned char *)ptr;
	i = 0;
	while (i < n)
	{
		recup[i] = value;
		i++;
	}
}