/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:30:26 by mabbas            #+#    #+#             */
/*   Updated: 2023/02/09 21:36:16 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/** We are mallocing and error handling and refactored main **/

int	main(int argc, char **argv[])
{
	t_sims	*sims;

	if (argc < 5 || argc > 6)
	{
		printf("Bazinga!! Wrong parameters given to the program!");
		return (0);
	}
	if (ft_atoi(argv[1] > 200))
	{
		printf("Too many Philosophers to handle for my memory");
		return (0);
	}
	sims = malloc(sizeof(sims) * 1);
	if (ft_init(argv, argc, sims))
		return (-1);
	ft_checkEnd(sims);
}
