#ifndef __PAISES__
#define __PAISES__
#include "Pais.h"
#include <set>
using namespace std;
class Paises{
  private:
    set<Pais> datos;
  public:

	/**
	 * @brief Constructor por defecto
	 * 
	 */
      Paises(){}

	  /**
	   * @brief Inserta un pais en el conjunto de paises
	   * 
	   * @param P 
	   */
      void Insertar(const Pais &P){
	  datos.insert(P);
      }

	  /**
	   * @brief Borra un país del conjunto de paises
	   * 
	   * @param P 
	   */
      void Borrar(const Pais &P){
	  datos.erase(P);
      }
      
      class const_iterator;
	class iterator{
	private:
	    set<Pais>::iterator p;
	public:
	    iterator(){}
	    iterator & operator ++(){
		++p;
		return * this;
	    }
	    
	    iterator & operator --(){
		--p;
		return * this;
	    }
	    bool operator ==(const iterator  & it){
		return it.p ==p;
	    }
	    bool operator !=(const iterator  & it){
		return it.p !=p;
	    }
	     const Pais & operator*()const{
		  return *p;
	    }
	    friend class Paises;
	    friend class const_iterator;
	};    
	class const_iterator{
	private:
	    set<Pais>::const_iterator p;
	public:
	    const_iterator(){}
	    const_iterator(const iterator & it){
	      p=it.p;
	      
	    }
	    const_iterator & operator=(const iterator & it){
		p=it.p;
		return *this;
	    }	
	    const_iterator & operator ++(){
		++p;
		return * this;
	    }
	    
	    const_iterator & operator --(){
		--p;
		return * this;
	    }
	    bool operator ==(const const_iterator  & it){
		return it.p ==p;
	    }
	    bool operator !=(const const_iterator  & it){
		return it.p !=p;
	    }
	    const Pais &operator*()const {
		  return *p;
	    }
	    friend class Paises;
	   
	};
	iterator begin(){
	  iterator it;
	  it.p = datos.begin();
	  return it;
	}  
	
	const_iterator begin()const{
	  const_iterator it;
	  it.p = datos.begin();
	  return it;
	}
	iterator end(){
	  iterator it;
	  it.p = datos.end();
	  return it;
	}
	const_iterator end()const{
	  const_iterator it;
	  it.p = datos.end();
	  return it;
	}
	iterator find(const Pais &p){
	    iterator it;
	    set<Pais>::iterator i;
	    for (i=datos.begin(); i!=datos.end() && !((*i)==p);++i);
	    it.p=i;
	    return it;
	}
	iterator find(const Punto &p){
	    iterator it;
	    set<Pais>::iterator i;
	    for (i=datos.begin(); i!=datos.end() && !((*i)==p);++i);
	    it.p=i;
	    return it;
	}

	/**
	 * @brief Operador de entrada
	 * 
	 * @param is 
	 * @param R 
	 * @return istream& 
	 */
	friend istream & operator>>(istream & is, Paises & R){
	      Paises rlocal;
	      //leemos el comentario
	      if (is.peek()=='#'){
		string a;
		getline(is,a);
	      }	
	      
	      Pais P;
	      while (is>>P){
		  rlocal.Insertar(P);
		  
	      }
	      R=rlocal;
	      return is;
	}

	/**
	 * @brief Operador de salida
	 * 
	 * @param os 
	 * @param R 
	 * @return ostream& 
	 */
	friend ostream & operator<<(ostream & os, const Paises &R){
	  
	    Paises::const_iterator it;
	    for (it=R.begin(); it!=R.end(); ++it){
		os<<*it<<"\t";
	    }
	    return os;
	}
};
#endif
