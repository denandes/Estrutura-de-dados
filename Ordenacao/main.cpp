#include <iostream>
#include <ctime>
#include <cstdlib> //rand
#include "libs/ed_sort.h"

using namespace std;

//cores rgbcymkw
//red, green, blue, cyan, yellow, magenta, black, white

void swap_sort(vector<int>& vet){
    for(int i = 0; i < (int) vet.size() - 1; i++){
        view_set_faixa(i, vet.size() - 1);
        for(int j = i + 1; j < (int) vet.size(); j++){
            view_show(vet, {i, j}, "yg");
            if(vet[j] < vet[i]){
                std::swap(vet[i], vet[j]);
                view_show(vet, {i, j}, "yg");
            }
        }
    }
}

void selection_sort(vector<int>& vet){
    for(int i = 0; i < (int) vet.size() - 1; i++){
        int imenor = i;
        view_set_faixa(i, vet.size() - 1);
        for(int j = i + 1; j < (int) vet.size(); j++){
            view_show(vet, {i, j, imenor}, "ygr");
            if(vet[j] < vet[imenor]){
                imenor = j;
                view_show(vet, {i, j, imenor}, "ygr");
            }
        }
        std::swap(vet[imenor], vet[i]);
    }
}

void reverse_minimum_sort(vector<int>& vet){
    int ultimo = vet.size() - 1;
    for(int i = 0; i <= ultimo; ultimo--){
        int imaior = ultimo;
        for(int j = 0; j < ultimo; j++){
            view_show(vet, {j, imaior, ultimo}, "ygr");
            if(vet[j] > vet[imaior]){
                imaior = j;
                view_show(vet, {j, imaior, ultimo}, "ygr");
            }
        }
        std::swap(vet[imaior], vet[ultimo]);
    }
}

void palma_sort(vector<int>& vet){
    int ultimo = vet.size() - 1;
    for(int i = 0; i <= ultimo; i++, ultimo--){
        int imaior = i;
        int imenor = i;
        view_set_faixa(i, ultimo);
        for(int j = i; j <= ultimo; j++){
            view_show(vet, {i, j, imenor, imaior, ultimo}, "rgyyr");
            if(vet[j] < vet[imenor]){
                imenor = j;
                view_show(vet, {i, j, imenor, imaior, ultimo}, "rgyyr");
            }
            else if(vet[j] > vet[imaior]){
                imaior = j;
                view_show(vet, {i, j, imenor, imaior, ultimo}, "rgyyr");
            }
        }
        std::swap(vet[imenor], vet[i]);
        if(imaior == i)
            imaior = imenor;
        std::swap(vet[imaior], vet[ultimo]);
        view_show(vet, {i, imenor, imaior, ultimo}, "ryyr");
    }
}

void bubble_sort(vector<int>& vet){
    for(int i = vet.size() - 1; i < 0; i--){
        for(int j = 0;j < i;j++){
            view_show(vet, {i, j, j + 1}, "rgy");
            if(vet[j] > vet[j + 1]){
                std::swap(vet[j], vet[j + 1]);
                view_show(vet, {i, j, j + 1}, "rgy");
            }
        }
    }
}
void insertion_sort(vector<int>& vet){
    for(int i = 0;i < vet.size();i++){
        for(int j = i;j > 0;j--){
            view_show(vet, {i, j, j - 1}, "rgy");
            if(vet[j] < vet[j - 1]){
                std::swap(vet[j], vet[j - 1]);
                view_show(vet, {i, j, j - 1}, "rgy");
            }else{
                break;
            }
        }
    }
}
void quick_sort(vector<int> & vet, int C, int F){
    if(C >= F){
        return;
    }
    int pivo = vet[C];
    int i = C;
    int j = F;
    view_set_faixa(C, F);
    while (i <= j){
        while((vet[i] < pivo) && (i < F)){
            i++;
            view_show(vet,{C, F, i, j}, "rgby");
        }
        while((vet[j] > pivo) && (j > C)){
           j--;
           view_show(vet,{C, F, i, j}, "rgby");
        }
        if(vet[i] >= vet[j]){
            std::swap(vet[i],vet[j]);
            view_show(vet,{C, F, i, j}, "rgyb");
            i++;
            j--;
        }
    }
    quick_sort(vet, C, j);
    quick_sort(vet, i, F);
}

void test_sort(vector<int>& vet){
    for(int i = 0; i < (int) vet.size() - 1; i++){
        if(vet[i] <= vet[i + 1])
            view_show(vet, {i, i + 1}, "gg");
        else{
            view_show(vet, {i, i + 1}, "rr");
            view_lock();
        }
    }
}

int main(){
    srand(time(NULL));

    const int qtd = 70;
    vector<int> vet(qtd, 0);

    int min = 10;
    int max = 400;

    for(int i = 0; i < qtd; i++)
        vet[i] = (rand() % (max - min + 1) + min);

//    view_set_dot();
    view_set_bar();
    view_set_faixa(0, qtd - 1);

    //swap_sort(vet);
    //selection_sort(vet);
    palma_sort(vet);
//    reverse_minimum_sort(vet);

    test_sort(vet);
    view_lock();
    return 0;
}





















