/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:32:03 by kaheinz           #+#    #+#             */
/*   Updated: 2022/12/06 00:07:50 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *data)
{
	t_philo	*philo;
	t_args	*args;

	philo = (t_philo *)data;
	args = philo->args;
	if (philo->philo_id % 2 == 0)
		usleep(args->time_eat * 1000);
	pthread_mutex_lock(&args->meal_mutex);
	philo->previous_meal = time_stamp();
	pthread_mutex_unlock(&args->meal_mutex);
	while (1)
	{
		actions(philo, args);
	}
	return (0);
}

void	actions(t_philo *philo, t_args *args)
{
	eating(philo, args);
	sleeping(philo, args);
	thinking(philo, args);
}

void	eating(t_philo *philo, t_args *args)
{
	(void)args;
//	pthread_mutex_lock(&(args->fork_mutex[philo->l_fork]));
	print_message(philo, "has taken a fork.");
//	pthread_mutex_lock(&(args->fork_mutex[philo->r_fork]));
	print_message(philo, "has taken a fork.");
	//eat for time to
	pthread_mutex_lock(&(args->meal_mutex));
	philo->previous_meal = time_stamp();
	//mutex for time stamp for previous meal
	pthread_mutex_unlock(&(args->meal_mutex));
	usleep(args->time_eat * 1000);
	//add to times eaten
	//unlock forks
//	pthread_mutex_unlock(&(args->fork_mutex[philo->l_fork]));
//	pthread_mutex_unlock(&(args->fork_mutex[philo->r_fork]));
}	

void	sleeping(t_philo *philo, t_args *args)
{
	(void)args;
	print_message(philo, "is sleeping.");
}

void	thinking(t_philo *philo, t_args *args)
{
	(void)args;
	print_message(philo, "is thinking.");
}
