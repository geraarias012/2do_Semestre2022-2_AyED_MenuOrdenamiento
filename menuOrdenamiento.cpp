#include <iostream>
#include <stdlib.h>
#define max 6

using namespace std;

class menuOrdenamiento
{
private:
    int datos[max];
public:
    void llenado();
    void mostrar();
    void insercion();
    void seleccion();
    void burbuja();
    void burbujabidireccional();
    void mezcla(int, int, int);
    void mezcla_sort(int, int);
    menuOrdenamiento();
    ~menuOrdenamiento();
};
menuOrdenamiento::menuOrdenamiento(){}
menuOrdenamiento::~menuOrdenamiento(){}

void menuOrdenamiento::llenado()
{
    int i, dato;
    cout<<"\nINTRODUZCA LOS DATOS DEL ARREGLO:\n";
    for (i=0;i<max;i++)
    {
        cout<<"POSICION ["<<i+1<<"]: ";
        cin>>dato;
        datos[i]=dato;

}
}

void menuOrdenamiento::mostrar()
{
    int i;
    cout<<"\nLOS VALORES ORDENADOS DEL ARREGLO SON:\n";
    for(i=0;i<max;i++)
    {
        cout<<"POSICION ["<<i+1<<"]: "<<datos[i]<<"\n";
    }
    cout<<"\n"<<endl;
}

void menuOrdenamiento::insercion()
{
    int i,pos,aux;
    for (i=0;i<=max;i++)
    {
        pos=i;
        aux = datos[i];
        while((pos>0)&&(datos[pos-1]>aux))
        {
            datos[pos]=datos[pos-1];
            pos--;
        }
        datos[pos]=aux;
    }
}

void menuOrdenamiento::seleccion()
{
  int menor, inicio = 0, posAct, posInter;
  while (inicio <= 4)
    {
    menor=datos[inicio];
    posAct=inicio+1;
    posInter=inicio;
    do {
      if ((menor) > (datos[posAct])) {
        posInter=posAct;
        menor=datos[posInter];
      }
      posAct++;
    }while(posAct<=max);
    datos[posInter]=datos[inicio];
    datos[inicio]=menor;
    inicio++;
  }
}


void menuOrdenamiento::burbuja()
{
    int aux;
    for (int i=0;i<max;i++)
    {
        for (int j=0;j<max;j++)
        {
            if(datos[j]>datos[j+1])
            {
                aux=datos[j+1];
                datos[j+1]=datos[j];
                datos[j]=aux;
            }
        }
    }
}

void menuOrdenamiento::burbujabidireccional()
{
int aux=0, a=5, b=0, c=0, d=0;
  	do
    {
    do
    {
      if ((datos[b]>(datos[b+1]))&&(b < 5))
    {
        aux=datos[b];
        datos[b]=datos[b+1];
        datos[b+1]=aux;
        c=b;
    }
      b++;
    } while(b<=a);
    a=c;
      do
      {
        if ((datos[b]<(datos[b-1]))&&(b > 0))
        {
          aux=datos[b];
          datos[b]=datos[b-1];
          datos[b-1]=aux;
          c=b;
        }
        b--;
      } while (b>=d);
      d=c;
    }while (a>d);

}

void menuOrdenamiento::mezcla_sort(int izquierda, int derecha)
{
    int medio;
    if(izquierda<derecha)
    {
        medio=(izquierda+derecha)/2;
        mezcla_sort(izquierda,medio);
        mezcla_sort(medio+1,derecha);
        mezcla(izquierda,medio,derecha);
    }
}

void menuOrdenamiento::mezcla(int izquierda, int medio, int derecha)
{
    int h,i,j,k,datosAux[max];
    h=izquierda;
    i=izquierda;
    j=medio+1;
    while( (h<=medio) && (j<=derecha) )
    {
        if(datos[h]<=datos[j])
        {
            datosAux[i]=datos[h];
            h++;
        }
        else
        {
            datosAux[i]=datos[j];
            j++;
        }
        i++;
    }
    if(h>medio)
    {
        for(k=j;k<=derecha;k++)
        {
            datosAux[i]=datos[k];
            i++;
        }
    }
    else
    {
        for(k=h;k<=medio;k++)
        {
            datosAux[i]=datos[k];
            i++;
        }
    }
    for(k=izquierda;k<=derecha;k++){
        datos[k]=datosAux[k];
    }
}

int main()
{
    int op;
    menuOrdenamiento obj1;
    do
    {
    cout<<"METODOS DE ORDENAMIENTO:\n1)INSERCION\n2)SELECCION\n3)BURBUJA\n4)BURBUJA BIDIRECCIONAL\n5)MEZCLA\n6)SALIR\n\nINTRODUZCA LA OPCION DESEADA: ";
    cin>>op;
    switch(op)
    {
    case 1:
        {
        obj1.llenado();
        obj1.insercion();
        obj1.mostrar();
        system("pause");
        break;
        }
    case 2:
        {
        obj1.llenado();
        obj1.seleccion();
        obj1.mostrar();
        system("pause");
        break;
        }
    case 3:
        {
        obj1.llenado();
        obj1.burbuja();
        obj1.mostrar();
        system("pause");
        break;
        }
    case 4:
        {
        obj1.llenado();
        obj1.burbujabidireccional();
        obj1.mostrar();
        system("pause");
        break;
        }
    case 5:
        {
        obj1.llenado();
        obj1.mezcla_sort(0,max);
        obj1.mostrar();
        system("pause");
        break;
        }
    case 6:
        {
        cout<<"\nADIOS\n"<<endl;
        system("pause");
        break;
        }
    default:
        {
            cout<<"\nOPCION NO VALIDA"<<endl;
            system("pause");
        }
    }
    system("cls");
    }while(op!=6);
    return 0;
}
