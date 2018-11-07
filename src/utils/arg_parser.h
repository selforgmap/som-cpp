//
// Created by Sumedhe Dissanayake on 10/28/18.
//

#ifndef SOM_ARG_PARSER_H
#define SOM_ARG_PARSER_H


#include "../core/som.h"

/**
 * Convert arguments to config
 * @param argc Argument count
 * @param args Arguments
 * @return Config
 */
void parse_config_from_args(SOM som, int argc, char** argv);


#endif //SOM_ARG_PARSER_H
