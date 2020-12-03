#ifndef SORTS_H
#define SORTS_H

#include <vector>
#include "pokemon.h"

using namespace std;

size_t split(const string &txt, vector<string> &strs, char ch)
{
    size_t pos = txt.find( ch );
    size_t initialPos = 0;
    strs.clear();

    while( pos != string::npos ) {
        strs.push_back( txt.substr( initialPos, pos - initialPos ) );
        initialPos = pos + 1;

        pos = txt.find( ch, initialPos );
    }
    strs.push_back( txt.substr( initialPos, min( pos, txt.size() ) - initialPos + 1 ) );

    return strs.size();
}

template <class T>
void swap(vector<T> &v, int i, int j) {
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

template <class T>
vector<T> bubbleNumero(vector<T> &v)
{
	for (int i = v.size() - 1; i > 0; i--)
  {
		for (int j = 0; j < i; j++)
    {
			if (v[j].numeroPokemon > v[j + 1].numeroPokemon)
      {
				swap(v, j, j + 1);
			}
		}
	}
	return v;
}

template <class T>
vector<T> bubbleNombre(vector<T> &v)
{
	for (int i = v.size() - 1; i > 0; i--)
  {
		for (int j = 0; j < i; j++)
    {
			if (v[j].nombrePokemon > v[j + 1].nombrePokemon)
      {
				swap(v, j, j + 1);
			}
		}
	}
	return v;
}

template <class T>
vector<T> bubbleTipo(vector<T> &v)
{
	for (int i = v.size() - 1; i > 0; i--)
  {
		for (int j = 0; j < i; j++)
    {
			if (v[j].tipoPokemon > v[j + 1].tipoPokemon)
      {
				swap(v, j, j + 1);
			}
		}
	}
	return v;
}

template <class T>
vector<T> bubbleAltura(vector<T> &v)
{
	for (int i = v.size() - 1; i > 0; i--)
  {
		for (int j = 0; j < i; j++)
    {
			if (v[j].alturaPokemon > v[j + 1].alturaPokemon)
      {
				swap(v, j, j + 1);
			}
		}
	}
	return v;
}

template <class T>
vector<T> bubblePeso(vector<T> &v)
{
	for (int i = v.size() - 1; i > 0; i--)
  {
		for (int j = 0; j < i; j++)
    {
			if (v[j].pesoPokemon > v[j + 1].pesoPokemon)
      {
				swap(v, j, j + 1);
			}
		}
	}
	return v;
}

template <class T>
void busq(vector<T> &v, string tipo) {
  ofstream myfilein ("datos_pokedex.txt");
	for (int i = 0; i < v.size(); i++) {
    if (myfilein.is_open())
    {
      if(v[i].tipoPokemon.find(tipo)!= string::npos)
      {
          myfilein<<"---------------------------"<<endl;
          myfilein<<"No. "<<v[i].numeroPokemon<<" "<<v[i].nombrePokemon<<endl;
          myfilein<<"Type"<<endl;
          myfilein<<"\t\t"<<v[i].tipoPokemon<<endl;
          myfilein<<"Weight"<<" .......... "<<v[i].pesoPokemon<<" Kg"<<endl;
          myfilein<<"Height"<<" .......... "<<v[i].alturaPokemon<<" Mts"<<endl;
          myfilein<<"---------------------------"<<endl;
      }
    }
  }
	myfilein.close();
}

#endif