NAME		= libftprintf.a


SRCS		= ./ft_printf.c \
			  ./compt_size.c \
			  ./size_for_flag.c \
			  ./print.c \
			  ./storage.c \
			  ./scp_format.c \
			  ./i_format.c \
			  ./u_format.c \
			  ./xX_format.c \
			  ./i_format.c \
			  ./i_format2.c \
			  ./utils_to_parsing.c \
			  ./utils_to_print_ic.c \
			  ./utils_to_print_upx.c \
			  ./size_for_flag_2.c \

INC			= ft_printf.h 

OBJSBONUS	= $(SRCSBONUS:.c=.o) $(SRCS:.c=.o)
CFLAGS		= -Wall -Wextra -Werror

OBJS		= $(SRCS:.c=.o)



CC			= gcc

%.o:		%.c		$(INC)
			$(CC) $(CFLAGS) -c -o $@ $<


all			:	$(NAME) 

$(NAME)		:			$(OBJS) $(INC)
			ar rc $(NAME) $(OBJS)


clean		:
			rm -rf $(OBJS) 

fclean		:	clean
			rm -rf $(NAME)

re 			:	fclean all

.PHONY		:	 all clean fclean re
