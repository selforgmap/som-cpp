#!/usr/bin/env python

from flask import Flask
import som
import json



# Create the application instance
app = Flask(__name__)

# Create a URL route in our application for "/"
@app.route('/')
def home():
    """
    This function just responds to the browser ULR
    localhost:5000/

    :return:        the rendered template 'home.html'
    """


    # Create a session of SOM
    session = som.Session()

    # Set configurations
    session.SetXDim(5)
    session.SetYDim(5)
    session.SetDimension(3)
    session.SetGridType("RECTANGULAR")
    session.SetIterationLimit(100)
    session.SetStartingLearningRate(0.5)
    session.SetNodeInitializationMethod("RANDOM")
    session.SetLearningRateType("CONSTANT")
    session.SetNeighborhoodType("BUBBLE")
    session.SetMinNodeWeight(1)
    session.SetMaxNodeWeight(100)

    # Start training
    data = [[1,1,1],[99,99,99]]
    session.Train(data);

    print (session.GetResult())

    x = {
        'result' : session.GetResult()
    }
    json_string = json.dumps(x)
    return json_string
    # return "hello"
    # return render_template('home.html')

# If we're running in stand alone mode, run the application
if __name__ == '__main__':
    app.run(debug=True)





