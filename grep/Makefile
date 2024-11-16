FLAGS = -Wall -Werror -Wextra -std=c11 -D _POSIX_C_SOURCE=200809L -D _GNU_SOURCE_ -D _GNU_SOURCE
FILE = test1
COMPILE = gcc $(FLAGS) -c
FILES = main.o flags.o files.o
BUILD = gcc $(FLAGS) $(FILES) -o s21_grep

all: $(FILES)
	$(BUILD)

s21_grep: $(FILES)
	$(BUILD)

main.o:
	$(COMPILE) main.c

flags.o:
	$(COMPILE) flags.c

files.o:
	$(COMPILE) files.c

tests: all
	-diff <(./s21_grep He $(FILE)) <(grep He $(FILE))
	-diff <(./s21_grep -i He $(FILE)) <(grep -i He $(FILE))
	-diff <(./s21_grep -v He $(FILE)) <(grep -v He $(FILE))
	-diff <(./s21_grep -c He $(FILE)) <(grep -c He $(FILE))
	-diff <(./s21_grep -l He $(FILE)) <(grep -l He $(FILE))
	-diff <(./s21_grep -n He $(FILE)) <(grep -n He $(FILE))
	-diff <(./s21_grep -h He $(FILE)) <(grep -h He $(FILE))
	-diff <(./s21_grep -s He non-existent file) <(grep -s He non-existent file)
	-diff <(./s21_grep -f patterns_file $(FILE)) <(grep -f patterns_file $(FILE))
	-diff <(./s21_grep -o He $(FILE)) <(grep -o He $(FILE))
	-diff <(./s21_grep -in He $(FILE)) <(grep -in He $(FILE))
	-diff <(./s21_grep -oinc He $(FILE)) <(grep -oinc He $(FILE))
	-diff <(./s21_grep -nf patterns_file $(FILE)) <(grep -nf patterns_file $(FILE))

clean:
	rm -rf *.o  s21_grep
