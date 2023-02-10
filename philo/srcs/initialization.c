/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:40:26 by mabbas            #+#    #+#             */
/*   Updated: 2023/02/10 18:38:07 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/** Initialize mutex objects and synchonize access to resources 
 *  between multiple threads
 *  display-> sync to output message
 *  death,stop -> stopping resources
 * Initializes mutex objects forks
 * Refactored the code into two duncitons
**/

void	init_philo_vals(t_philo *philo, size_t n, t_sims *sims)
{
	philo->count = n;
	philo->meal_count = 0;
	philo->left_hand = n;
	philo->right_hand = (n + 1) % sims->num_of_philo;
	philo->sims = sims;
}

void	init_philosophers(size_t n, t_sims *sims)
{
	sims->when_dead = 1;
	while (n-- > 0)
		init_philo_vals(&sims->philo[n], n, sims);
	init_philo_vals(&sims->philo[n], 0, sims);
}

/** Initialize forks **/

size_t	init_fork(size_t n, t_sims *sims)
{
	while (n > 0)
	{
		if (pthread_mutex_init(&sims->forks[n], NULL))
			return (0);
		n--;
	}
	if (pthread_mutex_init(&sims->display, NULL))
		return (0);
	return (1);
}

/** creates threads -> sets last meal to curr time
 *  it creates threads for the routine work of 
 *  philosophers
**/

size_t	init_philo_thread(size_t n, t_sims *sims)
{
	sims->begin = ft_get_time();
	while (n > 0)
	{
		if (pthread_create(&sims->philo->thread, NULL, \
			&ft_routine, &sims->philo[n]))
			return (0);
		sims->philo->last_meal = ft_get_time();
		n--;
	}
	sims->logs_philo = true;

	return (1);
}

typedef size_t	(*t_init_func[4])(t_sims *);

size_t	ft_init(char *argv[], size_t argc, t_sims *sims)
{
	size_t	t_init_func[4];

	t_init_func[0] = check_num_of_philo;
	t_init_func[1] = check_time_to_die;
	t_init_func[2] = check_num_of_philo;
	t_init_func[3] = check_time_to_sleep;

	sims->num_of_philo = ft_atoi(argv[1]);
	sims->time_to_die = ft_atoi(argv[2]);
	sims->time_to_eat = ft_atoi(argv[3]);
	sims->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		sims->num_of_meals = ft_atoi(argv[5]);
	else
		sims->num_of_meals = -1;
	if (!init_fork(sims->num_of_philo, sims))
		return (FORK);
	init_philosophers(sims->num_of_philo, sims);
	if (!init_philo_thread(sims->num_of_philo, sims))
		return (EAT);
	return (0);
}
