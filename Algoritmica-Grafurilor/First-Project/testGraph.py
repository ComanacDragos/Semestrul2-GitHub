import unittest
from DirectedGraph import *

class TestGraph(unittest.TestCase):
    def test_addVertex(self):
        g = DoubleDictGraph()
        g.add_vertex(0)

        self.assertEqual(g.is_vertice(0), True);
        self.assertEqual(g.is_vertice(1), False);
        with self.assertRaises(VertexException):
            g.add_vertex(0)

    def test_add_edge(self):
        g = DoubleDictGraph()
        g.add_vertex(0)
        g.add_vertex(1)
        g.add_edge(0,1,5)

        assert g.is_edge(0,1) == True

        with self.assertRaises(AlreadyExists):
            g.add_edge(0,1,5)
        with self.assertRaises(VertexException):
            g.add_edge(0,2,5)
        with self.assertRaises(VertexException):
            g.add_edge(2,1,5)

    def test_get_vertices(self):
        g = DoubleDictGraph()
        g.add_vertex(0)
        g.add_vertex(1)
        g.add_vertex(2)
        cont = 0
        for i in g.get_vertices():
            assert  i == cont
            cont += 1

    def test_get_in_out_degree(self):
        g = DoubleDictGraph()
        g.add_vertex(0)
        g.add_vertex(1)
        g.add_edge(0,1,4)

        assert g.get_in_degree(0) == 0
        assert g.get_out_degree(0) == 1

        assert g.get_out_degree(1) == 0
        assert g.get_in_degree(1) == 1

        with self.assertRaises(VertexException):
            g.get_in_degree(3)
        with self.assertRaises(VertexException):
            g.get_out_degree(3)

    def test_parse_outbound(self):
        g = DoubleDictGraph()
        g.add_vertex(0)
        g.add_vertex(1)
        g.add_vertex(2)
        g.add_edge(0,1,1)
        g.add_edge(0,2,1)
        g.add_edge(2,1,0)

        outbound = g.parse_outbound(0)
        assert len(outbound) == 2
        assert outbound[0] == 1
        assert outbound[1] == 2

        outbound = g.parse_outbound(1)
        assert len(outbound) == 0

        outbound = g.parse_outbound(2)
        assert len(outbound) == 1
        assert outbound[0] == 1

        with self.assertRaises(VertexException):
            g.parse_outbound(5)

    def test_parse_inbound(self):
        g = DoubleDictGraph()
        g.add_vertex(0)
        g.add_vertex(1)
        g.add_vertex(2)
        g.add_edge(0, 1, 1)
        g.add_edge(0, 2, 1)
        g.add_edge(2, 1, 0)

        inbound = g.parse_inbound(0)
        assert  len(inbound) == 0

        inbound = g.parse_inbound(1)
        assert len(inbound) == 2
        assert inbound[0] == 0
        assert inbound[1] == 2

        inbound = g.parse_inbound(2)
        assert len(inbound) == 1
        assert inbound[0] == 0

        with self.assertRaises(VertexException):
            g.parse_inbound(5)

    def test_get_cost(self):
        g = DoubleDictGraph()
        g.add_vertex(0)
        g.add_vertex(1)
        g.add_vertex(2)
        g.add_edge(0, 1, 1)
        g.add_edge(0, 2, 1)
        g.add_edge(2, 1, 0)

        assert g.get_cost(0,1) == 1
        assert g.get_cost(0,2) == 1
        assert g.get_cost(2,1) == 0

        with self.assertRaises(EdgeException):
            g.get_cost(0,3)

    def test_modify_cost(self):
        g = DoubleDictGraph()
        g.add_vertex(0)
        g.add_vertex(1)
        g.add_vertex(2)
        g.add_edge(0, 1, 1)
        g.add_edge(0, 2, 1)
        g.add_edge(2, 1, 0)

        g.modify_cost(0,1,5)
        assert g.get_cost(0,1) == 5
        assert g.get_cost(0, 2) == 1
        assert g.get_cost(2, 1) == 0


if __name__ == '__main__':
    unittest.main()

'''
class TestMenu:
    def __init__(self):
        self._test = TestGraph()

    def print_menu(self):
    
    def start(self):
        commands = {
            "1" : self._test.test_addVertex
        }
        while True:
            self.print_menu()
            choice = input(">")
            if choice in commands:
                commands[choice]()
            elif choice == "x":
                return
            else:
                print("Invalid command")'''