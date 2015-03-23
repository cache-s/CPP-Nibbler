##
## Makefile for nibbler in /home/cache-_s/rendu/cpp_nibbler
## 
## Made by Sebastien Cache-Delanos
## Login   <cache-_s@epitech.net>
## 
## Started on  Mon Mar 23 13:21:25 2015 Sebastien Cache-Delanos
## Last update Mon Mar 23 13:28:39 2015 Sebastien Cache-Delanos
##

NAME	= nibbler

SRCS	= ./sources/main.cpp			\

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS= -W -Wall -Wextra -Werror -I ./includes

CXX	= g++

RM	= rm -rf

GREEN	= "\\033[1;32m"
NORMAL	= "\\033[0;39m"
YELLOW	= "\\033[1;33m"

all: $(NAME)

$(NAME): $(OBJS)
	@echo ' '
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	$(CXX) -o $@ $^
	@echo -n 'Finished building target:'
	@echo -e $(GREEN) '$@'
	@echo -e $(NORMAL) ' '

%.o: %.c
	@echo ' '
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	$(CXX) $(CPPFLAGS) -c -o $@ $<
	@echo -n 'Finished building: '
	@echo -e $(YELLOW) '$<'
	@echo -e $(NORMAL) ' '

clean:
	$(RM) $(OBJS)
	@find ./ -name '*~' -exec rm '{}' \;
	@find ./ -name '*#' -exec rm '{}' \;

fclean: clean
	$(RM) $(NAME)

re: fclean all
