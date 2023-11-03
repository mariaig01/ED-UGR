/**
 * @file Ruta.h
 * @author María de las Angustias Izquierdo García
 * @brief 
 * @version 0.1
 * @date 2021-01-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#ifndef __RUTA__
#define __RUTA__

#include <iostream>
#include <list>
#include "Punto.h"
#include <iterator>
using namespace std;

/**
 * @brief T.D.A Ruta
 * 
 * 
 * Una instancia @e c del tipo de datos abstacto @c Ruta es un objeto con
 * dos campos, una lista de @c Puntos y un código asociado a la ruta
 * 
 * Un ejemplo de su uso:
 * @include Ruta.cpp
 * 
 * 
 */
class Ruta{


/**
 * @page repConjunto Rep del TDA Ruta
 * 
 * @section invConjunto Invariante de la representación
 * 
 * El código de la ruta tiene que empezar por R
 * 
 * @section faConjunto Función de abstraccion
 * 
 * rep.codigo
 * rep.ruta[0]
 * rep.ruta[1]
 * ...
 * 
 * 
 */
private:

list<Punto> ruta;
string codigo;
void Copiar(const Ruta & R);
void Borrar();


public:

/**
 * @brief Construye un objeto Ruta
 * 
 */
Ruta();

/**
 * @brief Constructor de copia
 * 
 * @param p 
 */
Ruta(const Punto & p);

/**
 * @brief Obtenemos el codigo del objeto
 * 
 * @return const string 
 */
const string GetCodigo()const;

/**
 * @brief Operador de asignación.
 * 
 * @param p 
 * @return Ruta& 
 */
Ruta & operator=(const Ruta & p);

/**
 * @brief Asigna una ruta a la ruta de (*this)
 * 
 * @param p 
 */
void AsignaRuta(const list<Punto> & p);

/**
 * @brief Limpia el objeto ruta
 * 
 */
void Clear();

/**
 * @brief Asigna eñ código que recibe como parámetro al código de (*this)
 * 
 * @param c 
 */
void AsignaCodigo(const string & c);

/**
 * @brief Operador de salida
 * 
 * @param os 
 * @param r 
 * @return ostream& 
 */
 friend ostream & operator<<(ostream & os, Ruta & r);
			      
/**
 * @brief Operador de entrada
 * 
 * @param is 
 * @param r 
 * @return istream& 
 */
friend istream & operator>>(istream & is, Ruta & r);


/**
 * @brief Comprueba si un punto se encuentra en la ruta o no
 * 
 * @param p 
 * @return true 
 * @return false 
 */
bool EstaPunto(const Punto & p);

/**
 * @brief Inserta un punto en la ruta
 * 
 * @param p 
 */
void InsertarPunto(const Punto & p);



class iterator{
	 private:
	list<Punto>::iterator it;

	public:



	/**
	* @brief Operador ++
	* @return Iterador al siguiente objeto
	*/
	iterator & operator++(){
	++it;

	return *this;
	}

	/**
	* @brief Operador --
	* @return Iterador al anterior objeto a iterar
	*/
	iterator & operator--(){
	--it;

	return *this;
	}

	/**
	* @brief Operador *
	* @return pareja de strings. El primer elemento es el usuario.
	* El segundo elemento es el número de teléfono
	*/
	Punto & operator *(){
	return *it;
	}

	/**
	* @brief Operador ==
	* @param i iterador a comparar
	* @return True si el contenido del iterador es igual al de 
	* i. False en caso contrario
	*/
	bool operator ==(const iterator &i){
	return i.it==it;
	}	  

	/**
	* @brief Operador !=
	* @param i iterador a comparar
	* @return True si el contenido del iterador es distinto al de
	* i. False en caso contrario
	*/
	bool operator !=(const iterator &i){
	return i.it!=it;
	}


	/**
	* @brief Operador de asignacion
	* @param it iterador a copiar
	* @return referencia al objeto con el contenido de it
	*/
	iterator &operator=(const iterator &it){

		if(this != &it){
        this->it = it.it;
    	}

    return *this;
	}

    friend class Ruta;

	};


	class const_iterator{
	 private:
	list<Punto>::const_iterator it;

	public:



	/**
	* @brief Operador ++
	* @return Iterador al siguiente objeto
	*/
	const_iterator & operator++(){
	++it;

	return *this;
	}

	/**
	* @brief Operador --
	* @return Iterador al anterior objeto a iterar
	*/
	const_iterator & operator--(){
	--it;

	return *this;
	}

	/**
	* @brief Operador *
	* @return pareja de strings. El primer elemento es el usuario.
	* El segundo elemento es el número de teléfono
	*/
	const Punto & operator *()const{
	return *it;
	}

	/**
	* @brief Operador ==
	* @param i iterador a comparar
	* @return True si el contenido del iterador es igual al de 
	* i. False en caso contrario
	*/
	bool operator ==(const const_iterator &i)const{
	return i.it==it;
	}	  

	/**
	* @brief Operador !=
	* @param i iterador a comparar
	* @return True si el contenido del iterador es distinto al de
	* i. False en caso contrario
	*/
	bool operator !=(const const_iterator &i)const{
	return i.it!=it;
	}


	/**
	* @brief Operador de asignacion
	* @param it iterador a copiar
	* @return referencia al objeto con el contenido de it
	*/
	const_iterator &operator=(const const_iterator &it){

		if(this != &it){
        this->it = it.it;
    	}

    return *this;
	}

    friend class Ruta;

	};

	Ruta::iterator begin(){
		iterator i;
		i.it = ruta.begin();

		return i;
		
	}

	Ruta::iterator end(){
		iterator i;
		i.it = ruta.end();

		return i;

	}

	Ruta::const_iterator begin()const{
		const_iterator i;
		i.it = ruta.begin();

		return i;

		
	}

	Ruta::const_iterator end()const{
		const_iterator i;
		i.it = ruta.end();

		return i;

	}

    
};
#endif


