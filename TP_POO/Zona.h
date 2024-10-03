
#ifndef TP_ZONA_H
#define TP_ZONA_H

#include "utils.h"

#include "Animal.h"
#include "Alimento.h"

class Zona {

public:
    Zona(int linha, int coluna);
    Zona(const Zona& zona);
    Zona *duplica();
    Zona &operator=(const Zona &zona);
    ~Zona();

    //ANIMAIS
    bool adicionaAnimal(Animal* a);
    bool removeAnimal(int id);
    void mataAnimal(int id);

    //ALIMENTOS
    void adicionaAlimento(Alimento* a);
    void removeAlimento(int id);

    const string getAsString() const;

    const vector<Animal*> &getAnimais() const;
    void setAlimento(Alimento* alimento);
    Alimento *getAlimento() const;

private:
    Alimento* alimento;
    vector<Animal*> animais;
    int linha, coluna;

};


#endif //TP_ZONA_H
