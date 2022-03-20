NAME = a.out
INCLUDE_DIR = ./include/

SRCS_DIR = ./src/
SRCS_DIR2 = ./src/scene/ ./src/trace/ ./src/trace/hit/ ./src/trace/ray/ ./src/utils/

SRCS_NAME = main.c\
			vec3_utils.c\
			canvas.c\
			object_create.c\
			scene.c\
			print.c\
			hit_sphere.c\
			normal.c\
			ray.c\
			hit.c\
			object_utils.c\
			phong_lighting.c


BASIC = $(addprefix $(SRCS_DIR), $(SRCS_NAME))

OBJ_DIR = objs

vpath %.c $(SRCS_DIR) $(SRCS_DIR2)

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(BASIC:.c=.o)))

CC = gcc
RM = rm -rf
FLAG = -Wall -Wextra -Werror -I $(INCLUDE_DIR)

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(FLAG) -o $(NAME) $(OBJS)

$(OBJ_DIR) :
	mkdir $(OBJ_DIR)

# mkdir $(OBJ_DIR)도 같이 진행
$(OBJ_DIR)/%.o : %.c $(OBJ_DIR)
	$(CC) $(FLAG) -c $< -o $@

clean :
	$(RM) $(OBJ_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

# addprefix(dir, file) -> 경로와 파일을 엮어줌
# vpath %.c $(SRCS_DIR) -> $(SRCS_DIR) 위치에 있는 %.c를 찾음
# notdir -> 파일 경로를 제거한 파일명만을 출력
# $@ -> 현재의 목표 파일(Target)
# $< -> 현재의 목표 파일(Target)보다 더 최근에 갱신된 파일 이름
