/**
 * @file Punto.h
 * @author María de las Angustias Izquierdo García
 * @brief 
 * @version 0.1
 * @date 2021-01-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */



#ifndef __PUNTO__
#define __PUNTO__


#include <iostream>
#include <fstream>
#include <iterator>
using namespace std;

/**
 * @brief T.D.A Punto
 * 
 *  Una instancia @e c del tipo de datos abstracto @c Punto es un objeto
 * con dos campos, la latitud y la longitud.
 * 
 * Un ejemplo de su uso:
 * @include Punto.cpp
 *
 * 
 */
class Punto{

/**
 * @page repConjunto Rep del TDA Punto
 * 
 * 
 * @section invConjunto Invariante de la representación
 * 
 * No tiene invariante, ya que latitud y longitud pueden tomar cualquier valor
 * 
 * @section faConjunto Función de abstracción
 * 
 * Un objeto válido @e rep del TDA Punto 
 * 
 * (rep.latitud,rep.longitud)
 * 
 */

private:

double longitud;
double latitud;

public:

/**
 * @brief Constructor por defecto. Construye un objeto punto
 * 
 * 
 */

Punto();


/**
 * @brief Constructor con parámetros. 
 * 
 * @param lat lat lo asignamos a latitud
 * @param lon lon lo asignamos a longitud
 */
Punto(double lat,double lon);

/**
 * @brief Constructor de copia.
 * 
 * @param p 
 */
Punto(const Punto & p);


/**
 * @brief Operador de asignación
 * 
 * @param p Asigna p a (*this)
 * @return Punto& 
 */
Punto & operator=(const Punto & p);

/**
 * @brief Obtenemos la longitud del objeto
 * 
 * @return const double 
 */
const double GetLongitud()const;

/**
 * @brief Obtenemos la latitud del objeto
 * 
 * @return const double 
 */
const  double GetLatitud()const;

/**
 * @brief Operador de igualdad constante. Comprueba si P es igual a *this
 * 
 * @param P Objeto con el que se compara 
 * @return true 
 * @return false 
 */
const bool operator==(const Punto &P)const;

/**
 * @brief Operador de igualdad. 
 * 
 * @param P 
 * @return true 
 * @return false 
 */
bool operator==(const Punto &P);

/**
 * @brief Establece la latitud del objeto
 * 
 * @param lat 
 */
void SetLatitud( double lat);

/**
 * @brief Establece la longitud del objeto
 * 
 * @param lon 
 */
void SetLongitud( double lon);

/**
 * @brief Operador de salida.
 * 
 * @param os 
 * @param p 
 * @return ostream& 
 */
friend ostream & operator<<(ostream & os,const Punto & p);

/**
 * @brief Operador de entrada. Lee un punto
 * 
 * @param is 
 * @param g 
 * @return istream& 
 */
 friend istream & operator>>(istream & is, Punto & g);

/**
 * @brief Limpia el objeto. Pone la latitud y la longitud a 0
 * 
 */
 void Clear();

};


#endif
