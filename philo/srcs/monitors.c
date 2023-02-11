/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 03:53:01 by mabbas            #+#    #+#             */
/*   Updated: 2023/02/11 04:33:33 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/** disp_death function retrieves the current value of the global variable
 *  stored in g_function, locks its result member,
 *  updates the global variable with a new value,
 *  gets the current time in milliseconds, 
 *  displays the values of the time, id, and "died", and
 *  frees and destroys a mutex. **/
void	disp_death(int id)
{
	int64_t		ms;
	t_all		all;

	all = g_function(NULL);
	pthread_mutex_lock(&all.result);
	g_function(&all);
	ms = ft_get_time();
	printf("%lld %d %s%s%s\n", ms, id, PINK, "died", RESET);
	destroy_n_free_mutex();
}

/** 
 * Here, state means the philo nbr/count
 * continuously checks the status of each philosopher 
 *  to determine if any died.
 *  It uses the g_function to get information about philosophers,
 *  current state, number of philosophers,
 *  and the time they have to live.
 *  returning 0 if a philosopher has died or all 
 *  philosophers have finished eating. 
 **/
int	check_philo_death(void)
{
	int		i;
	int		done;
	t_all	all;

	all = g_function(NULL);
	while (1)
	{
		i = -1;
		done = 0;
		while (++i < all.details.nbr_of_philo)
		{
			if (all.state[i].eating == 0 && ft_get_time()
				- all.state[i].last_meal > all.details.time_to_die)
			{
				disp_death(all.state[i].id);
				return (0);
			}
			if (all.details.time_to_eat != 0 && all.state[i].meal_times
				== all.details.times_to_eat)
					done++;
		}
		if (done == all.details.nbr_of_philo)
			return (0);
	}
	return (0);
}
