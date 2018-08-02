from ctypes import c_char_p, c_void_p, pointer
from Base import Base

class Application(Base):
	def __init__(self, lib, argv=[]):
		Base.__init__(lib)
		self.obj = ctypes.c_void_p()
		self.argc = len(argv)
		self.argv = argv
		pargv = (ctypes.c_char_p * self.argc)()
		for i in range(self.argc):
			pargv[i] = bytes(self.argv[i], encoding='utf-8')
		self.dll.Application_FromArg(ctypes.pointer(self.obj), c_int(self.argc), pargv)

	def exec(self):
		self.dll.Application_Exec(ctypes.pointer(self.obj))



