#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;
//7 questão struct
struct Turma {
    string nome;
    int quantidade;
    double* notas;
};

double calcularMedia(const Turma* t) {
    double soma = 0;

    for (int i = 0; i < t->quantidade; i++) {
        soma += t->notas[i];
    }

    return soma / t->quantidade;
}

int main() {
    Turma* turma = new Turma;

    do {
        cout << "Nome da turma: ";
        getline(cin, turma->nome);
    } while (turma->nome.empty());

    do {
        cout << "Quantidade de alunos (de 1 a 100): ";
        cin >> turma->quantidade;
    } while (turma->quantidade < 1 || turma->quantidade > 100);

    turma->notas = new double[turma->quantidade];

    for (int i = 0; i < turma->quantidade; i++) {
        do {
            cout << "Nota " << i + 1 << " (0 a 10): ";
            cin >> turma->notas[i];
        } while (turma->notas[i] < 0 || turma->notas[i] > 10);
    }

    cout << fixed << setprecision(2);

    cout << "\n---------------------RESULTADO GERAL: TURMAS UNIFBV WYDEN --------------------" << endl;
    cout << "\nTurma: " << turma->nome << endl;
    cout << "Notas: ";

    for (int i = 0; i < turma->quantidade; i++) {
        cout << turma->notas[i] << " | ";
    }

    cout << "\nMédia: " << calcularMedia(turma) << endl;
    cout << "------------------------------------------------------------------------------" << endl;

    delete[] turma->notas;
    turma->notas = nullptr;

    delete turma;
    turma = nullptr;

    return 0;
}
