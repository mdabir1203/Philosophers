/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:36:46 by mabbas            #+#    #+#             */
/*   Updated: 2023/02/09 19:37:51 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_free_all(t_sims *simulation, t_philo *philo)
{
	free(philo);
	free(simulation->forks);
	free(simulation->threads);
	free(simulation->death);
	free(simulation->display);
	free(simulation->stop);
}

void	ft_destrol_all(t_sims *simulation, t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(simulation->death);
	pthread_mutex_destroy(simulation->display);
	pthread_mutex_destroy(simulation->stop);
	while (i < simulation->philo_nbrs)
	{
		pthread_mutex_destroy(simulation->forks + i);
		pthread_mutex_destroy(philo[i].eat);
		free(philo[i].eat);
		i++;
	}
	ft_free_all(simulation, philo);
}
