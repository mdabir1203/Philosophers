/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 09:36:13 by mabbas            #+#    #+#             */
/*   Updated: 2023/02/11 04:50:54 by mabbas           ###   ########.fr       */
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
# define D_RED  "\033[0;31m"

/*
** Routines messages
*/
# define EAT_MSG "is eating🥙"
# define SLEEP_MSG "is sleeping😴"
# define THINK_MSG "is thinking🤔"
# define FORK_MSG "has taken a fork🍴"
# define DIED_MSG "\x1B[35mdied 👻"

/** struct for philo routines **/

typedef struct s_details
{
	int64_t			since_started;
	int				nbr_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_to_eat;
}	t_details;

/** Philosophers table counting **/
typedef struct s_state
{
	int				id;
	int				eating;
	int64_t			last_meal;
	int				meal_times;
}	t_state;

/** simulating properties of philosophers */
typedef struct s_all
{
	pthread_mutex_t		*fork;
	pthread_mutex_t		result;
	t_details			details;
	t_state				*state;
}	t_all;

/** checking for stats of philos **/

void		state_initialize(void);
size_t		mutex_initialize(void);
size_t		parse_arg(int argc, char *argv[]);

/** Error and utils **/

size_t		ft_atoi(const char *str);
int			err_msg(char *message);
int64_t		ft_get_time(void);

/** destroy the mutexes and exit **/
void		disp_state(int id, char *status);
void		disp_death(int id);
void		sleep_mod(int ms);
// size_t	diff(size_t pre, size_t post); Put it in static
void		destroy_n_free_mutex(void);
int			check_philo_death(void);
t_all		g_function(t_all *fill);

#endif