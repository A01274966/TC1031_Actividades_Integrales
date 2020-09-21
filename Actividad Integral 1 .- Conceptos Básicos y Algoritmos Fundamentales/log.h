#ifndef LOG_H
#define LOG_H
#include<string>
using namespace std;

class Log
{  
  public:
    string mes;
    string dia;
    string hora;
    string ip;
    string mensaje;
    
    Log(string mes, string dia, string hora, string ip, string mensaje){
      this->mes = mes;
      this->dia = dia;
      this->hora = hora;
      this->ip = ip;
      this->mensaje = mensaje;
    }
};

#endif