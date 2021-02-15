#makefile de juego OCA

ocaEXE: command.o game.o game_loop.o graphic_engine.o screen.o space.o game_reader.o
	gcc -o ocaEXE command.o game.o game_loop.o graphic_engine.o screen.o space.o game_reader.o

command.o: command.c command.h 
	gcc -Wall -c command.c

game.o: game.c game.h
	gcc -Wall -c game.c
	
game_loop.o: game_loop.c graphic_engine.h
	gcc -Wall -c game_loop.c
	
graphic_engine.o: graphic_engine.c screen.h graphic_engine.h command.h 
	gcc -Wall -c graphic_engine.c

screen.o: screen.c screen.h
	gcc -Wall -c screen.c

space.o: space.c types.h space.h
	gcc -Wall -c space.c

game_reader.o: game_reader.c game_reader.h
	gcc -Wall -c game_reader.c
	
clean: 
	@echo "Limpiando"
	rm -rf *.o ocaEXE
