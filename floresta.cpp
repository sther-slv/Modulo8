#include <iostream>
#include <string>
#include <memory>

class Personagem {
protected:
    std::string nome;
    int poder;
    std::string tipo;

public:
    Personagem(std::string n, int p, std::string t) 
        : nome(n), poder(p), tipo(t) {}

    virtual ~Personagem() = default; 

    int getPoder() const { return poder; }

    
    virtual void exibir() const {
        std::cout << "Nome: " << nome << " | Tipo: " << tipo << " | Poder: " << poder;
    }
};


class ChefeFloresta : public Personagem {
private:
    std::string reino;

public:
    ChefeFloresta(std::string n, int p, std::string t, std::string r)
        : Personagem(n, p, t), reino(r) {}

    // Sobrescrevendo o método para incluir o reino do Chefe
    void exibir() const override {
        Personagem::exibir(); // Chama a exibição da classe base
        std::cout << " [Chefe do Reino: " << reino << "]";
    }
};

struct Nodo {
    std::shared_ptr<Personagem> personagem; 
    Nodo* esquerda;
    Nodo* direita;

    Nodo(std::shared_ptr<Personagem> p) 
        : personagem(p), esquerda(nullptr), direita(nullptr) {}
};

class ArvoreFlorestal {
private:
    Nodo* raiz;

    Nodo* inserirRecursivo(Nodo* nodo, std::shared_ptr<Personagem> p) {
        if (nodo == nullptr) {
            return new Nodo(p);
        }

        if (p->getPoder() < nodo->personagem->getPoder()) {
            nodo->esquerda = inserirRecursivo(nodo->esquerda, p);
        } else {
            nodo->direita = inserirRecursivo(nodo->direita, p);
        }
        return nodo;
    }

    
    void emOrdemRecursivo(Nodo* nodo) const {
        if (nodo != nullptr) {
            emOrdemRecursivo(nodo->esquerda);
            nodo->personagem->exibir();
            std::cout << std::endl;
            emOrdemRecursivo(nodo->direita);
        }
    }

    void liberarMemoria(Nodo* nodo) {
        if (nodo != nullptr) {
            liberarMemoria(nodo->esquerda);
            liberarMemoria(nodo->direita);
            delete nodo;
        }
    }

public:
    ArvoreFlorestal() : raiz(nullptr) {}
    
    ~ArvoreFlorestal() {
        liberarMemoria(raiz);
    }

    void inserir(std::shared_ptr<Personagem> p) {
        raiz = inserirRecursivo(raiz, p);
    }

    void exibirDoMenosParaOMaisPoderoso() const {
        emOrdemRecursivo(raiz);
    }
};

int main() {
    ArvoreFlorestal floresta;

    
    floresta.inserir(std::make_shared<Personagem>("Lupi", 45, "Animal"));
    floresta.inserir(std::make_shared<Personagem>("Mago Merlin", 90, "Mago"));
    floresta.inserir(std::make_shared<ChefeFloresta>("Chefe Dragao", 150, "Dragao", "Montanhas de Fogo"));
    floresta.inserir(std::make_shared<Personagem>("Groot", 70, "Planta"));
    floresta.inserir(std::make_shared<Personagem>("Fada Flora", 30, "Fada"));
    floresta.inserir(std::make_shared<ChefeFloresta>("Rainha Elfa", 120, "Elfo", "Floresta de Cristal"));

    // Exibindo o resultado
    std::cout << "--- Personagens da Floresta Encantada (Ordem Crescente de Poder) ---\n" << std::endl;
    floresta.exibirDoMenosParaOMaisPoderoso();
    std::cout << "\n---------------------------------------------------------------------" << std::endl;

    return 0;
}