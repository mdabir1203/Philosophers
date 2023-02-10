/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:49:19 by mabbas            #+#    #+#             */
/*   Updated: 2023/02/09 21:20:33 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

size_t	check_num_of_philo(t_sims *sims)
{
	if (sims->num_of_philo <= 0)
		return (SLEEP);
	return (0);
}

size_t	check_time_to_die(t_sims *sims)
{
	if (sims->time_to_die <= 0)
		return (THINK);
	return (0);
}

size_t	check_time_to_eat(t_sims *sims)
{
	if (sims->time_to_eat <= 0)
		return (DEAD);
	return (0);
}

size_t	check_time_to_sleep(t_sims *sims)
{
	if (sims->time_to_sleep <= 0)
		return (DONE);
	return (0);
}
