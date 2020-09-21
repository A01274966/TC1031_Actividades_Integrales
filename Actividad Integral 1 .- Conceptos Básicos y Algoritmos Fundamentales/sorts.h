#ifndef SORTS_H_
#define SORTS_H_

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


template <class T>
class Sorts
{
private:
  void swap(vector<T>&, int, int);
	void copyArray(vector<T>&, vector<T>&, int, int);
public:
  vector<T> ordenarArchivo(vector<T>&);
  vector<T>Busqueda(vector<T>&, int)
};

template <class T>
void Sorts<T>::swap(std::vector<T> &v, int i, int j)
{
  T aux = v[i];
  v[i]= v[j];
  v[j] = aux;
}

template <class T>
void Sorts<T>::copyArray(std::vector<T> &A, std:: vector<T> &B, int low, int high)
{
  for(int i = low; i <= high; i++)
  {
    A[i] = B[i];
  }
}
