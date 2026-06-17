#include <iostream>
#include <cstring>
#include <string>
#include <locale.h>
#include <windows.h>
#include <stdexcept>

using namespace std;

class ContaBancaria {
private:
    std::string titular;
    double saldo;

public:
    // construtor
    ContaBancaria(string t, double s) : titular(t), saldo(s) {}

    string getTitular() const { return titular;}
    double getSaldo() const { return saldo; }

    void depositar(double valor) {
        if (valor > 0) {
            saldo += valor;
            cout << "Depósito de R$ " << valor << " realizado." << endl;
        } else {
            cout << "Valor inválido para depósito." << endl;
        }
    }

    bool sacar(double valor) {
        if (valor > 0 && valor <= saldo) {
            saldo -= valor;
            cout << "Saque de R$ " << valor << " realizado." << endl;
            return true;
        } else {
            cout << "Saldo insuficiente ou valor inválido." << endl;
            return false;
        }
    }
    
};

int main(){

    ContaBancaria conta("João Silva", 1000.00);

    cout << "Titular: " << conta.getTitular() << endl;
    cout << "Saldo inicial: R$ " << conta.getSaldo() << endl;


    return 0;
}