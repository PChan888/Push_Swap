# NAME = libft.a defines the name of the output file 
# (by convention a static library), which is later created using ar.
# .a is an archive format used for static libraries, which packages 
# multiple object files into a single file.
NAME = libft.a

# This section groups source files into mandatory and bonus sets for 
# clarity and to match the project specification; Make treats them as 
# plain variables until they are referenced later.
PART1 = ft_tolower.c ft_toupper.c ft_isprint.c ft_isascii.c ft_isalnum.c \
		ft_isdigit.c ft_isalpha.c ft_atoi.c ft_strlen.c ft_strlcat.c \
		ft_strncmp.c ft_strdup.c ft_calloc.c ft_memcpy.c ft_strchr.c \
		ft_strrchr.c ft_strnstr.c ft_bzero.c ft_memchr.c ft_memcmp.c \
		ft_memset.c ft_memmove.c ft_strlcpy.c

PART2 = ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c

BONUS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
		ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c \
		ft_lstlast_bonus.c ft_lstsize_bonus.c ft_lstmap_bonus.c \
		ft_lstnew_bonus.c

# CC = cc defines which compiler command will be used, allowing it to be 
# reused and easily changed throughout the Makefile.
# We use uppercase CC as a Makefile variable by convention, 
# which avoids confusion with the actual cc.
CC = cc

# CFLAGS holds compiler flags so options like -Wall -Wextra -Werror 
# don’t have to be repeated.
CFLAGS = -Wall -Wextra -Werror

# remove and force remove
RM = rm -f

SRCS = ${PART1} ${PART2}

OBJS = $(SRCS:.c=.o)

# ":" is used for suffix substitution.
BONUS_OBJS = $(BONUS:.c=.o)

# no need for -I. include path header in same folder.
# derived from source .c
.c:.o
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

# ${NAME}: ${OBJS} Runs only if .o files changed or ${NAME} is missing.
# ar rcs means: create the archive if needed, replace/add object files, 
# and generate the symbol index.
${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

# Makes just the SRCS files here.
all: ${NAME}

# bonus: Always runs, ignores whether ${NAME} exists.
bonus:	${OBJS} ${BONUS_OBJS}
		ar rcs ${NAME} ${OBJS} ${BONUS_OBJS}

# just cleans .o
clean:
	${RM} ${OBJS} ${BONUS_OBJS}

# cleans all including .o and libft.a
fclean: clean
	${RM} ${NAME}

# rebuild the library cleans then remakes
re: fclean all

# .PHONY prevents make from confusing command 
# targets with real files of the same name.
.PHONY: all clean fclean re