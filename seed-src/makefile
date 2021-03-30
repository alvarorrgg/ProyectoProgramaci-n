#makefile de juego OCA
target = ocaEXE
FLAGS=-ansi -pedantic -g -Wall -DDEBUG -I src -I include
OBJ = command.o game.o game_loop.o graphic_engine.o screen.o space.o game_reader.o object.o player.o set.o die.o
CC = gcc

vpath %.c src:include
vpath %.h include
vpath %.o obj
 

all: $(target)

ocaEXE: $(OBJ)
	$(CC) -o  $@ $^

command.o: command.c command.h types.h
	@echo "######################"
	@echo "Creando $@"
	$(CC) -c  $(FLAGS) $<

game.o: game.c game.h player.h types.h object.h command.h space.h die.h game_reader.h
	@echo "######################"
	@echo "Creando $@"	
	$(CC)  -c $(FLAGS) $<
        
game_loop.o: game_loop.c graphic_engine.h game.h player.h types.h object.h command.h space.h die.h
	@echo "######################"
	@echo "Creando $@"
	$(CC) -c $(FLAGS) $<
        
graphic_engine.o: graphic_engine.c screen.h graphic_engine.h command.h game.h player.h types.h object.h space.h die.h
	@echo "######################"
	@echo "Creando $@"
	$(CC) -c $(FLAGS) $<

screen.o: screen.c screen.h
	@echo "######################"
	@echo "Creando $@"
	$(CC) -c $(FLAGS) $<

space.o: space.c set.h types.h space.h
	@echo "######################"
	@echo "Creando $@"
	$(CC) -c $(FLAGS) $<

game_reader.o: game_reader.c game_reader.h game.h player.h object.h command.h space.h die.h types.h
	@echo "######################"
	@echo "Creando $@"
	$(CC) -c $(FLAGS) $<

player.o: player.c player.h types.h object.h
	@echo "######################"
	@echo "Creando $@"
	$(CC) -c $(FLAGS) $<

object.o: object.c object.h types.h
	@echo "######################"
	@echo "Creando $@"
	$(CC) -c $(FLAGS) $<

set.o: set.c set.h types.h
	@echo "#####################"
	@echo "Creando $@"
	$(CC) -c $(FLAGS) $<

die.o: die.c die.h types.h
	@echo "#####################"
	@echo "Creando $@"
	$(CC) -c $(FLAGS) $<

.PHONY: clean
clean: 
	@echo "Limpiando"
	rm -rf *.o ocaEXE setPruebaEXE spacePruebaEXE diePruebaEXE
