##
## Makefile for Makefile in /home/Epitech
##
## Made by moriss_h
## Login   <moriss_h@epitech.net>
##
## Started on  Sun Jun  9 03:35:24 2013 Hugues
## Last update Wed Feb 12 17:50:28 2014 jonathan.collinet
##

SRC		=	main.cpp \
			Abstract.cpp \
			Parser.cpp \

CC		=	g++

RM		=	rm -f

NAME		=	avm

OBJDIR		=	obj/
SRCDIR		=	src/

CFLAGS		+=	-Wall -Wextra

OBJ		=	$(patsubst %.cpp,${OBJDIR}%.o, $(SRC))

dummy		:=	$(shell test -d $(OBJDIR) || mkdir -p $(OBJDIR))
dummy		:=	$(shell test -d $(SRCDIR) || mkdir -p $(SRCDIR))

$(OBJDIR)%.o:		$(patsubst %.cpp,${SRCDIR}%.cpp, %.cpp)
			@if [ ! -d $(dir $@) ]; then mkdir -p $(dir $@); fi
			@echo "C3PO says : Compiling $< --{ $(CFLAGS) }--"
			@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):		$(OBJ)
			@$(CC) $(LDFLAGS) -o $(NAME) $(OBJ)

all:			$(NAME)

clean:
			@echo "C3PO says : Removing object ... my god i need an oil bath !"
			@$(RM) $(OBJ)

fclean:			clean
			@echo "C3PO says : I Remove ${NAME}, need a new program for my little head !"
			@$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean re

