#include <iostream>
#include <string>

class Animal {
private:
    std::string especie;
    std::string som;

public:
   
    Animal(std::string especieAnimal, std::string somAnimal) {
        especie = especieAnimal;
        som = somAnimal;
    }

    // Método para simular o som que o animal faz
    void emitir_som() {
        std::cout << "O " << especie << " faz: " << som << "!\n";
    }
};

int main() {
    Animal cachorro("Cachorro", "Au Au");
    Animal gato("Gato", "Miau");

    // Chamando o método para emitir o som de cada um
    cachorro.emitir_som();
    gato.emitir_som();

    return 0;
}