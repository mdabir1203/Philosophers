/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 09:36:13 by mabbas            #+#    #+#             */
/*   Updated: 2023/02/10 18:50:43 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdint.h>


/*
** Colors
*/
# define RESET "\e[0m"
# define PINK "\e[0;38;5;199m"
# define GREEN "\e[0;32m"
# define BLUE "\e[0;34m"
# define G_BLUE "\e[0;38;5;24m"
# define B_BLUE "\e[1;34m"
# define G_CYAN "\e[0;38;5;44m"


/*
** Routines messages
*/
# define EAT_MSG "is eating🥙"
# define SLEEP_MSG "is sleeping😴"
# define THINK_MSG "is thinking🤔"
# define FORK_MSG "has taken a fork🍴"
# define DIED_MSG "\x1B[35mdied 👻"

typedef enum e_STATSCODE
{
	FORK = 1,
	EAT = 2,
	SLEEP = 3,
	THINK = 4,
	DEAD = 5,
	DONE = 6
}	t_STATSCODE;



/** Philosophers table counting **/
typedef struct s_philo
{
	pthread_t			thread;
	size_t				left_hand;
	size_t				right_hand;
	// pthread_mutex_t		philo_lock;
	size_t				count;
	size_t				last_meal;
	size_t				meal_count;
	struct s_sims		*sims;
}	t_philo;

/** simulating properties of philosophers */
typedef struct s_sims
{
	pthread_mutex_t		forks[200];
	pthread_mutex_t		display;
	t_philo				philo[200];
	size_t				begin;
	size_t				when_dead;
	size_t				num_of_philo;
	size_t				num_of_meals;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	bool				logs_philo;
}				t_sims;

size_t			ft_get_time(void);
void			ft_meal(t_philo *philo);
void			*ft_routine(void *argv);
size_t			ft_atoi(const char *str);
size_t			ft_init(char *argv[], size_t argc, t_sims *sims);

/** checking for stats of philos **/
size_t			check_num_of_philo(t_sims *sims);
size_t			check_time_to_die(t_sims *sims);
size_t			check_time_to_eat(t_sims *sims);
size_t			check_time_to_sleep(t_sims *sims);

/** destroy the mutexes and exit **/
void			ft_join_thread(size_t n, t_sims *sims);
void			ft_destroy_all(t_sims *simulation, t_philo *philo);
void			ft_disp_output(t_philo *philo, char *msg);
void			ft_disp_death(t_philo *philo, t_sims *sims, size_t n);
void			ft_check_end(t_sims *simulation);
// size_t	diff(size_t pre, size_t post); Put it in static
void			ft_sleep_time_given(size_t time);
size_t			diff(size_t pre, size_t post);

#endif