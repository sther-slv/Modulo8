#include <iostream>
#include <string>

class Pessoa {
public:
    std::string nome;
    int idade;

    Pessoa(std::string n, int i) {
        nome = n;
        idade = i;
    }

    void exibirDados() {
        std::cout << "Nome: " << nome << " | Idade: " << idade << " anos\n";
    }

    int main() {
        Pessoa pessoa1("Maria", 30);
        Pessoa pessoa2("Stephany", 25);

        pessoa1.exibirDados(); // exibe os dados da pessoa 1
        pessoa2.exibirDados(); // exibe os dados da pessoa 2
        
        return 0;
    }

   
};
