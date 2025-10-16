# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 10:05:49 by macarval          #+#    #+#              #
#    Updated: 2025/10/16 19:00:30 by macarval         ###   ########.fr        #
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
			sudo ip addr add $(IP_SOURCE)/24 dev $(INTERFACE)

net_vm_b:
			@make --no-print-directory net
			sudo ip addr add $(IP_TARGET)/24 dev $(INTERFACE)
			@ping -c 1 $(IP_SOURCE)

config:
			sudo apt update
			sudo apt install net-tools iputils-ping tcpdump arping valgrind


run_vm_a:
			@echo "\n$(YELLOW)Configuring VM A...$(RESET)\n"
			@echo "\n$(YELLOW)Starting Packet Capture...$(RESET)\n"
			sudo tcpdump -vv -i $(INTERFACE) arp

run_vm_b:
			@echo "\n$(YELLOW)Configuring VM B...$(RESET)\n"
			watch ip neigh

request:
			@echo "\n$(YELLOW)Sending ARP Request...$(RESET)\n"
			sudo arping -c 1 -I $(INTERFACE) $(IP_SOURCE) > /dev/null 2>&1 || true
			@echo "\n$(BGREEN)Tabela ARP imediatamente apos o ataque:$(RESET)"
			@echo "------------------------------------------------"
			@ip neigh show dev $(INTERFACE) | grep --color=always $(IP_SOURCE) || echo "$(BRED)Entrada para $(IP_SOURCE) nao encontrada.$(RESET)"
			@echo "------------------------------------------------"

comp:
			clear
			@sudo sysctl -w net.ipv4.conf.enp0s3.arp_ignore=
			@make --no-print-directory -s re
			@{ sudo ./$(NAME) $(IP_SOURCE) $(MAC_SOURCE) $(IP_TARGET) $(MAC_TARGET) $(FLAG); } || true
			@sudo sysctl -w net.ipv4.conf.enp0s3.arp_ignore=0

val:
			clear
			@make --no-print-directory -s re
			@{ sudo valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(IP_SOURCE) $(MAC_SOURCE) $(IP_TARGET) $(MAC_TARGET) $(FLAG); } || true

verify_spoof:
			@echo "$(BYELLOW)Verificando se o spoofing foi bem-sucedido...$(RESET)"
			@ip neigh show dev $(INTERFACE) | grep $(IP_SOURCE) | grep $(MAC_SOURCE) > /dev/null && \
			echo "$(BGREEN)✅ Spoofing detectado: IP $(IP_SOURCE) está associado ao MAC falso $(MAC_SOURCE)$(RESET)" || \
			echo "$(BRED)❌ Spoofing falhou: IP $(IP_SOURCE) ainda está com MAC real$(RESET)"

help:
			@echo "\n$(YELLOW)Available commands:$(RESET)\n"
			@echo "$(BYELLOW)make all$(RESET)        - Compile the project."
			@echo "$(BYELLOW)make clean$(RESET)      - Remove object files and temporary files."
			@echo "$(BYELLOW)make fclean$(RESET)     - Remove all generated files including the executable."
			@echo "$(BYELLOW)make re$(RESET)         - Recompile the project (fclean + all)."
			@echo "$(BYELLOW)make net$(RESET)        - Set up the network interface."
			@echo "$(BYELLOW)make net_vm_a$(RESET)   - Configure network for VM A."
			@echo "$(BYELLOW)make net_vm_b$(RESET)   - Configure network for VM B."
			@echo "$(BYELLOW)make config$(RESET)     - Install necessary packages."
			@echo "$(BYELLOW)make run_vm_a$(RESET)   - Run configuration commands for VM A."
			@echo "$(BYELLOW)make run_vm_b$(RESET)   - Run configuration commands for VM B."
			@echo "$(BYELLOW)make request$(RESET)    - Send an ARP request."
			@echo "$(BYELLOW)make comp$(RESET)       - Compile and run the program with sudo."
			@echo "$(BYELLOW)make val$(RESET)        - Compile and run the program with Valgrind."
			@echo "$(BYELLOW)make git$(RESET)        - Commit and push changes to Git with a structured message.\n"
			@echo "Example usage: $(BWHITE)make comp FLAG=-v INTERFACE=enp0s3$(RESET)\n"
			@echo "Note: Replace 'enp0s3' with your actual network interface name.\n"

git:
			clear
			@make --no-print-directory fclean
			@git add .
			@git status
			@echo "$(BPURPLE)Choose the commit type:"; \
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

.PHONY:		all re clean fclean comp val git net net_vm_a net_vm_b config \
			run_vm_a run_vm_b request help
