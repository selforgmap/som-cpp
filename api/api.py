#!/usr/bin/env python

from flask import Flask
from flask import jsonify
from flask import request
import som
import json
import unicodedata

# Create the application instance
app = Flask(__name__)
app.config['JSON_SORT_KEYS'] = False


# Create a URL route in our application for "/"
@app.route('/train', methods=['GET', 'POST'])
def train():

    # Load request data
    data = request.json

    # Create a session of SOM
    session = som.Session()

    # Set configurations
    # TODO: Set default value
    session.x_dim                      = data['x_dim']
    session.y_dim                      = data['y_dim']
    session.dimension                  = data['dimension']
    session.grid_type                  = data['grid_type'].encode('ascii','ignore').upper()
    session.iteration_limit            = data['iteration_limit']
    session.starting_learning_rate     = data['starting_learning_rate']
    session.node_initialization_method = data['node_initialization_method'].encode('ascii','ignore')
    session.learning_rate_type         = data['learning_rate_type'].encode('ascii','ignore').upper()
    session.neighborhood_type          = data['neighborhood_type'].encode('ascii','ignore').upper()
    session.min_node_weight            = data['min_node_weight']
    session.max_node_weight            = data['max_node_weight']

    dataset = data['dataset'] if  'dataset' in data else [[]]

    # Start training
    session.Initialize();
    print(session.GetResult())

    session.Train(dataset);

    # Create response
    res = {
    	'dataset' : dataset,
    	'config' : {
	        'x_dim' : session.x_dim,
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
    	},
    	'result' : {
    		'weight_matrix': session.GetResult(),
    		'umatrix' : { }
    	}
    }

    print (res)
    return jsonify(res)

# Run the application
if __name__ == '__main__':
    app.run(debug=True)





