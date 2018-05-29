#include <iostream>
#include <list>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "sftext.h"

using namespace std;

struct Ambiente{
    list<char> texto;
    list<char>::iterator cursor;
    Ambiente(){
        cursor = texto.end();
    }

    string toString(){
        stringstream ss;
        for(auto it = texto.begin(); it != texto.end(); it++){
            if(it == cursor)
                ss << "#";
            ss << (*it);
        }
        if(cursor == texto.end())
            ss << "#";
        return ss.str();
    }
};
int main()

//ajeitar os ponteiros

{
    Ambiente amb;
    amb.texto.push_back('a');
    amb.texto.push_back('m');
    amb.texto.push_back('o');
    amb.texto.push_back('r');

    list<Ambiente> aux;
    list<Ambiente>::iterator caux;

    aux.push_back(amb);
    caux = aux.begin();

    sf::RenderWindow janela(sf::VideoMode(800, 600), "Janela");

    while(janela.isOpen()){

        sf::Event event;
        while(janela.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                janela.close();
            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Z){
                    if(event.key.control)
                        cout << "control z" << endl;
                    if(atual!=la.begin())
                        atual--;
                    }
                }
                else if(event.key.code == sf::Keyboard::R){
                    if(event.key.control);
                        cout << "control r" << endl;
                    if(atual!=la.end())
                        atual++;
                }
                else if((event.key.code >= sf::Keyboard::A) &&
                   (event.key.code <= sf::Keyboard::Z)){
                    char tecla = (event.key.code - sf::Keyboard::A) + 'a';
                    aux.erase(++caux);
                    aux.push_back(*caux);
                    caux == --aux.end();
                    caux->texto.insert(caux->cursor, tecla);
                }
                else if((event.key.code == sf::Keyboard::Space)){
                        caux->cursor = caux->texto.insert(caux->cursor,' ');
                        aux.push_back(amb);
                }
                else if(event.key.code == sf::Keyboard::BackSpace){
                    if(amb.cursor != amb.texto.begin()){
                        amb.cursor = amb.texto.erase(--amb.cursor);
                        lista.push_back(amb);
                    }
                }
                else if(event.key.code == sf::Keyboard::Delete){
                    if(amb.cursor != amb.texto.end()){
                        amb.cursor = amb.texto.erase(amb.cursor);
                        aux.push_back(amb);
                    }
                }
                else if(event.key.code == sf::Keyboard::Left){
                    if(amb.cursor != amb.texto.begin()){
                        amb.cursor--;
                    }
                }
                else if(event.key.code == sf::Keyboard::Right){
                    if(amb.cursor != amb.texto.end()){
                    amb.cursor++;
                }
            }
        }

        auto pos = sf::Vector2f(30, 50);
        janela.clear();
        janela.draw(sfText(pos, amb.toString(), sf::Color::White, 30));
        janela.display();
    }
    return 0;
}




