#makefile de juego OCA
target = ocaEXE space_test set_test die_test inventory_test player_test
FLAGS=-ansi -pedantic -g -Wall -DDEBUG -I src -I include
OBJ = command.o game.o game_loop.o graphic_engine.o screen.o space.o game_reader.o object.o player.o set.o die.o inventory.o
CC = gcc

vpath %.c src:include
vpath %.h include
vpath %.o obj
 

all: $(target)

ocaEXE: $(OBJ)
	@echo "#####################"
	@echo "Creando $@"
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
	
inventory.o: inventory.c inventory.h set.h types.h
	@echo "#####################"
	@echo "Creando $@"
	$(CC) -c $(FLAGS) $<

die_test: die_test.o die.o
	@echo "#####################"
	@echo "Creando $@"
	$(CC) -o  $@ $^

die_test.o: die_test.c die_test.h die.h
	@echo "#####################"
	@echo "Creando $@"
	$(CC) -c $(FLAGS) $<

set_test: set_test.o set.o
	@echo "#####################"
	@echo "Creando $@"
	$(CC) -o  $@ $^

set_test.o: set_test.c set_test.h set.h
	@echo "#####################"
	@echo "Creando $@"
	$(CC) -c $(FLAGS) $<

space_test: space_test.o space.o set.o
	@echo "#####################"
	@echo "Creando $@"
	$(CC) -o  $@ $^

space_test.o: space_test.c space_test.h space.h set.h
	@echo "#####################"
	@echo "Creando $@"
	$(CC) -c $(FLAGS) $<
	
inventory_test: inventory_test.o inventory.o set.o
	@echo "#####################"
	@echo "Creando $@"
	$(CC) -o  $@ $^	

inventory_test.o: inventory_test.c inventory_test.h inventory.h test.h 
	@echo "#####################"
	@echo "Creando $@"
	$(CC) -c $(FLAGS) $<

player_test: player_test.o player.o inventory.o set.o
	@echo "#####################"
	@echo "Creando $@"
	$(CC) -o  $@ $^	

player_test.o: player_test.c player_test.h player.h test.h inventory.h set.h
	@echo "#####################"
	@echo "Creando $@"
	$(CC) -c $(FLAGS) $<

.PHONY: clean
clean: 
	@echo "Limpiando"
	rm -rf *.o ocaEXE set_test space_test die_test inventory_test player_test 
	
