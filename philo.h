/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 09:36:13 by mabbas            #+#    #+#             */
/*   Updated: 2022/12/29 09:45:35 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdio.h>

#define PHI 5
#define EAT_C 10
#define DIE_TIME 5
#define EAT_TIME 3
#define SLEEP_TIME 2

pthread_mutex_t	forks[PHI];

#endif