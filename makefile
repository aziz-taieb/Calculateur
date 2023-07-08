all: f_recherche algo_dynamique jesuiscourageux

f_recherche: f_recherche.c
	gcc -Wall f_recherche.c -o f_recherche

algo_dynamique: algo_dynamique.c
	gcc -Wall algo_dynamique.c -o algo_dynamique

jesuiscourageux: jesuiscourageux.c
	gcc -Wall jesuiscourageux.c -o jesuiscourageux

clean:
	rm -f f_recherche algo_dynamique jesuiscourageux
