#include <iostream>
using namespace std;
//9 questão
struct Celula {
    int valor;
};

int main() {
    int linhas, colunas;

    do {
        cout << "Quantidade de linhas (de 1 a 20): ";
        cin >> linhas;
    } while (linhas < 1 || linhas > 20);

    do {
        cout << "Quantidade de colunas (de 1 a 20): ";
        cin >> colunas;
    } while (colunas < 1 || colunas > 20);

    Celula** matriz = new Celula*[linhas];

    for (int i = 0; i < linhas; i++) {
        matriz[i] = new Celula[colunas];
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            do {
                cout << "Valor [" << i << "][" << j << "]: ";
                cin >> matriz[i][j].valor;
            } while (matriz[i][j].valor < -1000 ||
                     matriz[i][j].valor > 1000);
        }
    }

    cout << "\n------- MATRIZ DE CRIAÇÃO: MATEMÁTICA COMPUTACIONAL NA UNIFBV WYDEN -------\n";

    for (int i = 0; i < linhas; i++) {
        int soma = 0;

        for (int j = 0; j < colunas; j++) {
            cout << matriz[i][j].valor << " ";
            soma += matriz[i][j].valor;
        }

        cout << "\nSoma da " << i + 1 << "ª linha: "
             << soma << endl;
    }

    for (int i = 0; i < linhas; i++) {
        delete[] matriz[i];
    }
    cout << "----------------------------------------------------------" << endl;
    delete[] matriz;
    matriz = nullptr;

    return 0;
}
