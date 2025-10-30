# ============================================================================ #
#                                    CONFIG                                    #
# ============================================================================ #

# Executable Name
EXE				:=	scop

# Directories
SRC_DIR			:=	src
INC_DIR			:=	includes
OBJ_DIR			:=	obj

# Compiler and Flags
CXX				:=	c++
CXXFLAGS		:=	-Wall -Werror -Wextra -O2 -std=c++20

# Colors
CLR_GREEN		:=	\033[1;32m
CLR_RESET		:=	\033[0m

# Files
SRCS			:=	main.cpp

SRC_FILES		:=	${addprefix ${SRC_DIR}/,${SRCS}}
INC_FILES		:=	${addprefix -I,${INC_DIR}}
OBJ_FILES		:=	${addprefix ${OBJ_DIR}/,${SRCS:.cpp=.o}}

# ============================================================================ #
#                                    RULES                                     #
# ============================================================================ #

all				:	${EXE}

${EXE}			:	${OBJ_FILES}
					@echo "${CLR_GREEN}Linking '${EXE}'...${CLR_RESET}"
					${CXX} ${CXXFLAGS} ${OBJ_FILES} -o ${EXE}
					@echo "${CLR_GREEN}Build complete!${CLR_RESET}"

${OBJ_DIR}/%.o	:	${SRC_DIR}/%.cpp
					@mkdir -p ${dir $@}
					@echo "${CLR_GREEN}Compiling...${CLR_RESET}"
					${CXX} ${CXXFLAGS} ${INC_FILES} -c $< -o $@

clean			:
					@echo "${CLR_GREEN}Cleaning object files...${CLR_RESET}"
					rm -rf ${OBJ_DIR}

fclean			:	clean
					@echo "${CLR_GREEN}Removing binary...${CLR_RESET}"
					rm -rf ${EXE}

re				:	fclean all

.PHONY			:	all clean fclean re
