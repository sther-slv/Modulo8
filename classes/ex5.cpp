#include <iostream>
#include <string>

class ContaBancaria {
private:
    std::string titular;
    double saldo;

public:
    // Construtor para inicializar o titular e o saldo inicial
    ContaBancaria(std::string nomeTitular, double saldoInicial) {
        titular = nomeTitular;
        saldo = saldoInicial;
    }

    
    void depositar(double valor) {
        if (valor > 0) {
            saldo += valor;
            std::cout << "Depósito de R$ " << valor << " realizado com sucesso.\n";
        } else {
            std::cout << "Valor de depósito inválido.\n";
        }
    }

    // Método para sacar um valor (com validação de saldo)
    void sacar(double valor) {
        if (valor > 0 && valor <= saldo) {
            saldo -= valor;
            std::cout << "Saque de R$ " << valor << " realizado com sucesso.\n";
        } else if (valor > saldo) {
            std::cout << "Saldo insuficiente para o saque de R$ " << valor << ".\n";
        } else {
            std::cout << "Valor de saque inválido.\n";
        }
    }

    void mostrarSaldo() {
        std::cout << "Titular: " << titular << " | Saldo Atual: R$ " << saldo << "\n";
    }
};

int main() {
    // 1. Criando o objeto (Conta com saldo inicial de R$ 1000.00)
    ContaBancaria minhaConta("Carlos Silva", 1000.00);
    minhaConta.mostrarSaldo();
    
    std::cout << "-----------------------------------\n";

    
    minhaConta.depositar(500.00);
    minhaConta.sacar(200.00);

    std::cout << "-----------------------------------\n";

    // 4. Mostrando o saldo final
    minhaConta.mostrarSaldo();

    return 0;
}
