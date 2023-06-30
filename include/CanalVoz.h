/**
 * @file CanalVoz.h
 * @brief Arquivo header da classe CanalVoz.
 */
#ifndef CANALVOZ_H
#define CANALVOZ_H

#include "Canal.h"    /**< Inclui a classe Canal. */
#include "Mensagem.h" /**< Inclui a classe Mensagem. */

/**
 * @class CanalVoz
 * @brief Classe que representa um canal de voz.
 */
class CanalVoz : public Canal
{
protected:
    Mensagem ultimaMensagem;    /**< Última mensagem enviada no canal de voz. */

public:
    /**
     * @brief Construtor da classe CanalVoz.
     *
     * @param nome O nome do canal de voz.
     */
    CanalVoz(string nome);

    /**
     * @brief Destrutor padrão da classe CanalVoz.
     */
    ~CanalVoz();

    /**
     * @brief Obtém o tipo do canal de voz.
     * 
     * @return O tipo do canal de voz.
     */
    string getTipo() const;

    /**
     * @brief Obtém as mensagens do canal de voz.
     * 
     * @return Um vetor contendo as mensagens do canal de voz.
     */
    vector<Mensagem> getMensagens() override;

    /**
     * @brief Envia uma mensagem para o canal de voz.
     * 
     * @param mensagem A mensagem a ser enviada.
     */
    void enviarMensagem(const Mensagem &) override;
};

#endif