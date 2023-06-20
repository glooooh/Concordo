/**
 * @file Mensagem.h
 * @brief Arquivo header da classe Mensagem.
 */
#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <string>
#include <vector>

using namespace std;

/**
 * @class Mensagem
 * @brief Classe que representa um mensagem.
 */
class Mensagem
{
private:
    string dataHora;
    int enviadaPor; /*<! Guardar o ID do usuário que enviou a mensagem */
    string conteudo;

public:
    // Construtores
    Mensagem(string, int, string);
    Mensagem();

    // Destrutor
    ~Mensagem();
};

#endif