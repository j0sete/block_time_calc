#include <stdlib.h>
#include <stdio.h>
#include <string.h>

unsigned int *t_j, *c_j;
unsigned int c_i;

void calculo_bloqueo(unsigned int c_i_n, unsigned int *t_j, unsigned int *c_j, unsigned short int data_size, int iteraciones);

// argv -> 0 - nombre programa; 1 -> c_i; 2 -> num_iteraciones; primer grupo -> periodos; segundo grupo -> c_j
int main( int argc, char* argv[]) {

	unsigned short int iteraciones = atoi(argv[2]);

	if( argc > 1 && ((argc-3)%2) != 0 ) {
		printf("ERROR Need more arguments! argc = %d\n", argc);
		exit(-1);
	}

	unsigned short int data_size = (argc-3)/2;
	c_i = atoi(argv[1]);

	printf("Data size = %d\n", data_size);
	
	t_j = malloc( sizeof(unsigned int) * data_size);
	c_j = malloc( sizeof(unsigned int) * data_size);
	if( !t_j || !c_j) {
		printf("ERROR Can't allocate memory!\n");
		exit(-1);
	}
	memset(t_j, 0, sizeof(unsigned int)*data_size);
	memset(c_j, 0, sizeof(unsigned int)*data_size);

	int i;
	for (i = 3; i < 3+data_size; i++) {
		t_j[i-3] = atoi(argv[i]);
	}
	for (i = data_size+3; i < argc; i++) {
		c_j[i-(data_size+3)] = atoi(argv[i]);
	}

	calculo_bloqueo( c_i, t_j, c_j, data_size, iteraciones);

	return 0;
}

void calculo_bloqueo(unsigned int c_i_n, unsigned int *t_j, unsigned int *c_j, unsigned short int data_size, int iteraciones) {

	unsigned long suma, c_i_n2 = c_i_n;

	for( int j = 0; j < iteraciones; j++) {

		suma = 0;
		
		for(int i = 0; i < data_size; i++) {
			suma = (c_i_n2%t_j[i]) > 0 ? suma + ( ((c_i_n2 / t_j[i]) + 1) * c_j[i] ) : suma + ( (c_i_n2 / t_j[i]) * c_j[i] );
		}
		suma += c_i;
		c_i_n2 = suma;

		printf("w_%d = %ld\n", j+1, suma);
	}

}