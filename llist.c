/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 19:22:17 by tkobb             #+#    #+#             */
/*   Updated: 2018/08/15 10:35:39 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "llist.h"

t_llist		*llist_create_element(void *data)
{
	t_llist		*list;

	if ((list = malloc(sizeof(t_llist))) == 0)
		return (NULL);
	list->next = NULL;
	list->data = data;
	return (list);
}
