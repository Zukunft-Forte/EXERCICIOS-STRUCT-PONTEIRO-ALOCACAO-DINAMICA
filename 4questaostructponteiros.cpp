#include <iostream>
#include <iomanip>
using namespace std;
//4 Questão struct, ponteiros e alocação dinâmica prof alex
int main() {
    int n;

    cout << "Quantidade de elementos: ";
    cin >> n;

    while (n < 1 || n > 1000) {
        cout << "Quantidade inválida. Digite novamente abaixo: \n";
        cin >> n;
    }

    int* p = new int[n];

    for (int i = 0; i < n; i++) {
        cout << "Digite o " << i + 1 << "º elemento: ";
        cin >> *(p + i);

        while (*(p + i) < -10000 || *(p + i) > 10000) {
            cout << "Valor inválido. Digite novamente abaixo: \n";
            cin >> *(p + i);
        }
    }

    int soma = 0;
    int menor = *p;
    int maior = *p;

    cout << "\nElementos: ";

    for (int i = 0; i < n; i++) {
        cout << *(p + i) << " ";

        soma += *(p + i);

        if (*(p + i) < menor) {
            menor = *(p + i);
        }

        if (*(p + i) > maior) {
            maior = *(p + i);
        }
    }
    //percorrendo o vetor
    double media = static_cast<double>(soma) / n;

    cout << fixed << setprecision(2);
    cout << "\n---------------------------------------------------" << endl;
    cout << "                        RESULTADOS DAS OPERAÇÕES                 " << endl;
    cout << "\nSoma: " << soma << endl;
    cout << "Média: " << media << endl;
    cout << "Menor: " << menor << endl;
    cout << "Maior: " << maior << endl;
    cout << "---------------------------------------------------" << endl;

    delete[] p;
    p = nullptr;

    return 0;
}