#!/usr/bin/env python

import api

session = api.Session()

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

data = [[1,1,1],[99,99,99]]
result = session.Train(data);

print (result)

