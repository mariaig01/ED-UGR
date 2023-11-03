/**
 * @file Punto.cpp
 * @author María de las Angustias Izquierdo García
 * @brief 
 * @version 0.1
 * @date 2021-01-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "Punto.h"
#include <cstdlib>

using namespace std;

 Punto::Punto(){

latitud = 0;
longitud = 0;
}

Punto::Punto( double lat, double lon){

longitud= lon;
latitud= lat;

}

Punto::Punto(const Punto & p){

longitud = p.longitud;
latitud = p.latitud;

}

Punto & Punto::operator=(const Punto & p){

if(this!=&p){
longitud = p.longitud;
latitud = p.latitud;
}

return (*this);

}

const double Punto::GetLongitud()const{

return longitud;
}

const double Punto::GetLatitud()const{

return latitud;

}

const bool Punto::operator==(const Punto &P)const{

return (latitud==P.latitud && longitud==P.longitud);

}

bool Punto::operator==(const Punto &P){

return (latitud==P.latitud && longitud==P.longitud);

}

ostream & operator<<(ostream &os,const Punto & p){
	  
	os<<"("<<p.latitud<<','<<p.longitud<<")"<<"\t";
	return os;
}	

void Punto::SetLatitud( double lat){

	latitud = lat;
}

void Punto::SetLongitud(double lon){

	longitud = lon;
}



 istream & operator>>(istream & is, Punto & g){

	 double lon,lat;
	string lat_,lon_;
	string cadena;
	char c;
	
	is>>c;
	if(c=='('){
		cadena.push_back(c);
		while(c!=')'){
		is>>c;
		cadena.push_back(c);
		}

	}


	int pos = cadena.find(",");

	for(int i=1;i<pos;i++){
		if(cadena.at(i)!=' '){
		lat_.push_back(cadena.at(i));
		}
	}

	char latitud[lat_.size()+1];
	strcpy(latitud, lat_.c_str());

	lat = atof(latitud);

	for(int i=pos+1;i<cadena.size();i++){
		if(cadena.at(i)!=' '){
		lon_.push_back(cadena.at(i));
		}
	}

	char longitud[lon_.size()+1];
	strcpy(longitud, lon_.c_str());

	lon = atof(longitud);



	g.latitud = lat;
	g.longitud = lon;


	return is;
 }



void Punto::Clear(){

latitud = 0;
longitud = 0;

}















