NAME = cub3d

# *** #
# INC #
# *** #

INCLUDES	=	./includes
LIBFT		=	./lib/bin/libft.a

# *** #
# DIR #
# *** #

OBJ_DIR		=	./objs
SRC_DIR		=	./srcs

# *** #
# OBJ #
# *** #

OBJS	= 	$(addprefix ${OBJ_DIR}/,${SRC:.c=.o})

# *** #
# SRC #
# *** #

SRC += ft_print_error.c
SRC += check.c
SRC += convert.c
SRC += copy.c
SRC += first_tests.c
SRC += give_me_wall.c
SRC += main.c
