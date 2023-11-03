/**
 * @file almacen_rutas.h
 * @author María de las Angustias Izquierdo García
 * @brief 
 * @version 0.1
 * @date 2021-01-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __ALMACEN_RUTAS__
#define __ALMACEN_RUTAS__
#include <iostream>
#include <fstream>
#include <set>
#include <list>
#include<iterator>
#include "Ruta.h"
using namespace std;

/**
 * @brief T.D.A Almacen_Rutas
 * 
 * 
 * Una instancia @e c del tipo de datos abstacto @c Almacen_Rutas es un objeto con
 * dos campos, una lista de @c Rutas y un código asociado a la ruta
 * 
 * Un ejemplo de su uso:
 * @include Almacen_Rutas
 * 
 * 
 */

class Almacen_Rutas{

/**
 * @page repConjunto Rep del TDA Almacen_Rutas
 * 
 * @section invConjunto Invariante de la representación
 * 
 * No puede haber dos rutas con el mismo codigo
 * 
 * @section faConjunto Función de abstraccion
 * 
 * rep.almacen[0]
 * rep.almacen[1]
 * rep.almacen[2]
 * ...
 * 
 * 
 */

private:

list<Ruta> almacen;

public:

/**
 * @brief Constructor por defecto.
 * 
 */
Almacen_Rutas();

/**
 * @brief Obtenemos la ruta asociada al código que recibe como argumento
 * 
 * @param tipo 
 * @return Ruta 
 */
Ruta GetRuta( string & tipo);

/**
 * @brief Constructor de copia
 * 
 * @param alr 
 */
Almacen_Rutas(const Almacen_Rutas & alr);


/**
 * @brief Operador de salida
 * 
 * @param os 
 * @param r 
 * @return ostream& 
 */
friend ostream & operator<<(ostream & os, Almacen_Rutas & r);

/**
 * @brief Operador de asignación.
 * 
 * @param alr Asigna alr a (*this)
 * @return Almacen_Rutas& 
 */
Almacen_Rutas & operator=(const Almacen_Rutas & alr);

/**
 * @brief Inserta una ruta en el almacén
 * 
 * @param r 
 */
void InsertarRuta(const Ruta & r);

/**
 * @brief Vacía el objeto
 * 
 */
void Clear();

/**
 * @brief Operador de entrada. 
 * 
 * @param is 
 * @param r 
 * @return istream& 
 */
friend istream & operator>>(istream & is, Almacen_Rutas & r);

class iterator{
	 private:
	list<Ruta>::iterator it;

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
	 Ruta & operator *(){
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

    friend class  Almacen_Rutas;

	};

	class const_iterator{
	 private:
	list<Ruta>::const_iterator it;

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
	const Ruta & operator *()const{
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

    friend class  Almacen_Rutas;

	};
		    


	Almacen_Rutas::iterator begin(){
		iterator i;
		i.it = almacen.begin();

		return i;
	}

	Almacen_Rutas::iterator end(){
		iterator i;
		i.it = almacen.end();

		return i;
	}

	Almacen_Rutas::const_iterator begin()const{
		const_iterator i;
		i.it = almacen.begin();

		return i;


	}

	Almacen_Rutas::const_iterator end()const{
		const_iterator i;
		i.it = almacen.end();

		return i;

	}

};


#endif



