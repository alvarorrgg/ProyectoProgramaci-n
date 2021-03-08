#makefile de juego OCA
FLAGS=-ansi -pedantic
#setPruebaEXE: set.o set_test.o
	#gcc -o setPruebaEXE $(FLAGS) set.o set_test.o

ocaEXE: command.o game.o game_loop.o graphic_engine.o screen.o space.o game_reader.o object.o player.o set.o die.o
	gcc -o ocaEXE $(FLAGS) command.o game.o game_loop.o graphic_engine.o screen.o space.o game_reader.o object.o player.o set.o die.o

command.o: command.c command.h
	@echo "######################"
	@echo "Creando $@"
	gcc -Wall -c $(FLAGS) command.c

game.o: game.c set.c space.c object.c player.c game.h game_reader.h
	@echo "######################"
	@echo "Creando $@"	
	gcc -Wall -c $(FLAGS) game.c
        
game_loop.o: game_loop.c graphic_engine.h
	@echo "######################"
	@echo "Creando $@"
	gcc -Wall -c $(FLAGS) game_loop.c
        
graphic_engine.o: graphic_engine.c screen.h graphic_engine.h command.h
	@echo "######################"
	@echo "Creando $@"
	gcc -Wall -c $(FLAGS) graphic_engine.c

screen.o: screen.c screen.h
	@echo "######################"
	@echo "Creando $@"
	gcc -Wall -c $(FLAGS) screen.c

space.o: space.c set.h types.h space.h
	@echo "######################"
	@echo "Creando $@"
	gcc -Wall -c $(FLAGS) space.c

game_reader.o: game_reader.c game_reader.h game.h
	@echo "######################"
	@echo "Creando $@"
	gcc -Wall -c $(FLAGS) game_reader.c

player.o: player.c player.h types.h
	@echo "######################"
	@echo "Creando $@"
	gcc -Wall -c $(FLAGS) player.c

object.o: object.c object.h types.h
	@echo "######################"
	@echo "Creando $@"
	gcc -Wall -c $(FLAGS) object.c

set.o: set.c set.h types.h
	@echo "#####################"
	@echo "Creando $@"
	gcc -Wall -c $(FLAGS) set.c

die.o: die.c die.h types.h
	@echo "#####################"
	@echo "Creando $@"
	gcc -Wall -c $(FLAGS) die.c

clean: 
	@echo "Limpiando"
	rm -rf *.o ocaEXE setPruebaEXE spacePruebaEXE
