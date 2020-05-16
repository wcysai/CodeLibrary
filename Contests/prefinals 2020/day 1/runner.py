#!/usr/bin/env python

from cyaron import *

_n = ati([0,10, 20,   50, 200,  200, 500, 1E3, 2E3, 2E3,3E3,5E3,1E4,2E4,5E4,1E5,1E5,1E5,1E5,1E5,1E5])
_m = ati([0,200, 200, 200, 200, 2E3, 2E3, 2E3, 2E3, 1E5,1E5,1E5,1E5,1E5,1E5,1E5,1E5,1E5,1E5,1E5,1E5])
_q = ati([0,200, 200, 200, 200, 2E3, 2E3, 2E3, 2E3, 1E5,1E5,1E5,1E5,1E5,1E5,1E5,1E5,1E5,1E5,1E5,1E5])

for i in range(1, 21):
    test_data = IO(file_prefix="drive", data_id=i)

    n = _n[i]
    m = _m[i]
    q = _q[i]
    test_data.input_writeln(n, m, q)

    graph = Graph.graph(n, m, weight_limit=1000000000)
    test_data.input_writeln(graph)
    for j in range(0,q):
        x=randint(1,1000000000)
        test_data.input_writeln(x)
    test_data.output_gen("std.exe") 