from DirectedGraph import *

class Controller:
    def __init__(self, graph):
        self._graph = graph

    def get_nr_vertices(self):
        '''
        :return: number of vertices in graph
        '''
        return self._graph.vertices

    def get_vertices(self):
        """
        :return: an iterable of the set of vertices
        """
        return self._graph.get_vertices()

    def is_edge(self, x, y):
        '''
        Returns True if there is an edge between x and y and false otherwise
        :param x: left end-point
        :param y:  rigt end-point
        :return: True/False
        '''
        return self._graph.is_edge(x,y)

    def get_degrees(self, vertex):
        '''
        :param vertex:
        :return: a tupple consisting of the in and out degrees of the vertex
        '''
        return(self._graph.get_in_degree(vertex), self._graph.get_out_degree(vertex))

    def parse_inbound(self, vertex):
        """
        :param vertex: a vertex of the graph
        :return: the list of target vertices
        """
        return self._graph.parse_inbound(vertex)

    def parse_outbound(self, vertex):
        """
        :param vertex: a vertex of the graph
        :return: the list of target vertices
        """
        return self._graph.parse_outbound(vertex)

    def get_cost(self, x, y):
        """
        :param x: left end-point
        :param y: right end-point
        :return: cost of the edge(x,y)
        """
        return self._graph.get_cost(x,y)

    def modify_cost(self, x, y, newValue):
        """
        :param x: left end-point
        :param y: right end-point
        :param newValue: new cost
        :return: None
        """
        self._graph.modify_cost(x, y, newValue)
