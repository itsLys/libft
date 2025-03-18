/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisempty.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 07:41:47 by ihajji            #+#    #+#             */
/*   Updated: 2025/03/18 07:41:48 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strisempty(char *str)
{
	while (*str && *str == ' ')
		str++;
	return (!*str);
}
