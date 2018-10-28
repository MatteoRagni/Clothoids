require_relative 'G2lib.bundle'
require 'test/unit'

class TestLineSegment < Test::Unit::TestCase
  def setup
    @l1 = G2lib::LineSegment.new
    @l2 = G2lib::LineSegment.new(0, 0, 0, 10)
    @l3 = G2lib::LineSegment.new(@l2)
  end

  def test_constructor
    assert_equal(@l1.class, G2lib::LineSegment)
    assert_equal(@l2.class, G2lib::LineSegment)
    assert_equal(@l3.class, G2lib::LineSegment)
  end

  def test_attribute
    assert_equal(@l2.xBegin, 0)
    assert_equal(@l2.yBegin, 0)
    assert_equal(@l2.xEnd, 10)
    assert_equal(@l2.yEnd, 0)
    assert_equal(@l2.theta, 0)
    assert_equal(@l2.sinTheta, 0)
    assert_equal(@l2.cosTheta, 1)
    assert_equal(@l2.length, 10)
    v = @l2.p1p2
    assert_equal(v, {:begin => [0, 0], :end => [10, 0]})
  end

  def test_build
    @l1.build(0, 0, Math::PI, 10)
    assert_equal(@l1.xBegin, 0)
    assert_equal(@l1.yBegin, 0)
    assert_equal(@l1.length, 10)
    assert_equal(@l1.theta, Math::PI)

    @l3.build_2P([5, -5], [5, 5])
    assert_equal(@l3.xBegin, 5)
    assert_equal(@l3.yBegin, -5)
    assert_equal(@l3.xEnd, 5)
    assert_equal(@l3.yEnd, 5)
    
    @l3.build_2P(0, 5, 10, -5)
    assert_equal(@l3.xBegin, 0)
    assert_equal(@l3.yBegin, 5)
    assert_equal(@l3.xEnd, 10)
    assert_equal(@l3.yEnd, -5)

    assert_raise(ArgumentError) do
      @l3.build_2P([], [])
    end

    v = @l3.p1p2()
    assert_equal(v, {:begin => [0,5], :end => [10,-5]})
  end

  def test_eval
    v = @l2.eval(5)
    assert_equal(v, [5, 0])
    v = @l2.eval(5, 1)
    assert_equal(v, [5, 1])
    v = @l2.eval_D(5)
    assert_equal(v, [1, 0])
    v = @l2.eval_DD(5)
    assert_equal(v, [0, 0])
    v = @l2.eval_DDD(5)
    assert_equal(v, [0, 0])
    v = @l2.eval_D(5, 1)
    assert_equal(v, [1, 0])
    v = @l2.eval_DD(5, 1)
    assert_equal(v, [0, 0])
    v = @l2.eval_DDD(5, 1)
    assert_equal(v, [0, 0])
    assert_equal(
      {:begin => @l2.eval(0), :end =>@l2.eval(@l2.length)}, 
      @l2.p1p2())
  end

  def test_closest_point
    v = @l2.closestPoint([5, 1])
    assert_equal(v, {:s => 5, :dist => 1, :point => [5, 0]})
    v = @l2.distance(5, 1)
    assert_equal(v, {:s => 5, :dist => 1})
  end

  def test_intersect
    @l1.build_2P([0, 0], [2, 0])
    @l2.build_2P([0, 1], [2, 1])
    @l3.build_2P([0.5, -1], [0.5, 1])
    v = @l2.intersect(@l1)
    assert_equal(v, {:intersect => false, :s1 => 0, :s2 => 0})
    v = @l2.intersect(@l3)
    assert_equal(v, {:intersect => true, :s1 => 0.5, :s2 => 2})
  end

  def test_transformation
    @l1.build_2P([0, 0], [2, 0])
    @l1.translate(100.0, 100.0)
    assert_equal(@l1.p1p2(), {:begin => [100, 100], :end => [102, 100]})
    @l1.rotate(Math::PI/2, [101, 100])
    assert_equal(@l1.p1p2(), {:begin => [101, 99], :end => [101, 101]})

    @l2.build_2P([-2, 0], [2, 0])
    @l2.trim(1, 3)
    assert_equal(@l2.p1p2(), {:begin => [-1, 0], :end => [1, 0]})
    @l2.reverse
    assert_equal(@l2.p1p2(), {:begin => [1, 0], :end => [-1, 0]})
  end
end