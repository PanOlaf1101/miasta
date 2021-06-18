#include <stdlib.h>
#include <stdio.h>
#include <time.h>
typedef unsigned short us;
char litery[] = "ABCDEFGHIJKLMNOPRSTUWZ";
const size_t size = sizeof(litery)-1;
void mix() {
	srand(time(NULL) ^ rand());
	char temp;
	int random;
	for(us i=0; i<size; i++) {
		random = rand()%size;
		temp = litery[random];
		litery[random] = litery[i];
		litery[i] = temp;
	}
}
int main(int argc, char** argv) {
	mix();
	us ile_tur = atoi(*(argv+1));
	argc -= 2;
	argv += 2;
	us* gracze = (us*) calloc(sizeof(us), argc);
	us los;
	ile_tur = (ile_tur > size)? size : ile_tur;
	for(us i=0; i<ile_tur; i++) {
		printf("Wylosowana litera to %c\n", litery[i]);
		for(us j=0; j<argc; j++) {
			printf("Ile %s ma w tej rundzie punktow? ", *(argv+j));
			scanf("%hu", &los);
			*(gracze+j) += los;
		}
	}
	for(us i=0; i<argc; i++) {
		printf("\n%s ma %hu punktow.", *(argv+i), *(gracze+i));
	}
	printf("\n");
	free(gracze);
	return 0;
}