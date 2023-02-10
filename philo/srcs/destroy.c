/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:36:46 by mabbas            #+#    #+#             */
/*   Updated: 2023/02/10 17:28:18 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/** Used to wait for threads to finish execution. **/

void	ft_join_thread(size_t n, t_sims *sims)
{
	size_t	i;

	i = 0;
	while (i <= n)
	{
		pthread_join(sims->philo[n].thread, NULL);
		i++;
	}
}

/** Used to cleanup resources that were 
 *  acquired during simulation and avoid
 *  resource leaks / data races **/
void	ft_destrol_all(size_t n, t_sims *sims)
{
	size_t	i;

	i = 0;
	while (i <= n)
	{
		pthread_detach(sims->philo[n].thread);
		pthread_mutex_destroy(&sims->forks[n]);
		i++;
	}
	pthread_mutex_destroy(&sims->display);
}

/** double check to prevent undefined behaviour
 *  and potential bugs **/

void	ft_check_end(t_sims *sims)
{
	ft_join_thread(sims->num_of_philo, sims);
	ft_destrol_all(sims->num_of_philo, sims);
	free(sims);
}
