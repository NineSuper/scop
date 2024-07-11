/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:14:12 by tde-los-          #+#    #+#             */
/*   Updated: 2024/07/11 15:27:30 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

/*		Libft		*/
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/gnl/get_next_line.h"
/*		Librairie	*/
# include <GL/gl.h>
# include <GL/glut.h>
# include <SDL2/SDL.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <time.h>
# include "object.h"

/*		String		*/
# define TITLE "SCOP"
/*      Error       */
# define E_ALLOC    "Error: Memory allocation failed."
# define E_SDL_INIT "Error: SDL initialization failed."
# define E_WIN      "Error: Window initialization failed."
# define C_OPEN      "Error: Can\'t open: "
# define B_ARG		"./Scop <file>.obj"
/*		Texture		*/

/*		Color		*/
# define C_BLUE "\033[1;36m"
# define C_GREEN "\033[1;32m"
# define C_RED "\033[1;41m"
# define C_NONE "\033[0m"
/*		Screen Size	 */
# ifndef WIDTH
#  define WIDTH 1280
# endif

# ifndef HEIGHT
#  define HEIGHT 720
# endif

// macOS
# ifdef __APPLE__
#  include <OpenGL/glu.h>
#  define USE_GLK
# else
// Linux/Windows
# include <GL/glu.h>
#  undef USE_GLK
# endif

# ifdef __APPLE__
#  include <GLKit/GLKMatrix4.h>
#  define gluPerspective(fovy, aspect, zNear, zFar) GLKMatrix4MakePerspective(fovy, aspect, zNear, zFar)
#  define gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ) GLKMatrix4MakeLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ)
# endif

typedef struct s_win
{
	SDL_GLContext	context;
	SDL_Window		*window;
	SDL_Event		event;
	char			*title;
	int				height;
	int				width;
}	t_win;

typedef struct s_cam
{
	float	xrot;
	float	yrot;
	float	xdiff;
	float	ydiff;
	float	tra_x;
	float	tra_y;
	float	tra_z;
	float	grow_shrink;
	float	resize_f;
	int		mouseDown;
}	t_cam;

typedef struct s_master
{
	t_win	win;
	t_obj	object;
	t_cam	cam;
	bool	quit;
}	t_master;

//			FUNCTION		//

//	INIT
void	ft_init_window(t_master *s_m);
void	ft_sdl_loop(t_master *s_m);
int		ft_parse_obj(t_obj *object);
void	init_glpos(t_obj *obj);
void	get_random_color(GLfloat *color);
void	setup_camera(t_cam *cam);
void	setup_lighting();
void	ft_init_mtl(t_mtl *mtl, char *dir);
//	FREE
void	ft_free_all(t_master *s_m);
void	free_tab(char **tab);
void	ft_free_obj(t_obj *object);
void	free_glfloat(GLfloat **vertices, int nb_vertices);
// PARSING
void	ft_read_file(t_obj *object);
void	ft_scanf_face(const char *str, t_face *lst);
// UTILS
void	generate_color(t_face *new_face);
void	ft_face_draw(int num);
void	ft_camera(t_cam *cam);
void 	ft_key(t_master *s_m, int key);
void    ft_mouse_motion(t_master *s_m, int x, int y);
void    ft_mouse_button(t_master *s_m, int button, int state, int x, int y);
void	ft_otherEvent(t_master *s_m, SDL_Event event);
//			FUNCTION		//

#endif
