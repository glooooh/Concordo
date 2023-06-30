/**
 * @file Canal.h
 * @brief Arquivo header da classe Canal.
 */
#ifndef CANAL_H
#define CANAL_H

#include <string>
#include <vector>

#include "Mensagem.h"   /**< Inclui a classe Mensagem. */

using namespace std;

/**
 * @class Canal
 * @brief Classe que representa um canal.
 */
class Canal
{
protected:
    string nome;    /**< Nome do canal. */

public:
    /**
     * @brief Construtor da classe Canal.
     *
     * @param nome O nome do canal.
     */
    Canal(string);

    /**
     * @brief Construtor padrão da classe Canal.
     */
    Canal();

    /**
     * @brief Destrutor padrão da classe Canal.
     */
    virtual ~Canal();

    /**
     * @brief Obtém o nome do Canal.
     *
     * @return o nome do Canal.
     */
    string getNome();

    /**
     * @brief Obtém o tipo do canal.
     *
     * @return O tipo do canal.
     */
    virtual string getTipo() const;

    /**
     * @brief Obtém as mensagens do canal.
     * 
     * @return Um vetor contendo as mensagens do canal.
     */
    virtual vector<Mensagem> getMensagens() = 0;

    /**
     * @brief Envia uma mensagem para o canal.
     * 
     * @param mensagem A mensagem a ser enviada.
     */
    virtual void enviarMensagem(const Mensagem &mensagem) = 0;
};

#endif