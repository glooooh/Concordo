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
    ~Canal();
};

#endif