#makefile de juego OCA
FLAGS=-ansi -pedantic -g -Wall -DDEBUG
OBJ = command.o game.o game_loop.o graphic_engine.o screen.o space.o game_reader.o object.o player.o set.o die.o
ocaEXE: $(OBJ)
	gcc -o ocaEXE command.o game.o game_loop.o graphic_engine.o screen.o space.o game_reader.o object.o player.o set.o die.o

command.o: command.c command.h types.h
	@echo "######################"
	@echo "Creando $@"
	gcc -c  $(FLAGS) command.c

game.o: game.c game.h player.h types.h object.h command.h space.h die.h game_reader.h
	@echo "######################"
	@echo "Creando $@"	
	gcc  -c $(FLAGS) game.c
        
game_loop.o: game_loop.c graphic_engine.h game.h player.h types.h object.h command.h space.h die.h
	@echo "######################"
	@echo "Creando $@"
	gcc -c $(FLAGS) game_loop.c
        
graphic_engine.o: graphic_engine.c screen.h graphic_engine.h command.h game.h player.h types.h object.h space.h die.h
	@echo "######################"
	@echo "Creando $@"
	gcc -c $(FLAGS) graphic_engine.c

screen.o: screen.c screen.h
	@echo "######################"
	@echo "Creando $@"
	gcc -c $(FLAGS) screen.c

space.o: space.c set.h types.h space.h
	@echo "######################"
	@echo "Creando $@"
	gcc -c $(FLAGS) space.c

game_reader.o: game_reader.c game_reader.h game.h player.h object.h command.h space.h die.h types.h
	@echo "######################"
	@echo "Creando $@"
	gcc -c $(FLAGS) game_reader.c

player.o: player.c player.h types.h object.h
	@echo "######################"
	@echo "Creando $@"
	gcc -c $(FLAGS) player.c

object.o: object.c object.h types.h
	@echo "######################"
	@echo "Creando $@"
	gcc -c $(FLAGS) object.c

set.o: set.c set.h types.h
	@echo "#####################"
	@echo "Creando $@"
	gcc -c $(FLAGS) set.c

die.o: die.c die.h types.h
	@echo "#####################"
	@echo "Creando $@"
	gcc -c $(FLAGS) die.c

.PHONY: clean
clean: 
	@echo "Limpiando"
	rm -rf *.o ocaEXE setPruebaEXE spacePruebaEXE diePruebaEXE
