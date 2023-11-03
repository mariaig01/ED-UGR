/**
 * @file almacen_rutas.cpp
 * @author María de las Angustias Izquierdo García
 * @brief 
 * @version 0.1
 * @date 2021-01-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include <iostream>
#include <list>
#include <fstream>
#include <iterator>
#include "almacen_rutas.h"
#include "Punto.h"
#include "Ruta.h"

using namespace std;


Almacen_Rutas::Almacen_Rutas(){}


//FUNCIONA
Almacen_Rutas::Almacen_Rutas(const Almacen_Rutas & alr){

almacen = alr.almacen;

}

//FUNCIONA
Almacen_Rutas & Almacen_Rutas::operator=(const Almacen_Rutas & alr){

if(this!=&alr){
almacen = alr.almacen;
}

return *this;

}

ostream & operator<<(ostream & os, Almacen_Rutas & r){

list<Ruta>::iterator it;

for(it=r.almacen.begin();it!=r.almacen.end();++it){
os<<(*it)<<"\t";
os<<endl;
}

return os;
}
			      
//Funciona
istream & operator>>(istream & is, Almacen_Rutas & r){

string cadenamagica;
Ruta r1;


is>>cadenamagica;

if(cadenamagica=="#Rutas"){
        while(is>>r1){
        r.almacen.push_back(r1);
        r1.Clear();
        }

    }



return is;

}



//Funciona
Ruta Almacen_Rutas::GetRuta( string & tipo){

Ruta r1;
list<Ruta>::iterator it;
bool encontrado=false;

for(it=almacen.begin();it!=almacen.end() && !encontrado;++it)

if((*it).GetCodigo()==tipo){
r1=(*it);
encontrado=true;
}



return r1;
}

//Funciona
void Almacen_Rutas::InsertarRuta(const Ruta & r){


almacen.insert(almacen.end(),r);
}

void Almacen_Rutas::Clear(){

    almacen.clear();
}