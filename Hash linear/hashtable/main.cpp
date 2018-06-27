#include <iostream>

using namespace std;

const char VAZIO = -1;
const char APAGADO = -2;

struct Item{
    int key;
    int value;

    Item(int key = VAZIO, int value = 0){
        this->key = key;
        this->value = value;
    }

};

struct HashTable{
    int max;
    int size;
    Item * data;

    HashTable(int max){
        this->max = max;
        this->data = new Item[max];
    }

    ~HashTable(){
        delete [] data;
    }

    void show(){
        cout << "|";
        for(int i = 0; i < max; i++)
            cout << i << "," << data[i].key << "," << data[i].value << "|";
        cout << endl;
    }
    Item * find(int key){
        int pos = key % this->max;
        while(true){
            if(data[pos].key == VAZIO)
                return nullptr;
            if(data[pos].key == key)
                return &data[pos];
            pos = (pos + 1) % this->max;
        }
        return nullptr;
    }

    bool remove(int key){
        auto encontrado = find(key);
        if(encontrado != nullptr){
            encontrado->key = APAGADO;

            size--;
            return true;
        }
        return false;
    }

    bool insert(int key, int value){
        int pos = key % this->max;
        while (true) {
            if((data[pos].key == VAZIO || data[pos].key == APAGADO)){
                data[pos].key = key;
                data[pos].value = value;
                this->size++;
                return true;
            }else if(data[pos + 1].key == VAZIO || data[pos + 1].key == APAGADO){
                data[pos + 1].key = key;
                data[pos + 1].value = value;
                this->size++;
                return true;
            }
            if(data[pos].key == key)
                break;
            pos = (pos + 1) % this->max;
        }
        return false;
    }
 };

#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

int main(){

        HashTable tabela(10);
        tabela.show();

    while(true){
        int x;
        cout << "digite 1 para inserir um numero no hash" << endl;
        cout << "digite 2 para remover um numero no hash" << endl;
        cin >> x;

        if(x == 1){
            cout << "digite a key";
            int key;
            cin >> key;
            cout << "digite o valor";
            int value;
            cin >> value;
            tabela.insert(key, value);
            tabela.show();
        }
        if(x == 2){
            cout << "digite a key";
            int key;
            cin >> key;
            tabela.remove(key);
            tabela.show();
        }
    }
    tabela.show();
    return 0;
}

















