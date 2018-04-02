#include <stdio.h>
#include <iostream>
#include <list>

void rodar (std::list<int> &lista){
    lista.push_back(lista.front());
    lista.pop_front();
}

int main(){
    int qtd = 0;
    std::cout << "digite quantos amigos vão jogar";
    std::cin >> qtd;

    int primeiro = 0;
    std::cout << "digite onde vai estar a espada";
    std::cin >> primeiro;

    int n = 0;
    std::cout << "digite quantos amigos a espada vai saltar";
    std::cin >> n;

    std::list<int> lista;
    for(int i = 1;i <= qtd;i++){
        lista.push_back(i);
    }
    while(lista.front() != primeiro){
        rodar(lista);
    }
    while(lista.size() > 1){
        if(lista.front() == primeiro){
            for(int i = 0;i < n;i++){
                rodar(lista);
            }
            lista.pop_front();
            primeiro = lista.front();
        }else{
            rodar(lista);
        }
    }
}
