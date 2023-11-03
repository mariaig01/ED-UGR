/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Imagen.cpp
 * Author: angustias
 * 
 * Created on 16 de noviembre de 2020, 1:07
 */

#include "/home/angustias/Escritorio/TDAImagen/inc/Imagen.h"
#include "/home/angustias/Escritorio/TDAImagen/inc/imagenES.h"

#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include <tgmath.h>
#include <cmath>

using namespace std;

Imagen::Imagen() {
    
    filas = 0;
    cols = 0;
    
    img = nullptr;
    
}

Imagen::Imagen(int f, int c, unsigned char* v){

    filas = f;
    cols = c;
    img = new byte*[filas];

    int n=0;
    
    for (int i=0;i<filas;i++){
    img[i] = new byte[cols];
 
    }
    
    
    
    for(int i=0;i<filas;i++){
        
        for(int j=0;j<cols;j++){
        
          
            img[i][j]=v[n];
        
            n++;
            
           
        }
        n++;
    }
    
    
}

Imagen::Imagen(int f, int c){

    filas = f;
    cols = c;
    
    reserve(filas,cols);




}



Imagen::Imagen(const Imagen& orig) {
    
    filas = orig.filas;
    cols = orig.cols;
    
    img = new byte*[filas];
    
    for(int i=0;i<filas;i++){
    
        img[i] = new byte [cols];
    
        copy_n(orig.img[i],orig.cols,img[i]);
    }
    
    
    
    
}

Imagen::~Imagen() {
    
    if(img!=nullptr){
    
        for(int i=0;i<filas;i++)
            delete[] img[i];
            
            delete[] img;
    
    }
    
}

int Imagen::num_filas() const{

    return filas;

}

int Imagen::num_columnas() const{

    return cols;

}

void Imagen::asigna_pixel(int fila, int col, byte valor){

    img[fila][col]=valor;

}

byte Imagen::valor_pixel(int fila, int col) const{

    return img[fila][col];
    
}




Imagen & Imagen::operator =(const Imagen& i){

    cols = i.cols;
    filas = i.filas;
    
    if(this!=&i){
        if(img!=nullptr){
            for(int i=0;i<filas;i++)
                delete[] img[i];
                delete[] img;
                
                reserve(i.filas,i.cols);
                copiar(i);
        
        }
    }
    return (*this);
}


void Imagen::UmbralizarEscala(int T1, int T2, const char *nombreE, const char *nombreS){

    unsigned char *v = new unsigned char[filas*cols];  
    TipoImagen tipo;
    tipo = LeerTipoImagen(nombreE);
    int nf=0,nc=0;
    
    if(tipo == IMG_PGM){
    
        v = LeerImagenPGM(nombreE,nf,nc);
    
    }
    
    if(tipo == IMG_PPM){
    
        v = LeerImagenPPM(nombreE,nf,nc);
      
    }
    
    
    //NO se si aqui se inicializa con los valores 0 o con los que ha cogido de
    //la funcion LeerImagenPPM o LeerImagenPGM
    //COMPROBAR
   Imagen O(nf,nc,v);
   
   *this = O;
    
    for(int i=0;i<filas;i++){
        for(int j=0;j<cols;j++){
        
            if(img[i][j]<=T1 || img[i][j]>=T2){
            
                img[i][j]=255;
            
            }
        }
    }
   
   //Lo guardamos en el fichero
   //Con el metodo flat pasamos de matriz2D a vector1D
   
   unsigned char *vs = new unsigned char[filas*cols];  
     vs = this->Flat();
   
     if(tipo == IMG_PGM){
    
         EscribirImagenPGM(nombreS,vs,filas,cols);
    }
    
    if(tipo == IMG_PPM){
    
        EscribirImagenPPM(nombreS,vs,filas,cols);
      
    }
    

}

void Imagen::Zoom(const char* nombreE, const char* nombreS, int x_1, int y_1, int x_2, int y_2){

    unsigned char *v = new unsigned char[filas*cols];  
    /*TipoImagen tipo;
    tipo = LeerTipoImagen(nombreE);*/
    int nf=0,nc=0;
    
   /* if(tipo == IMG_PGM){
    
        v = LeerImagenPGM(nombreE,nf,nc);
    
    }
    */
    v = LeerImagenPGM(nombreE,nf,nc);
    
    /*if(tipo == IMG_PPM){
    
        v = LeerImagenPPM(nombreE,nf,nc);
      
    }*/
    
  
   Imagen O(nf,nc,v);
   
   
   int f=x_2-x_1;
   int c=y_2-y_1;
   
   Imagen T((2*f)+1,(2*c)+1);
   int n=0,n2=0;
   unsigned char m[f][c];
   
   //Con este bucle nos quedamos con la imagen pequeña
   for(int i=x_1;i<=x_2;i++){
      
       for(int j=y_1;j<=y_2;j++){
       
           m[n][n2]=O.img[i][j];
           n2++;
       }
       n++;
   }
   
   
   //Hacemos hueco para interpolar entre columnas
   for(int i=0;i<f;i++){
       n++;
       for(int j=0;j<T.cols;j+2){
       
           T.img[i][j]=m[n][n2];
           n2++;
       }
       n++;
   }

   //Con este interpolamos sobre las columnas
   for(int i=0;i<f;i++){
       for(int j=1;j<T.cols;j+2){
       
           T.img[i][j]=round(((T.img[i][j--]+T.img[i][j])/2));
       
       }
   }
   
   //Hacemos hueco para interpolar entre filas
   
   for(int i=1;i<T.filas;i++){
       for(int j=0;j<T.cols;j++){
       
          
           T.img[i++][j]=T.img[i][j];
            T.img[i][j]=0;
       }
   
   }
   
   //Interpolamos con las filas
   
   for(int i=1;i<T.filas;i++){
       for(int j=0;j<T.cols;j++){
       
          
           T.img[i][j]=round(((T.img[i--][j]+T.img[i++][j])/2));
       }
   }
   
   //Ya tenemos la nueva matriz
   //La pasamos al fichero de salida

   *this = T;
   
unsigned char *vs = new unsigned char[filas*cols];  
     vs = this->Flat();
   
    /* if(tipo == IMG_PGM){
    
         EscribirImagenPGM(nombreS,vs,filas,cols);
    }*/
     
     EscribirImagenPGM(nombreS,vs,filas,cols);
    
    /*if(tipo == IMG_PPM){
    
        EscribirImagenPPM(nombreS,vs,filas,cols);
      
    }*/

     delete[] vs;
     delete[] v;
     O.LiberarMemoria();
     T.LiberarMemoria();
     
}


//NO SE SI HACER LAS FUNCIONES SOBRE EL OBJETO O O SOBRE OTRO
void Imagen::AumentoContraste(const char* nombreE, const char* nombreS, int min, int max){

  unsigned char *v = new unsigned char[filas*cols];  
    TipoImagen tipo;
    tipo = LeerTipoImagen(nombreE);
    int nf=0,nc=0;
    
    if(tipo == IMG_PGM){
    
        v = LeerImagenPGM(nombreE,nf,nc);
    
    }
    
    if(tipo == IMG_PPM){
    
        v = LeerImagenPPM(nombreE,nf,nc);
      
    }
    
     //NO se si aqui se inicializa con los valores 0 o con los que ha cogido de
    //la funcion LeerImagenPPM o LeerImagenPGM
    //COMPROBAR
   Imagen O(nf,nc,v);
   
   byte a = O.GetMin(), b = O.GetMax();
   byte cociente = ((max-min)/(b-a));
   
   for(int i=0;i<O.filas;i++){
       for(int j=0;j<O.cols;j++){
       
           double valor = min + ((cociente)*(O.img[i][j]-a));
           O.img[i][j]=round(valor);
       
       }
   }
   
   unsigned char *vs = new unsigned char[filas*cols];  
     vs = O.Flat();
   
     if(tipo == IMG_PGM){
    
         EscribirImagenPGM(nombreS,vs,O.filas,O.cols);
    }
    
    if(tipo == IMG_PPM){
    
        EscribirImagenPPM(nombreS,vs,O.filas,O.cols);
      
    }



}

void Imagen::reserve(int f, int c){

filas = f;
cols = c;
img = new byte*[filas];

    for (int i=0;i<filas;i++){
    img[i] = new byte[cols];
 
    }

}


void Imagen::copiar(const Imagen& i){

  filas = i.filas;                 
  cols = i.cols;
    
    for (int f = 0; f < filas; f++) {
        for (int c = 0; c < cols; c++)
            img[f][c] = i.img[f][c];
    }

}

unsigned char *Imagen::Flat(){

    unsigned char *v = new unsigned char[filas*cols];
    int n=0;

    for(int i=0;i<filas;i++){
        
        for(int j=0;j<cols;j++){
        
           
            v[n] = img[i][j];
            n++;
            
        }
        n++;
    }

    return v;

}

byte Imagen::GetMax(){
    
    byte max = 0;
    
    
for (int i =0; i < filas; i++){
        for (int j=0; j < cols;j++){

            if(img[i][j]>max)
                max=img[i][j];
        }
    }

    return max;

}

byte Imagen::GetMin(){

byte min = 255;
    
    
for (int i =0; i < filas; i++){
        for (int j=0; j < cols;j++){

            if(img[i][j]<min)
                min=img[i][j];
        }
    }

    return min;
}

void Imagen::LiberarMemoria(){

    if(img!=nullptr){
    
        for (int i = 0; i < filas; i++)
			delete [] img[i];
		delete [] img;

                img = nullptr;
    
    }
}


