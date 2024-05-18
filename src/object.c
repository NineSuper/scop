/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 06:31:22 by tde-los-          #+#    #+#             */
/*   Updated: 2024/05/18 07:25:27 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

int	ft_open_obj(t_obj *object)
{
	object->fd = open(object->file, O_RDONLY);
	if (object->fd < 0)
		return (ft_printf("%s%s%s%s\n", C_RED, C_OPEN, object->file, C_NONE));
	return (0);
}
