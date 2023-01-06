/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 09:36:13 by mabbas            #+#    #+#             */
/*   Updated: 2023/01/06 02:47:41 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <stdlib.h>
# include <pthread.h>
# include <semaphore.h>
# include <unistd.h>
# include <stdio.h>

struct	s_args;

typedef struct s_philo
{
	int				phi_id;
	int				total_meals;
	int				total_meals_1;
	int				phi_nbr;
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	int				stop;
	time_t			last_meal_time;
	time_t			life_limit;
	time_t			begin_time;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	struct s_args	*args;

}	t_philo;

typedef struct s_args
{
	int				phi_num;
	int				phi_id;
	time_t			begin_time;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				dead;
	int				meal_no;
	pthread_mutex_t	*forks;
	pthread_t		*t_ids;
	pthread_mutex_t	*print_lock;
	t_philo			*philo_all;
}	t_args;

void	forks_taken(t_philo *philo);
void	eat(t_philo *philo);
void	sleep(t_philo *philo);
void	think(t_philo *philo);
long	ft_time(void);
void	ft_usleep(int ms);
int		ft_meal_count(t_philo *philo);
void	*monitor(void *args);
void	*ft_process(void *args);
void	ft_init_philo(t_args *args);
void	ft_init_mutex(t_args *args);
void	ft_init_threads(t_args *args);
void	ft_threads_end(t_args *args);
int		ft_init_args(t_args *args, int argc, char **argv);
void	ft_args_check(void);
void	free(t_args *args);
void	unlock_destroy_mutex(t_args *args);

#endif