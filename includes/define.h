/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoorickx <hugoorickx@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:34:20 by hugoorickx        #+#    #+#             */
/*   Updated: 2022/03/30 14:01:00 by hugoorickx       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define ERROR_WRONG_VALUE "Error: Wrong value\n"
# define ERROR_MALLOC "Error: Malloc doesn't work\n"
# define ERROR_NOT_MAP "Error: Not map in file\n"
# define ERROR_WRONG_CHAR "Error: Wrong char in map\n"
# define ERROR_WRONG_POS "Error: Wrong position of char in map\n"
# define ERROR_RBG_MAX_INT "Error: rgb can't be bigger than max int\n"
# define ERROR_RBG_NEG "Error: rgb can't be negative\n"
# define ERROR_RGB_255 "Error: rgb can't be bigger than 255\n"
# define ERROR_RGB_MIN_INT "Error: rgb can't be bigger than min int\n"
# define ERROR_MORE_PLAYER "Error: Two players or more in map\n"
# define ERROR_NO_PLAYER "Error: No player in map\n"
# define ERROR_VOID_LINE "Error: Void line in map\n"
# define ERROR_MORE_COLOR "Error: Two colors for the floor/sky\n"
# define ERROR_INV_NUMBER_COLOR "Error: Invalid number of colors for the rgb\n"
# define ERROR_NB_ARGUMENTS "Error: Arguments\n./Cub3d <path_to_file.cub>\n"
# define ERROR_WRONG_FILENAME "Error: File name\n./Cub3d <path_to_file.cub>\n"
# define ERROR_FILE_NOT_EXIST "Error: File doesn't exist\n"
# define ERROR_DATA_MISSING "Error: Datas missing\n"
# define ERROR_TOO_MANY_DATAS "Error: too many datas\n"
# define ERROR_DATA_INV "Error: Data not valid\n"
# define ERROR_TOO_MANY_IMG "Error: Two images for a wall\n"
# define ERROR_WRONG_TYPE_IMG "Error: Wrong type for image\n"
# define ERROR_IMG_NOT_EXIST "Error: image doesn't exist\n"
# define MESSAGE_END_EXIT "Thanks for playing\n"
# define W 13
# define Q 12
# define ESC 53
# define D 2
# define A 0
# define S 1
# define WINDOW_PRESS_EXIT 17
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define DOWN_ARROW 125
# define UP_ARROW 126

#endif