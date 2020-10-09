#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

//----------------------------------No se que sea esto pero es para una funcion sleep, lo saque de internet:)
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <cstdlib>
//----------------------------------

#include "pokemon.h"
#include "list.h"



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

void swap(vector<Pokemon> &v, int i, int j)
{
  Pokemon aux = v[i];
  v[i]= v[j];
  v[j] = aux;
}

vector<Pokemon> bubbleNumero(vector<Pokemon> &v)
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

vector<Pokemon> bubbleNombre(vector<Pokemon> &v)
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

vector<Pokemon> bubbleTipo(vector<Pokemon> &v)
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

vector<Pokemon> bubbleAltura(vector<Pokemon> &v)
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

vector<Pokemon> bubblePeso(vector<Pokemon> &v)
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

void busq(vector<Pokemon> &v, string tipo) {
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
int numeroPokemon;
string nombrePokemon;
string tipoPokemon;
float alturaPokemon;
float pesoPokemon;

vector<Pokemon> list_pokemon;
vector<Pokemon> list_pokemon_bubble;

List<Pokemon> lista;


ofstream myfilein ("datos_pokedex.txt");
int main() 
{
  int opcion;

  string line;
  ifstream myfileout ("bitacora.txt");
  if(myfileout.is_open()){
    int k=0;
    while(getline(myfileout,line))
    {
      if(k==20)
      break;
      k++;
      vector<string> v;
      split( line, v, ' ');
      string numeroPokemon = v[0];
      string nombrePokemon = v[1];
      string alturaPokemon = v[2];
      string pesoPokemon = v[3];
      string tipoPokemon = v[4];

      Pokemon pokemon(stoi(numeroPokemon), nombrePokemon, tipoPokemon,stof(alturaPokemon), stof(pesoPokemon));
      list_pokemon.push_back(pokemon);
    }
    myfileout.close();
  }

  if (myfileout.is_open()) {
  while (myfileout>>numeroPokemon>>nombrePokemon>>tipoPokemon>>nombrePokemon>>numeroPokemon){
    cout<< numeroPokemon << " " << nombrePokemon << " " << tipoPokemon << " " << alturaPokemon << " " << pesoPokemon << " " << endl;

    Pokemon pokemon_list(numeroPokemon,nombrePokemon,tipoPokemon,alturaPokemon, pesoPokemon);
    lista.add(pokemon_list);
  }
  }

  
   cout<<"__ ___         _            __     ___      ___"<<endl;
   cout<<"| '_  \\       | |           | |    \\  \\    /  /"<<endl;
   cout<<"| |_) |  ___  | | _____  ___| |___  \\  \\  /  /"<<endl;
   cout<<"| .___/ / _ \\ | |/ / _ \\/  _  | _ \\  \\  \\/  /"<<endl;
   cout<<"| |    | (_) ||   <| __/| (_) | __/  /  /\\  \\"<<endl;
   cout<<"| |     \\___/ |_|\\_\\___/\\_____|___/ /  /  \\  \\"<<endl;
   cout<<"|_|                                /__/    \\__\\"<<endl;

   cout<<"\n";
   cout<<"1. Mostrar datos de pokedex originales"<<endl;
   cout<<"2. Ordenar datos de pokedex por atributos"<<endl;
   cout<<"3. Buscar objetos por tipo de Pokemon"<<endl;
   cout<<"4. Salir"<<endl;
   cout<<"\n";
   cin>>opcion;


   switch(opcion)
   {
     case 1:
      for(int i=0; i<list_pokemon.size();i++)
      {
        if (myfilein.is_open())
        {
          myfilein<<"---------------------------"<<endl;
          myfilein<<"No. "<<list_pokemon[i].numeroPokemon<<" "<<list_pokemon[i].nombrePokemon<<endl;
          myfilein<<"Type"<<endl;
          myfilein<<"\t\t"<<list_pokemon[i].tipoPokemon<<endl;
          myfilein<<"Weight"<<" .......... "<<list_pokemon[i].pesoPokemon<<" Kg"<<endl;
          myfilein<<"Height"<<" .......... "<<list_pokemon[i].alturaPokemon<<" Mts"<<endl;
          myfilein<<"---------------------------"<<endl;
        }
      }
      cout<<"\n";
      cout<<"Imprimiendo datos"<<endl;
      sleep(1);
      cout<<"."<<endl;
      sleep(1);
      cout<<"."<<endl;
      sleep(1);
      cout<<"."<<endl;
      sleep(1);
      cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl;
      break;
     case 2:
      int opcioncaso2;
      cout<<"\n";
      cout<<"¿Por que atributo deseas ordenar?"<<endl;
      cout<<"\n";
      cout<<"1. Numero de Pokedex  2. Nombre"<<endl;
      cout<<"3. Tipo               4. Altura"<<endl;
      cout<<"5. Peso"<<endl;
      cout<<"\n";
      cin>>opcioncaso2;
      switch(opcioncaso2)
      {
        case 1:
          list_pokemon_bubble = bubbleNumero(list_pokemon);
          for(int i=0; i<list_pokemon_bubble.size();i++)
          {
            if (myfilein.is_open())
            {
              myfilein<<"---------------------------"<<endl;
              myfilein<<"No. "<<list_pokemon_bubble[i].numeroPokemon<<" "<<list_pokemon_bubble[i].nombrePokemon<<endl;
              myfilein<<"Type"<<endl;
              myfilein<<"\t\t"<<list_pokemon_bubble[i].tipoPokemon<<endl;
              myfilein<<"Weight"<<" .......... "<<list_pokemon_bubble[i].pesoPokemon<<" Kg"<<endl;
              myfilein<<"Height"<<" .......... "<<list_pokemon_bubble[i].alturaPokemon<<" Mts"<<endl;
              myfilein<<"---------------------------"<<endl;
            }
          }
          cout<<"\n";
          cout<<"Imprimiendo datos"<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl;   
          break;
        case 2:
          list_pokemon_bubble = bubbleNombre(list_pokemon);
          for(int i=0; i<list_pokemon_bubble.size();i++)
          {
            if (myfilein.is_open())
            {
              myfilein<<"---------------------------"<<endl;
              myfilein<<"No. "<<list_pokemon_bubble[i].numeroPokemon<<" "<<list_pokemon_bubble[i].nombrePokemon<<endl;
              myfilein<<"Type"<<endl;
              myfilein<<"\t\t"<<list_pokemon_bubble[i].tipoPokemon<<endl;
              myfilein<<"Weight"<<" .......... "<<list_pokemon_bubble[i].pesoPokemon<<" Kg"<<endl;
              myfilein<<"Height"<<" .......... "<<list_pokemon_bubble[i].alturaPokemon<<" Mts"<<endl;
              myfilein<<"---------------------------"<<endl;
            }
          }
          cout<<"\n";
          cout<<"Imprimiendo datos"<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl; 
          break;
        case 3:
          list_pokemon_bubble = bubbleTipo(list_pokemon);
          for(int i=0; i<list_pokemon_bubble.size();i++)
          {
            if (myfilein.is_open())
            {
              myfilein<<"---------------------------"<<endl;
              myfilein<<"No. "<<list_pokemon_bubble[i].numeroPokemon<<" "<<list_pokemon_bubble[i].nombrePokemon<<endl;
              myfilein<<"Type"<<endl;
              myfilein<<"\t\t"<<list_pokemon_bubble[i].tipoPokemon<<endl;
              myfilein<<"Weight"<<" .......... "<<list_pokemon_bubble[i].pesoPokemon<<" Kg"<<endl;
              myfilein<<"Height"<<" .......... "<<list_pokemon_bubble[i].alturaPokemon<<" Mts"<<endl;
              myfilein<<"---------------------------"<<endl;
            }
          }
          cout<<"\n";
          cout<<"Imprimiendo datos"<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl;     
          break;
        case 4:
          list_pokemon_bubble = bubbleAltura(list_pokemon);
          for(int i=0; i<list_pokemon_bubble.size();i++)
          {
            if (myfilein.is_open())
            {
              myfilein<<"---------------------------"<<endl;
              myfilein<<"No. "<<list_pokemon_bubble[i].numeroPokemon<<" "<<list_pokemon_bubble[i].nombrePokemon<<endl;
              myfilein<<"Type"<<endl;
              myfilein<<"\t\t"<<list_pokemon_bubble[i].tipoPokemon<<endl;
              myfilein<<"Weight"<<" .......... "<<list_pokemon_bubble[i].pesoPokemon<<" Kg"<<endl;
              myfilein<<"Height"<<" .......... "<<list_pokemon_bubble[i].alturaPokemon<<" Mts"<<endl;
              myfilein<<"---------------------------"<<endl;
            }
          }
          cout<<"\n";
          cout<<"Imprimiendo datos"<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl;     
          break;
        case 5:
          list_pokemon_bubble = bubblePeso(list_pokemon);
          for(int i=0; i<list_pokemon_bubble.size();i++)
          {
            if (myfilein.is_open())
            {
              myfilein<<"---------------------------"<<endl;
              myfilein<<"No. "<<list_pokemon_bubble[i].numeroPokemon<<" "<<list_pokemon_bubble[i].nombrePokemon<<endl;
              myfilein<<"Type"<<endl;
              myfilein<<"\t\t"<<list_pokemon_bubble[i].tipoPokemon<<endl;
              myfilein<<"Weight"<<" .......... "<<list_pokemon_bubble[i].pesoPokemon<<" Kg"<<endl;
              myfilein<<"Height"<<" .......... "<<list_pokemon_bubble[i].alturaPokemon<<" Mts"<<endl;
              myfilein<<"---------------------------"<<endl;
            }
          }
          cout<<"\n";
          cout<<"Imprimiendo datos"<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl;  
          break;
        default:
          break;
      }
      break;
     case 3:
      int opcioncaso3;
      
      cout<<"\n";
      cout<<"¿Que tipo de Pokemon deseas buscar?"<<endl;
      cout<<"\n";
      cout<<"1. Agua       2. Fuego"<<endl;
      cout<<"3. Planta     4. Bicho"<<endl;
      cout<<"5. Normal     6. Veneno"<<endl;
      cout<<"7. Electrico  8. Tierra"<<endl;
      cout<<"9. Hada       10. Lucha"<<endl;
      cout<<"11. Psiquico  12. Roca"<<endl;
      cout<<"13. Fantasma  14. Hielo"<<endl;
      cout<<"15. Dragon"<<endl;
      cout<<"\n";
      cin>>opcioncaso3;
      switch(opcioncaso3)
      {
        case 1:
          busq(list_pokemon, "Agua");
          cout<<"\n";
          cout<<"Imprimiendo datos"<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl;
          break;
        case 2:
          busq(list_pokemon, "Fuego");
          cout<<"Imprimiendo datos"<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl;
          break;
        case 3:
          busq(list_pokemon, "Planta");
          cout<<"Imprimiendo datos"<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl;
          break;
        case 4:
          busq(list_pokemon, "Bicho");
          cout<<"Imprimiendo datos"<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl;
          break;
        case 5:
          busq(list_pokemon, "Normal");
          cout<<"Imprimiendo datos"<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl;
          break;
        case 6:
          busq(list_pokemon, "Veneno");
          cout<<"Imprimiendo datos"<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl;
          break;
        case 7:
          busq(list_pokemon, "Electrico");
          cout<<"Imprimiendo datos"<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl;
          break;
        case 8:
          busq(list_pokemon, "Tierra");
          cout<<"Imprimiendo datos"<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl;
          break;
        case 9:
          busq(list_pokemon, "Hada");
          cout<<"Imprimiendo datos"<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl;
          break;
        case 10:
          busq(list_pokemon, "Lucha");
          cout<<"Imprimiendo datos"<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl;
          break;
        case 11:
          busq(list_pokemon, "Psiquico");
          cout<<"Imprimiendo datos"<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl;
          break;
        case 12:
          busq(list_pokemon, "Roca");
          cout<<"Imprimiendo datos"<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl;
          break;
        case 13:
          busq(list_pokemon, "Fantasma");
          cout<<"Imprimiendo datos"<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl;
          break;
        case 14:
         busq(list_pokemon, "Hielo");
         cout<<"Imprimiendo datos"<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl;
          break;
        case 15:
          busq(list_pokemon, "Dragon");
          cout<<"Imprimiendo datos"<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"."<<endl;
          sleep(1);
          cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl;
          break; 
        default:
          break;         
      }
      break;
     case 4:
      cout<<"Hasta luego entrenador!"<<endl;
      break;
     default:
      break;
   }
}