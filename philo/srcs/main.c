/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 23:25:09 by mtavares          #+#    #+#             */
/*   Updated: 2022/07/23 23:48:56 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	pthread_mutex_t	mutex;
	t_gen			gen;
	t_philo			*philo;
	t_table			*table;
	int				*is_dead;

	if (ac != 5 || ac != 6)
		return (0);
	*is_dead = 0;
	gen = create_gen(ac, av);
	table = create_table(gen.philo_num);
	philo = create_philo(&gen, table, &mutex, is_dead);
	thread_creation(&philo);
}
