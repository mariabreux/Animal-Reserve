
#include "Configuracao.h"

int Configuracao::sCoelho = 20;
int Configuracao::sOvelha = 30;
int Configuracao::sLobo = 25;
int Configuracao::sCanguru = 20;
int Configuracao::sAnimalMisterio = 55;

int Configuracao::vCoelho = 30;
int Configuracao::vOvelha = 35;
int Configuracao::vLobo = 40;
int Configuracao::vCanguru = 70;
int Configuracao::vAnimalMisterio = 50;

int Configuracao::pCoelho = 4;
int Configuracao::pOvelha = 3;
int Configuracao::pLobo = 5;
int Configuracao::pCanguru= 7;
int Configuracao::pAnimalMisterio = 10;

int Configuracao::vRelva = 20;
int Configuracao::vCenoura = 0;
int Configuracao::vBife = 30;
int Configuracao::vAlimentoMisterio = 0;

int Configuracao::nRelva = 3;
int Configuracao::nCenoura = 4;
int Configuracao::nBife = 10;
int Configuracao::nAlimentoMisterio = 0;

int Configuracao::tRelva = 0;
int Configuracao::tCenoura = 1;
int Configuracao::tBife = 2;
int Configuracao::tAlimentoMisterio = 5;



bool Configuracao::configuraFicheiro(const string &linha) {
    istringstream ss(linha);
    string variavel;
    int valor;

    ss >> variavel >> valor;

    if(ss){
        if(variavel == "SCoelho"){
            setSCoelho(valor);
        }
        else if(variavel == "SOvelha"){
            setSOvelha(valor);
        }
        else if(variavel == "SLobo"){
            setSLobo(valor);
        }
        else if(variavel == "SCanguru"){
            setSCanguru(valor);
        }
        else if(variavel == "SAnimalMisterio"){
            setSAnimalMisterio(valor);
        }
        if(variavel == "VCoelho"){
            setVCoelho(valor);
        }
        else if(variavel == "VOvelha"){
            setVOvelha(valor);
        }
        else if(variavel == "VLobo"){
            setVLobo(valor);
        }
        else if(variavel == "VCanguru"){
            setVCanguru(valor);
        }
        else if(variavel == "VAnimalMisterio"){
            setVAnimalMisterio(valor);
        }
        if(variavel == "PCoelho"){
            setPCoelho(valor);
        }
        else if(variavel == "POvelha"){
            setPOvelha(valor);
        }
        else if(variavel == "PLobo"){
            setPLobo(valor);
        }
        else if(variavel == "PCanguru"){
            setPCanguru(valor);
        }
        else if(variavel == "PAnimalMisterio"){
            setPAnimalMisterio(valor);
        }
        return true;
    }
    return false;
}

int Configuracao::getSCoelho() {
    return sCoelho;
}

void Configuracao::setSCoelho(int sCoelho) {
    Configuracao::sCoelho = sCoelho;
}

int Configuracao::getSOvelha() {
    return sOvelha;
}

void Configuracao::setSOvelha(int sOvelha) {
    Configuracao::sOvelha = sOvelha;
}

int Configuracao::getSLobo() {
    return sLobo;
}

void Configuracao::setSLobo(int sLobo) {
    Configuracao::sLobo = sLobo;
}

int Configuracao::getSCanguru() {
    return sCanguru;
}

void Configuracao::setSCanguru(int sCanguru) {
    Configuracao::sCanguru = sCanguru;
}

int Configuracao::getSAnimalMisterio() {
    return sAnimalMisterio;
}

void Configuracao::setSAnimalMisterio(int sAnimalMisterio) {
    Configuracao::sAnimalMisterio = sAnimalMisterio;
}

int Configuracao::getVCoelho() {
    return vCoelho;
}

void Configuracao::setVCoelho(int vCoelho) {
    Configuracao::vCoelho = vCoelho;
}

int Configuracao::getVOvelha() {
    return vOvelha;
}

void Configuracao::setVOvelha(int vOvelha) {
    Configuracao::vOvelha = vOvelha;
}

int Configuracao::getVLobo() {
    return vLobo;
}

void Configuracao::setVLobo(int vLobo) {
    Configuracao::vLobo = vLobo;
}

int Configuracao::getVCanguru() {
    return vCanguru;
}

void Configuracao::setVCanguru(int vCanguru) {
    Configuracao::vCanguru = vCanguru;
}

int Configuracao::getVAnimalMisterio() {
    return vAnimalMisterio;
}

void Configuracao::setVAnimalMisterio(int vAnimalMisterio) {
}

int Configuracao::getPCoelho() {
    return pCoelho;
}

void Configuracao::setPCoelho(int pCoelho) {
    Configuracao::pCoelho = pCoelho;
}

int Configuracao::getPOvelha() {
    return pOvelha;
}

void Configuracao::setPOvelha(int pOvelha) {
    Configuracao::pOvelha = pOvelha;
}

int Configuracao::getPLobo() {
    return pLobo;
}

void Configuracao::setPLobo(int pLobo) {
    Configuracao::pLobo = pLobo;
}

int Configuracao::getPCanguru() {
    return pCanguru;
}

void Configuracao::setPCanguru(int pCanguru) {
    Configuracao::pCanguru = pCanguru;
}

int Configuracao::getPAnimalMisterio() {
    return pAnimalMisterio;
}

void Configuracao::setPAnimalMisterio(int pAnimalMisterio) {
    Configuracao::pAnimalMisterio = pAnimalMisterio;
}

int Configuracao::getVRelva() {
    return vRelva;
}

void Configuracao::setVRelva(int vRelva) {
    Configuracao::vRelva = vRelva;
}

int Configuracao::getVCenoura() {
    return vCenoura;
}

void Configuracao::setVCenoura(int vCenoura) {
    Configuracao::vCenoura = vCenoura;
}

int Configuracao::getVBife() {
    return vBife;
}

void Configuracao::setVBife(int vBife) {
    Configuracao::vBife = vBife;
}

int Configuracao::getVAlimentoMisterio() {
    return vAlimentoMisterio;
}

void Configuracao::setVAlimentoMisterio(int vAlimentoMisterio) {
    Configuracao::vAlimentoMisterio = vAlimentoMisterio;
}

int Configuracao::getNRelva() {
    return nRelva;
}

void Configuracao::setNRelva(int nRelva) {
    Configuracao::nRelva = nRelva;
}

int Configuracao::getNCenoura() {
    return nCenoura;
}

void Configuracao::setNCenoura(int nCenoura) {
    Configuracao::nCenoura = nCenoura;
}

int Configuracao::getNBife() {
    return nBife;
}

void Configuracao::setNBife(int nBife) {
    Configuracao::nBife = nBife;
}

int Configuracao::getNAlimentoMisterio() {
    return nAlimentoMisterio;
}

void Configuracao::setNAlimentoMisterio(int nAlimentoMisterio) {
    Configuracao::nAlimentoMisterio = nAlimentoMisterio;
}

int Configuracao::getTRelva() {
    return tRelva;
}

int Configuracao::getTCenoura() {
    return tCenoura;
}

void Configuracao::setTCenoura(int tCenoura) {
    Configuracao::tCenoura = tCenoura;
}

int Configuracao::getTBife() {
    return tBife;
}

int Configuracao::getTAlimentoMisterio() {
    return tAlimentoMisterio;
}

void Configuracao::setTAlimentoMisterio(int tAlimentoMisterio) {
    Configuracao::tAlimentoMisterio = tAlimentoMisterio;
}



