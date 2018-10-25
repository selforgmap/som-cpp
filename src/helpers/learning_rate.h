//
// Created by Sumedhe Dissanayake on 10/18/18.
//

#ifndef SOM_LEARNING_RATE_H
#define SOM_LEARNING_RATE_H

#include <map>

class LearningRate {
public:
    enum type {
        LR_CONSTANT,
        LR_LINEAR,
        LR_INVERSE_OF_TIME,
        LR_POWER_SERIES
    };

    // To convert string to learning rate type
    static std::map<std::string, LearningRate::type> type_map;

    /**
     * Calculate Learning rate
     * @param type Learning rate function
     * @param starting_learning_rate Starting learning rate
     * @param iteration Current iteration
     * @param iteration_limit Iteration limit
     * @return Learning rate
     */
    static float Calculate(LearningRate::type type, float starting_learning_rate, int iteration, int iteration_limit);

private:
    /**
     * Constant Learning Rate
     * @param starting_learning_rate Starting learning rate
     * @return Learning rate
     */
    static float ConstantLearningRate(float starting_learning_rate);

    /**
     * Linear Learning Rate
     * alpha(0) * (1 / t)
     * @param starting_learning_rate Starting learning rate
     * @param iteration Current Iteration
     * @return Learning rate
     */
    static float LinearLearningRate(float starting_learning_rate, int iteration);

    /**
     * Inverse of time function for learning rate
     * alpha(0) * (1 - t/T)
     * @param starting_learning_rate Starting learning rate
     * @param iteration Current iteration
     * @param iteration_limit Maximum iterations
     * @return Learning rate
     */
    static float InverseOfTimeLearningRate(float starting_learning_rate, int iteration, int iteration_limit);

    /**
     * Power series function for learning rate
     * alpha(0) * e^(t/T)
     * @param starting_learning_rate Starting learning rate
     * @param iteration Current iteration
     * @param iteration_limit Iteration limit
     * @return Learning rate
     */
    static float PowerSeriesLearningRate(float starting_learning_rate, int iteration, int iteration_limit);
};



#endif //SOM_LEARNING_RATE_H
