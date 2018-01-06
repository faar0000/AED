#include<iostream>
#include<fstream>
#include <cstdio>
#include "CImg.h"
using namespace std;
using namespace cimg_library;

template<class T>
class NodoE
{
	public:
        T m_Dato;
		NodoE<T>* m_pSigFil;
		NodoE<T>* m_pSigCol;
		int m_Fil;
		int m_Col;
		NodoE(T d, int f, int c):m_Dato(d), m_Fil(f),m_Col(c), m_pSigFil(0), m_pSigCol(0) {};
};


template<class T>
class Matrix
{
	private:
		NodoE<T> ** m_Filas;
		NodoE<T>  ** m_Colums;
		int     NFil;
		int NCol;
	public:
	    Matrix();
		Matrix(int f, int c) {
		  NFil = f;
		  NCol = c;
		  m_Filas = new NodoE<T> * [f];
		  m_Colums = new NodoE<T> * [c];

	    for( int  i=0;i<f;i++)

                   m_Filas[i]=0;
           for(int j=0;j<c;j++)
               m_Colums[j]=0;

       }

       bool find_fil(int f, int c, NodoE<T> ** & p)
       {
                p = &(m_Colums[c]);
                while(*p)
                {
                      if ((*p)->m_Fil == f)  return true;
                      if ((*p)->m_Fil > f )  return false;
                      p = &((*p)->m_pSigFil);
                }
             return false;

       }


       bool find_col(int f, int c, NodoE<T> ** & p)
       {
                p = &(m_Filas[f]);
                while(*p)
                {
                      if ((*p)->m_Col == c)  return true;
                      if ((*p)->m_Col > c )  return false;
                      p = &((*p)->m_pSigCol);
                }
             return false;

       }

       void Add(T d, int x, int y)
			{
				      NodoE<T> ** p;
							NodoE<T> ** q;
							bool ff = find_fil(x,y,q);
							bool fc = find_col(x,y,p);
							if(!ff)
							{
                    NodoE<T> * pNuevo = new NodoE<T>(d,x,y);
										pNuevo->m_pSigCol= *p;
										pNuevo->m_pSigFil = *q;
										*p= *q = pNuevo;

							}
			}

			 void  Print( ostream & os)

			 {
				    NodoE<T> ** p;
				    for(int i =0;i< NFil; i++)
						{
							 os<<endl;
						   for( int j =0;j<NCol; j++)
							  	if (find_fil(i,j,p))
										 os<<(*p)->m_Dato<<" ";
							    else
										  os<<"0 ";
						}
			 }


};


CImg<unsigned char> Binarizar(char const *nombre, int valor_umbral){
    CImg<unsigned char> imagen(nombre);
    unsigned char r,g,b,promedio;
    CImg<int> imagenBW(imagen.width(),imagen.height(),1,1);
    for(int x=0;x<imagenBW.width();x++){
        for(int y=0;y<imagenBW.height();y++){
                r=imagen(x,y,0,0);
                g=imagen(x,y,0,1);
                b=imagen(x,y,0,2);
                promedio=((r+g+b)/3);

                if( promedio>=valor_umbral)
                    imagenBW(x,y,0,0)=255;

                if( promedio<valor_umbral){
                    imagenBW(x,y,0,0)=0;
                }
        }
    }
    return imagenBW;
}

template <class T>
 void GuardarImg(Matrix<T> &M,CImg<unsigned char> imagen){
     for(int x=0;x<imagen.width();x++){
        for(int y=0;y<imagen.height();y++){
                if(imagen(x,y,0,0)==0){
                    M.Add(1,y,x);
                }
        }
    }
};

int  main()
{
    CImg<unsigned char> imagen;
    imagen=(Binarizar("imagen2.bmp",120));
    imagen.save("imagen2gris.bmp");
    Matrix<int> A(imagen.height(),imagen.width());
    GuardarImg(A,imagen);
    A.Print(cout);
    ofstream file("salida.txt");
    A.Print(file);
    imagen.display("Imagen");
    return 0;
}







