/**
 * @file CanalVoz.h
 * @brief Arquivo header da classe CanalVoz.
 */
#ifndef CANALVOZ_H
#define CANALVOZ_H

#include "Canal.h"
#include "Mensagem.h"

/**
 * @class CanalVoz
 * @brief Classe que representa um canal de voz.
 */
class CanalVoz : public Canal
{
protected:
    Mensagem ultimaMensagem;

public:
    // Construtores
    CanalVoz();

    // Destrutor
    ~CanalVoz();
};

#endif