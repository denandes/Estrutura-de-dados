#include <vector>
#include <list>
#include <algorithm>
#include <ctime>//funcao time
#include <cstdlib> //funcao srand
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

//Cada dia possui 6 horas de trabalho
//60 minutos x 6 horas = 360 minutos
//cada minuto eh um turno.
const int TURNOS_DIA = 360;

//A quantidade máxima de caixa.
const int MAX_CAIXAS = 10;

//Esse valor determina o quanto o banco por caixa por dia de trabalho
const int CUSTO_CAIXA_DIA = 100;

//numero de simulacoes de teste
const int N_EXEC_TESTE = 100;

struct Cliente
{
    int paciencia;
    int documentos;
    std::string nome;

    Cliente(int paciencia, int documentos)
    {
        gerarNomeAleatorio();
        this->paciencia = paciencia;
        this->documentos = documentos;
    }

    void gerarNomeAleatorio(){
        std::string consoantes = "bcdfghjklmnpqrstvxyz";
        std::string vogais = "aeiou";
        this->nome = std::string(1, consoantes[std::rand() % consoantes.size()]);
        this->nome += std::string(1, vogais[std::rand() % vogais.size()]);
    }
};



//gera um numero entre min e max, [min, max]
int rand_mm(int min, int max){
    static int init = 1;
    if(init){
        init = 0;
        srand(time(NULL));
    }
    return rand() % (max - min + 1) + min;
}

std::string to_string(const Cliente *cliente){
    std::stringstream str;
    str << "[" << cliente->nome << ":";
    str << "d" << setw(2) << cliente->documentos <<
           ":p" << setw(2) << cliente->paciencia << "]";
    return str.str();
}


void print_banco(list<Cliente *> fila, vector<Cliente *> caixas, int turno, int lucro){
    Cliente dummy(0, 0);
    int slot = to_string(&dummy).size();//quandos caracteres ocupa um cliente
    std::cout << string(1 + (slot - 1) * MAX_CAIXAS, '#') << std::endl;
    std::cout << "|";
    for(auto& x : caixas){
        if(x == nullptr)
            cout << std::string(slot - 2, ' ');
        else
            cout << to_string(x);
        cout << "|";
    }
    for(int x = 0; x < MAX_CAIXAS - (int) caixas.size(); x++)
        std::cout << std::string(slot - 2, '-') << "|";
    std::cout << endl;
    std::cout << "-" << std::string(slot - 2, ' ') << std::string((slot - 1) * MAX_CAIXAS, '-') << std::endl;

    std::cout << " ";
    int ind = 1;
    for(auto it = fila.begin(); it != fila.end(); it++, ind++){
        if(ind % MAX_CAIXAS == 0)
            cout << endl << " ";
        cout << to_string(*it) << " ";
    }
    std::cout << std::endl;
    std::cout << std::string(1 + (slot - 1) * MAX_CAIXAS, '#') << std::endl;
    std::cout << "Turno : " << turno << endl;
    std::cout << "Lucro : " << lucro << endl;
}

//pac é paciencia do cliente, entre min e max
//doc é a quantidade de documentos do cliente
//cli é a quantidade de clientes que entra por minuto
//numCaixas é o número de caixas no banco
int simulacao(pair<int, int> pac, pair<int, int> doc, pair<int, int> cli, int numCaixas){
    std::vector<Cliente*> caixa(numCaixas);
    std::list<Cliente*> fila;

    int LUCRO;

    int qtd = rand_mm(cli.first, cli.second);
       int Bopen = 1;

       while(Bopen == 1 || TURNOS_DIA <= 360){
           if(rand_mm(0, 9) < 7){
               fila.push_back(new Cliente(rand_mm(pac.first, pac.second), rand_mm(doc.first, doc.second)));
           }
           for(int i = 0;i < numCaixas; i++){
               if(caixa[i] == nullptr){
                   caixa[i] = fila.front();
                   fila.pop_front();
               }
           }
           for(auto cliente : fila){
               cliente->paciencia--;
               if(cliente->paciencia = 0){
                   fila.remove(cliente);
               }
           }
           for(int i = 0;i < numCaixas; i++){
               if(caixa[i] != nullptr){
                   caixa[i]->documentos--;
                   LUCRO++;
               }
               if(caixa[i]->documentos == 0){
                   caixa[i] = nullptr;
               }
           }
           if(fila.empty()){
               Bopen = 0;
           }
           TURNOS_DIA--;
       }

       return LUCRO - MAX_CAIXAS * CUSTO_CAIXA_DIA;
}


int main ()
{
    simulacao({5, 10}, {3, 5}, {1, 3}, 4);
    return 0;
}
