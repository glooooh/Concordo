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
    string dataHora; /**< A data e hora em que a mensagem foi enviada. */
    int enviadaPor;  /*<! Guardar o ID do usuário que enviou a mensagem */
    string conteudo; /**< O conteúdo da mensagem. */

public:
    /**
     * @brief Construtor da classe Mensagem.
     *
     * @param texto O conteúdo da mensagem.
     * @param idRemetente O ID do remetente da mensagem.
     * @param data_hora A data e hora da mensagem.
     */
    Mensagem(const string &texto, int idRemetente, const string &);

    /**
     * @brief Construtor padrão da classe Mensagem.
     */
    Mensagem();

    /**
     * @brief Destrutor da classe Mensagem.
     */
    ~Mensagem();

    /**
     * @brief Obtém a data e hora da mensagem.
     *
     * @return A data e hora da mensagem.
     */
    string getDataHora();

    /**
     * @brief Obtém o ID do remetente da mensagem.
     *
     * @return O ID do remetente da mensagem.
     */
    int getIdRemetente();

    /**
     * @brief Obtém o conteúdo da mensagem.
     *
     * @return O conteúdo da mensagem.
     */
    string getConteudo() const;

    /**
     * @brief Verifica se a mensagem está vazia.
     *
     * @return True se a mensagem estiver vazia, False caso contrário.
     */
    bool empty();
};

#endif