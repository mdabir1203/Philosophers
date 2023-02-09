/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_chk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:48:24 by mabbas            #+#    #+#             */
/*   Updated: 2023/02/09 18:57:10 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/** clock_monotonic_raw --> 
 *  not affected by discontinuous jumps 
 *  in the system time . Gives raw Hardware time **/
size_t	ft_get_time(void)
{
	struct timeval	curr_time;

	gettimeofday(&curr_time, NULL);
	return ((curr_time.tv_sec * 1000) +(curr_time.tv_usec / 1000));
}

/** Difference between timestamps. **/

static size_t	diff(size_t pre, size_t post)
{
	return (pre - post);
}

/* This function waits for a specified amount of time
   by continuously checking the current time and breaking out of the loop
   when the desired amount of time has passed.
   ->  uint64_t is used for portability
*/
void	ft_sleep_time_given(size_t time)
{
	uint64_t	i;

	i = ft_get_time();
	while (1)
	{
		if (diff(ft_get_time(), i) >= time)
			break ;
	}
}
