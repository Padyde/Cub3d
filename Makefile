-include datas_makefile/colors.mk

-include datas_makefile/srcs.mk

CFLAGS		=	-Wall -Wextra -Werror

all:  global_libft_init creat_dir print ${NAME}

-include datas_makefile/manip_global_lib.mk

${NAME}:    ${OBJS}
	@gcc ${CFLAGS} -I ${INCLUDES} -I /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit ${LIBFT} ${OBJS} -o $@
	@printf "${START_FIRST}${BLUE}%-30s${DEFAULT}\t\t[${GREEN} OK ${DEFAULT}]%40s\n" "Compile" ""

${OBJ_DIR}/%.o:${SRC_DIR}/%.c
	@${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o $@
	@printf "${START_FIRST}${BLUE}%-30s${DEFAULT}\t\t[${GREEN}%-30s${DEFAULT}]" "minishell" $<
	@sleep ${FAST}

creat_dir:
	@mkdir -p ${OBJ_DIR}

clean:
	@rm -rf ${OBJ_DIR}
	@printf "${RED}%-30s${DEFAULT}\t\t[${GREEN} OK ${DEFAULT}]\n" "Cleaning up object files"

fclean: clean
	@rm -f ${NAME}
	@printf "${RED}%-30s${DEFAULT}\t\t[${GREEN} OK ${DEFAULT}]\n" "Removed ${NAME}"

re: re_libft print fclean  all

run: ${NAME}
	@./${NAME}

print:
	@printf "\n\t${BLUE_UNDERLINE}${NAME} :${DEFAULT}\n\n"

add:
	@bash ./bash/add.sh
	@printf "${GREEN}File(s) ok !${DEFAULT}\n\n"

man:
	@bash ./bash/makefile_man.sh