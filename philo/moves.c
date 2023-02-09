/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 03:53:01 by mabbas            #+#    #+#             */
/*   Updated: 2023/02/09 18:48:45 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_fork_taken(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->lft_hand]);
	ft_print_message(FORK, philo);
	pthread_mutex_lock(&philo->data->forks[philo->r_hand]);
	ft_print_message(FORK, philo);
}

/**  // philo->next meal is always positive **/
void	ft_eat(t_philo	*philo)
{
	pthread_mutex_lock(philo->eat);
	ft_print_message(EATING, philo);
	if (philo->data->eating_counter != -1)
		philo->data->current_eat_time++;
	philo->eating_time = ft_get_time();
	philo->next_meal = philo->eating_time \
		+ (unsigned int)philo->data->time_to_die;
	usleep_modified(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->data->forks[philo->lft_hand]);
	pthread_mutex_unlock(&philo->data->forks[philo->r_hand]);
	pthread_mutex_unlock(philo->eat);
}

void	ft_sleep(t_philo *philo)
{
	usleep(10);
	ft_print_message(SLEEPING, philo);
	usleep(philo->data->time_to_die * 1000);
}
