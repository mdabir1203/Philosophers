/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 02:38:00 by mabbas            #+#    #+#             */
/*   Updated: 2023/02/11 03:38:28 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/** Code checking if a philosopher is dead is isolated in check_dead_philo
 *  function, making it easier to understand
 * and maintain. The ft_disp_output function has 
 * become simpler and readable as a result.
 **/
int	err_msg(char *message)
{
	return (printf("%s%s%s\n", D_RED, message, RESET));
}

/** clock_monotonic_raw --> 
 *  not affected by discontinuous jumps 
 *  in the system time . Gives raw Hardware time **/
int64_t	ft_get_time(void)
{
	struct timeval	time_stamp;
	int64_t			result;
	t_all			all;

	all = g_function(NULL);
	gettimeofday(&time_stamp, NULL);
	result = ((time_stamp.tv_sec * 1000) +(time_stamp.tv_usec / 1000));
	return (result - all.details.since_started);
}

void	disp_state(int id, char *status)
{
	t_all	all;

	all = g_function(NULL);
	pthread_mutex_lock(&all.result);
	printf("%lld %d %s%s\n", ft_get_time(), id, status, RESET);
	pthread_mutex_unlock(&all.result);
}

/** usleep modified to account for overhead of measuring time
 * It ensure that the total wait time is close to the desired value. **/

void	sleep_mod(int ms)
{
	struct timeval	time_stamp;
	int64_t			current;
	int64_t			end;

	gettimeofday(&time_stamp, NULL);
	end = time_stamp.tv_usec + (time_stamp.tv_sec * 1000000);
	current = end;
	usleep((ms - 10) * 1000);
	while ((current - end) < (ms * 1000))
	{
		gettimeofday(&time_stamp, NULL);
		current = time_stamp.tv_usec + (time_stamp.tv_sec * 1000000);
	}
}
