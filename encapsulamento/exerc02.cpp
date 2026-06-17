#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Produto {
private:
    std::string nome;
    double preco;

public:
    // Construtor
    Produto(std::string nomeInicial, double precoInicial) {
        nome = nomeInicial;
        // Usamos o próprio setter no construtor para garantir a validação desde o início
        set_preco(precoInicial); 
    }

    // Getter para o Nome
    std::string get_nome() const {
        return nome;
    }

    // Getter para o Preço
    double get_preco() const {
        return preco;
    }

    // Setter para o Nome
    void set_nome(std::string novoNome) {
        nome = novoNome;
    }

    // Setter para o Preço com validação (não pode ser zero ou negativo)
    void set_preco(double novoPreco) {
        if (novoPreco > 0.0) {
            preco = novoPreco;
        } else {
            std::cout << "Erro para [" << nome << "]: O preco R$ " << novoPreco 
                      << " e invalido! O valor deve ser maior que zero.\n";
            preco = 0.01; // Define um valor mínimo padrão caso seja inválido
        }
    }

    // Método auxiliar para exibir os dados do produto facilmente
    void exibirDados() const {
        std::cout << "Produto: " << nome << " | Preco: R$ " 
                  << std::fixed << std::setprecision(2) << preco << "\n";
    }
};

int main() {
    std::cout << "--- CRIANDO E TESTANDO PRODUTO 1 (Notebook) ---\n";
    // Criando o primeiro produto com dados válidos
    Produto p1("Notebook", 3500.00);
    p1.exibirDados();

    // Tentando alterar para um preço inválido (negativo)
    p1.set_preco(-150.0);
    p1.exibirDados(); // O preço antigo é mantido ou ajustado pelo sistema de segurança

    // Alterando para um preço válido novo
    p1.set_preco(3200.00);
    p1.exibirDados();


    std::cout << "\n--- CRIANDO E TESTANDO PRODUTO 2 (Smartphone) ---\n";
    // Criando o segundo produto já tentando colocar um preço inválido (zero)
    Produto p2("Smartphone", 0.0); 
    p2.exibirDados(); // O construtor vai barrar o 0.0 através do setter

    // Corrigindo o preço do segundo produto para um valor válido
    p2.set_preco(1599.90);
    p2.exibirDados();

    return 0;
}