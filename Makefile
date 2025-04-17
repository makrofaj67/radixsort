# ============================================================================== #
#                           PUSH_SWAP - Ana Makefile                           #
#               (argparser ve radixsorter klasör yapısına göre)                #
# ============================================================================== #

# --- Değişkenler ---
NAME			=	push_swap
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -f

# --- Kütüphane (ft_printf) ---
PRINTF_DIR		=	lib/ft_printf
PRINTF_A		=	$(PRINTF_DIR)/libftprintf.a
PRINTF_INC		=	-I$(PRINTF_DIR)/printf -I$(PRINTF_DIR)/libft

# --- Proje Başlık Dosyası Yolları ---
PROJECT_INC		=	-Iinc -Iargparser
INC_DIRS		=	$(PROJECT_INC) $(PRINTF_INC)

# --- Kaynak Dosyaları ---
# Ana giriş noktası
SRCS_MAIN		=	main.c

# Argüman ayrıştırma modülü dosyaları
SRCS_ARGPARSER	=	$(wildcard argparser/*.c)

# Sıralama mantığı modülü dosyaları (radixsorter klasöründen, main.c HARİÇ)
# Not: Eğer radixsorter içinde başka .c dosyaları varsa onları da ekleyin.
# Manuel listelemek daha güvenli olabilir.
SRCS_SORTER		=	radixsorter/indexing.c \
					radixsorter/push_swap_main_logic.c \
					radixsorter/radix_sort.c \
					radixsorter/sort_small.c \
					radixsorter/stack_ops_rev_rotate.c \
					radixsorter/stack_ops_rotate.c \
					radixsorter/stack_ops_swap_push.c \
					radixsorter/stack_utils.c
# Eğer swap ve push'u ayırdıysanız:
# SRCS_SORTER		=	radixsorter/indexing.c \
#					radixsorter/push_swap_main_logic.c \
#					radixsorter/radix_sort.c \
#					radixsorter/sort_small.c \
#					radixsorter/stack_ops_rev_rotate.c \
#					radixsorter/stack_ops_rotate.c \
#					radixsorter/stack_ops_swap.c \    # Ayrıysa
#					radixsorter/stack_ops_push.c \    # Ayrıysa
#					radixsorter/stack_utils.c

# Tüm kaynak dosyaları
SRCS			=	$(SRCS_MAIN) $(SRCS_ARGPARSER) $(SRCS_SORTER)

# --- Nesne Dosyaları ---
OBJS			=	$(SRCS:.c=.o)

# --- Başlık Dosyası Bağımlılıkları ---
DEPS			=	inc/push_swap.h argparser/argparser.h Makefile

# ============================================================================== #
#                                   Kurallar                                     #
# ============================================================================== #

all:			$(NAME)

$(NAME):		$(OBJS) $(PRINTF_A)
				@echo "\033[1;34mLinking $(NAME)...\033[0m"
				$(CC) $(CFLAGS) $(OBJS) $(PRINTF_A) -o $(NAME)
				@echo "\033[1;32mSuccessfully created $(NAME)\033[0m"

$(PRINTF_A):
				@echo "\033[1;36mBuilding printf library...\033[0m"
				@$(MAKE) -s -C $(PRINTF_DIR)
				@echo "\033[1;32mPrintf library built.\033[0m"

# .o kuralı: Tüm include yollarını içerir ve DEPS'e bağlıdır
# Bu kural, farklı dizinlerdeki .c dosyalarını doğru şekilde işler.
%.o:			%.c $(DEPS)
				@echo "\033[0;33mCompiling $<...\033[0m"
				$(CC) $(CFLAGS) $(INC_DIRS) -c $< -o $@

clean:
				@echo "\033[1;31mCleaning push_swap objects...\033[0m"
				@$(RM) $(OBJS)
				@echo "\033[1;31mCleaning printf library objects...\033[0m"
				@$(MAKE) -s -C $(PRINTF_DIR) clean
				@echo "\033[0;32mCleaning done.\033[0m"

fclean:			clean
				@echo "\033[1;31mCleaning $(NAME)...\033[0m"
				@$(RM) $(NAME)
				@echo "\033[1;31mCleaning printf library archive...\033[0m"
				@$(MAKE) -s -C $(PRINTF_DIR) fclean
				@echo "\033[0;32mFull cleaning done.\033[0m"

re:				fclean all

.PHONY:			all clean fclean re

#ifndef SILENT
#.SILENT:
#endif
