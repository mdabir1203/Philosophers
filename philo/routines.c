/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 03:53:01 by mabbas            #+#    #+#             */
/*   Updated: 2023/02/10 03:27:03 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/**  Here sims = table
 *   2 forks - 1 for left and 1 for right **/
void	ft_meal(t_philo	*philo)
{
	t_sims	*sims;

	sims = philo->sims;
	pthread_mutex_lock(&sims->forks[philo->left_hand]);
	ft_disp_output(philo, FORK_MSG);
	pthread_mutex_lock(&sims->forks[philo->right_hand]);
	ft_disp_output(philo, FORK_MSG);
	ft_disp_output(philo, EAT_MSG);
	ft_sleep_time_given(sims->time_to_eat);
	philo->last_meal = ft_get_time();
	philo->meal_count++;
	pthread_mutex_unlock(&sims->forks[philo->left_hand]);
	pthread_mutex_unlock(&sims->forks[philo->right_hand]);
}

