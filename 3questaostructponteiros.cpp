#include <iostream>
#include <string>
using namespace std;

struct Livro {
    string titulo;
    string autor;
    int ano;
};

int main() {
    Livro* livro = new Livro;

    cout << "Título: ";
    getline(cin, livro->titulo);

    while (livro->titulo.empty()) {
        cout << "Título inválido. Digite novamente abaixo: ";
        getline(cin, livro->titulo);
    }

    cout << "Autor: ";
    getline(cin, livro->autor);

    while (livro->autor.empty()) {
        cout << "Autor inválido. Digite novamente abaixo: ";
        getline(cin, livro->autor);
    }

    cout << "Ano de lançamento do livro: ";
    cin >> livro->ano;

    while (livro->ano < 1 || livro->ano > 2100) {
        cout << "Ano inválido. Digite novamente abaixo: ";
        cin >> livro->ano;
    }

    cout << "\n--------- CADASTRO DE LIVRO: LIVRARIA LEITURA -----------\n" << endl;
    cout << "Título: " << livro->titulo << endl;
    cout << "Autor: " << livro->autor << endl;
    cout << "Ano: " << livro->ano << endl;
    cout << "-------------------------------------------------------------" << endl;
    delete livro;
    livro = nullptr;
    /*OBS: COMO SOLICITADO NA QUESTÃO E ESPECIFICADO NO MEU README, SEGUE EXPLICAÇÃO SOLICITADA NESSA 3ª QUESTÃO
    DO POR QUE O USO DE DELETE[] SERIA INADEQUADO NESSE CASO: 
    excluí o objeto e colocamos o livro como nullptr.
    Não se foi utilizado o delete[] pois apenas utilizamos o new para alocar apenas UM objeto.
    Por isso, utilizei o delete sem colchetes.*/
    return 0;
}
