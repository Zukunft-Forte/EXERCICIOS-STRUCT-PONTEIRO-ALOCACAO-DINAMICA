#include <iostream>
#include <string>
using namespace std;
//1 Questão prof alex struct, ponteiros e aloções dinâmicas
struct Aluno{
    int matricula;
    string nome;
    double nota;
    
    
};


int main()
{

    Aluno aluno;
    cout << "Matrícula: ";
    cin >> aluno.matricula;
    
    while(aluno.matricula <= 0){
        cout << "Matrícula inválida! Informe-a novamente abaixo.\n" << endl;
        cout << "Matrícula: ";
            cin >> aluno.matricula;
    }
    
    cout << "Nome do(a) aluno(a): ";
    cin >> aluno.nome;
    while (aluno.nome.empty()){
        cout << "Nome inválido/vazio! Escreva-o novamente abaixo.\n" << endl;
        cout << "Nome do(a) aluno(a): ";
        cin >> aluno.nome;
    }
    
    cout << "Nota da 1ª avaliação: ";
    cin >> aluno.nota;
    while(aluno.nota <0 || aluno.nota >10 ){
        cout << "Nota inválida. Informe-a novamente abaixo." << endl;
        cout << "Nota da 1ª avaliação: ";
        cin >> aluno.nota;
    }
    if (aluno.nota >=6){
        cout <<" \nO(a) aluno(a) " << aluno.nome << " está aprovado(a)! "<< endl;
    }else{
        cout <<" \nO(a) aluno(a) " << aluno.nome << " está reprovado(a)! "<< endl;

    }
    cout << "--------------------------------------------------------------" << endl;
    cout << "\n                      STATUS DO ALUNO               \n" << endl;
    cout << "\n" << endl;
    cout << "\nNome do aluno(a): " << aluno.nome << endl;
    cout << "\nMatrícula: " << aluno.matricula << endl;
    cout << "\nNota da 1ª avaliação: " << aluno.nota << endl;
    if (aluno.nota >=6){
        cout <<" \nO(a) aluno(a) " << aluno.nome << " está aprovado(a)! "<< endl;
    }else{
        cout <<" \nO(a) aluno(a) " << aluno.nome << " está reprovado(a)! "<< endl;

    }
    cout << "\n--------------------------------------------------------------" << endl;

    return 0;
}