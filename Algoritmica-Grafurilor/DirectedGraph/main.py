from UI import *

class Main:
    def __init__(self):
        self.graph = DoubleDictGraph()
        self.controller = Controller(self.graph)
        self.UI = UI(self.controller)
        self.UI.start()

Main()

