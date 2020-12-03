#ifndef POKEMON_H
#define POKEMON_H
#include<string>
using namespace std;

class Pokemon
{
  public:
    int numeroPokemon;
    string nombrePokemon;
    string tipoPokemon;
    float alturaPokemon;
    float pesoPokemon;
    
    Pokemon();
    Pokemon(int numero, string nombre, string tipo, float altura, float peso);
    
    int get_numero();
    string get_nombre();
    string get_tipo();
    float get_altura();
    float get_peso();

};

Pokemon::Pokemon(){}

Pokemon::Pokemon(int numero, string nombre,  string tipo, float altura, float peso)
{
  numeroPokemon = numero;
  nombrePokemon = nombre;
  tipoPokemon = tipo;
  alturaPokemon = altura;
  pesoPokemon = peso;
}

int Pokemon::get_numero(){return numeroPokemon;}

string Pokemon::get_nombre(){return nombrePokemon;}

string Pokemon::get_tipo(){return tipoPokemon;}

float Pokemon::get_altura(){return alturaPokemon;}

float Pokemon::get_peso(){return pesoPokemon;}

#endif