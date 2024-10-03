#ifndef TP_CONFIGURACAO_H
#define TP_CONFIGURACAO_H

#include "utils.h"

class Configuracao {
public:

    static int getSCoelho();

    static void setSCoelho(int sCoelho);

    static int getSOvelha();

    static void setSOvelha(int sOvelha);

    static int getSLobo();

    static void setSLobo(int sLobo);

    static int getSCanguru();

    static void setSCanguru(int sCanguru);

    static int getSAnimalMisterio();

    static void setSAnimalMisterio(int sAnimalMisterio);

    static int getVCoelho();

    static void setVCoelho(int vCoelho);

    static int getVOvelha();

    static void setVOvelha(int vOvelha);

    static int getVLobo();

    static void setVLobo(int vLobo);

    static int getVCanguru();

    static void setVCanguru(int vCanguru);

    static int getVAnimalMisterio();

    static void setVAnimalMisterio(int vAnimalMisterio);

    static int getPCoelho();

    static void setPCoelho(int pCoelho);

    static int getPOvelha();

    static void setPOvelha(int pOvelha);

    static int getPLobo();

    static void setPLobo(int pLobo);

    static int getPCanguru();

    static void setPCanguru(int pCanguru);

    static int getPAnimalMisterio();

    static void setPAnimalMisterio(int pAnimalMisterio);

    static int getVRelva();

    static void setVRelva(int vRelva);

    static int getVCenoura();

    static void setVCenoura(int vCenoura);

    static int getVBife();

    static void setVBife(int vBife);

    static int getVAlimentoMisterio();

    static void setVAlimentoMisterio(int vAlimentoMisterio);

    static int getNRelva();

    static void setNRelva(int nRelva);

    static int getNCenoura();

    static void setNCenoura(int nCenoura);

    static int getNBife();

    static void setNBife(int nBife);

    static int getNAlimentoMisterio();

    static void setNAlimentoMisterio(int nAlimentoMisterio);

    static int getTRelva();

    static int getTCenoura();

    static void setTCenoura(int tCenoura);

    static int getTBife();

    static int getTAlimentoMisterio();

    static void setTAlimentoMisterio(int tAlimentoMisterio);

    static bool configuraFicheiro(const string &linha);

private:
    //saude animais
    static int sCoelho;
    static int sOvelha;
    static int sLobo;
    static int sCanguru;
    static int sAnimalMisterio;

    //duração de vida animais
    static int vCoelho;
    static int vOvelha;
    static int vLobo;
    static int vCanguru;
    static int vAnimalMisterio;

    //perceção animais
    static int pCoelho;
    static int pOvelha;
    static int pLobo;
    static int pCanguru;
    static int pAnimalMisterio;

    //duraçao de vida alimentos
    static int vRelva;
    static int vCenoura;
    static int vBife;
    static int vAlimentoMisterio;

    //valor nutritivo alimentos
    static int nRelva;
    static int nCenoura;
    static int nBife;
    static int nAlimentoMisterio;

    //valor toxico alimentos
    static int tRelva;
    static int tCenoura;
    static int tBife;
    static int tAlimentoMisterio;


};


#endif //TP_CONFIGURACAO_H
