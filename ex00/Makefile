# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/30 19:57:48 by lvichi            #+#    #+#              #
#    Updated: 2024/04/07 17:45:12 by ecarvalh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g #-lstdc++
RM = rm -fr
FILES = *.cpp
OBJS = *.o

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS): $(FILES)
	@$(CPP) $(CFLAGS) -c $(FILES)

clean:
	@$(RM) $(OBJS) obj

fclean:
	@$(RM) $(OBJS) $(NAME) obj

re: fclean all
