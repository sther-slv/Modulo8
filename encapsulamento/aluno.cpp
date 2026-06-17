#include <iostream>
#include <string>

class Aluno {
private:
    std::string nome;
    int idade;
    std::string curso;

public:
    // Construtor para inicializar o aluno com dados válidos desde o início
    Aluno(std::string nomeInicial, int idadeInicial, std::string cursoInicial) {
        // Usamos os métodos setters para garantir que nenhuma regra seja burlada na criação
        setNome(nomeInicial);
        setIdade(idadeInicial);
        setCurso(cursoInicial);
    }

    // --- MÉTODOS GETTERS ---
    std::string getNome() const {
        return nome;
    }

    int getIdade() const {
        return idade;
    }

    std::string getCurso() const {
        return curso;
    }

    void setNome(std::string novo_nome) {
        if (!novo_nome.empty()) {
            nome = novo_nome;
        } else {
            std::cout << "Erro: O nome do aluno nao pode ser vazio! Mantendo o anterior ou padrao.\n";
            if (nome.empty()) nome = "Aluno Sem Nome"; // Fallback caso ocorra no construtor
        }
    }

    // Altera apenas se a idade for um número maior que 0
    void setIdade(int nova_idade) {
        if (nova_idade > 0) {
            idade = nova_idade;
        } else {
            std::cout << "Erro: A idade deve ser maior que 0! Mantendo a anterior ou padrao.\n";
            if (idade <= 0) idade = 1; // Fallback caso ocorra no construtor
        }
    }

    // Altera apenas se não for vazio
    void setCurso(std::string novo_curso) {
        if (!novo_curso.empty()) {
            curso = novo_curso;
        } else {
            std::cout << "Erro: O curso nao pode ser vazio! Mantendo o anterior ou padrao.\n";
            if (curso.empty()) curso = "Nao Informado"; // Fallback caso ocorra no construtor
        }
    }

    void apresentar() const {
        std::cout << "Nome: " << nome << " | Idade: " << idade << " | Curso: " << curso << "\n";
    }
};

int main() {
    std::cout << "--- MATRICULANDO ALUNOS (Cenários Válidos) ---\n";
    
    // Criando alunos com dados corretos
    Aluno aluno1("Joao", 20, "Informatica");
    Aluno aluno2("Maria", 18, "Edificacoes");

    
    aluno1.apresentar();
    aluno2.apresentar();

    std::cout << "\n--- TESTANDO VALIDAÇÕES (Cenários Inválidos) ---\n";

    
    std::cout << "Tentando mudar a idade do Joao para -5:\n";
    aluno1.setIdade(-5); 
    
    
    std::cout << "Tentando mudar o curso da Maria para vazio:\n";
    aluno2.setCurso("");

    std::cout << "\n--- DADOS FINAIS DOS ALUNOS ---\n";
    
    aluno1.apresentar();
    aluno2.apresentar();

    return 0;
}