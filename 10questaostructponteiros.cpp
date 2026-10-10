#include <iostream>
using namespace std;
//10 questão struct, ponteiros e alocação dinâmica, prof alex
struct No {
    int valor;
    No* proximo;
};

void inserir(No*& inicio, int valor) {
    No* novo = new No;

    novo->valor = valor;
    novo->proximo = inicio;

    inicio = novo;
}

void listar(No* inicio) {
    if (inicio == nullptr) {
        cout << "Lista atualmente vazia" << endl;
        return;
    }

    No* atual = inicio;

    while (atual != nullptr) {
        cout << atual->valor << " ";
        atual = atual->proximo;
    }

    cout << endl;
}

bool remover(No*& inicio, int valor) {
    No* atual = inicio;
    No* anterior = nullptr;

    while (atual != nullptr) {
        if (atual->valor == valor) {
            if (anterior == nullptr) {
                inicio = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }

            delete atual;
            return true;
        }

        anterior = atual;
        atual = atual->proximo;
    }

    return false;
}

void liberarLista(No*& inicio) {
    No* atual = inicio;

    while (atual != nullptr) {
        No* proximo = atual->proximo;

        delete atual;

        atual = proximo;
    }

    inicio = nullptr;
}

int main() {
    No* inicio = nullptr;
    int opcao, valor;

    do {
        cout << "\n----------- MENU DE INSERÇÃO DE VALORES: ESTRUTURAS DE DADOS UNIFBV WYDEN ----------\n";
        cout << "1 - Inserir\n";
        cout << "2 - Listar\n";
        cout << "3 - Remover\n";
        cout << "0 - Sair\n";
        cout << "Opção desejada: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                do {
                    cout << "Valor (-1000 a 1000): ";
                    cin >> valor;
                } while (valor < -1000 || valor > 1000);

                inserir(inicio, valor);
                cout << "Inserido" << endl;
                break;

            case 2:
                listar(inicio);
                break;

            case 3:
                do {
                    cout << "Valor para remover (de -1000 a 1000): ";
                    cin >> valor;
                } while (valor < -1000 || valor > 1000);

                if (remover(inicio, valor)) {
                    cout << "Removido com sucesso!" << endl;
                } else {
                    cout << "Valor não encontrado" << endl;
                }
                break;

            case 0:
                break;

            default:
                cout << "Opcao invalida" << endl;
        }

    } while (opcao != 0);
    cout << "----------------------------------------" << endl;
    liberarLista(inicio);

    return 0;
}
