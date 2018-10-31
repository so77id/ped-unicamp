MAIN = lab13

SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))
CC = gcc
GFLAGS = -ansi -Wall -pedantic-errors -Werror -g -lm

$(MAIN): $(OBJ)
	$(CC) $(GFLAGS) $(OBJ) -o $@

%.o: %.c
	$(CC) $(GFLAGS) -c $< -o $@

clean:
	rm -f $(MAIN) *.o

.PHONY: testar_tudo
testar_tudo: $(MAIN)
	@set -e ; \
	if [ ! -d testes_abertos ] ; then \
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

.PHONY: baixar_fechados
FECHADOS = 16 17 18 19 20 21 22 23 24 25
ULTIMO_FECHADO = 25
baixar_fechados:
	@mkdir -p testes_fechados ; \
	if [ -f testes_fechados/arq$(ULTIMO_FECHADO).res ] ; then \
		echo "Testes fechados já foram baixados." ; \
		exit 0 ; \
	fi ; \
	lab=$$(echo "$(MAIN)" | sed -re 's/lab//') ; \
	curl -sk "https://susy.ic.unicamp.br:9999/mc202efgh/SANDBOX-$$lab/dados/arq$(ULTIMO_FECHADO).in" | grep -e '<HTML>' ; \
	if [ $$?  = "0" ] ; then \
		echo "*********************************************************" ; \
		echo "Certifique-se de que os testes fechados estejam liberados" ; \
		echo "*********************************************************" ; \
		exit 1 ; \
	fi ; \
	for i in $(FECHADOS) ; do \
		for ext in .in .res ; do \
			curl -k "https://susy.ic.unicamp.br:9999/mc202efgh/SANDBOX-$$lab/dados/arq$$i$$ext" > testes_fechados/arq$$i$$ext ; \
		done ; \
	done
