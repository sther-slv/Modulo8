#include <iostream>
#include <string>

class Aluno {
    public:
    std::string nome;
    double nota1;
    double nota2;

    Aluno(std::string n, double n1, double n2) {
        nome = n;
        nota1 = n1;
        nota2 = n2;
    }

    double calcularMedia() {
        return (nota1 + nota2) / 2.0;
    }

    void exibirSituacao() {
        double media = calcularMedia();
        std::cout << "Aluno: " << nome << " | Média: " << media << " | Situação: ";
        if (media >= 7.0) {
            std::cout << "Aprovado\n";
        } else {
            std::cout << "Reprovado\n";
        }
    }

    int main() {
        Aluno aluno1("João", 8.5, 7.0);
        Aluno aluno2("Maria", 5.0, 6.0);

        std::cout << "=== Situação dos Alunos ===\n";

        aluno1.exibirSituacao(); // exibe a situação do aluno 1
        aluno2.exibirSituacao(); // exibe a situação do aluno 2
        
        return 0;
    }};
    