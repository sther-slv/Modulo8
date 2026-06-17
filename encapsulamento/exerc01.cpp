#include <iostream>
#include <cstring>
#include <string>
#include <locale.h>
#include <windows.h>
#include <stdexcept>

using namespace std;

class Aluno {
private:
    std::string nome;
    double nota;

public:
    Aluno(std::string nomeInicial) {
        nome = nomeInicial;
        nota = 0.0; // Nota inicial padrão
    }

   
    void set_nota(double novaNota) {
        if (novaNota >= 0.0 && novaNota <= 10.0) {
            nota = novaNota;
            std::cout << "Nota " << novaNota << " atribuida com sucesso ao aluno(a) " << nome << ".\n";
        } else {
            std::cout << "Erro: A nota " << novaNota << " e invalida! Digite um valor entre 0 e 10.\n";
        }
    }

    
    std::string get_nome() const {
        return nome;
    }

    double get_nota() const {
        return nota;
    }
};

int main() {
    Aluno aluno1("Mariana");

    std::cout << "Aluno: " << aluno1.get_nome() << " | Nota Inicial: " << aluno1.get_nota() << "\n\n";

    
    aluno1.set_nota(8.5);
    std::cout << "Nota atual: " << aluno1.get_nota() << "\n\n";

    
    aluno1.set_nota(11.0); 
    std::cout << "Nota apos tentativa invalida: " << aluno1.get_nota() << "\n\n";

    
    aluno1.set_nota(-2.5);
    std::cout << "Nota final: " << aluno1.get_nota() << "\n";

    return 0;
}