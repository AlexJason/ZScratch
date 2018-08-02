# Color.py
from Base import Base

class Color(Base):
	def __init__(self, lib, r=0, g=0, b=0, a=1.0):
		super().__init__(lib)
		self.r = int(r)
		self.g = int(g)
		self.b = int(b)
		self.a = float(a)

	def __add__(self, that):
		a = self.a - self.a*that.a + that.a
		f = lambda x0, a0, x1, a1: int((x0*a0 + x1*a1 - x0*a0*a1)/a)
		r = f(self.r, self.a, that.r, that.a)
		g = f(self.g, self.a, that.g, that.a)
		b = f(self.b, self.a, that.b, that.a)
		return Color(self.lib, r, g, b, a)

	def __repr__(self):
		return '(' + str(self.r) + ',' + str(self.g) + ',' + str(self.b) + ',' + str(self.a) + ')'
