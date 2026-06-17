#include <iostream>
#include <string>

class Computador {
public:
    std::string marca;
    bool ligado;

    Computador(std::string mca) {
        marca = mca;
        ligado = false;
    }

    void ligar() {
        ligado = true;
        std::cout << "O computador " << marca << " ligou!\n";
    }

    int main() {
        Computador meuPC("Dell");
        meuPC.ligar(); // o método para o pc ligar.
        
        return 0;
    }
};
