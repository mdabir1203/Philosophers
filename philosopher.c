/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 09:45:51 by mabbas            #+#    #+#             */
/*   Updated: 2022/12/29 10:00:26 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	release(int left, int right, int pid)
{
	pthread_mutex_unlock(&forks[left]);
	printf("Philo]->%d released left fork: %d.\n", pid, left);
	pthread_mutex_unlock(&forks[right]);
	printf("Philo]->%d released right fork: %d.\n", pid, left);
}

void	fork_left(int pid, int left)
{
	pthread_mutex_lock(&forks[left]);
	printf("Philo]->%d took left fork: %d.\n", pid, left);
}

void	fork_right(int pid, int right)
{
	pthread_mutex_lock(&forks[right]);
	printf("Philo]->%d took right fork: %d.\n", pid, right);
}

void	*philos(void *arg)
{
	int	pid;
	int	left;
	int	right;

	pid = *((int *) arg);
	left = pid;
	right = (pid + 1) % PHI;
	while (1)
	{
		printf("[[Philo]->%d thinking.\n]", pid);
		usleep(SLEEP_TIME);
		fork_left(pid, left);
		fork_right(pid, right);
		printf("[[Philo]->%d is eating.\n]", pid);
		usleep(EAT_TIME);
		release(pid, left, right);
	}
	return (NULL);
}
