/**
 * @file CanalTexto.h
 * @brief Arquivo header da classe CanalTexto.
 */
#ifndef CANALTEXTO_H
#define CANALTEXTO_H

#include "Canal.h"
#include "Mensagem.h"

/**
 * @class CanalTexto
 * @brief Classe que representa um canal de texto.
 */
class CanalTexto : public Canal
{
protected:
    vector<Mensagem> mensagens;

public:
    // Construtores
    CanalTexto();

    // Destrutor
    ~CanalTexto();
};

#endif