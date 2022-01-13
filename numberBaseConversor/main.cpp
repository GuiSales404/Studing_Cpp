#include <iostream>
#include <cmath>

int main() {
  int esc; 
  std::cout << "Escolha a base de origem e destino \n 1- Decimal/Binário \n 2- Binário/Decimal \n";
  std::cin >> esc;
  if (esc == 1){
    // =-=-=-=-=-=-=-=- CONVERSOR DE DECIMAL PARA BINÁRIO -=-=-=-=-=-=-=-=-=-=
    int num = 27; 
    int i = 0, j = 0;
    char bin[50];
    while (num > 0 ){
      if (num%2 == 0) bin[i] = '0'; 
      else bin[i] = '1';
      num = num/2; 
      i++;
    }

    while(j <= i){
      std::cout << bin[i - j];
      j++;
    }
  } else{
    // =-=-=-=-=-=-=-=- CONVERSOR DE BINÁRIO PARA DECIMAL -=-=-=-=-=-=-=-=-=-=
    int num[] = {1, 1, 0, 1, 1}; 
    int i = 0;
    int j = 0;
    int dec = 0; 
    int cont = 0;
    int sizevet = sizeof(num)/sizeof(int); 

    //Método 1 
    while ( i  < sizevet){
      dec = dec + num[sizevet - 1 - i] * pow(2, i);
      i++;
    }
    std::cout << dec << "\n";

    //Método 2 
    while (j < sizevet){
      if (num[j] == 1){
        cont = cont + pow(2, sizevet - j - 1);
      }
      j++;
    }
    std::cout << cont << "\n";
  }
}