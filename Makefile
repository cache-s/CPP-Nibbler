##
## Makefile for nibbler in /home/cache-_s/rendu/cpp_nibbler
## 
## Made by Sebastien Cache-Delanos
## Login   <cache-_s@epitech.net>
## 
## Started on  Mon Mar 23 13:21:25 2015 Sebastien Cache-Delanos
## Last update Wed Mar 25 12:38:06 2015 Sebastien Cache-Delanos
##

NAME_EXE	= nibbler
SRCS_EXE	= ./sources/main.cpp			\
		  ./sources/nibbler.cpp			\
		  ./sources/game.cpp			\
		  ./sources/snake.cpp			\

OBJS_EXE	= $(SRCS_EXE:.cpp=.o)

NAME_LIB	= lib_nibbler_SDL.so
SRCS_LIB	= ./sources/SDL/Lib_SDL.cpp
OBJS_LIB	= $(SRCS_LIB:.cpp=.o)

NAME_LIB2	= lib_nibbler_Qt.so
SRCS_LIB2	= ./sources/Qt/Lib_Qt.cpp
OBJS_LIB2	= $(SRCS_LIB2:.cpp=.o)

LDFLAGS		+= -ldl
CXXFLAGS	+= -g -W -Wall -Wextra -Werror -fPIC -I ./includes

CXX		= g++

RM		= rm -rf

GREEN		= "\\033[1;32m"
NORMAL		= "\\033[0;39m"
YELLOW		= "\\033[1;33m"
CYAN		= "\\033[1;36m"

all: $(NAME_LIB2) $(NAME_LIB) $(NAME_EXE)

$(NAME_EXE): $(OBJS_EXE)
	@echo ' '
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	$(CXX) -o $(NAME_EXE) $(OBJS_EXE) $(LDFLAGS)
	@echo -n 'Finished building target:'
	@echo -e $(GREEN) '$@'
	@echo -e $(NORMAL) ' '

$(NAME_LIB): $(OBJS_LIB)
	@echo ' '
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	$(CXX) -shared -o $(NAME_LIB) $(OBJS_LIB)
	@echo -n 'Finished building target:'
	@echo -e $(CYAN) '$@'
	@echo -e $(NORMAL) ' '

$(NAME_LIB2): $(OBJS_LIB2)
	@echo ' '
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	$(CXX) -shared -o $(NAME_LIB2) $(OBJS_LIB2)
	@echo -n 'Finished building target:'
	@echo -e $(CYAN) '$@'
	@echo -e $(NORMAL) ' '

%.o: %.cpp
	@echo ' '
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	$(CXX) $(CXXFLAGS) -c -o $@ $<
	@echo -n 'Finished building: '
	@echo -e $(YELLOW) '$<'
	@echo -e $(NORMAL) ' '

clean:
	$(RM) $(OBJS_EXE) $(OBJS_LIB) $(OBJS_LIB2)
	@find ./ -name '*~' -exec rm '{}' \;
	@find ./ -name '*#' -exec rm '{}' \;

fclean: clean
	$(RM) $(NAME_EXE) $(NAME_LIB) $(NAME_LIB2)

dbg:    CPPFLAGS += -g
dbg:    re

nf:     CPPFLAGS = -I ./includes
nf:     re

re: fclean all
