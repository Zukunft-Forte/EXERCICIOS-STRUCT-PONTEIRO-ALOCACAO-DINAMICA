#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
//2 Questão Prof Alex struct, ponteiro e alocação dinâmica
struct Produto {
    int codigo;
    string nome;
    double preco;
    
    //struct básico do produto solicitado do usuário
};

void reajustar(Produto* p, double percentual) {
    p->preco = p->preco * (1 + percentual / 100);
    //função para o reajuste do preço, que deverá ser mostrado depois.
}

int main() {
    Produto produto;
    Produto* p = &produto;
    double percentual;

    cout << "-----------------------------------------------------------------------" << endl;
    cout << "                  SCANNER DE PRODUTOS: CAIXA DE MERCADO" << endl;
    //simulei um caixa de mercado, já que a questão solicitava structs e afins com produtos.
    
    
    cout << "Código do produto: ";
    cin >> produto.codigo;

    while (produto.codigo <= 0) {
        cout << "Código inválido. Digite novamente abaixo: ";
        cin >> produto.codigo;
    }

    cout << "Nome do produto: ";
    getline(cin >> ws, produto.nome);

    while (produto.nome.empty()) {
        cout << "Nome inválido. Digite novamente: ";
        getline(cin, produto.nome);
    }

    cout << "Preço do produto: ";
    cin >> produto.preco;

    while (produto.preco < 0) {
        cout << "Preço inválido. Digite novamente: ";
        cin >> produto.preco;
    }

    cout << "Percentual de reajuste: ";
    cin >> percentual;

    while (percentual < 0 || percentual > 100) {
        cout << "Percentual inválido. Digite novamente: ";
        cin >> percentual;
    }

    double precoAnterior = p->preco;

    reajustar(p, percentual);

    cout << fixed << setprecision(2);
    cout << "\nProduto: " << p->nome << endl;
    cout << "Preço anterior: " << precoAnterior << endl;
    cout << "Preço atualizado: " << p->preco << endl;
    cout << "-----------------------------------------------------------------------" << endl;


    return 0;
}