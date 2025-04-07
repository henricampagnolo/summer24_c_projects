# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 21:19:28 by ncolomer          #+#    #+#              #
#    Updated: 2019/10/18 23:01:39 by ncolomer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Compiler and flags
CC = gcc
CFLAGS = -Werror -Wall -Wextra

# Executable name
NAME = libftprintf.a
MAIN = ft_printf.c
EXEC = prog

# Source and object files
SRCFILES = 	ft_putchar_fd.c ft_putstr_fd.c ft_print_memory.c ft_isalpha.c ft_isdigit.c \
			ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
			ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
			ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putendl_fd.c \
			ft_putnbr_fd.c

BONUS_SRCFILES =	ft_lstadd_front.c ft_lstnew.c ft_lstsize.c ft_lstlast.c \
					ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

LIBRARY = ./libft/libft.a
LIBFOLDER = ./libft
MAKE = make

OBJFILES = $(SRCFILES:%.c=%.o) 

BONUS_OBJFILES = $(BONUS_SRCFILES:%.c=%.o)

# Default target
run: build $(EXEC)
	./$(EXEC)
	valgrind --leak-check=yes --track-origins=yes ./$(EXEC)
	@rm ./$(EXEC)

build: 
	@rm -f $(EXEC)

$(EXEC): $(LIBRARY)
	$(CC) $(CFLAGS) $(MAIN) -o $(EXEC) -L. -l:$(LIBRARY)

all: $(LIBRARY) $(NAME) bonus

$(LIBRARY):
	cd $(LIBFOLDER) && $(MAKE) bonus && cd ..

$(NAME): $(addprefix $(FOLDER)/, $(OBJFILES))
	ar rcs $(NAME) $(addprefix $(FOLDER)/, $(OBJFILES))

bonus: $(addprefix $(FOLDER)/, $(BONUS_OBJFILES))
	ar rcs $(NAME) $(addprefix $(FOLDER)/, $(BONUS_OBJFILES))

# Compile source files into object files
$(FOLDER)/%.o: $(FOLDER)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(addprefix $(FOLDER)/, $(OBJFILES)) $(addprefix $(FOLDER)/, $(BONUS_OBJFILES))

fclean: clean
	rm -f $(NAME)

# Rebuild everything from scratch
re: fclean all

.PHONY:	all clean fclean re bonus
