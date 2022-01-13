#include <iostream>
#include <new>
using std::nothrow;
using namespace std; 

/*Escreva um programa C++ que leia números inteiros digitados pelo usuário, armazenando-os em vetor alocado dinamicamente, e que ao final imprima esses mesmos números em ordem crescente. Um zero digitado pelo usuário indicará o fim da entrada (o zero não deve estar entre os números impressos ao final).

Não há limite conhecido para a quantidade dos números que serão digitados pelo usuário. Sempre que o vetor no qual os números estiverem sendo armazenados ficar cheio, o programa deverá (a) alocar outro vetor com o dobro do tamanho, (b) copiar os números para o novo vetor e (c) desalocar o vetor antigo. O primeiro vetor utilizado deve ter tamanho 1.*/ 

int* duplicarVetor(int *tamvet, int *v){ //*v aponta para o vetor de *vaux, libera antigo vetor de *vaux para novo vetor aux
 	int *vaux = new(nothrow) int[2*(*tamvet)];
	for(int j = 0; j<*tamvet; j++){
		vaux[j] = v[j]; 
	}
	delete v;
	*tamvet *= 2;
	return vaux;
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
 
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){ 
	int *v = NULL; 
	int ent = 1, tam = 1;
	int i = 0; 
	v = new(nothrow) int[tam];   
	while(1) {
		cout << "Selecione um valor\n";
		cin >> v[i];// 8 [0, 7]
		if(v[i] == 0){ 
      cout << "\n"; 
      insertionSort(v, tam);
      printArray(v, tam);
			break;
      }
		i++; 
		if(i == tam){
			v = duplicarVetor(&tam, v);
		}
	}

	// o vetor tem tamanho tam e i elementos.
}  

