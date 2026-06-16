#include <iostream>
#include <string>

class Cachorro {
public:
    std::string nome;
    std::string raca;

    Cachorro(std::string n, std::string r) {
        nome = n;
        raca = r;
    }

    void latir() {
        std::cout << "Au Au! O cachorro " << nome << " está latindo!\n";
    }

    int main() {
        Cachorro meuCao("Rex", "Labrador");
        meuCao.latir(); // o método para o cachorro latir.
        
        return 0;
    }

   
};