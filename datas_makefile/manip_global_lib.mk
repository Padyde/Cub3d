global_libft_init:
	@if [ ! -e "./lib/bin/libft.a" ]; then \
		printf "\n\t${BLUE_UNDERLINE}Libft :${DEFAULT}\n\n"; \
		make -C ./lib; \
	fi

clean_libft:
	@if [ -e "./lib/bin/libft.a" ]; then \
		printf "\n\t${BLUE_UNDERLINE}Libft :${DEFAULT}\n\n"; \
		make clean -C ./lib; \
	fi

fclean_libft:
	@if [ -e "./lib/bin/libft.a" ]; then \
		printf "\n\t${BLUE_UNDERLINE}Libft :${DEFAULT}\n\n"; \
		make fclean -C ./lib; \
	fi

re_libft:
	@printf "\n\t${BLUE_UNDERLINE}Libft :${DEFAULT}\n\n"
	@make re -C ./lib

add_libft:
	@make add -C ./lib