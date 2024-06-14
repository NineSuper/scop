/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 07:55:17 by tde-los-          #+#    #+#             */
/*   Updated: 2024/06/14 13:59:16 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"


void setup_lighting()
{
    GLfloat light_position[] = { 5.0f, 5.0f, -5.0f, 1.0f };
    GLfloat light_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat light_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
    GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat high_shininess[] = { 100.0f };
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

void setup_camera(t_cam *cam) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(cam->grow_shrink, cam->resize_f * WIDTH / HEIGHT, cam->resize_f, 100 * cam->resize_f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(5.0, 5.0, 5.0,
            0.0, 0.0, 0.0,
            0.0, 1.0, 0.0);
    glTranslatef(cam->tra_x, cam->tra_y, cam->tra_z);
}

void	ft_camera(t_cam *cam)
{
	setup_camera(cam);
	glRotatef(cam->xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(cam->yrot, 0.0f, 1.0f, 0.0f);
}

void	ft_face_draw(int num)
{
	if (num == 3)
		glBegin(GL_TRIANGLES);
	if (num == 4)
		glBegin(GL_QUADS);
	if (num == 5)
		glBegin(GL_POLYGON);
}
