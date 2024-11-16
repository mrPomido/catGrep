FLAGS = -Wall -Werror -Wextra -std=c11
COMPILE = gcc $(FLAGS) -c
FILESC = main.c flags.c files.c
FILESO = main.o flags.o files.o
BUILD = gcc $(FLAGS) $(FILESO) -o s21_cat

all: $(FILESO)
	$(BUILD)

main.o:
	$(COMPILE) main.c

flags.o:
	$(COMPILE) flags.c

files.o:
	$(COMPILE) files.c


s21_cat: $(FILESO)
	$(BUILD)

test: s21_cat
	gcc test.c -o testCat
	./testCat

clean:
	rm -rf *.o

rebuild: clean all
	
