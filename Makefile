##
## Makefile for make in /home/collin_b/project/abstract_vm/abstract_VM
## 
## Made by jonathan.collinet
## Login   <collin_b@epitech.net>
## 
## Started on  Thu Feb 13 13:32:41 2014 jonathan.collinet
## Last update Tue Feb 25 21:25:05 2014 jonathan.collinet
##

SRC		=	main.cpp \
			Abstract.cpp \
			Parser.cpp \
			Exception.cpp \
			Memory.cpp \
			Cpu.cpp \
			Instruction.cpp \
			OperandFactory.cpp \
			Operand.cpp \

CC		=	g++

RM		=	rm -f

NAME		=	avm

OBJDIR		=	obj/
SRCDIR		=	src/

CFLAGS		+=	-g -Wall -Wextra

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
			@echo "C3PO says : Removing object ..."
			@$(RM) $(OBJ)

fclean:			clean
			@echo "C3PO says : I remove ${NAME}"
			@$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
