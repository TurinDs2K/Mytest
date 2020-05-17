#ifndef CONTADOR_H
#define CONTADOR_H
#include <iostream>
#include <iomanip>
using std::string;
using std::cin;
using std::cout;
using std::setfill;
using std::setw;

class Contador
{
private:
    string codigo;
    float l_anterior;
    float l_actual;
    float Consumo;

public:
    Contador();
    Contador(string,float,float,float);
    ~Contador();
    void Leer();
    void ImprimirCLI();
    void Borde();


    string getCodigo() const;
    void setCodigo(string value);

    float getL_anterior() const;
    void setL_anterior(float value);

    float getL_actual() const;
    void setL_actual(float value);

    float getConsumo() const;
    void setConsumo(float value);

};

#endif // CONTADOR_H
