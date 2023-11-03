/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * @file   Imagen.h
 * @author angustias
 *
 * Created on 16 de noviembre de 2020, 1:07
 */

#ifndef IMAGEN_H
#define IMAGEN_H




typedef unsigned char byte;

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Imagen {
public:
    Imagen();
    
    //Con este constructor construimos la matriz2D a partir del vector1D
    Imagen(int f, int c,unsigned char *v);
    
    Imagen(const Imagen& orig);
    virtual ~Imagen();
    Imagen(int f, int c);
    int num_filas() const;
    int num_columnas() const;
    void asigna_pixel(int fila, int col, byte valor);
    byte valor_pixel (int fila, int col) const;
    void UmbralizarEscala(int T1, int T2, const char *nombreE, const char  *nombreS);
    void Zoom(const char *nombreE, const char  *nombreS,int x_1,int y_1,int x_2,int y_2);
    
    void reserve(int f,int c);
    Imagen & operator=( const Imagen & i) ;
    void copiar(const Imagen & i);
    void AumentoContraste(const char *nombreE, const char  *nombreS,int min,int max);
    void ConversionRGBGris(const char *nombreE, const char  *nombreS);
    void LiberarMemoria();
    
    //No se si son const o no
    byte GetMax();
    byte GetMin();
    //Devuelve un vector1D de pixeles. Pasamos la mtatriz2D a vector1D
    unsigned char *Flat();

    
private:

    int filas;
    int cols;
    byte **img;
    
    
};



#endif /* IMAGEN_H */

