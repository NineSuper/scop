/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 20:13:22 by tde-los-          #+#    #+#             */
/*   Updated: 2024/08/14 19:47:14 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	get_random_color(GLfloat *color)
{
    GLfloat	adjustment_factor;
	GLfloat	random_adjustment;
	int		i;

	adjustment_factor = 2.5f;
	i = -1;
	while (++i < 3)
	{
    	random_adjustment = ((GLfloat)rand() / RAND_MAX) * adjustment_factor - (adjustment_factor / 2);
        color[i] += random_adjustment;
        if (color[i] > 2.5f)
            color[i] = 2.5f;
        else if (color[i] < 0.0f)
            color[i] = 0.0f;
    }
    color[3] = 1.0f;
}

void	generate_color(t_face *new_face)
{
    new_face->color[0] = 2.0f;
    new_face->color[1] = 0.0f;
    new_face->color[2] = 0.0f;
    new_face->color[3] = 1.0f;
}
