#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;
//6 questão struct, ponteiros
struct Produto {
    int codigo;
    string nome;
    double preco;
};

Produto* buscar(Produto* produtos, int n, int codigo) {
    for (int i = 0; i < n; i++) {
        if (produtos[i].codigo == codigo) {
            return &produtos[i];
        }
    }

    return nullptr;
}

int main() {
    int n;

    do {
        cout << "Quantidade de produtos (de 1 a 100): ";
        cin >> n;
    } while (n < 1 || n > 100);

    Produto* produtos = new Produto[n];

    for (int i = 0; i < n; i++) {
        cout << "\nProduto " << i + 1 << endl;

        bool repetido;

        do {
            cout << "Código: ";
            cin >> produtos[i].codigo;

            repetido = produtos[i].codigo <= 0;

            for (int j = 0; j < i && !repetido; j++) {
                if (produtos[j].codigo == produtos[i].codigo) {
                    repetido = true;
                    cout << "Código solicitado repetido. Digite outro para prosseguirmos, por obséquio.\n";
                }
            }
        } while (repetido);

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        do {
            cout << "Nome: ";
            getline(cin, produtos[i].nome);
        } while (produtos[i].nome.empty());

        do {
            cout << "Preço: ";
            cin >> produtos[i].preco;
        } while (produtos[i].preco < 0);
    }

    int codigo;

    do {
        cout << "\nCódigo para buscar: ";
        cin >> codigo;
    } while (codigo <= 0);

    Produto* encontrado = buscar(produtos, n, codigo);

    cout << fixed << setprecision(2);

    if (encontrado != nullptr) {
        double anterior = encontrado->preco;
        double novoPreco;

        do {
            cout << "Novo preço: ";
            cin >> novoPreco;
        } while (novoPreco < 0);

        encontrado->preco = novoPreco;

        cout << "----------------- AJUSTES: --------------------------" << endl;
        cout << "Nome do produto: " << encontrado->nome << endl;
        cout << "Preço anterior: " << anterior << endl;
        cout << "Preço atualizado: " << encontrado->preco << endl;
        cout << "----------------------------------------------------" << endl;
    } else {
        cout << "Produto não encontrado!" << endl;
    }

    delete[] produtos;
    produtos = nullptr;

    return 0;
}
