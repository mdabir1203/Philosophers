/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:40:26 by mabbas            #+#    #+#             */
/*   Updated: 2023/02/11 03:32:56 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/** arg error check **/
int	check_for_mistakes(int argc, char *argv[])
{
	int		i;
	int		j;

	i = 1;
	if (argc < 5 || argc > 6)
		return (err_msg("Error: Wrong number of arguments"));
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] < '0' || argv[i][j] > '9' || argv[i][0] == '0')
				return (err_msg("Error: invalid argument"));
			j++;
		}
		i++;
	}
	return (0);
}


/** Initialize philo states **/

size_t	parse_arg(int argc, char *argv[])
{
	t_all	all;

	all.details.since_started = 0;
	if (check_for_mistakes(argc, argv) == 1)
		return (1);
	all.details.since_started = ft_get_time();
	all.details.nbr_of_philo = ft_atoi(argv[1]);
	all.details.time_to_die = ft_atoi(argv[2]);
	all.details.time_to_eat = ft_atoi(argv[3]);
	all.details.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		all.details.times_to_eat = ft_atoi(argv[5]);
	else
		all.details.times_to_eat = 0;
	g_function(&all);
	return (0);
}

/** mutex initialization **/

size_t	mutex_initialize(void)
{
	int		i;
	t_all	all;

	all = g_function(NULL);
	i = 0;
	all.fork = malloc(sizeof(pthread_mutex_t) * all.details.nbr_of_philo);
	while (i < all.details.nbr_of_philo)
	{
		if (pthread_mutex_init(&all.fork[i], NULL) != 0)
			return (err_msg("Error: Can't generate mutex"));
		i++;
	}
	if (pthread_mutex_init(&all.result, NULL) != 0)
		return (err_msg("Error: Can't generate mutex"));
	g_function(&all);
	return (0);
}

/** Initialize mutex objects and synchonize access to resources 
 *  between multiple threads
 *  display-> sync to output message
 *  death,stop -> stopping resources
 * Initializes mutex objects forks
 * Refactored the code into two duncitons
**/

void	state_initialize(void)
{
	int		i;
	t_all	all;

	all = g_function(NULL);
	i = 0;
	all.state = malloc(sizeof(t_state) * all.details.nbr_of_philo);
	while (i < all.details.nbr_of_philo)
	{
		all.state[i].id = i + 1;
		all.state[i].eating = 0;
		all.state[i].last_meal = ft_get_time();
		all.state[i].meal_times = 0;
		i++;
	}
	g_function(&all);
}