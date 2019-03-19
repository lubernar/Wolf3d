/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelpuec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 12:12:56 by jdelpuec          #+#    #+#             */
/*   Updated: 2018/11/15 13:30:32 by jdelpuec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	while ((*(alst))->next != NULL)
	{
		del((*(alst))->content, (*(alst))->content_size);
		free(*alst);
		(*(alst)) = (*(alst))->next;
	}
	del((*(alst))->content, (*(alst))->content_size);
	free(*alst);
	*alst = NULL;
}
