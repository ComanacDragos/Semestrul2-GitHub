class DoubleDictGraph:
    def __init__(self):
        self._dictIn = {}
        self._dictOut = {}
        self._dictCosts = {}
        self._vertices = 0
        self._edges = 0

    @property
    def vertices(self):
        return self._vertices

    @vertices.setter
    def vertices(self, value):
        self._vertices = value

    @property
    def edges(self):
        return self._edges

    @edges.setter
    def edges(self,value):
        self._edges = value

    def is_edge(self, x, y):
        '''
        Checks wheter or not there is an endge between x and y
        :param x: left end-point
        :param y: right end-point
        :return: true if such an edge exists, false otherwise
        '''
        edge = (x,y)
        return edge in self._dictCosts

    def is_vertice(self, n):
        """
        Checks wether or not a number is a vertice or not
        :param n:
        :return: True if it is / False otherwise
        """
        return n in self._dictIn

    def add_vertex(self, n):
        '''
        Adds the vertex n if it does not exists
        :param n: integer number
        :return:
        :exception: if the vertice already exists
        '''
        if self.is_vertice(n) == True:
            raise VertexException("Vertex already in graph")
        self._dictIn[n] = {}
        self._dictOut[n] = {}
        self._vertices += 1

    def remove_vertex(self, vertex):
        '''
        Removes a given vertex from the graph
        :param vertex:
        :return:
        :exception: if the vertex does not exist raises an exception
        '''
        if vertex not in self._dictIn:
            raise VertexException("Vertex not in graph")

        for edges in self._dictCosts.keys():
            if vertex in edges:
                pass

    def add_edge(self, x, y, cost):
        '''
        Adds the edge x -> y with a cost
        :param x: left endpoint
        :param y: right endpoint
        :param cost: cost of the edge
        :return: None
        :exception: if the edge already exists
        '''
        if self.is_edge(x, y) == True:
            raise AlreadyExists("There already exists such an edge")
        if self.is_vertice(x) == False or self.is_vertice(y) == False:
            raise VertexException("Vertex doesn't exist")

        self._dictIn[y][len(self._dictIn[y])] = x
        self._dictOut[x][len(self._dictOut[x])] = y
        self._dictCosts[(x,y)] = cost


    def get_vertices(self):
        """
        :return: list of all vertices
        """
        vertices = []
        for i in self._dictIn:
            vertices.append(i)
        return vertices

    def get_in_degree(self, vertex):
        """
        :param vertex: a vertex
        :return: the in degree of the vertex
        :exception: if the vertex doesn't exist
        """
        if self.is_vertice(vertex) == False:
            raise VertexException("Vertex doesn't exist")
        return len(self._dictIn[vertex])

    def get_out_degree(self, vertex):
        """
        :param vertex: a vertex
        :return: the out degree of the vertex
        :exception: if the vertex doesn't exist
        """
        if self.is_vertice(vertex) == False:
            raise VertexException("Vertex doesn't exist")
        return len(self._dictOut[vertex])

    def parse_outbound(self, vertex):
        """
        :param vertex: a vertex of the graph
        :return: the list of outbound vertices
        :exception: the vertex doesn't exist
        """
        if self.is_vertice(vertex) == False:
            raise VertexException("Vertex doesn't exist")
        vertices = []
        for v in self._dictOut[vertex]:
            vertices.append(self._dictOut[vertex][v])
        return vertices

    def parse_inbound(self, vertex):
        """
        :param vertex: a vertex of the graph
        :return: the list of inbound vertices
        :exception: the vertex doesn't exist
        """
        if self.is_vertice(vertex) == False:
            raise VertexException("Vertex doesn't exist")
        vertices = []
        for v in self._dictIn[vertex]:
            vertices.append(self._dictIn[vertex][v])
        return vertices

    def get_cost(self, x, y):
        """
        :param x: left end-point
        :param y: right end-point
        :return: the cost of the edge (x,y)
        :exception: the edge doesn't exist
        """
        if (x,y) not in self._dictCosts.keys():
            raise EdgeException("Edge doesn't exist")
        return self._dictCosts[(x,y)]

    def modify_cost(self, x, y, newValue):
        """
        :param x: left end-point
        :param y: right end-point
        :param newValue: new cost
        :return: None
        :exception: the edge doesn't exist
        """
        if (x,y) not in self._dictCosts.keys():
            raise EdgeException("Edge doesn't exist")
        self._dictCosts[(x,y)] = newValue



class AlreadyExists (Exception):
    pass

class VertexException(Exception):
    pass

class EdgeException(Exception):
    pass

