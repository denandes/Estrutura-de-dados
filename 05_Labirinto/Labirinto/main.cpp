#include <QCoreApplication>


#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int nlinhas = 20;
int ncolunas = 35;

const char PAREDE = 'k';
const char ABERTO = 'w';
const char EMBUSCA = 'y';
const char CAMINHO = 'b';
const char ABATIDO = 'm';

void showMat(matchar& mat,vector<Par> pilha, Par inicio, Par fim, Par atual){
    mat_draw(mat);
    for(Par par : pilha){
        mat_focus(par, 'c');
    }
    mat.focus(pilha.back(), 'k');
    mat_focus(inicio, 'g');
    mat_focus(fim, 'r');
}
vector<Par> getNeib(Par par){
    vector<Par> vizinhos;
    vizinhos.push_back(Par(par.l + 1, par.c));
    vizinhos.push_back(Par(par.l - 1, par.c));
    vizinhos.push_back(Par(par.l, par.c + 1));
    vizinhos.push_back(Par(par.l, par.c - 1));
    return vizinhos;
}
int countOpen(matchar &mat, Par par){
    int cont = 0;
    for(auto vizinhos : getNeib(par)){
        if(!mat.is_inside(vizinhos) || mat.get(vizinhos) != PAREDE){
            cont++;
        }
    }
    return cont;
}
vector<Par> shuffle(vector<Par> vet){
    std::random_shuffle(vet.begin(), vet.end());
    return vet;
}
void create_lab_pilha(matriz<char>& mat){
    vector<Par> pilha1;
    vector<Par> viz_true;
    pilha1.push_back(mar.get(par) = ABERTO);

    while(pilha1.size() != 0){
        Par topo = pilha1.back();
        for(Par par : getNeib(topo)){
            if(countOpen(mat, topo) <= 1){
                viz_true.push_back(par);
                Par buraco = viz_true[rand() % viz_true.size()];
                mat.get(buraco) = ABERTO;
                pilha1.push_back(buraco);
            }else{
                pilha1.pop_back();
            }
        }
    }
}
//void furar(matchar &mat, Par par){
//    if(!mat.equals(par, PAREDE) || countOpen(mat, par) > 1){
//        return;
//    }
//    mat.get(par) = ABERTO;
//    for(Par vizinho : shuffle(getNeib(par))){
//        furar(mat, vizinho);
//    }
//}
bool findPath(matchar& mat, Par inicio, Par final){
    vector<Par> pilha2;
    pilha.push_back(inicio);
    mat.get(inicio) = EMBUSCA;
    while(pilha2.size() != 0){
        Par topo = pilha2.back();
        if(topo == final){
            return true;
        }
        vector<Par> viz_abertos;
        for(Par par : getNeib(topo)){
            if(mat.get(par) == ABERTO){
                viz_abertos.push_back(par);
            }
        }
        if(viz_abertos.size() = 0){
            pilha2.pop_back();
        }else{
            Par escolhido = viz_abertos[rand() % viz_abertos.size()];
            mat.get(escolhido) = EMBUSCA;
            pilha2.push_back(escolhido);
        }

    }
    return false;
}
//bool findPath(matchar& mat, Par inicio, Par final, Par atual){
//    if(atual == final){
//        mat.get(atual) = CAMINHO;
//        showMat(mat,inicio, final, atual);
//        return true;
//    }
//    if(!mat.is_inside(atual)){
//        return false;
//    }
//    if(mat.get(atual) != ABERTO){
//        return false;
//    }
//    mat.get(atual) = EMBUSCA;
//    showMat(mat, inicio, final, atual);

//    for(Par vizinhos : shuffle(getNeib(atual))){
//        if(findPath(mat, inicio, final, vizinho)){
//            mat.get(atual) = CAMINHO;
//            showMat(mat, inicio, final, atual);
//            return true;
//        }
//    }
//    mat.get(atual) = ABATIDO;
//    showMat(mat, inicio, final, atual);
//    return false;
//}

# include <cstdlib>
# include <ctime>

int main(){
    srand(time(NULL));
    matchar mat(15, 20, PAREDE);
    furar(mat, Par(1, 1));
    mat_draw(mat);
    ed_show();

    Par inicio = mat_get_click(mat);
    Par final = mat_get_click(mat);
    mat_draw(mat);
    ed_show();

    findPath(mat, inicio, final);

    ed_lock();
    return 0;
}
