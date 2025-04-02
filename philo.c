/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:20:59 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/09/08 03:34:05 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_list *data)
{
	int	i;

	i = 0; 
	while (i < data->num_philo)
	{
		data->ph[i].id = i + 1;
		data->ph[i].count_meals = 0;
		data->ph[i].dead = 0;
		pthread_create(&data->ph[i].philo, NULL, &routine, &data->ph[i]);
		pthread_detach(data->ph[i].philo);
		usleep(30);
		i++;
	}
}

void	init_fork(t_list *data)
{
	int	i;

	i = 0;
	pthread_mutex_init(&data->printf_, NULL);
	pthread_mutex_init(&data->meals_count, NULL);
	pthread_mutex_init(&data->update_time, NULL);
	while (i < data->num_philo)
	{
		pthread_mutex_init(&data->fork[i], NULL);
		data->ph[i].data = data; 
		i++;
	}
}

int	main(int ac, char **av)
{
	t_list	args;

	if (valid_input(ac, av, &args))
		return (1);
	args.fork = malloc(sizeof(pthread_mutex_t) * args.num_philo);
	args.ph = malloc(sizeof(t_philo) * args.num_philo);
	args.start_time = time_();
	init_fork(&args);
	init_philo(&args);
	check_death(&args, ac);
	return (0);
}
