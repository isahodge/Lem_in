/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:37:27 by ihodge            #+#    #+#             */
/*   Updated: 2017/12/05 14:15:23 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astar.h"

t_queue	*q_init(void)
{
	t_queue *qu;

	qu = (t_queue*)malloc(sizeof(t_queue));
	qu->first = NULL;
	qu->last = NULL;
	return (qu);
}

int		enqueue_cont(t_lemin **new, t_lemin **list, t_lemin *content)
{
	while ((*list)->next)
	{
		if (content->heuristic < (*list)->next->heuristic)
		{
			(*new)->next = (*list)->next;
			(*list)->next = (*new);
			return (1);
		}
		(*list) = (*list)->next;
	}
	if (content->heuristic < (*list)->heuristic)
	{
		(*new)->next = (*list);
		(*list)->next = (*new);
		return (1);
	}
	return (0);
}

void	enqueue(t_queue *queue, t_lemin *content)
{
	t_lemin *list;
	t_lemin *tmp;
	t_lemin *new;

	new = astar_init(content);
	if (queue->first)
	{
		if (content->heuristic < queue->first->heuristic)
		{
			tmp = queue->first;
			queue->first = new;
			queue->first->next = tmp;
			queue->last = tmp;
			return ;
		}
		list = queue->first;
		if (enqueue_cont(&new, &list, content))
			return ;
		else if (!list->next)
			list->next = new;
		queue->last = list->next;
	}
	else
		queue->first = new;
}

t_lemin	*dequeue(t_queue *queue)
{
	t_lemin *first;

	first = NULL;
	if (queue->first)
	{
		first = queue->first;
		queue->first = queue->first->next;
		first->next = NULL;
		return (first);
	}
	return (NULL);
}
