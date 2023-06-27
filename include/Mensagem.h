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
    /**
     * @brief Construtor da classe Mensagem.
     * 
     * @param texto O texto da mensagem.
     * @param idRemetente O id do usuário remetente da mensagem.
     */
    Mensagem(string texto, int idRemetente);
    
    /**
     * @brief Construtor padrão da classe Mensagem.
    */
    Mensagem();
    
    /**
     * @brief Destrutor da classe Mensagem.
    */
    ~Mensagem();
};

#endif