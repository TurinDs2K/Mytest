#include "contador.h"


Contador::Contador()
{
    this->codigo="";
    this->l_anterior=0;
    this->l_anterior=0;
    this->Consumo=0;
}
Contador::Contador(string cod,float lan,float lact,float con){
    this->codigo=cod;
    this->l_anterior=lan;
    if( this->l_anterior < lact ){
        this->l_actual=lact;
    }else{
        cout<<"La Lectura Actual NO debe ser Menor que la Lectura Anterior!!!\n"
            <<"Se estableceran ambos valores en cero!!!\n"
            <<"Favor utilizar la opción de Modificar para realizar los cambios pertinentes!!!\n";
        this->l_anterior = 0;
        this->l_actual = 0;
    }
    this->Consumo=con;
}

Contador::~Contador(){}



string Contador::getCodigo() const
{
    return codigo;
}

void Contador::setCodigo(string value)
{
    codigo = value;
}

float Contador::getL_anterior() const
{
    return l_anterior;
}

void Contador::setL_anterior(float value)
{
    l_anterior = value;
}

float Contador::getL_actual() const
{
    return l_actual;
}

void Contador::setL_actual(float value)
{
    l_actual = value;
}

float Contador::getConsumo() const
{
    return Consumo;
}

void Contador::setConsumo(float value)
{
    Consumo = value;
}

void Contador::Leer(){
    cout<<"Ingrese El Codigo";
    getline(cin,codigo);
    cout<<"Ingrese la Lectura Anterior";
    cin>>this->l_anterior;
    cout<<"Ingrese la Lectura Actual";
    cin>>this->l_actual;
    this->Consumo = this->l_actual-this->l_anterior;
    cin.ignore();
}

void Contador::ImprimirCLI(){
    cout<<"|"<<setfill(' ')<<setw(9)<<codigo
        <<"|"<<setfill(' ')<<setw(10)<<l_anterior
        <<"|"<<setfill(' ')<<setw(10)<<l_actual
        <<"|"<<setfill(' ')<<setw(15)<<Consumo<<"|\n";
}
void Contador::Borde()
{
    cout<<"+---------+----------+----------+---------------+\n";
}
