/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_algo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 03:32:19 by mabbas            #+#    #+#             */
/*   Updated: 2023/02/10 03:54:20 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/** Check log status of philos and update state of simulation. Waits until all ready to go **/

void	check_philo(t_philo *philo, t_sims *sims)
{
	if (philo->count == 1)
	{
		sims->logs_philo = true;
		sims->begin = ft_get_time();
	}
	while (sims->logs_philo == false)
		usleep(1);
}

/** Philos Roundabouts
 * --> Runs in a separate thread **/

void	*ft_routine(void *argv)
{
	t_philo	*philo;
	t_sims	*sims;

	philo = (t_philo *)argv;
	sims = philo->sims;
	check_philo(philo, sims);
	if (sims->num_of_philo == 1)
	{
		ft_sleep_time_given(sims->time_to_die);
		ft_disp_output(philo, DIED_MSG);
		return (NULL);
	}
	if (philo->count % 2)
		usleep(sims->time_to_eat * 1000);
	while (sims->when_dead)
	{
		ft_meal(philo);
		if (philo->meal_count == sims->num_of_meals)
			break ;
		ft_disp_output(philo, SLEEP_MSG);
		ft_sleep_time_given(sims->time_to_sleep);
		ft_disp_output(philo, THINK_MSG);
	}
	return (NULL);
}
