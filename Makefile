CC			=	clang++-6.0

FWARN		=	-Wall -Wextra -Werror -Wno-unused-function -Wno-unused-variable
FDEBUG		=	-g
FOPTI		=	-O3 -Ofast
FLAGS		=	$(FWARN) $(FDEBUG) $(FOPTI)

NAME		=	libregex.a

SRCS_DIR	=	srcs
OBJS_DIR  	=	objs
INC_DIR		=	includes

SRCS	=	NFA.cpp \
			NFAState.cpp \
			Regex.cpp

INCLUDE	=	$(addprefix $(INC_DIR)/, \
				NFA.hpp, \
				NFAState.hpp, \
				Regex.hpp \
			)

OBJS		= $(SRCS:.cpp=.o)

all:	$(NAME)

$(NAME): $(addprefix $(OBJS_DIR)/, $(OBJS))
	ar rc $(NAME) $(addprefix $(OBJS_DIR)/, $(OBJS))

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(addprefix $(OBJS_DIR)/, $(OBJS))

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
