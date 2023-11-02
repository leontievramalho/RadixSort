#include <iostream>
using namespace std;

int max(int vetor[], int tamanho){
	int maior = vetor[0];
	for(int i = 0; i < tamanho; i++){
		if(vetor[i] > maior){
			maior = vetor[i];
		}
	}
	return maior;
}

void countingSort(int vetor[], int tamanho, int div){
	// cria vetor contador com 10 posicoes zerado e o vetor de saida temporario
	int count[10] = {0};
	int saida[tamanho] = {0};
	
	// incrementa na posicao correspondente a unidade do numero (ou dezena, centena, etc)
	for(int i = 0; i<tamanho; i++){
		count[(vetor[i]/div) % 10] ++;
	}
	
	// atualiza o contador de cada posicao com a quantidade acumulada desde o 0 ate o momento
	// isso é feito para determinar os índices do vetor saida
	for(int i = 1; i<10; i++){
		count[i] += count[i-1];
	}
	
	// os numeros vao sendo inseridos no vetor de saida na posição correspondente ao valor acumulado do contador
	for(int i = tamanho - 1; i >= 0; i--){
		saida[count[(vetor[i]/div) % 10] - 1] = vetor[i];
		count[(vetor[i]/div) % 10] --;
	}
	
	// atualiza o vetor com os valores do temporario
	for(int i = 0; i < tamanho; i++){
		vetor[i] = saida[i];
	}
}

void radixSort(int vetor[], int tamanho){
	int maior = max(vetor, tamanho);
	int div = 1;
	while(maior/div != 0){
		countingSort(vetor, tamanho, div);
		div *= 10;
	}
}

int main() {
	int vetor[10] = {23, 168, 4, 243, 178, 124, 44, 233, 115, 100};
	
	cout << "Vetor antes do Radix Sort: ";
	for(int i = 0; i < 10; i++){
		cout << vetor[i] << " ";
	}
	cout << endl;	
	
	radixSort(vetor, 10);
	
	cout << "Vetor depois do Radix Sort: ";
	for(int i = 0; i < 10; i++){
		cout << vetor[i] << " ";
	}
	cout << endl;
	return 0;
}
