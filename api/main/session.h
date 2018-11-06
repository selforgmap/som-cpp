//
// Created by Sumedhe Dissanayake on 11/5/18.
//

#ifndef SOM_API_H
#define SOM_API_H

#include <string>
#include <boost/python.hpp>
#include <boost/python/list.hpp>
#include <vector>
#include "../../src/core/som.h"
#include "../../src/struct/config.h"

/**
 * Session class
 */
class Session {
public:
    Config config;
    vector<vector<double> > result;

    /**
     * Constructor
     */
    Session(){

    }

    /**
     * Start training
     * @param data Python list matrix of dataset
     * @return Result / Weight vector
     */
    void Train(boost::python::list& data);

    /**
     * Get training result
     * @return Python list matrix of result
     */
    boost::python::list GetResult();

    /**
     * Set X dimension
     * @param value Value
     */
    void SetXDim(int value);

    /**
     * Set Y dimension
     * @param value Value
     */
    void SetYDim(int value);

    /**
     * Set dimension of the dataset
     * @param value Value
     */
    void SetDimension(int value);

    /**
     * Set the type of grid.
     * RECTANGULAR | HEXAGONAL
     * @param value Grid type name
     */
    void SetGridType(string value);

    /**
     * Set the iteration limit
     * @param value Value
     */
    void SetIterationLimit(int value);

    /**
     * Set the starting learning rate
     * @param value Value
     */
    void SetStartingLearningRate(float value);

    /**
     * Set node initialization method
     * @param value Name of the method
     */
    void SetNodeInitializationMethod(string value);

    /**
     * Set the learning rate type
     * @param value Name of the type
     */
    void SetLearningRateType(string value);

    /**
     * Set the neighborhood type
     * @param value Name of the neighborhood type
     */
    void SetNeighborhoodType(string value);

    /**
     * Minimum node weight
     * @param value Value
     */
    void SetMinNodeWeight(float value);

    /**
     * Maximum node weight
     * @param value Value
     */
    void SetMaxNodeWeight(float value);

};

#endif //SOM_API_H
