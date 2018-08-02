import ctypes

class GuiC():
	def __init__(self, path):
		ll = ctypes.cdll.LoadLibrary
		self.dll = ll(path)

	def getLib(self):
		return self.dll

		
