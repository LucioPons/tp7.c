#include <stdio.h>

#define TAM 5

int main() {
	int codigos[TAM];
	float precios[TAM];
	int i;
	int pos_max = 0;
	int pos_min = 0;
	
	printf("Ingrese %d productos, se solicitará el código y precio:\n", TAM);
	
	for (i = 0; i < TAM; i++) {
		do {
			printf("Ingrese el código de barras (1-999999999): ");
			scanf("%d", &codigos[i]);
			if (codigos[i] < 1 || codigos[i] > 999999999) {
				printf("Error. El código de barras debe estar entre 1 y 999999999\n");
			}
		} while (codigos[i] < 1 || codigos[i] > 999999999);
		
		do {
			printf("Ingrese el precio: ");
			scanf("%f", &precios[i]);
			if (precios[i] < 0) {
				printf("Error. El precio no puede ser negativo.\n");
			}
		} while (precios[i] < 0);
	}
	
	printf("\nCódigo\t\tPrecio\n");
	for (i = 0; i < TAM; i++) {
		printf("%8d\t%9.2f\n", codigos[i], precios[i]);
	}
	
	for (i = 1; i < TAM; i++) {
		if (precios[i] > precios[pos_max]) {
			pos_max = i;
		}
		if (precios[i] < precios[pos_min]) {
			pos_min = i;
		}
	}
	
	printf("\nMás caro: [%d] %.2f\n", codigos[pos_max], precios[pos_max]);
	printf("Más barato: [%d] %.2f\n", codigos[pos_min], precios[pos_min]);
	
	return 0;
}
