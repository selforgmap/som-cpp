#!/usr/bin/env python

import api

s = api.Session()
s.SetXDim(3)
s.SetYDim(3)
x = s.Train();

print (x)

