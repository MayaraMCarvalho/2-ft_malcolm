# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 10:05:49 by macarval          #+#    #+#              #
#    Updated: 2025/10/13 16:24:44 by macarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_malcolm

SRCS		= main.c errors.c info.c interface.c reply.c request.c setup.c \
			utils.c validations.c

VPATH		= srcs/
OBJS_PATH	= obj
LIBS		= -L./libs/libft

#libft
LIBFT_PATH	= ./libs/libft
LIBFT_INC	= $(LIBFT_PATH)/includes
LIBFT		= $(LIBFT_PATH)/libft.a
INCLUDE		= -I./include -I$(LIBFT_INC)

FLAGS		= -g3 -Wall -Wextra -Werror -g
LFLAGS		= -lft
CC			= gcc

# Regular colors
RED			= \033[0;31m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
PURPLE		= \033[0;35m
CYAN		= \033[0;36m
WHITE		= \033[0;37m
RESET		= \033[0m

# Bold
BRED		= \033[1;31m
BGREEN		= \033[1;32m
BYELLOW		= \033[1;33m
BBLUE		= \033[1;34m
BPURPLE		= \033[1;35m
BCYAN		= \033[1;36m
BWHITE		= \033[1;37m

OBJS		= $(addprefix $(OBJS_PATH)/, $(SRCS:.c=.o))

# Config
IP_SOURCE	= 192.168.250.2
MAC_SOURCE	= aa:bb:cc:dd:ee:ff
IP_TARGET	= 192.168.250.3
MAC_TARGET	= 10:dd:b1:00:00:00
FLAG		= -v
INTERFACE	= enp0s3
IP_HOST		= 192.168.250.4

all: 		$(NAME)

$(NAME):	$(LIBFT) $(OBJS_PATH) $(OBJS)
			@$(CC) $(FLAGS) $(OBJS) $(LFLAGS) $(LIBS) -o $(NAME)
			@echo "\n$(CYAN)$(NAME): $(GREEN)Done!$(RESET)\n"

$(LIBFT):
			@make -sC $(LIBFT_PATH)

$(OBJS_PATH):
			@mkdir -p $(OBJS_PATH)

$(OBJS_PATH)/%.o: %.c
			@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@
			@echo -n "$(YELLOW)Generating $(CYAN)$(NAME) $(YELLOW)objects..." $@
			@echo -n "\n"

clean:
			@make -sC $(LIBFT_PATH) clean
			@rm -rf $(OBJS_PATH) Test
			@echo "$(CYAN)$(NAME): $(GREEN)Clean done!$(RESET)"

fclean:		clean
			@make -sC $(LIBFT_PATH) fclean
			@rm -f $(NAME)
			@echo "$(CYAN)$(NAME): $(GREEN)Full clean done!$(RESET)"

re:			fclean all

net:
			@echo "\n$(YELLOW)Setting up network interface...$(RESET)\n"
			sudo ip link set dev $(INTERFACE) up
			sudo ip addr flush dev $(INTERFACE)

net_vm_a:
			@make --no-print-directory net
			sudo ip addr add $(IP_HOST)/24 dev $(INTERFACE)

net_vm_b:
			@make --no-print-directory net
			sudo ip addr add $(IP_TARGET)/24 dev $(INTERFACE)

net_vm_c:
			@make --no-print-directory net
			sudo ip addr add $(IP_SOURCE)/24 dev $(INTERFACE)

config:
			sudo apt update
			sudo apt install net-tools iputils-ping tcpdump arping valgrind


run_vm_a:
			@echo "\n$(YELLOW)Configuring VM A...$(RESET)\n"
			ping -c 1 $(IP_TARGET)
			@make --no-print-directory config
			ip -4 -o addr show $(INTERFACE) | awk '{print $$4}'
			@echo "\n$(YELLOW)Starting Packet Capture...$(RESET)\n"
			sudo tcpdump -vv -i $(INTERFACE) arp

run_vm_b:
			@echo "\n$(YELLOW)Configuring VM B...$(RESET)\n"
			make config
			watch ip neigh

request:
			@echo "\n$(YELLOW)Sending ARP Request...$(RESET)\n
			sudo ip neigh flush dev $(INTERFACE)
			sudo arping -c 1 -I $(INTERFACE) $(IP_SOURCE)

comp:
			clear
			@make --no-print-directory -s re
			@{ sudo ./$(NAME) $(IP_SOURCE) $(MAC_SOURCE) $(IP_TARGET) $(MAC_TARGET) $(FLAG); } || true

val:
			clear
			@make --no-print-directory -s re
			@{ sudo valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(IP_SOURCE) $(MAC_SOURCE) $(IP_TARGET) $(MAC_TARGET) $(FLAG); } || true

git:
			clear
			@make --no-print-directory fclean
			@git add .
			@git status
			echo "$(BPURPLE)Choose the commit type:"; \
			echo "$(BYELLOW)1. feat: $(WHITE)Adds a new feature to your codebase"; \
			echo "$(BYELLOW)2. fix: $(WHITE)Solves a problem in your codebase"; \
			echo "$(BYELLOW)3. docs: $(WHITE)Documentation changes"; \
			echo "$(BYELLOW)4. style: $(WHITE)Formatting, sender_ipcing, etc."; \
			echo "$(BYELLOW)5. refactor: $(WHITE)Refactoring code used in production, e.g. renaming a variable"; \
			echo "$(BYELLOW)6. test: $(WHITE)Adding tests, refactoring tests"; \
			echo "$(BYELLOW)7. chore: $(WHITE)Adjust build script, updating dependencies, makefile etc"; \
			read type_choice; \
			case $$type_choice in \
						1) type="feat" ;; \
						2) type="fix" ;; \
						3) type="docs" ;; \
						4) type="style" ;; \
						5) type="refactor" ;; \
						6) type="test" ;; \
						7) type="chore" ;; \
						*) echo "$(BRED)Invalid choice"; exit 1 ;; \
			esac; \
			echo -n "\n"; \
			echo "$(BGREEN)Enter the commit message:"; \
			read msg; \
			echo -n "\n"; \
			echo "$(BBLUE)"; \
			git commit -m "[$(NAME)] $$type: $$msg"; \
			git push

.PHONY:		all re clean fclean comp val git
