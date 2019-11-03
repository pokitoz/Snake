CC=gcc
BINARY=Snake

SOURCE_C=\
	Apple.c \
	Game.c \
	main.cpp \
	Option.c \
	Wall.c \
	Menu.c \
	Snake.c


${BINARY}:
	${CC} ${SOURCE_C} -lSDL -o $@
