MAIN = lab08

SRC = $(wildcard *.c)
DEPS = $(wildcard *.h)
OBJ = $(patsubst %.c, %.o, $(SRC))
CC = gcc
GFLAGS = -ansi -Wall -pedantic-errors -Werror -g -lm

$(MAIN): $(OBJ)
	$(CC) $(GFLAGS) $(OBJ) -o $@

%.o: %.c $(DEPS)
	$(CC) $(GFLAGS) -c $< -o $@

clean:
	rm -f *.o $(MAIN)

.PHONY: testar_tudo
testar_tudo: $(MAIN)
	@set -e ; \
	if [ ! -d ./testes_abertos ] ; then \
		echo "*****************************************************************" ; \
		echo "Copie o diretório 'testes_abertos' para a mesma pasta do Makefile" ; \
		echo "*****************************************************************" ; \
		exit 1 ; \
	fi ; \
	for entrada in testes_*/*.in ; do \
		saida=$$(echo "$$entrada" | sed -re 's/\.in$$/.out/' ) ; \
		resposta=$$(echo "$$entrada" | sed -re 's/\.in$$/.res/' ) ; \
		./$(MAIN) < "$$entrada" > "$$saida" ; \
		echo ; \
		echo "Testando $$entrada: " ; \
		if diff "$$resposta" "$$saida" ;  then \
			echo "OK" ; \
		else \
			echo "***********************************"; \
			echo "Falhou para $$entrada" ; \
			echo "***********************************"; \
			exit 1; \
		fi ; \
	done
