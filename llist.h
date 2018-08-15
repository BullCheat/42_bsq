/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 19:20:19 by tkobb             #+#    #+#             */
/*   Updated: 2018/08/15 11:28:49 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LLIST_H
# define LLIST_H
# include <stdlib.h>

typedef struct		s_llist
{
	void			*data;
	struct s_llist	*next;
}					t_llist;

t_llist				*llist_create_element(void *data);

#endif
