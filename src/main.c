/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:00:57 by tde-los-          #+#    #+#             */
/*   Updated: 2024/05/18 07:16:51 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

/*
	TODO	Créer des objets 3D sur blender
	TODO	Parser les objets
	TODO	Faire une fenêtre avec SDL2
	*	Apprendre à regarder les leaks sans voir les erreurs génerés automatiquement via OpenGL
	*	Faire des évènements sur la fenêtre
	*	Mettre un cube via OpenGL sur la fenêtre SDL2 
	TODO	Afficher un cube fait sur blender
	TODO	Faire un HUD
*/

int	ft_args(int argc, char **argv, t_master *s_m)
{
	if (argc == 2)
	{
		if (argv[1] && argv[1][0] && ft_strlen(argv[1]) > 4)
		{
			if (ft_strnstr(argv[1] + ft_strlen(argv[1] + 4), ".obj", 4))
			{
				s_m->object.file = ft_strdup(argv[1]);
				ft_printf("%s[%s]%s\n", C_GREEN, s_m->object.file, C_NONE);
				return (0);
			}
		}
	}
	ft_printf("%s%s%s\n", C_RED, "./Scop <file>.obj", C_NONE);
	return (1);
}

/*
	TODO	Parse <file>.obj
*/

int	ft_open_obj(t_obj *object)
{
	object->fd = open(object->file, O_RDONLY);
	if (object->fd < 0)
		return (ft_printf("%s%s%s%s\n", C_RED, C_OPEN, object->file, C_NONE));
	return (0);
}

int	main(int argc, char **argv)
{
    t_master	*s_m;

    s_m = ft_calloc(1, sizeof(t_master));
    if (!s_m)
		 return (ft_printf("%s%s%s\n", C_RED, E_ALLOC, C_NONE));
	if (ft_args(argc, argv, s_m) || ft_open_obj(&s_m->object))
		ft_free_all(s_m);
	// ft_init_window(s_m);
	// init_font(&s_m->font);
	// ft_sdl_loop(s_m);
    ft_free_all(s_m);
    return (0);
}

// ft_test((t_win){.height = 5});
