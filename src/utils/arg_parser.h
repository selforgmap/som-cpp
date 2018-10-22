//
// Created by Sumedhe Dissanayake on 10/28/18.
//

#ifndef SOM_ARG_PARSER_H
#define SOM_ARG_PARSER_H

#include "../struct/config.h"

/**
 * Convert arguments to config
 * @param argc Argument count
 * @param args Arguments
 * @return Config
 */
Config argsToConfig(int argc, char** argv);


#endif //SOM_ARG_PARSER_H
