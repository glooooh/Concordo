/**
 * @file Servidor.h
 * @brief Arquivo header da classe Servidor.
 */
#ifndef SERVIDOR_H
#define SERVIDOR_H

#include "Canal.h"

/**
 * @class Servidor
 * @brief Classe que representa um servidor.
 */
class Servidor
{
private:
    int usuarioDonoId;            /**< O ID do usuário dono do servidor. */
    string nome;                  /**< O nome do servidor. */
    string descricao;             /**< A descrição do servidor. */
    string codigoConvite;         /**< Código necessário para se entrar no servidor */
    vector<Canal *> canais;       /**< Os canais do servidor. */
    vector<int> participantesIDs; /**< Os IDs dos participantes do servidor. */

public:
    /**
     * @brief Construtor da classe Servidor.
     *
     * @param donoId O ID do usuário dono do servidor.
     * @param nomeServidor O nome do servidor.
     */
    Servidor(int donoId, string nomeServidor);

    /**
     * @brief Construtor padrão da classe Usuario.
     */
    Servidor();

    /**
     * @brief Destrutor da classe Usuario.
     */
    ~Servidor();

    /**
     * @brief Obtém o ID do usuário dono do servidor.
     *
     * @return O ID do usuário dono.
     */
    int getIdDono();

    /**
     * @brief Obtém o nome do servidor.
     *
     * @return O nome do servidor.
     */
    string getNome();

    /**
     * @brief Obtém a descrição do servidor.
     *
     * @return A descrição do servidor.
     */
    string getDescricao();

    /**
     * @brief Obtém o código de convite do servidor.
     *
     * @return O código de convite do servidor.
     */
    string getCodigo();

    /**
     * @brief Obtém os IDs dos participantes do servidor.
     *
     * @return Um vetor contendo os IDs dos participantes.
     */
    vector<int> getParticipantesID();

    /**
     * @brief Obtém os canais do servidor.
     *
     * @return Um vetor contendo os canais do servidor.
     */
    vector<Canal *> getCanais();

    /**
     * @brief Define a descrição do servidor.
     *
     * @param desc A nova descrição a ser atribuída ao servidor.
     */
    void setDescricao(string desc);

    /**
     * @brief Define o código de convite do servidor.
     *
     * @param cod O novo código de convite a ser atribuído ao servidor.
     */
    void setCodigo(string cod);

    /**
     * @brief Adiciona um participante ao servidor.
     *
     * @param id O ID do participante a ser adicionado.
     */
    void adicionarParticipantes(int id);

    /**
     * @brief Verifica se um participante com o ID específico está no servidor.
     *
     * @param id O ID do participante a ser buscado.
     * @return true se o participante está no servidor, false caso contrário.
     */
    bool buscarParticipantePorId(int id);

    /**
     * @brief Cria um novo canal no servidor.
     *
     * @param nome O nome do canal.
     * @param tipo O tipo do canal.
     */
    void criarCanal(string nome, string tipo);
};

#endif