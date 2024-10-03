#ifndef TP_RESERVA_H
#define TP_RESERVA_H

#include "utils.h"
#include "Zona.h"

class Reserva {

public:
    Reserva(int linhas, int colunas);
    Reserva(const Reserva &reserva);
    Reserva *duplica();
    ~Reserva();

    Reserva &operator=(const Reserva &reserva);

    static bool validaDimensoes(int linhas, int colunas);
    void criaZonas();
    string printReserva();

    bool adicionaAnimalReserva(char letra, int x, int y);
    void removeAnimalReserva(int id);
    void mataAnimalReserva(int id);

    bool adicionaAlimentoReserva(char letra, int x, int y, int vN, int vT);
    void removeAlimentoReserva(int id);

    int aumentaInstante(int valor);
    void verificaCoordenadas(int &x, int &y);

    const vector<vector<Zona *>> &getZonas() const;

    static int getNextId();
    int getNLinhas() const;
    int getNColunas() const;
    static int getInstante();
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    static const int getAreaVisivel();

    //METODOS COMANDOS
    bool mataAnimal(int linha, int coluna);
    bool alimentaAnimaisLC(int linha, int coluna, int pontosNutri, int pontosToxicos);
    bool alimentaAnimaisId(int id, int pontosNutri, int pontosToxicos);
    bool eliminaPos(int linha, int coluna);
    bool veNaPosicao(int linha, int coluna);
    bool veInfo(int id);
    bool listaAnimaisPorId();
    bool listaAlimentosPorId();
    bool listaAnimaisVisiveis();
    bool deslizaArea(string direcao, int valorSlide);

private:
    static int ids;
    int id;

    int nLinhas;
    int nColunas;

    int x;
    int y;

    static const int minLinhas;
    static const int minColunas;
    static const int maxLinhas;
    static const int maxColunas;

    static const int areaVisivel;

    static int instante;
    int instant;

    vector<vector<Zona*>> zonasReserva;   //vetor que aponta para cada zona da reserva

};


#endif //TP_RESERVA_H
