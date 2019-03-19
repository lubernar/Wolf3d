/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelpuec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:43:54 by jdelpuec          #+#    #+#             */
/*   Updated: 2018/11/16 14:58:09 by jdelpuec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstend(t_list *lst, t_list *new)
{
	if (new == NULL || lst == NULL)
		return ;
	while (lst->next != NULL)
		lst = lst->next;
	lst->next = new;
	new->next = NULL;
	return ;
}
