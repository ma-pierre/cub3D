# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irakraki <irakraki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 14:02:03 by irakraki          #+#    #+#              #
#    Updated: 2024/06/26 22:22:12 by irakraki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=		./ft_isalpha.c \
			./ft_isdigit.c \
			./ft_isalnum.c \
			./ft_isascii.c \
			./ft_isprint.c \
			./ft_strlen.c \
			./ft_memset.c \
			./ft_bzero.c \
			./ft_memcpy.c \
			./ft_memmove.c \
			./ft_strlcpy.c \
			./ft_strlcat.c \
			./ft_toupper.c \
			./ft_tolower.c \
			./ft_strchr.c \
			./ft_strrchr.c \
			./ft_strncmp.c \
			./ft_memchr.c \
			./ft_memcmp.c \
			./ft_strnstr.c \
			./ft_atoi.c \
			./ft_calloc.c \
			./ft_strdup.c \
			./ft_substr.c \
			./ft_strjoin.c \
			./ft_strtrim.c \
			./ft_putstr_fd.c \
			./ft_putendl_fd.c \
			./ft_putnbr_fd.c \
			./ft_putchar_fd.c \
			./ft_split.c \
			./ft_itoa.c \
			./ft_strmapi.c \
			./ft_striteri.c \
			./ft_printf.c \
			./ft_printf_c.c \
			./ft_printf_id.c \
			./ft_printf_p.c \
			./ft_printf_s.c \
			./ft_printf_u.c \
			./ft_printf_x.c \
			./ft_printf_xmaj.c \
			./get_next_line.c \
			./get_next_line_utils.c \
			#./get_next_line_bonus.c \
			#./get_next_line_utils_bonus.c \
			



B_SRCS	=		./ft_lstnew.c \
			./ft_lstadd_front.c \
			./ft_lstsize.c \
			./ft_lstlast.c \
			./ft_lstadd_back.c \
			./ft_lstdelone.c \
			./ft_lstclear.c \
			./ft_lstiter.c \
			./ft_lstmap.c \

OBJS	=	$(SRCS:%.c=%.o)

B_OBJS	=	$(B_SRCS:%.c=%.o)

NAME	=	libft.a

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

all:		$(NAME)

%.o:		%.c
	$(CC) $(CFLAGS) -c $< -o $(<:%.c=%.o)

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
clean:
	rm -Rf $(OBJS) $(B_OBJS)

fclean:		clean
	rm -Rf $(NAME)

bonus:		$(OBJS) $(B_OBJS)
	ar rc $(NAME) $(OBJS) $(B_OBJS)
	ranlib $(NAME)
	

re:			fclean all

rebonus:	fclean bonus

.PHONY:		all clean fclean re bonus rebonus
