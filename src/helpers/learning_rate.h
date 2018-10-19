//
// Created by Sumedhe Dissanayake on 10/18/18.
//

#ifndef SOM_LEARNING_RATE_H
#define SOM_LEARNING_RATE_H

/**
 * Constant Learning Rate
 * @param starting_learning_rate Starting learning rate
 * @return Learning rate
 */
float constant_learning_rate(float starting_learning_rate);

/**
 * Linear Learning Rate
 * alpha(0) * (1 / t)
 * @param starting_learning_rate Starting learning rate
 * @param iteration Current Iteration
 * @return Learning rate
 */
float linear_learning_rate(float starting_learning_rate, int iteration);

/**
 * Inverse of time function for learning rate
 * alpha(0) * (1 - t/T)
 * @param starting_learning_rate Starting learning rate
 * @param iteration Current iteration
 * @param iteration_limit Maximum iterations
 * @return Learning rate
 */
float inverse_of_time_learning_rate(float starting_learning_rate, int iteration, int iteration_limit);

/**
 * Power series function for learning rate
 * alpha(0) * e^(t/T)
 * @param starting_learning_rate Starting learning rate
 * @param iteration Current iteration
 * @param iteration_limit Iteration limit
 * @return Learning rate
 */
float power_series_learning_rate(float starting_learning_rate, int iteration, int iteration_limit);

#endif //SOM_LEARNING_RATE_H
