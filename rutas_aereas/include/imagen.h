#ifndef __IMAGEN_H
#define __IMAGEN_H
#include "imagenES.h"
#include <cassert>
#include <iostream>
#include <string>
enum Tipo_Pegado {OPACO, BLENDING};
using namespace std;
struct Pixel{
  unsigned char r,g,b;
  unsigned char transp; //0 no 255 si
};  
class Imagen{

  private:

    Pixel ** data;
    int nf,nc;
    void Borrar();
    void Copiar(const Imagen &I);

  public:

  /**
   * @brief Constructor por defecto
   * 
   */
   Imagen();
   
   /**
    * @brief Constructor con parámetros.
    * Construye un objeto con f filas y c columnas
    * 
    * @param f 
    * @param c 
    */
   Imagen(int f,int c);
   
   /**
    * @brief Constructor de copia
    * 
    * @param I 
    */
   Imagen(const Imagen & I);
   
   /**
    * @brief Operador de asignación
    * 
    * @param I 
    * @return Imagen& 
    */
   Imagen & operator=(const Imagen & I);
   
   /**
    * @brief Destructor
    * 
    */
   ~Imagen();
   
   //set y get
   /**
    * @brief Devuelve un pixel en la posicion [i][k]. 
    * Devuelve un valor por referencia por lo que puede 
    * asignar un pixel en la posicion [i][j]
    * 
    * @param i 
    * @param j 
    * @return Pixel& 
    */
   Pixel & operator ()(int i,int j);
   
   /**
    * @brief Devuelve un pixel en la posicion [i][k]
    * 
    * @param i 
    * @param j 
    * @return const Pixel& 
    */
   const Pixel & operator ()(int i,int j)const;
   
   /**
    * @brief Escribe la imagen
    * 
    * @param nombre 
    */
   void EscribirImagen(const char * nombre);
   
   /**
    * @brief Lee la imagen
    * 
    * @param nombre 
    * @param nombremascara 
    */
   void LeerImagen (const char *nombre,const string &nombremascara="");

  /**
   * @brief Pone transp a 0 si es distinto de 0 y de 255
   * 
   */
   void LimpiarTransp();

   /**
    * @brief Número de filas
    * 
    * @return int 
    */
   int num_filas()const{return nf;}

   /**
    * @brief Número de columnas
    * 
    * @return int 
    */
   int num_cols()const{return nc;}

   /**
    * @brief Inserta una imagen
    * 
    * @param posi FIla en la que se inserta
    * @param posj Columna en la que se inserta
    * @param I Imagen a insertar
    * @param tippegado Tipo de pegado
    */
   void PutImagen(int posi,int posj, const Imagen &I,Tipo_Pegado tippegado=OPACO);

   /**
    * @brief Extrae una imagen de las posiciones que recibe como parámetro
    * 
    * @param posi 
    * @param posj 
    * @param dimi 
    * @param dimj 
    * @return Imagen 
    */
   Imagen ExtraeImagen(int posi,int posj,int dimi,int dimj);
};   
   
#endif