# Compiler and flags
CC = gcc
CFLAGS = -Werror -Wall -Wextra

# Executable name
NAME = libft.a
MAIN = main.c
EXEC = prog

# Source and object files
SRCDIR = ./srcs
SRCFILES = 	ft_putchar_fd.c ft_putstr_fd.c ft_print_memory.c ft_isalpha.c ft_isdigit.c \
			ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
			ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
			ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putendl_fd.c \
			ft_putnbr_fd.c

BONUS_SRCDIR = ./bonus_srcs
BONUS_SRCFILES =	ft_lstadd_front.c ft_lstnew.c ft_lstsize.c ft_lstlast.c \
					ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c


OBJDIR = ./objs
OBJFILES = $(SRCFILES:%.c=%.o) $(BONUS_SRCFILES:%.c=%.o)

# Default target
all: run

run: erase $(EXEC)
	./$(EXEC)
	valgrind --leak-check=yes --track-origins=yes ./$(EXEC)
	@rm ./$(EXEC)

erase:
	rm -f ./$(EXEC)

$(EXEC): $(NAME)
	$(CC) $(CFLAGS) $(MAIN) -o $(EXEC) -L. -l:$(NAME)

$(NAME): $(addprefix $(OBJDIR)/, $(OBJFILES))
	ar rcs $(NAME) $(addprefix $(OBJDIR)/, $(OBJFILES))

# Compile source files into object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(BONUS_SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(addprefix $(OBJDIR)/, $(OBJFILES))

fclean: clean
	rm -f $(NAME)

# Rebuild everything from scratch
re: fclean all

