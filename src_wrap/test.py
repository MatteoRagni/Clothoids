import G2lib

line = G2lib.LineSegment()

line.build_2P([0.0, 0.0], [10.0, 0.0])

print(line.findST(5.0, 5.0))