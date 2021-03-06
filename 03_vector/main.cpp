#include <iostream>

using namespace std;

struct Vetor{
    int * _data;//bloco de dados
    int _capacidade;//tamanho maximo do vetor
    int _size; //quantos elementos estao inseridos

    Vetor(int capacidade){
        this->_capacidade = capacidade;
        this->_size = 0;
//        this->data = (int*) malloc(capacidade * 4);//retorno lixo
        this->_data = new int[capacidade];//retorno zerado
    }
    void push_back(int value){
        if(this->_size == this->_capacidade){
            this->reserve(2 * _capacitade);
            return;
        }
        this->_data[this->_size] = value;
        this->_size += 1;
    }
    void pop_back(){
        if(this->_size == 0)
            return;
        this->_data[_size] = 0;
        this->_size -= 1;
    }

    //retornar a refencia Ã  variavel dessa posicao
    int& at(int indice){
        return this->_data[indice];
    }
    int& front(){
        return this->_data[0];
    }
    int& back(){
        return this->_data[this->_size - 1];
    }
    int * begin(){
        return &this->_data[0];
    }
    int * end(){
        return &this->_data[this->_size];
    }
    int size(){
        return Vetor._size;
    }
    int capacity(){
        return Vetor._capacidade
    }

    void reserve(int capacity){
        Vetor* p = new Vetor[capacity];
        for(int i = 0; i <_size; i++){
            p[i] = Vetor[i];
        }
        this->_capacidade = capacity;
        delete[] Vetor;
        Vetor = p;
    }


};

#include <vector>
int main()
{
    vector<int> v;
    v.push_back(1);//1 elemento, 1 de capacidade
    v.push_back(3);//2 elementos,2 de cap
    v.push_back(5);//3 elementos,4 cap

    v.reserve(100);
    v.size();// 3
    v.capacity();//100

    //lvalue
    v.front();//1
    v.back();//5
    v.front() = 6;

    //posicoes - iteradores
    //nÃ£o sÃ£o ponteiro, mas se comportam como se fosse
    v.begin();//iterador pro primeiro
    v.end();//iterador pro abismo

    vector<string> frutas(5, "bananas");
    vector<string> f2(frutas);
    list<float> lfloat(10, 0.1f);

//    list<int> list = {3, 2, 5, 4, 3, 6, 8, 6};
//    for(int x : list)
//        cout << x << " ";
//    for(auto it = list.begin(); it != list.end(); it++)
//        cout << *it << " ";

    Vetor pivet(5);
    pivet.push_back(4);
    pivet.push_back(2);
    pivet.push_back(7);
    cout << pivet.at(2)
    pivet.at(2) = 9;

    int x = 3;
    int y = 2;
    x = y;
    int z = x;
    //lvalue & significa referencia
    int& a = x;



    cout << "Hello World!" << endl;
    return 0;
}
