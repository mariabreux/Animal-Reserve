
#ifndef TP_ALIMENTO_H
#define TP_ALIMENTO_H

#include "utils.h"

class Reserva;
class Alimento {

public:
    Alimento(char letra, int valorNutritivo, int valorToxico, int duracaoVida, Reserva &reserva, int x, int y);
    Alimento(const Alimento &alimento);
    virtual Alimento* duplica();
    virtual ~Alimento();

    virtual void passaInstante() = 0;

    virtual string getAsString() const;

    char getLetra() const;

    int getId() const;

    const string &getTipoAlimento() const;

    int getValorNutritivo() const;

    int getValorToxico() const;

    int getDuracaoVida() const;

    const vector<string> &getCheiro() const;

    int getX() const;

    int getY() const;

    void setConsumido(bool consumido);

    bool isConsumido() const;

protected:
    char letra;
    int id;
    string tipoAlimento;
    int valorNutritivo;
    int valorToxico;
    int duracaoVida;
    bool consumido;
    vector<string> cheiro;
    Reserva &reserva;
    int x;
    int y;


};


#endif //TP_ALIMENTO_H
