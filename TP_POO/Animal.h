
#ifndef TP_ANIMAL_H
#define TP_ANIMAL_H

#include "utils.h"

class Reserva;
class Alimento;

class Animal {
public:

    Animal(char letra, int peso, int fome, int saude, int percecao, int duracaoVida, Reserva &reserva, int x, int y);
    Animal(const Animal &animal);
    virtual ~Animal();
    virtual Animal *duplica();

    virtual void passaInstante() = 0;

    void aumentaSaude(int valor);
    void diminuiSaude(int valor);

    Animal *procuraMaisPesado(vector<Animal*> animais);


    int getPeso() const;
    int getFome() const;
    int getSaude() const;
    int getId() const;
    int getDuracaoVida() const;
    const char &getLetra() const;
    const string &getEspecie() const;
    virtual string getAsString() const;
    int getX() const;
    int getY() const;
    bool isAvancouInstante() const;
    void setAvancouInstante(bool avancouInstante);

    int getVn() const;
    int getVt() const;

protected:

    char letra;
    int id;
    int peso;
    int fome;
    int saude;
    int percecao;
    string especie;
    int duracaoVida;
    int instante;
    int x;
    int y;
    Reserva &reserva;
    bool avancouInstante;
    int vN, vT;


};


#endif //TP_ANIMAL_H
