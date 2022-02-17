/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenry <mhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:31:32 by martin            #+#    #+#             */
/*   Updated: 2022/02/17 14:53:35 by mhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <string.h>
# include <limits.h>
# include <pthread.h>

typedef struct s_phi
{
	struct s_vars	*vars;
	pthread_t		philo;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*last_fork;
	int				dead;
	int				*satiated;
	int				meal_counter;
	size_t			last_meal;
	size_t			elapsed_time;
	int				philo_count;
	size_t			id;
}				t_phi;

typedef struct s_vars
{
	t_phi			*phi;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	death;
	pthread_mutex_t	meal;
	pthread_mutex_t	time;
	pthread_mutex_t	print;
	int				satiated;
	int				start;
	int				stop;
	int				is_dead;
	int				philo_count;
	int				ttd;
	int				tte;
	int				tts;
	int				maxmeal;
	size_t			chrono_start;
	int				amount_of_threads_to_join;
}				t_vars;

int		ft_strlen(char *str);
int		is_digit(char c);
int		ft_strcmp(char *s1, char *s2);
int		ft_strcpy(char *dst, char *src);
int		ft_strcat(char *dst, char *src);
void	ft_bzero(char *str, size_t n);
void	ft_memset(void *ptr, size_t n, char value);
int		ft_atoi(char *str);
int		timetostr(char *str, size_t elapsed_time);
void	destroy_all_mutex(t_vars *vars);
int		join_all_threads(t_vars *vars);
int		clear_all(t_vars *vars);
int		ft_error(t_vars *vars, char *err_msg, int ret);
size_t	get_current_time(void);
int		check_arg(char *str);
void	set_phi(t_phi *phi);
int		unlock_and_return(pthread_mutex_t *mutex1, pthread_mutex_t *mutex2);
int		sleep_until(t_phi *phi, size_t stop);
int		wait_for_death(t_phi *phi);
void	make_delay(t_phi *phi);
void	build_str_to_print(t_phi *phi, char *str_to_print, char *status_str);
void	ft_print(t_phi *phi, char *status_str);
int		print_status(t_phi *phi, char *status_str, int status);
int		check_satiated(t_phi *phi);
int		eat_phase(t_phi *phi);
int		sleep_phase(t_phi *phi);
int		think_phase(t_phi *phi);
int		launch_phases(t_phi *phi);
void	*routine(void *ptr);
int		set_vars(int argc, char **argv, t_vars *vars);
int		alloc_philo_and_mutex(t_vars *vars);
int		init_mutex(t_vars *vars);
int		init_philo_and_mutex(t_vars *vars);
int		check_philo_satiated(t_phi *phi, t_vars *vars);
int		check_philo_death(t_phi *phi, t_vars *vars);
void	wait_all_philos(t_vars *vars);
int		check_philo_status(t_vars *vars);

#endif