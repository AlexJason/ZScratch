# Base.py
import ctypes

class Base():
	def __init__(self, dll):
		self.dll = ctypes.CDLL()
		self.dll = dll
