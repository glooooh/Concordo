/**
 * @file Canal.h
 * @brief Arquivo header da classe Canal.
 */
#ifndef CANAL_H
#define CANAL_H

#include <string>
#include <vector>

using namespace std;

/**
 * @class Canal
 * @brief Classe que representa um canal.
 */
class Canal
{
protected:
    string nome;

public:
    // Construtores
    Canal(string);
    Canal();

    // Destrutor
    ~Canal();
};

#endif