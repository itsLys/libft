/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:49:57 by ihajji            #+#    #+#             */
/*   Updated: 2025/03/05 17:50:06 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_exit(int status)
{
	t_list	*head;

	head = get_alloc_list();
	ft_lstclear(&head, free);
	exit(status);
}
