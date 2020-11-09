#!/usr/bin/env python3

from OurLibrary import Vector
from pytest import approx

def test_sum():
	v = Vector(101)
	v.fill()
	assert v.sum() == approx(5050.0)