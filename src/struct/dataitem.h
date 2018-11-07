//
// Created by Sumedhe Dissanayake on 11/7/18.
//

#include <vector>

#ifndef SOM_DATAITEM_H
#define SOM_DATAITEM_H

/**
 * Data item structure
 */
struct DataItem {
    std::vector<double> features;

    /**
     * Constructor
     */
    DataItem(){ }

    /**
     * Constructor
     * @param size Size of feature set
     */
    DataItem(int size) : features(size) { }
};

#endif //SOM_DATAITEM_H
