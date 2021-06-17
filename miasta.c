#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main(int argc, char *argv[]) {
	srand((unsigned)time(NULL));
	short gracze[(argc-1)];
	char litery[] = "ABCDEFGHIJKLMNOPRSTUWZ";
	short los;
	while(short ile_liter = sizeof(litery); ile_liter > 0; ile_liter--) {
		los = rand()%ile_liter;
		printf("Wylosowana litera to %c\nNacisnij enter.", litery[los]);
		getchar();
		for(short i=1; i<argc; i++) {
			printf("Ile %s ma teraz punktow? ", argv[i]);
			scanf("%hd", &los);
			gracze[i] += los;
		}
	}
	for(short i=1; i<argc; i++) {
		printf("%s ma %hd punktow.\n", argv[i], gracze[i-1]);
	}
	return 0;
}
