/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 02:38:00 by mabbas            #+#    #+#             */
/*   Updated: 2023/02/10 02:56:57 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/** Code checking if a philosopher is dead is isolated in check_dead_philo
 *  function, making it easier to understand
 * and maintain. The ft_disp_output function has 
 * become simpler and readable as a result.
 **/
void	ft_disp_death(t_philo *philo, t_sims *sims, size_t n)
{
	printf("\x1B[35m%zu ", diff(current_time(), philo->sims->count));
	printf("\x1B[35m%zu ", sims->philo[n].count);
	printf("\x1B[35m%s", "🦴died🦴\n");
}

void	ft_check_dead_philo(t_philo *philo, t_sims *sims, int n)
{
	if (diff(current_time(), sims->philo[n].last_meal) >= \
				philo->sims->time_to_die && philo->sims->when_dead)
	{
		sims->when_dead = 0;
		ft_disp_death(philo, sims, n);
	}
}

void	ft_disp_output(t_philo *philo, char *msg)
{
	t_sims	*sims;
	int		n;

	pthread_mutex_lock(&philo->sims->display);
	sims = philo->sims;
	n = sims->num_of_philo;
	while (n-- > 0 && sims->philo[n].count)
	{
		ft_check_dead_philo(philo, sims, n);
	}
	if (sims->when_dead)
	{
		printf("\033[1;34m%zu ", diff(current_time(), philo->sims->begin));
		printf("\033[1;33m%zu ", philo->count);
		printf("\033[1;32m%s\n", msg);
	}
	pthread_mutex_unlock(&philo->sims->display);
}
