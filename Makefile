# ============================================================================ #
#                                    CONFIG                                    #
# ============================================================================ #

# Executable Name
EXE				:=	scop

# Directories
SRC_DIR			:=	src
INC_DIR			:=	src/core src/utils includes external
OBJ_DIR			:=	obj

# Compiler and Flags
CXX				:=	c++
CXXFLAGS		:=	-Wall -Werror -Wextra -O2 -std=c++20

CC				:=	cc
CFLAGS			:=	-Wall -Werror -Wextra -O2

LIBS			:=	-lglfw -ldl -lGL

# Colors
CLR_GREEN		:=	\033[38;2;157;217;83m
CLR_BLUE		:=	\033[38;2;47;160;219m
CLR_RESET		:=	\033[0m

# Files
SRCS			:=	main.cpp \
					core/Window.cpp \
					core/Input.cpp \
					utils/debug.cpp

C_SRCS			:=	external/GLAD/glad.c

SRC_FILES		:=	${addprefix ${SRC_DIR}/,${SRCS}}
INC_FILES		:=	${addprefix -I,${INC_DIR}}
OBJ_FILES		:=	${addprefix ${OBJ_DIR}/,${SRCS:.cpp=.o}} \
					${addprefix ${OBJ_DIR}/,${C_SRCS:.c=.o}}

# ============================================================================ #
#                                    RULES                                     #
# ============================================================================ #

all				:	${EXE}

# Link all objects
${EXE}			:	${OBJ_FILES}
					@echo "${CLR_GREEN}Linking '${EXE}'...${CLR_RESET}"
					${CXX} ${CXXFLAGS} ${OBJ_FILES} -o ${EXE} ${LIBS}
					@echo "${CLR_GREEN}Build complete!${CLR_RESET}"

# Compile C++ files
${OBJ_DIR}/%.o	:	${SRC_DIR}/%.cpp
					@mkdir -p ${dir $@}
					@echo "${CLR_BLUE}Compiling $<...${CLR_RESET}"
					@${CXX} ${CXXFLAGS} ${INC_FILES} -c $< -o $@

# Compile C files
${OBJ_DIR}/%.o	:	%.c
					@mkdir -p ${dir $@}
					@echo "${CLR_BLUE}Compiling $<...${CLR_RESET}"
					@${CC} ${CFLAGS} ${INC_FILES} -c $< -o $@

# Clean object files
clean			:
					@echo "${CLR_GREEN}Cleaning object files...${CLR_RESET}"
					rm -rf ${OBJ_DIR}

# Clean everything
fclean			:	clean
					@echo "${CLR_GREEN}Removing binary...${CLR_RESET}"
					rm -rf ${EXE}

# Rebuild all
re				:	fclean all

.PHONY			:	all clean fclean re
