/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:30:26 by mabbas            #+#    #+#             */
/*   Updated: 2023/02/11 04:53:55 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	destroy_n_free_mutex(void)
{
	int			i;
	t_all		all;

	all = g_function(NULL);
	i = 0;
	while (i < all.details.nbr_of_philo)
	{
		pthread_mutex_destroy(&all.fork[i]);
		i++;
	}
	free(all.fork);
	free(all.state);
}

void	philos_simulation(t_state *state)
{
	size_t	left;
	size_t	right;
	t_all	all;

	all = g_function(NULL);
	left = state->id - 1;
	right = (left + 1) % all.details.nbr_of_philo;
	pthread_mutex_lock(&all.fork[left]);
	disp_state(state->id, FORK_MSG);
	pthread_mutex_lock(&all.fork[right]);
	disp_state(state->id, FORK_MSG);
	state->eating = 1;
	state->meal_times++;
	state->last_meal = ft_get_time();
	sleep_mod(all.details.time_to_eat);
	state->eating = 0;
	pthread_mutex_unlock(&all.fork[right]);
	pthread_mutex_unlock(&all.fork[left]);
	disp_state(state->id, SLEEP_MSG);
	sleep_mod(all.details.time_to_sleep);
	disp_state(state->id, THINK_MSG);
}

void	*routine(void *arg)
{
	t_state		*state;
	int			i;
	t_all		all;

	all = g_function(NULL);
	state = (t_state *)arg;
	i = 0;
	if (all.details.times_to_eat == 0)
	{
		while (1)
			philos_simulation(state);
	}
	else
	{
		while (i < all.details.times_to_eat)
		{
			philos_simulation(state);
			i++;
		}
	}
	return (NULL);
}

size_t	philosophers_gen(void)
{
	int			i;
	pthread_t	*thread;
	t_all		all;

	all = g_function(NULL);
	i = 0;
	thread = malloc(sizeof(pthread_t) * all.details.nbr_of_philo);
	while (i < all.details.nbr_of_philo)
	{
		if (pthread_create(&thread[i], NULL, routine, (void *)&all.state[i]))
			return (err_msg("Error: Can't generate threads"));
		usleep(100);
		i++;
	}
	free(thread);
	g_function(&all);
	return (0);
}

/** initialize mutex and gen philo **/

int	main(int argc, char *argv[])
{
	if (parse_arg(argc, argv) == 1 || mutex_initialize() == 1)
		return (1);
	state_initialize();
	if (philosophers_gen() == 1)
		return (1);
	return (check_philo_death());
}
