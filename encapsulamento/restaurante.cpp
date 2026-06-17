#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Para usar o std::find na busca de pratos

class Restaurante {
private:
    std::string nome;
    std::vector<std::string> cardapio;

public:
    // Construtor
    Restaurante(std::string nomeInicial) {
        // Usamos o setter para garantir que o restaurante não comece com nome vazio
        setNome(nomeInicial);
    }

    // Retorna o nome do restaurante
    std::string getNome() const {
        return nome;
    }

    // Altera o nome apenas se não for uma string vazia
    void setNome(std::string novo_nome) {
        if (!novo_nome.empty()) {
            nome = novo_nome;
        } else {
            std::cout << "Erro: O nome do restaurante nao pode ser vazio!\n";
        }
    }

    // Adiciona um novo prato ao cardápio somente se ele ainda não existir
    void adicionarPrato(std::string prato) {
        // std::find procura o prato no vetor do início ao fim
        auto it = std::find(cardapio.begin(), cardapio.end(), prato);
        
        if (it == cardapio.end()) { // Se 'it' chegou ao fim, significa que não achou o prato
            cardapio.push_back(prato);
            std::cout << "Prato [" << prato << "] adicionado ao cardapio.\n";
        } else {
            std::cout << "Aviso: O prato [" << prato << "] ja existe no cardapio.\n";
        }
    }

    // Exibe todos os pratos disponíveis
    void listarCardapio() const {
        std::cout << "\n--- CARDAPIO DO RESTAURANTE " << nome << " ---\n";
        if (cardapio.empty()) {
            std::cout << "O cardapio esta vazio.\n";
        } else {
            for (const auto& prato : cardapio) {
                std::cout << "- " << prato << "\n";
            }
        }
        std::cout << "----------------------------------------\n\n";
    }

    // Verifica se o prato está no cardápio e responde ao cliente
    void atenderCliente(std::string nome_cliente, std::string prato) {
        auto it = std::find(cardapio.begin(), cardapio.end(), prato);

        if (it != cardapio.end()) {
            std::cout << "[Atendimento] " << nome_cliente << ", seu pedido de [" 
                      << prato << "] foi confirmado com sucesso!\n";
        } else {
            std::cout << "[Atendimento] Desculpe, " << nome_cliente << ", mas o prato [" 
                      << prato << "] nao esta disponivel no momento.\n";
        }
    }
};

int main() {
    Restaurante meuRestaurante("Sabor Caseiro");
    std::cout << "Restaurante criado: " << meuRestaurante.getNome() << "\n\n";

    meuRestaurante.adicionarPrato("Feijoada");
    meuRestaurante.adicionarPrato("Frango com Quiabo");
    meuRestaurante.adicionarPrato("Lasanha de Carne");
    
    meuRestaurante.adicionarPrato("Feijoada"); 

    meuRestaurante.listarCardapio();

    meuRestaurante.atenderCliente("Carlos", "Feijoada");          // Prato existe
    meuRestaurante.atenderCliente("Mariana", "Sushi de Salmao");  // Prato NÃO existe

    std::cout << "\n";

    std::cout << "--- Alterando o nome do estabelecimento ---\n";
    meuRestaurante.setNome("Sabor & Arte Bistro");
    std::cout << "Novo nome do restaurante: " << meuRestaurante.getNome() << "\n";

    // Testando a validação de nome vazio
    meuRestaurante.setNome(""); 
    std::cout << "Nome mantido: " << meuRestaurante.getNome() << "\n";

    return 0;
}