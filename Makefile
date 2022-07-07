# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 22:56:47 by afrolova          #+#    #+#              #
#    Updated: 2022/07/07 19:57:50 by afrolova         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

		#COLORS

END_COLOR = \033[0;0m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

         #CARPETAS

DIR_OBJ = OBJ
DIR_SRCS = SRCS
SRCS = ft_printf.c ft_write.c ft_numbers.c ft_hexadecimales.c  

#convierte los archivos que le paso en SRCS de .c a .o. y los ubica en la carpeta OBJ

OBJS = $(addprefix $(DIR_OBJ)/,$(SRCS:.c=.o))
EXEC_NAME = printf
NAME := libftprintf.a
CC = gcc
RM = rm -rf
AR += -rcs
CFLAGS += -Wall -Werror -Wextra

#Estoy incluyendo mi libft.h dentro del libftprintf.h, si hago la copia... hace falta??

HEADER = INC/libftprintf.h
#HEADER_LIBFT = Libft/libft.h

#Nombre y ubicacion de la libreria libft al compilarse con el make que le mando desde aqui
LIBFT = Libft/libft.a

all: 				OBJ/ libft_make $(NAME)

#Lo quito de ejecucion dentro de NAME, hace falta hacer copia cada vez?? - cp $(LIBFT) $(NAME)
$(NAME):			$(OBJS) $(LIBFT)
					-cp $(LIBFT) $(NAME)
					$(AR) $@ $(OBJS)
					@echo "${GREEN}ft_printf compiled successfully!${END_COLOR}"

$(DIR_OBJ)/%.o: 	$(DIR_SRCS)/%.c $(HEADER)
					$(CC) -IINC -ILibft $(CFLAGS) -c $< -o $@

OBJ/:
			-mkdir OBJ

exec:		$(OBJS) $(LIBFT) 
			$(CC) $(OBJS) $(LIBFT) -o $(EXEC_NAME)

libft_make:		
			${MAKE} -C Libft

#$(LIBFT):	$(HEADER_LIBFT)
#			${MAKE} -C Libft

clean:
			$(RM) $(OBJS)
			${MAKE} -C Libft clean
			$(RM) OBJ/
			@echo "${BLUE}ft_printf object files cleaned!${END_COLOR}"

fclean:		clean
			$(RM) $(NAME)
			${MAKE} -C Libft fclean
			$(RM) $(EXEC_NAME)
			@echo "${CYAN}ft_print executable files cleaned!${END-COLOR}"
			
re:			fclean all
			@echo "${YELLOW}Cleaned und rebuilt everything for ft_printf${END_COLOR}"

dev: CFLAGS = -Wall -Wextra -Wpedantic -fsanitize=address,undefined
dev: re

.PHONY: all clean fclean re dev exec libft_make
