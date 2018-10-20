import unittest
from math import pi as M_PI
from G2lib import LineSegment as LS

class TestLineSegment(unittest.TestCase):
  def setUp(self):
    self.l1 = LS()
    self.l2 = LS(0, 0, 0, 10)
    self.l3 = LS(self.l2)

  def test_constructor(self):
    self.assertEqual(type(self.l1), LS)
    self.assertEqual(type(self.l2), LS)
    self.assertEqual(type(self.l2), LS)
  
  def test_attribute(self):
    self.assertEqual(self.l2.xBegin, 0)
    self.assertEqual(self.l2.yBegin, 0)
    self.assertEqual(self.l2.xEnd, 10)
    self.assertEqual(self.l2.yEnd, 0)
    self.assertEqual(self.l2.theta, 0)
    self.assertEqual(self.l2.sinTheta, 0)
    self.assertEqual(self.l2.cosTheta, 1)
    self.assertEqual(self.l2.length, 10)
    v = self.l2.p1p2()
    self.assertEqual(v, ([0, 0], [10, 0]))

  def test_build(self):
    self.l1.build(0, 0, M_PI, 10)
    self.assertEqual(self.l1.xBegin, 0)
    self.assertEqual(self.l1.yBegin, 0)
    self.assertEqual(self.l1.length, 10)
    self.assertEqual(self.l1.theta, M_PI)

    self.l3.build_2P([5, -5], [5, 5])
    self.assertEqual(self.l3.xBegin, 5)
    self.assertEqual(self.l3.yBegin, -5)
    self.assertEqual(self.l3.xEnd, 5)
    self.assertEqual(self.l3.yEnd, 5)
    
    self.l3.build_2P(0, 5, 10, -5)
    self.assertEqual(self.l3.xBegin, 0)
    self.assertEqual(self.l3.yBegin, 5)
    self.assertEqual(self.l3.xEnd, 10)
    self.assertEqual(self.l3.yEnd, -5)

    with self.assertRaises(UserWarning):
      self.l3.build_2P([], [])

    v = self.l3.p1p2()
    self.assertEqual(v, ([0,5], [10,-5]))

  def test_eval(self):
    v = self.l2.eval(5)
    self.assertEqual(v, [5, 0])
    v = self.l2.eval(5, 1)
    self.assertEqual(v, [5, 1])
    v = self.l2.eval_D(5)
    self.assertEqual(v, [1, 0])
    v = self.l2.eval_DD(5)
    self.assertEqual(v, [0, 0])
    v = self.l2.eval_DDD(5)
    self.assertEqual(v, [0, 0])
    v = self.l2.eval_D(5, 1)
    self.assertEqual(v, [1, 0])
    v = self.l2.eval_DD(5, 1)
    self.assertEqual(v, [0, 0])
    v = self.l2.eval_DDD(5, 1)
    self.assertEqual(v, [0, 0])
    self.assertEqual(
      (self.l2.eval(0), self.l2.eval(self.l2.length)), 
      self.l2.p1p2())
    
  def test_closest_point(self):
    v = self.l2.closestPoint([5, 1])
    self.assertEqual(v, (1, 5, [5, 0]))
    v = self.l2.distance(5, 1)
    self.assertEqual(v, (1, 5))

  def test_intersect(self):
    self.l1.build_2P([0, 0], [2, 0])
    self.l2.build_2P([0, 1], [2, 1])
    self.l3.build_2P([0.5, -1], [0.5, 1])
    v = self.l2.intersect(self.l1)
    self.assertEqual(v, (False, 0, 0))
    v = self.l2.intersect(self.l3)
    self.assertEqual(v, (True, 0.5, 2))

  def test_transformation(self):
    self.l1.build_2P([0, 0], [2, 0])
    self.l1.translate(100.0, 100.0)
    self.assertEqual(self.l1.p1p2(), ([100, 100], [102, 100]))
    self.l1.rotate(M_PI/2, [101, 100])
    self.assertEqual(self.l1.p1p2(), ([101, 99], [101, 101]))

    self.l2.build_2P([-2, 0], [2, 0])
    self.l2.trim(1, 3)
    self.assertEqual(self.l2.p1p2(), ([-1, 0], [1, 0]))
    self.l2.reverse()
    self.assertEqual(self.l2.p1p2(), ([1, 0], [-1, 0]))

    




    
if __name__ == '__main__':
    unittest.main()