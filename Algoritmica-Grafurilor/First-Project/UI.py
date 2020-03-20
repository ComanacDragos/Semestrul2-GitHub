from controller import *

class UI:
    def __init__(self, controller):
        self._controller = controller

    @staticmethod
    def menu():
        menu = """
1.Number of vertices
2.Iterate the set of vertices
3.Check existence of an edge
4.In degree and out degree of a vertex
5.Inbound vertices
6.Outbound vertices
7.Get cost of an edge
8.Update cost of an edge
9.Add vertex
10.Remove vertex
11.Add edge
12.Remove edge
x. Exit """
        print(menu)

    def UI_get_nr_vertices(self):
        print("The number of vertices is: " + str(self._controller.get_nr_vertices()))


    def UI_iterate_vertices(self):
        print("The vertices are: ", end=" ")
        for i in self._controller.get_vertices():
            print(i, end=" ")
        print()

    def UI_is_edge(self):
        left = int(input("Give left end-point: "))
        right = int(input("Give right end-point: "))
        if self._controller.is_edge(left, right) == True:
            print("\nThere is an edge between %d and %d" % (left, right))
        else:
            print("\nThere isn't an edge between %d and %d" %(left, right))

    def UI_in_out_degree(self):
        vertex = int(input("Give vertex: "))
        try:
            degrees = self._controller.get_degrees(vertex)
            print("The in degree of %d is: %d" %(vertex, degrees[0]))
            print("The out degree of %d is: %d" %(vertex, degrees[1]))
        except VertexException as err:
            print(err)

    def UI_in_bound_parse(self):
        vertex = int(input("Give vertex: "))
        print("The target vertices are: ", end=" ")
        try:
            inBound = self._controller.parse_inbound(vertex)
            for i in inBound:
                print(i, end=" ")
            print()
        except VertexException as err:
            print(err)

    def UI_out_bound_parse(self):
        vertex = int(input("Give vertex: "))
        try:
            outBound = self._controller.parse_outbound(vertex)
            print("The target vertices are: ", end=" ")
            for i in outBound:
                print(i, end=" ")
            print()
        except VertexException as err:
            print(err)

    def UI_get_cost(self):
        left = int(input("Give left end-point: "))
        right = int(input("Give right end-point: "))
        try:
            cost = self._controller.get_cost(left, right)
            print("The cost of %d->%d is:" % (left, right), end=" ")
            print(cost)
        except EdgeException as err:
            print(err)

    def UI_modify_cost(self):
        left = int(input("Give left end-point: "))
        right = int(input("Give right end-point: "))
        newValue = int(input("Give new cost: "))
        try:
            self._controller.modify_cost(left, right, newValue)
            print("The cost was updated succesfully")
        except EdgeException as err:
            print(err)

    def start(self):
        commands ={
            "1" : self.UI_get_nr_vertices,
            "2" : self.UI_iterate_vertices,
            "3" : self.UI_is_edge,
            "4" : self.UI_in_out_degree,
            "5" : self.UI_in_bound_parse,
            "6" : self.UI_out_bound_parse,
            "7" : self.UI_get_cost,
            "8" : self.UI_modify_cost,
        }
        while True:
            self.menu()
            print()
            choice = input(">")
            print()
            if choice in commands:
                commands[choice]()
            elif choice == "x":
                return
            else:
                print("Invalid command")