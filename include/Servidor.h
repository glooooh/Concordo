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
    int usuarioDonoId;
    string nome;
    string descricao;
    string codigoConvite;           /*!< Código necessário para se entrar no servidor */
    vector<Canal *> canais;
    vector<int> participantesIDs;   /*!< lista de IDs de usuários que já estão no servidor. */

public:
    // Construtores
    Servidor(int, string);
    Servidor();

    // Destrutor
    ~Servidor();

    // Gets
    int getIdDono();
    string getNome();
    string getDescricao();
    string getCodigo();
    vector<int> getParticipantesID();

    // Sets
    void setDescricao(string);
    void setCodigo(string);

    // Funções de participantes
    void adicionarParticipantes(int);
    bool buscarParticipantePorId(int);
};

#endif