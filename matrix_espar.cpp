#include<iostream>
#include<fstream>
using namespace std;

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




int  main() 
{
	     Matrix<int> A(100,100);
	     for(int i=0;i<10;i++)
				  A.Add(1,i,i);

       A.Print(cout);
			 ofstream file("salida.txt");
			 A.Print(file);
       return 0;
}







