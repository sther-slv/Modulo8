#include <iostream>
#include <string>
#include <vector>

class Aluno {
private:
    std::string nome;
    int idade;
    std::string curso;

public:
    Aluno(std::string nomeInicial, int idadeInicial, std::string cursoInicial) {
        setNome(nomeInicial);
        setIdade(idadeInicial);
        setCurso(cursoInicial);
    }

    std::string getNome() const { return nome; }
    int getIdade() const { return idade; }
    std::string getCurso() const { return curso; }

    void setNome(std::string novo_nome) {
        if (!novo_nome.empty()) nome = novo_nome;
    }

    void setIdade(int nova_idade) {
        if (nova_idade > 0) idade = nova_idade;
    }

    void setCurso(std::string novo_curso) {
        if (!novo_curso.empty()) curso = novo_curso;
    }

    void apresentar() const {
        std::cout << "Nome: " << nome << " | Idade: " << idade << " | Curso: " << curso << "\n";
    }
};

class Escola {
private:
    std::string nome;
    std::vector<Aluno> alunos; // Lista privada de objetos da classe Aluno

public:
    Escola(std::string nomeInicial) {
        setNome(nomeInicial);
    }

    // Getter para o nome da escola
    std::string getNome() const {
        return nome;
    }

    void setNome(std::string novo_nome) {
        if (!novo_nome.empty()) {
            nome = novo_nome;
        } else {
            std::cout << "Erro: O nome da escola nao pode ser vazio!\n";
        }
    }

    // Adiciona um aluno à lista (garantido pelo tipo 'Aluno' do parâmetro)
    void adicionarAluno(const Aluno& novoAluno) {
        alunos.push_back(novoAluno);
        std::cout << "Aluno(a) " << novoAluno.getNome() << " matriculado(a) com sucesso!\n";
    }

    
    void listarAlunos() const {
        std::cout << " ALUNOS MATRICULADOS - " << nome << "\n";

        if (alunos.empty()) {
            std::cout << "Nenhum aluno matriculado.\n";
        } else {
            for (const auto& aluno : alunos) {
                aluno.apresentar();    // Chama o método da classe Aluno
            }
        }
        std::cout << "=========================================\n\n";
    }
};

// === EXECUÇÃO DO DESAFIO EXTRA ===
int main() {
    // 1. Crie uma escola chamada “Escola Futuro”
    Escola minhaEscola("Escola Futuro");

    
    minhaEscola.listarAlunos();

    
    Aluno aluno1("Arthur", 16, "Informatica para Internet");
    Aluno aluno2("Beatriz", 17, "Mecatronica");

    
    std::cout << "--- Iniciando Matriculas ---\n";
    minhaEscola.adicionarAluno(aluno1);
    minhaEscola.adicionarAluno(aluno2); // (Nota: Ajustado mentalmente para minhaEscola)
    minhaEscola.adicionarAluno(aluno2);

    // 4. Exiba a lista de alunos matriculados
    minhaEscola.listarAlunos();

    // 5. Teste alterações de atributos usando os métodos set
    std::cout << "--- Atualizando Dados do Sistema ---\n";
    
    // Mudando o nome da escola
    minhaEscola.setNome("Instituto Tecnologico Futuro");
    std::cout << "Novo nome da instituicao: " << minhaEscola.getNome() << "\n\n";

    
    std::cout << "Modificando curso do Arthur...\n";
    aluno1.setCurso("Desenvolvimento de Sistemas");

    
    std::cout << "Dados diretos do objeto modificado:\n";
    aluno1.apresentar();

    return 0;
}