#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;
//5 questão struct, ponteiros e alocação dinâmica prof alex
struct Aluno {
    int matricula;
    string nome;
    double nota;
};

int main() {
    int n;

    do {
        cout << "Quantidade de alunos (de 1 a 100): ";
        cin >> n;
    } while (n < 1 || n > 100);

    Aluno* alunos = new Aluno[n];

    double soma = 0;
    int aprovados = 0;

    for (int i = 0; i < n; i++) {
        cout << "\nAluno " << i + 1 << endl;

        bool repetida;

        do {
            cout << "Matrícula: ";
            cin >> alunos[i].matricula;

            repetida = false;

            if (alunos[i].matricula <= 0) {
                repetida = true;
            } else {
                for (int j = 0; j < i; j++) {
                    if (alunos[j].matricula == alunos[i].matricula) {
                        repetida = true;
                        cout << "A foi Matrícula repetida. Digite outra para prosseguirmos.\n";
                        break;
                    }
                }
            }
        } while (repetida);

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        do {
            cout << "Nome: ";
            getline(cin, alunos[i].nome);
        } while (alunos[i].nome.empty());

        do {
            cout << "Nota (0 a 10): ";
            cin >> alunos[i].nota;
        } while (alunos[i].nota < 0 || alunos[i].nota > 10);

        soma += alunos[i].nota;

        if (alunos[i].nota >= 6) {
            aprovados++;
        }
    }

    cout << "\n------ ALUNOS CADASTROS: ALUNOS UNIFBV WYDEN -------\n" << endl;
    cout << fixed << setprecision(2);

    for (int i = 0; i < n; i++) {
        cout << "Matrícula: " << alunos[i].matricula
             << "  | Nome: " << alunos[i].nome
             << "  | Nota: " << alunos[i].nota << endl;
    }

    cout << "Média geral  da turma: " << soma / n << endl;
    cout << "Quantidade de aprovados da turma: " << aprovados << endl;
    cout << "-------------------------------------------------------"; << endl;
    delete[] alunos;
    alunos = nullptr;

    return 0;
}
