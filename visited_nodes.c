/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visited_nodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:36:24 by ihodge            #+#    #+#             */
/*   Updated: 2017/12/05 18:54:11 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astar.h"

void	collisions(t_lemin **node, t_link *links)
{
	while (*node)
	{
		if (ft_strequ((*node)->title, links->title))
			break ;
		(*node) = (*node)->next;
	}
}

void	mark_as_visited(t_lemin **arr, t_lemin *node)
{
	t_lemin *tmp;

	tmp = arr[hash_funct(node->title, -1, 7)];
	while (tmp)
	{
		if (ft_strequ(node->title, tmp->title))
			break ;
		tmp = tmp->next;
	}
	tmp->visited = 1;
}

int		visited_node(t_queue *q, t_lemin *node, t_lemin **arr)
{
	t_lemin *tmp;

	tmp = q->first;
	if (node->visited)
		return (1);
	while (tmp)
	{
		if (ft_strequ(tmp->title, node->title) &&
				ft_strequ(tmp->prev->title, node->prev->title))
		{
			if (node->heuristic < tmp->heuristic)
			{
				remove_from_queue(q, tmp);
				enqueue(q, node);
			}
			else if (node->heuristic == tmp->heuristic)
			{
				mark_as_visited(arr, node);
				remove_from_queue(q, tmp);
			}
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void	remove_from_queue(t_queue *q, t_lemin *node)
{
	t_lemin *tmp;
	t_lemin *tmp2;

	tmp = q->first;
	tmp2 = NULL;
	while (tmp)
	{
		if (node == tmp)
		{
			if (tmp2)
				tmp2->next = node->next;
			else
				q->first = node->next;
			free(node);
		}
		tmp2 = tmp;
		tmp = tmp->next;
	}
}
