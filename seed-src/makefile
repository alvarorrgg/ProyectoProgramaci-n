#makefile de juego OCA
target = ocaEXE  set_test die_test inventory_test player_test space_test object_test link_test command_test dialogue_test tests docs
FLAGS=-ansi -pedantic -g -Wall -DDEBUG -I src -I include -o obj/$@
OBJ = command.o game.o game_loop.o graphic_engine.o screen.o space.o game_management.o object.o player.o set.o die.o inventory.o link.o dialogue.o
TEST = set_test.o set.o die_test.o die.o inventory_test.o inventory.o player_test.o player.o space_test.o space.o object_test.o object.o link_test.o link.o command_test.o command.o dialogue_test.o dialogue.o
OCAEXEDIR = $(addprefix obj/,command.o game.o game_loop.o graphic_engine.o screen.o space.o game_management.o object.o player.o set.o die.o inventory.o link.o dialogue.o)
SET_TESTDIR = $(addprefix obj/,set_test.o set.o)
DIE_TESTDIR = $(addprefix obj/,die_test.o die.o)
INVENTORY_TESTDIR = $(addprefix obj/, inventory_test.o inventory.o set.o)
PLAYER_TESTDIR = $(addprefix obj/, player_test.o player.o inventory.o set.o)
SPACE_TESTDIR = $(addprefix obj/, space_test.o space.o set.o link.o)
OBJECT_TESTDIR = $(addprefix obj/, object_test.o object.o)
LINK_TESTDIR = $(addprefix obj/, link_test.o link.o)
COMMAND_TESTDIR = $(addprefix obj/, command_test.o command.o)
DIALOGUE_TESTDIR = $(addprefix obj/, dialogue_test.o dialogue.o player.o command.o inventory.o set.o)
CC = gcc

vpath %.c src
vpath %.h include
vpath %.o obj
 
all: $(target)

ocaEXE: $(OBJ)
	@echo "#####################"
	@echo "Creando $@"
	$(CC) -o  $@ $(OCAEXEDIR)

command.o: command.c command.h types.h
	@echo "######################"
	@echo "Creando $@"
	$(CC) -c  $(FLAGS) $<

game.o: game.c game.h player.h types.h object.h command.h space.h die.h game_management.h dialogue.h
	@echo "######################"
	@echo "Creando $@"	
	$(CC)  -c $(FLAGS) $<
        
game_loop.o: game_loop.c graphic_engine.h game.h player.h types.h object.h command.h space.h die.h
	@echo "######################"
	@echo "Creando $@"
	$(CC) -c $(FLAGS) $<
        
graphic_engine.o: graphic_engine.c screen.h graphic_engine.h command.h game.h player.h types.h object.h space.h die.h dialogue.h
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

game_management.o: game_management.c game_management.h game.h player.h object.h command.h space.h die.h types.h
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

link.o: link.c link.h types.h
	@echo "#####################"
	@echo "Creando $@"
	$(CC) -c $(FLAGS) $<

dialogue.o: dialogue.c dialogue.h types.h command.h player.h
	@echo "#####################"
	@echo "Creando $@"
	$(CC) -c $(FLAGS) $<

die_test: die_test.o die.o
	@echo "#####################"
	@echo "Creando $@"
	$(CC) -o  $@ $(DIE_TESTDIR)

die_test.o: die_test.c die_test.h die.h
	@echo "#####################"
	@echo "Creando $@"
	$(CC) -c $(FLAGS) $<

set_test: set_test.o set.o
	@echo "#####################"
	@echo "Creando $@"
	$(CC) -o  $@ $(SET_TESTDIR)

set_test.o: set_test.c set_test.h set.h
	@echo "#####################"
	@echo "Creando $@"
	$(CC) -c $(FLAGS) $<

space_test: space_test.o space.o set.o link.o
	@echo "#####################"
	@echo "Creando $@"
	$(CC) -o  $@ $(SPACE_TESTDIR)

space_test.o: space_test.c space_test.h space.h set.h link.h
	@echo "#####################"
	@echo "Creando $@"
	$(CC) -c $(FLAGS) $<
	
inventory_test: inventory_test.o inventory.o set.o
	@echo "#####################"
	@echo "Creando $@"
	$(CC) -o  $@ $(INVENTORY_TESTDIR)	

inventory_test.o: inventory_test.c inventory_test.h inventory.h test.h 
	@echo "#####################"
	@echo "Creando $@"
	$(CC) -c $(FLAGS) $<

player_test: player_test.o player.o inventory.o set.o
	@echo "#####################"
	@echo "Creando $@"
	$(CC) -o  $@ $(PLAYER_TESTDIR)	

player_test.o: player_test.c player_test.h player.h test.h inventory.h set.h
	@echo "#####################"
	@echo "Creando $@"
	$(CC) -c $(FLAGS) $<

object_test: object_test.o object.o
	@echo "#####################"
	@echo "Creando $@"
	$(CC) -o  $@ $(OBJECT_TESTDIR)	

object_test.o: object_test.c object_test.h object.h test.h
	@echo "#####################"
	@echo "Creando $@"
	$(CC) -c $(FLAGS) $<

link_test: link_test.o link.o
	@echo "#####################"
	@echo "Creando $@"
	$(CC) -o  $@ $(LINK_TESTDIR)	

link_test.o: link_test.c link_test.h link.h test.h 
	@echo "#####################"
	@echo "Creando $@"
	$(CC) -c $(FLAGS) $<

command_test: command_test.o command.o
	@echo "#####################"
	@echo "Creando $@"
	$(CC) -o  $@ $(COMMAND_TESTDIR)	

command_test.o: command_test.c command_test.h command.h test.h 
	@echo "#####################"
	@echo "Creando $@"
	$(CC) -c $(FLAGS) $<

dialogue_test: dialogue_test.o dialogue.o inventory.o player.o command.o set.o
	@echo "#####################"
	@echo "Creando $@"
	$(CC) -o  $@ $(DIALOGUE_TESTDIR)	

dialogue_test.o: dialogue_test.c dialogue_test.h dialogue.h test.h player.h command.h inventory.h set.h
	@echo "#####################"
	@echo "Creando $@"
	$(CC) -c $(FLAGS) $<

docs: $(OBJ)
	@doxygen ./Doxyfile
	
tests: set_test space_test die_test inventory_test player_test link_test command_test object_test dialogue_test

.PHONY: clean cleanDocs cleanGame cleanTests cleanObjs run runv runl runj 

clean: 
	@echo "Limpiando Todo documentacion incluida"
	rm -rf obj/* ocaEXE set_test space_test die_test inventory_test player_test link_test command_test object_test 
	rm -rf doc/*

cleanDocs: 
	@echo "Limpiando Documentación"
	rm -r doc/*

cleanGame: 
	@echo "Limpiando unicamente el ejecutable de la oca"
	rm -rf  ocaEXE 

cleanTests: 
	@echo "Limpiando los tests"
	rm -rf  set_test space_test die_test inventory_test player_test link_test command_test object_test 

cleanObjs: 
	@echo "Limpiando los objetos"
	rm -rf obj/* 

run: ocaEXE
	./ocaEXE data.dat

runv: ocaEXE
	valgrind --leak-check=full ./ocaEXE data.dat

runl: ocaEXE
	./ocaEXE data.dat -l log.txt

runj: ocaEXE
	./ocaEXE data.dat < partida1.oca



