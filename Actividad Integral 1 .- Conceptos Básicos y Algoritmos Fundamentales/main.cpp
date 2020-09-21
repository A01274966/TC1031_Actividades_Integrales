#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "log.h"

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

void swap(vector<Log> &v, int i, int j)
{
  Log aux = v[i];
  v[i]= v[j];
  v[j] = aux;
}

vector<Log> ordena(vector<Log> &v)
{
	for (int i = v.size() - 1; i > 0; i--)
  {
		for (int j = 0; j < i; j++)
    {
			if (v[j].mensaje > v[j + 1].mensaje)
      {
				swap(v, j, j + 1);
			}
		}
	}
	return v;
}

void busq(vector<Log> &v, string mensaje_error) {
  ofstream myfilein ("a.out");
	for (int i = 0; i < v.size(); i++) {
    if (myfilein.is_open())
    {
      if(v[i].mensaje.find(mensaje_error)!= string::npos)
      {
          myfilein<< v[i].mes<<" "<< v[i].dia<<" "<< v[i].hora<<" "<<v[i].ip<<" "<<v[i].mensaje<< "\n";
      }
    }
  }
	myfilein.close();
}


vector<Log> list_log;
vector<Log> list_log_ordenado;
int main() {

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
      string mes = v[0];
      string dia = v[1];
      string hora = v[2];
      string ip = v[3];
      string mensaje = "";
      for(int i=4; i<v.size();i++)
      {
        mensaje += v[i];
        mensaje += " ";
      }

      Log log(mes, dia, hora,ip, mensaje);
      list_log.push_back(log);
    }
    myfileout.close();
  }


  cout<<"Elije una opcion\n";
  cout<<"\n";
  cout<<"1. Mostrar datos originales\n2. Mostrar datos ordenados por mensaje de error\n3. Mostrar datos por busqueda de mensaje de error";
  cout<<""<<endl;
  cin>>opcion;

  ofstream myfilein ("a.out");

  switch(opcion)
  {
    case 1:
      for(int i=0; i<list_log.size();i++)
      {
        if (myfilein.is_open())
        {
          myfilein<< list_log[i].mes<<" "<< list_log[i].dia<<" "<< list_log[i].hora<<" "<<list_log[i].ip<<" "<<list_log[i].mensaje<< "\n";
        }
      }
      break;
    case 2:
      list_log_ordenado = ordena(list_log);
      for(int i=0; i<list_log_ordenado.size();i++)
      {
        if (myfilein.is_open())
        {
          myfilein<< list_log_ordenado[i].mes<<" "<< list_log_ordenado[i].dia<<" "<< list_log_ordenado[i].hora<<" "<<list_log_ordenado[i].ip<<" "<<list_log_ordenado[i].mensaje<< "\n";
        }
      }
      break;
    case 3:
      int op;
      string mensaje_error;
      list_log_ordenado = ordena(list_log);
      cout<<"Realizar busqueda por:\n \n 1. Illegal user\n 2. Failed password for admin\n 3. Failed password for illegal user guest\n 4. Failed password for illegal user test\n 5. Failed password for root";
      cout<<""<<endl;
      cin>>op;
      switch(op)
      {
        case 1:
        mensaje_error = "Illegal user";
        busq(list_log_ordenado, mensaje_error);
        break;
        case 2:
        mensaje_error = "Failed password for admin";
        busq(list_log_ordenado, mensaje_error);
        break;
        case 3:
        mensaje_error = "Failed password for illegal user guest";
        busq(list_log_ordenado, mensaje_error);
        break;
        case 4:
        mensaje_error = "Failed password for illegal user test";
        busq(list_log_ordenado, mensaje_error);
        break; 
        case 5:
        mensaje_error = "Failed password for root";
        busq(list_log_ordenado, mensaje_error);
        break;
        default:
          break;              
      }
      break;
    }
  }