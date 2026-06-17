#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Para usar o std::find na busca de livros repetidos

class Biblioteca {
private:
    std::string nome;
    std::vector<std::string> livros; // Lista de livros disponíveis

public:
    // Construtor
    Biblioteca(std::string nomeInicial) {
        setNome(nomeInicial); // Garante a validação do nome desde o início
    }

    
    std::string getNome() const {
        return nome;
    }

    
    void setNome(std::string novo_nome) {
        if (!novo_nome.empty()) {
            nome = novo_nome;
        } else {
            std::cout << "Erro: O nome da biblioteca nao pode ser vazio!\n";
        }
    }

    
    void adicionarLivro(std::string titulo) {
        // Validação 1: Verificar se o título está vazio
        if (titulo.empty()) {
            std::cout << "Erro: Nao e possivel adicionar um livro com titulo vazio.\n";
            return;
        }

        
        auto it = std::find(livros.begin(), livros.end(), titulo);
        
        if (it == livros.end()) { // Se não encontrou o livro
            livros.push_back(titulo);
            std::cout << "Livro \"" << titulo << "\" adicionado com sucesso.\n";
        } else {
            std::cout << "Erro: O livro \"" << titulo << "\" ja existe na lista (Impedido).\n";
        }
    }

    
    void listarLivros() const {
        std::cout << "\n--- LIVROS DISPONIVEIS NA " << nome << " ---\n";
        
        if (livros.empty()) {
            std::cout << "Nenhum livro cadastrado.\n";
        } else {
            for (size_t i = 0; i < livros.size(); ++i) {
                std::cout << i + 1 << ". " << livros[i] << "\n";
            }
        }
        std::cout << "-------------------------------------------\n\n";
    }
};

int main() {
    // 1. Crie uma biblioteca chamada “Biblioteca Central”
    Biblioteca minhaBiblioteca("Biblioteca Central");
    std::cout << "Biblioteca inicializada: " << minhaBiblioteca.getNome() << "\n\n";

    std::cout << "--- Adicionando Livros ---\n";
    minhaBiblioteca.adicionarLivro("O Alquimista");
    minhaBiblioteca.adicionarLivro("Dom Quixote");
    minhaBiblioteca.adicionarLivro("O Pequeno Principe");

   
    std::cout << "\n--- Testando Repeticao e Validade ---\n";
    minhaBiblioteca.adicionarLivro("Dom Quixote"); // Repetido
    minhaBiblioteca.adicionarLivro("");            // Inválido / Vazio

   
    minhaBiblioteca.listarLivros();

    
    std::cout << "--- Alterando o Nome da Biblioteca ---\n";
    minhaBiblioteca.setNome("Biblioteca Municipal Mario de Andrade");
    std::cout << "Novo nome confirmado: " << minhaBiblioteca.getNome() << "\n";

    return 0;
}