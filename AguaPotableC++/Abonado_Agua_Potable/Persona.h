#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include <cstring>
#include <iomanip>
using std::string;
//#include <QMainWindow>

class Persona /*: public QMainWindow*/
{
private:
    char *Id = new char[15];
    string Nom;
    string Dir;
    char *Tel = new char[14];
    //Q_OBJECT
public:
    /*explicit Abonado(QWidget *parent = nullptr);

signals:

public slots:*/
    Persona();
    Persona(char*, string, string, char*);
    ~Persona();

    char *getId() const;
    void setId(char *value);
    string getNom() const;
    void setNom(const string &value);
    string getDir() const;
    void setDir(const string &value);
    char *getTel() const;
    void setTel(char *value);

    void Leer();
    void ImprimirCLI();
    void Borde();
};

#endif // PERSONA_H
