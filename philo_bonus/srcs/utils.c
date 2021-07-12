/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:19:31 by kaye              #+#    #+#             */
/*   Updated: 2021/07/12 17:15:24 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_philo	*singleton(void)
{
	static t_philo	*philo = NULL;

	if (!philo)
	{
		philo = ft_calloc(sizeof(t_philo), 1);
		if (!philo)
			__exit__(E_MALLOC, FAILURE, NOTHING, NOTHING);
	}
	return (philo);
}

void	do_sleep(long long ms)
{
	const long long	start = get_time();

	while (get_time() - start < ms)
		usleep(400);
}

void	print_states(long long start, int index, int s_index)
{
	const long long	current_time = get_time();
	const char		*states[] = {"is eating", "has taken a fork",
		"is sleeping", "is thinking", "died"};

	if (!still_alive())
		return ;
	sem_wait(singleton()->sem_print);
	printf("[%lld] [%u] [%s]\n", current_time - start, index, states[s_index]);
	sem_post(singleton()->sem_print);
}
