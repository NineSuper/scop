/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 20:13:22 by tde-los-          #+#    #+#             */
/*   Updated: 2024/05/30 20:39:51 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	get_random_color(GLfloat *color)
{
	color[0] = (GLfloat)rand() / RAND_MAX;
	color[1] = (GLfloat)rand() / RAND_MAX;
	color[2] = (GLfloat)rand() / RAND_MAX;
	color[3] = 1.0f;
}

void	generate_color(t_face *new_face)
{
    new_face->color[0] = 2.0f;
    new_face->color[1] = 0.0f;
    new_face->color[2] = 0.0f;
    new_face->color[3] = 1.0f;
}