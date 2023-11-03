#ifndef __PAIS__
#define __PAIS__
#include "Punto.h"
class Pais{
  private:
    Punto p;
    string pais;
    string bandera;
    
  public:

    /**
     * @brief Constructor por defecto
     * 
     */
    Pais(){}

    /**
     * @brief Devuelve el punto del objeto
     * 
     * @return Punto 
     */
    Punto GetPunto()const { return p;}

    /**
     * @brief Obtenemos el pais
     * 
     * @return string 
     */
    string GetPais()const{ return pais;}

    /**
     * @brief Obtenemos la bandera del país
     * 
     * @return string 
     */
    string GetBandera()const{ return bandera;}
    
    /**
     * @brief Operador menor
     * 
     * @param P 
     * @return true 
     * @return false 
     */
    bool operator<(const Pais &P)const{
	return pais<P.pais;
    }	

    /**
     * @brief Operador de igualdad constante
     * 
     * @param P 
     * @return true 
     * @return false 
     */
    bool operator==(const Pais &P)const{
	return pais==P.pais;
    }

    /**
     * @brief Operador de igualdad
     * 
     * @param P 
     * @return true 
     * @return false 
     */
    bool operator==(const Punto &P)const{
	return p==P;
    }

    /**
     * @brief Operador de entrada
     * 
     * @param is 
     * @param P 
     * @return istream& 
     */
    friend istream & operator>>(istream & is, Pais & P){
 
    double lat,lng;
	is>>lat>>lng>>P.pais>>P.bandera;
	
    P.p=Punto(lat,lng);
	return is;
    }

    /**
     * @brief Operador de salida
     * 
     * @param os 
     * @param P 
     * @return ostream& 
     */
    friend ostream & operator<<(ostream & os, const Pais &P){
	os<<P.p<<" "<<P.pais<<" "<<P.bandera<<endl;
	return os;
    }
};
#endif