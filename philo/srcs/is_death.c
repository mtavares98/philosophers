/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_death.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 23:42:03 by mtavares          #+#    #+#             */
/*   Updated: 2022/09/09 23:17:54 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	is_dead(t_philo *p, t_time *t)
{
	int	death;

	death = 0;
	if (time_diff(t->last_meal, current_time()) >= (t_lu)p->data.time_to_die \
	|| ((p->num_time_eaten == p->data.num_time_to_eat) \
	&& (p->data.have_last_arg)))
	{
		printf("Ainda nao morri");
		pthread_mutex_lock(p->death->death);
		death = 1;
		if (!*p->death->is_death)
		{
			*p->death->is_death = 1;
			print_message(p, t, "is dead", 0);
		}
		pthread_mutex_unlock(p->death->death);
	}
	return (death);
}