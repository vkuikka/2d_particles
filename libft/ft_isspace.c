/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 14:51:45 by vkuikka           #+#    #+#             */
/*   Updated: 2019/11/02 14:51:48 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(int c)
{
	return (!(c != '\t' && c != '\n' && c != '\v' && c != '\f'
			&& c != '\r' && c != ' '));
}