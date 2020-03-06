from UI import *

class Main:
    def __init__(self):
        #filename = input("Give filename: " )
        self.graph = DoubleDictGraph("graph1m.txt")
        self.controller = Controller(self.graph)
        self.UI = UI(self.controller)
        self.UI.start()


Main()
