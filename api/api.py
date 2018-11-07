#!/usr/bin/env python

from flask import Flask
from flask import jsonify
import som
import json

# Create the application instance
app = Flask(__name__)
app.config['JSON_SORT_KEYS'] = False


# Create a URL route in our application for "/"
@app.route('/')
def home():

    # Create a session of SOM
    session = som.Session()

    # Set configurations
    session.x_dim = 3
    session.x_dim = 5
    session.dimension = 3
    session.grid_type = "RECTANGULAR"
    session.iteration_limit = 100
    session.starting_learning_rate = 0.5
    session.node_initialization_method = "RANDOM"
    session.learning_rate_type = "CONSTANT"
    session.neighborhood_type = "BUBBLE"
    session.min_node_weight = 1
    session.max_node_weight = 100

    # Start training
    session.Initialize();
    print(session.GetResult())

    data = [[1,1,1],[99,99,99]]
    session.Train(data);

    # Create response
    res = {
        'x_dim'  : session.x_dim,
        'y_dim'  : session.y_dim,
        'dimension' : session.dimension,
        'grid_type' : session.grid_type,
        'iteration_limit' : session.iteration_limit,
        'starting_learning_rate' : session.starting_learning_rate,
        'node_initialization_method' : session.node_initialization_method,
        'learning_rate_type' : session.learning_rate_type,
        'neighborhood_type' : session.neighborhood_type,
        'min_node_weight' : session.min_node_weight,
        'max_node_weight' : session.max_node_weight,
        'result' : session.GetResult()
    }

    print (res)
    return jsonify(res)

# Run the application
if __name__ == '__main__':
    app.run(debug=True)





