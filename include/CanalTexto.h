/**
 * @file CanalTexto.h
 * @brief Arquivo header da classe CanalTexto.
 */
#ifndef CANALTEXTO_H
#define CANALTEXTO_H

#include "Canal.h"      /**< Inclui a classe Canal. */
#include "Mensagem.h"   /**< Inclui a classe Mensagem. */

/**
 * @class CanalTexto
 * @brief Classe que representa um canal de texto.
 */
class CanalTexto : public Canal
{
protected:
    vector<Mensagem> mensagens;  /**< Vetor de mensagens do canal de texto. */

public:
    /**
     * @brief Construtor da classe CanalTexto.
     * 
     * @param nome O nome do canal de texto.
     */
    CanalTexto(string);

    /**
     * @brief Destrutor padrão da classe CanalTexto.
     */
    ~CanalTexto();

    /**
     * @brief Obtém o tipo do canal de texto.
     * 
     * @return O tipo do canal de texto.
     */
    string getTipo() const;

    /**
     * @brief Obtém as mensagens do canal de texto.
     * 
     * @return O vetor de mensagens do canal de texto.
     */
    vector<Mensagem> getMensagens() override;

    /**
     * @brief Envia uma mensagem no canal de texto.
     * 
     * @param mensagem A mensagem a ser enviada.
     */
    void enviarMensagem(const Mensagem &) override;
};

#endif