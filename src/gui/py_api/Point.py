# Point.py
from Base import Base
from ctypes import c_void_p

class Point(Base):
	def __init__(self, lib, x=0, y=0):
		Base.__init__(lib)
		self.obj = ctypes.c_void_p()
		self.x = x
		self.y = y
		self.dll.Point_FromInt(pointer(self.obj), c_int(self.x), c_int(self.y))

	def 
