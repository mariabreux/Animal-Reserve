
#ifndef TP_SIMULADOR_H
#define TP_SIMULADOR_H

#include "utils.h"
#include "Reserva.h"
#include "Animal.h"
#include <map>

class Simulador {

public:

    Simulador(Reserva &reserva);

    static void iniciaReserva(int *linhas, int *colunas);
    void escolheComando();
    bool verificaComando(const string &comando);

    const map<string, Reserva> getStoreReserva() const;

private:
    Reserva &reserva;

    map<string,Reserva > storeReserva;

    bool adicionaStoreReserva(const string &nome, Reserva reservaStore);

    bool criaAnimal(const string &args);
    bool mataAnimal(const string &args);
    bool colocaAlimento(const string &args);
    bool alimentaAnimais(const string &args);
    bool removeAlimento(const string &args);
    bool eliminaNaPos(const string &args);
    bool veNaPos(const string &args);
    bool veInfo(const string &args);
    bool passaInstante(const string &args);
    bool listaIdAnimais(const string &args);
    bool listaIdAlimentos(const string &args);
    bool listaIdAnimaisVisiveis(const string &args);
    bool armazenaReserva(const string &args);
    bool reativaReserva(const string &args);
    bool execFicheiros(const string &args);
    bool deslocaArea(const string &args);

    static bool leFicheiro(const string &nomeFicheiro);

};


#endif //TP_SIMULADOR_H
