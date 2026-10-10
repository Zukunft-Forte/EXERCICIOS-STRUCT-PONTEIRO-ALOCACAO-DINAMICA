#include <iostream>
#include <string>
#include <limits>
using namespace std;
//8 questão struct, ponteiros e alocação dinâmica 
struct Contato {
    string nome;
    string telefone;
};

int main() {
    int n;

    do {
        cout << "Quantidade de contatos (de 1 a 100): ";
        cin >> n;
    } while (n < 1 || n > 100);

    Contato* contatos = new Contato[n];

    for (int i = 0; i < n; i++) {
        cout << "\nContato " << i + 1 << endl;
        cout << "(para confirmar novo contato APÓS o 1º contato, aperte ENTER)." << endl;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        do {
            cout << "Nome: ";
            getline(cin, contatos[i].nome);
        } while (contatos[i].nome.empty());

        do {
            cout << "Nº de Telefone: ";
            getline(cin, contatos[i].telefone);
        } while (contatos[i].telefone.empty());
    }

    Contato* novo = new Contato[n + 1];

    for (int i = 0; i < n; i++) {
        novo[i] = contatos[i];
    }

    cout << "\nNovo contato\n";
    cout << "(para confirmar novo contato, aperte ENTER)." << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    do {
        cout << "Nome: ";
        getline(cin, novo[n].nome);
    } while (novo[n].nome.empty());

    do {
        cout << "Nº de Telefone: ";
        getline(cin, novo[n].telefone);
    } while (novo[n].telefone.empty());

    delete[] contatos;

    contatos = novo;
    n = n + 1;

    cout << "\n------- LISTA DE CONTATOS: SECRETARIA DE ATENDIMENTO UNIFBV WYDEN -------\n";

    for (int i = 0; i < n; i++) {
        cout << "Nome: " << contatos[i].nome << endl;
        cout << "Telefone: " << contatos[i].telefone << endl;
        cout << "--------------------------------------------------------" <<  endl;
    
    }

    delete[] contatos;
    contatos = nullptr;

    return 0;
}
