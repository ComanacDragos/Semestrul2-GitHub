from UI import *

class Main:
    def __init__(self):
        #filename = input("Give filename: " )
        self.graph = DoubleDictGraph("small_graph.txt")
        self.controller = Controller(self.graph)
        self.UI = UI(self.controller)
        self.UI.start()


Main()
