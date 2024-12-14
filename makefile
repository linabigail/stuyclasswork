.PHONY: compile run
run: 12.13classwork.o
	@./work
compile: 12.13classwork.o
	@gcc -o work 12.13classwork.o
12.13classwork.o: 12.13classwork.c
	@gcc -c 12.13classwork.c