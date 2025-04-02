/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:28:30 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/09/08 03:31:42 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				dead;
	int				count_meals;
	pthread_t		philo;
	long long		last_meal;
	struct s_list	*data;

}	t_philo;

typedef struct s_list
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_meals;
	long long		start_time;
	pthread_mutex_t	meals_count;
	pthread_mutex_t	update_time;
	pthread_mutex_t	printf_;
	pthread_mutex_t	*fork;
	t_philo			*ph;
}t_list;

int			ft_atoi(char *s);
int			is_digit(char *s);
void		ft_putstr_fd(char *s, int fd);
void		inits(t_list *data);
int			valid_input(int ac, char **av, t_list *args);
int			args_as_digit(int ac, char **av);
void		check_death(t_list *data, int ac);
void		init_fork(t_list *data);
void		init_philo(t_list *data);
void		*routine(void *ph);
void		thinking(t_philo *philo);
void		sleep_time(t_philo *philo);
void		dinner_time(t_philo *philo);
void		take_forks(t_philo *philo);
void		usleep_(long long chrono);
long long	time_(void);

#endif