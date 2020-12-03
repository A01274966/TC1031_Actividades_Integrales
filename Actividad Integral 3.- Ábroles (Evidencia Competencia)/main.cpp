#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

#include "pokemon.h"
#include "list.h"
#include "sorts.h"
#include "heap.h"

using namespace std;

vector<Pokemon> vector_pokemon;
vector<Pokemon> vector_pokemon_bubble;

List<Pokemon> lista;

Heap<string> numerosHeap(151);

int numeroPokemon;
string numPoke, nombrePokemon, tipoPokemon;
float alturaPokemon, pesoPokemon;


ofstream myfilein ("datos_pokedex.txt");
ofstream myfilein1;
int main() 
{
  int opcion;

  string line;
  ifstream myfileout ("bitacora.txt");
  if(myfileout.is_open()){
    while(getline(myfileout,line))
     {
      vector<string> v;
      split( line, v, ' ');
      string numeroPokemon = v[0];
      string nombrePokemon = v[1];
      string alturaPokemon = v[2];
      string pesoPokemon = v[3];
      string tipoPokemon = v[4];

      Pokemon pokemon(stoi(numeroPokemon), nombrePokemon, tipoPokemon,stof(alturaPokemon), stof(pesoPokemon));
      vector_pokemon.push_back(pokemon);
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
   cout<<"3. Buscar datos por tipo de Pokemon"<<endl;
   cout<<"4. Buscar datos de pokemon por medio de arbol heap"<<endl;
   cout<<"5. Salir"<<endl;
   cout<<"\n";
   cin>>opcion;
   cout<<"\n";

   switch(opcion)
   {
     case 1:
      for(int i=0; i<vector_pokemon.size();i++)
      {
        if (myfilein.is_open())
        {
          myfilein<<"---------------------------"<<endl;
          myfilein<<"No. "<<vector_pokemon[i].numeroPokemon<<" "<<vector_pokemon[i].nombrePokemon<<endl;
          myfilein<<"Type"<<endl;
          myfilein<<"\t\t"<<vector_pokemon[i].tipoPokemon<<endl;
          myfilein<<"Weight"<<" .......... "<<vector_pokemon[i].pesoPokemon<<" Kg"<<endl;
          myfilein<<"Height"<<" .......... "<<vector_pokemon[i].alturaPokemon<<" Mts"<<endl;
          myfilein<<"---------------------------"<<endl;
        }
      }
      cout<<"\n";
      cout<<"Imprimiendo datos"<<endl;
      cout<<"."<<endl;
      cout<<"."<<endl;
      cout<<"."<<endl;
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
          vector_pokemon_bubble = bubbleNumero(vector_pokemon);
          for(int i=0; i<vector_pokemon_bubble.size();i++)
          {
            if (myfilein.is_open())
            {
              myfilein<<"---------------------------"<<endl;
              myfilein<<"No. "<<vector_pokemon_bubble[i].numeroPokemon<<" "<<vector_pokemon_bubble[i].nombrePokemon<<endl;
              myfilein<<"Type"<<endl;
              myfilein<<"\t\t"<<vector_pokemon_bubble[i].tipoPokemon<<endl;
              myfilein<<"Weight"<<" .......... "<<vector_pokemon_bubble[i].pesoPokemon<<" Kg"<<endl;
              myfilein<<"Height"<<" .......... "<<vector_pokemon_bubble[i].alturaPokemon<<" Mts"<<endl;
              myfilein<<"---------------------------"<<endl;
            }
          }
          cout<<"\n";
          cout<<"Imprimiendo datos"<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl;   
          break;
        case 2:
          vector_pokemon_bubble = bubbleNombre(vector_pokemon);
          for(int i=0; i<vector_pokemon_bubble.size();i++)
          {
            if (myfilein.is_open())
            {
              myfilein<<"---------------------------"<<endl;
              myfilein<<"No. "<<vector_pokemon_bubble[i].numeroPokemon<<" "<<vector_pokemon_bubble[i].nombrePokemon<<endl;
              myfilein<<"Type"<<endl;
              myfilein<<"\t\t"<<vector_pokemon_bubble[i].tipoPokemon<<endl;
              myfilein<<"Weight"<<" .......... "<<vector_pokemon_bubble[i].pesoPokemon<<" Kg"<<endl;
              myfilein<<"Height"<<" .......... "<<vector_pokemon_bubble[i].alturaPokemon<<" Mts"<<endl;
              myfilein<<"---------------------------"<<endl;
            }
          }
          cout<<"\n";
          cout<<"Imprimiendo datos"<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl; 
          break;
        case 3:
          vector_pokemon_bubble = bubbleTipo(vector_pokemon);
          for(int i=0; i<vector_pokemon_bubble.size();i++)
          {
            if (myfilein.is_open())
            {
              myfilein<<"---------------------------"<<endl;
              myfilein<<"No. "<<vector_pokemon_bubble[i].numeroPokemon<<" "<<vector_pokemon_bubble[i].nombrePokemon<<endl;
              myfilein<<"Type"<<endl;
              myfilein<<"\t\t"<<vector_pokemon_bubble[i].tipoPokemon<<endl;
              myfilein<<"Weight"<<" .......... "<<vector_pokemon_bubble[i].pesoPokemon<<" Kg"<<endl;
              myfilein<<"Height"<<" .......... "<<vector_pokemon_bubble[i].alturaPokemon<<" Mts"<<endl;
              myfilein<<"---------------------------"<<endl;
            }
          }
          cout<<"\n";
          cout<<"Imprimiendo datos"<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl;     
          break;
        case 4:
          vector_pokemon_bubble = bubbleAltura(vector_pokemon);
          for(int i=0; i<vector_pokemon_bubble.size();i++)
          {
            if (myfilein.is_open())
            {
              myfilein<<"---------------------------"<<endl;
              myfilein<<"No. "<<vector_pokemon_bubble[i].numeroPokemon<<" "<<vector_pokemon_bubble[i].nombrePokemon<<endl;
              myfilein<<"Type"<<endl;
              myfilein<<"\t\t"<<vector_pokemon_bubble[i].tipoPokemon<<endl;
              myfilein<<"Weight"<<" .......... "<<vector_pokemon_bubble[i].pesoPokemon<<" Kg"<<endl;
              myfilein<<"Height"<<" .......... "<<vector_pokemon_bubble[i].alturaPokemon<<" Mts"<<endl;
              myfilein<<"---------------------------"<<endl;
            }
          }
          cout<<"\n";
          cout<<"Imprimiendo datos"<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl;     
          break;
        case 5:
          vector_pokemon_bubble = bubblePeso(vector_pokemon);
          for(int i=0; i<vector_pokemon_bubble.size();i++)
          {
            if (myfilein.is_open())
            {
              myfilein<<"---------------------------"<<endl;
              myfilein<<"No. "<<vector_pokemon_bubble[i].numeroPokemon<<" "<<vector_pokemon_bubble[i].nombrePokemon<<endl;
              myfilein<<"Type"<<endl;
              myfilein<<"\t\t"<<vector_pokemon_bubble[i].tipoPokemon<<endl;
              myfilein<<"Weight"<<" .......... "<<vector_pokemon_bubble[i].pesoPokemon<<" Kg"<<endl;
              myfilein<<"Height"<<" .......... "<<vector_pokemon_bubble[i].alturaPokemon<<" Mts"<<endl;
              myfilein<<"---------------------------"<<endl;
            }
          }
          cout<<"\n";
          cout<<"Imprimiendo datos"<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
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
          busq(vector_pokemon, "Agua");
          cout<<"\n";
          cout<<"Imprimiendo datos"<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl;
          break;
        case 2:
          busq(vector_pokemon, "Fuego");
          cout<<"Imprimiendo datos"<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl;
          break;
        case 3:
          busq(vector_pokemon, "Planta");
          cout<<"Imprimiendo datos"<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl;
          break;
        case 4:
          busq(vector_pokemon, "Bicho");
          cout<<"Imprimiendo datos"<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl;
          break;
        case 5:
          busq(vector_pokemon, "Normal");
          cout<<"Imprimiendo datos"<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl;
          break;
        case 6:
          busq(vector_pokemon, "Veneno");
          cout<<"Imprimiendo datos"<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl;
          break;
        case 7:
          busq(vector_pokemon, "Electrico");
          cout<<"Imprimiendo datos"<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl;
          break;
        case 8:
          busq(vector_pokemon, "Tierra");
          cout<<"Imprimiendo datos"<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl;
          break;
        case 9:
          busq(vector_pokemon, "Hada");
          cout<<"Imprimiendo datos"<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl;
          break;
        case 10:
          busq(vector_pokemon, "Lucha");
          cout<<"Imprimiendo datos"<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl;
          break;
        case 11:
          busq(vector_pokemon, "Psiquico");
          cout<<"Imprimiendo datos"<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl;
          break;
        case 12:
          busq(vector_pokemon, "Roca");
          cout<<"Imprimiendo datos"<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl;
          break;
        case 13:
          busq(vector_pokemon, "Fantasma");
          cout<<"Imprimiendo datos"<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl;
          break;
        case 14:
         busq(vector_pokemon, "Hielo");
         cout<<"Imprimiendo datos"<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl;
          break;
        case 15:
          busq(vector_pokemon, "Dragon");
          cout<<"Imprimiendo datos"<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl;
          break; 
        default:
          break;         
      }
      break;
     case 4:
      

      cout << "Cargando datos de la bitacora a un arbol heap . . ." << endl;
      cout<<""<<endl;
      myfileout.open("bitacora.txt");
      if (myfileout.is_open()) {
        while(getline(myfileout,line)) {
        stringstream stream(line);
        string col1;
        if(stream >> col1){
          numerosHeap.push(col1);
        } 
      }
      myfileout.close();

      myfilein1.open("numerosHeap.txt");
      if (myfilein1.is_open()) {
        myfilein1 << numerosHeap.toString() <<endl;
      }
      myfilein1.close();
      cout<<"Arbol heap creado correctamente y guardado en numerosHeap.txt"<<endl;
      cout<<"\n";
      string opcioncase4;
      cout<<"¿Que numero de pokemon te gusaria buscar? (Usar sintaxis 002, 054, 139, etc.)"<<endl;
      cout<<"\n";
      cin>>opcioncase4;
      cout<<"\n";
      

      if(numerosHeap.busqHeap(opcioncase4)){
      cout << "Pokemon encontrado!" << endl;
      cout<<"\n";
        if (myfilein.is_open())
        {
          myfilein<<"---------------------------"<<endl;
          myfilein<<"No. "<<vector_pokemon[stoi(opcioncase4)-1].numeroPokemon<<" "<<vector_pokemon[stoi(opcioncase4)-1].nombrePokemon<<endl;
          myfilein<<"Type"<<endl;
          myfilein<<"\t\t"<<vector_pokemon[stoi(opcioncase4)-1].tipoPokemon<<endl;
          myfilein<<"Weight"<<" .......... "<<vector_pokemon[stoi(opcioncase4)-1].pesoPokemon<<" Kg"<<endl;
          myfilein<<"Height"<<" .......... "<<vector_pokemon[stoi(opcioncase4)-1].alturaPokemon<<" Mts"<<endl;
          myfilein<<"---------------------------"<<endl;

          cout<<"Imprimiendo datos"<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"."<<endl;
  
          cout<<"Datos impresos satisfactoriamente en datos_pokedex.txt"<<endl;     
        }
      }
      else{
      cout << "Pokemon no encontrado" << endl;
      }
      }
      break;
     case 5:
      cout<<"Hasta luego entrenador!"<<endl;
      break;
     default:
      break;
   }
}
