/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 23:36:17 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/29 18:42:21 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	*philo_work(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (!(p->id % 2))
		usleep(10000);
	while (!is_dead(p))
	{
		if (eat(p))
			return (NULL);
		if ((p->data.num_time_to_eat != -1 && \
		p->num_time_eaten == p->data.num_time_to_eat) || is_dead(p))
			break ;
		print_message(p, "is sleeping");
		sleep_action(p->data.time_to_sleep, p);
		if (is_dead(p))
			return (NULL);
		print_message(p, "is thinking");
		if (p->data.philo_num % 2)
			usleep(2000);
	}
	return (NULL);
}

void	thread_creation(t_philo **philo)
{
	static pthread_mutex_t	print;
	int						i;

	pthread_mutex_init(&print, NULL);
	(init_timer())->start = current_time();
	i = -1;
	while (++i < (*philo)[0].data.philo_num)
	{
		(*philo)[i].print = &print;
		(*philo)[i].last_meal = 0;
	}
	i = -1;
	while (++i < (*philo)[0].data.philo_num)
		pthread_create(&(*philo)[i].philo, NULL, &philo_work, (*philo + i));
	i = -1;
	while (++i < (*philo)->data.philo_num)
		pthread_join((*philo)[i].philo, NULL);
	i = -1;
	while (++i < (*philo)->data.philo_num)
		pthread_mutex_destroy(&(*philo)[i].table[i].mutex_fork);
}
