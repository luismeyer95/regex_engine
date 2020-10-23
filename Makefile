CC			=	clang++-6.0

FWARN		=	-Wall -Wextra -Werror
FDEBUG		=	-g
FOPTI		=	-O3
FLAGS		=	$(FWARN) $(FDEBUG) $(FOPTI)

NAME		=	libregex.a

SRCS_DIR	=	srcs
OBJS_DIR  	=	objs
INC_DIR		=	includes

SRCS	=	regex.cpp \
			NFA.cpp \
			NFAState.cpp \
			PatternValidation.cpp

INCLUDE	=	$(addprefix $(INC_DIR)/, \
				NFA.hpp, \
				NFAState.hpp, \
				regex.hpp \
				PatternValidation.hpp \
			)

OBJS		= $(SRCS:.cpp=.o)

all:	$(NAME) main

$(NAME): $(addprefix $(OBJS_DIR)/, $(OBJS))
	ar rc $(NAME) $(addprefix $(OBJS_DIR)/, $(OBJS))
	ranlib $(NAME)

main:
	$(CC) $(FLAGS) main.cpp $(NAME) -o main

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	$(CC) $(FLAGS) $(addprefix -I, $(INC_DIR)) -c $< -o $@

clean:
	@rm -f $(addprefix $(OBJS_DIR)/, $(OBJS))

fclean: clean
	@rm -f $(NAME) main

re: fclean all

.PHONY: clean fclean re main
