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

/**
 * Session class
 */
class Session {
public:
    SOM som;
    vector<vector<double> > result;

    /**
     * Constructor
     */
    Session();

    /**
     * Initialize nodes
     */
    void Initialize();

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
     * Get X dimension
     * @return Value
     */
    int GetXDim();

    /**
     * Set X dimension
     * @param value Value
     */
    void SetXDim(int value);


    /**
     * Get Y dimension
     * @return Value
     */
    int GetYDim();

    /**
     * Set Y dimension
     * @param value Value
     */
    void SetYDim(int value);


    /**
     * Get dimension of the dataset
     * @return Value
     */
    int GetDimension();

    /**
     * Set dimension of the dataset
     * @param value Value
     */
    void SetDimension(int value);


    /**
     * Get the type of grid
     * @return Value
     */
    string GetGridType();

    /**
     * Set the type of grid.
     * RECTANGULAR | HEXAGONAL
     * @param value Grid type name
     */
    void SetGridType(string value);


    /**
     * Get the iteration limit
     * @return Value
     */
    int GetIterationLimit();

    /**
     * Set the iteration limit
     * @param value Value
     */
    void SetIterationLimit(int value);


    /**
     * Get the starting learning rate
     * @return Value
     */
    float GetStartingLearningRate();

    /**
     * Set the starting learning rate
     * @param value Value
     */
    void SetStartingLearningRate(float value);


    /**
     * Get node initialization method
     * @return Value
     */
    string GetNodeInitializationMethod();

    /**
     * Set node initialization method
     * @param value Name of the method
     */
    void SetNodeInitializationMethod(string value);


    /**
     * Get the learning rate type
     * @return Value
     */
    string GetLearningRateType();

    /**
     * Set the learning rate type
     * @param value Name of the type
     */
    void SetLearningRateType(string value);


    /**
     * Get the neighborhood type
     * @return Value
     */
    string GetNeighborhoodType();

    /**
     * Set the neighborhood type
     * @param value Name of the neighborhood type
     */
    void SetNeighborhoodType(string value);


    /**
     * Get minimum node weight
     * @return Value
     */
    float GetMinNodeWeight();

    /**
     * Minimum node weight
     * @param value Value
     */
    void SetMinNodeWeight(float value);


    /**
     * Get Maximum node weight
     * @return Value
     */
    float GetMaxNodeWeight();

    /**
     * Maximum node weight
     * @param value Value
     */
    void SetMaxNodeWeight(float value);

};

#endif //SOM_API_H
