/**
 * @file Ruta.cpp
 * @author María de las Angustias Izquierdo García
 * @brief 
 * @version 0.1
 * @date 2021-01-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include "Ruta.h"
using namespace std;

Ruta::Ruta(){

    codigo = "";


}

Ruta::Ruta(const Punto & p){

ruta.push_front(p);

}

void Ruta::Copiar(const Ruta & R){

ruta.assign(R.ruta.begin(),R.ruta.end());
codigo = R.codigo;

}


void Ruta::Borrar(){

this->ruta.erase(ruta.begin(),ruta.end());

}

const string Ruta::GetCodigo()const{
                      
return codigo;

}


Ruta & Ruta::operator=(const Ruta & p){

if(this!=&p){
ruta = p.ruta;
codigo = p.codigo;
}

return *this;
}

void Ruta::AsignaRuta(const list<Punto> & p){

ruta = p;

}

void Ruta::AsignaCodigo(const string & c){

codigo = c;

}



//FUNCIONA
istream & operator>>(istream & is, Ruta & r){

string cod;
int tam;
Punto p;

is>>cod;
r.AsignaCodigo(cod);
is>>tam;

for(int i=0;i<tam;i++){

is>>p;

r.ruta.push_back(p);

p.Clear();
}

return is;


}



//FUNCIONA
ostream & operator<<(ostream & os, Ruta & r){

os<<r.codigo<<"\t";

list<Punto>::const_iterator it;

for(it=r.ruta.begin();it!=r.ruta.end();++it){
os<<(*it)<<"\t";
}
os<<endl;

return os;
}


//FUNCIONA
bool Ruta::EstaPunto(const Punto & p){

    bool esta = false;
    list<Punto>::const_iterator it;

		for (it=ruta.begin();it!=ruta.end(); ++it){
			if(*it==p)
				esta = true;			 
		}

		return esta;



}




//FUNCIONA
void Ruta::InsertarPunto(const Punto & p){

ruta.insert(ruta.end(),p);

}

void Ruta::Clear(){

codigo.erase();
ruta.clear();

}