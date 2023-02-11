/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_collector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 01:54:13 by mabbas            #+#    #+#             */
/*   Updated: 2023/02/11 03:15:37 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/** a simple mechanism for storing and retrieving a 
 *  global variable of type t_all that is shared across 
 *  all calls to the function **/

t_all	g_function(t_all *fill)
{
	static t_all	var;

	if (fill)
		var = *fill;
	return (var);
}
