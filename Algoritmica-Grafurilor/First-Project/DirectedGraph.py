class DoubleDictGraph:
    def __init__(self, filename):
        self._dictIn = {}
        self._dictOut = {}
        self._dictCosts = {}
        self._loadGraph(filename)

    def _loadGraph(self, filename):
        f = open(filename, "r")
        lines = f.readlines()
        first = lines[0]
        first = first.strip().split()
        self._vertices = int(first[0])
        self._edges = int(first[1])
        lines.pop(0)

        for i in range(self._vertices):
            self._dictIn[i] = []
            self._dictOut[i] = []

        for line in lines:
            line = line.strip().split()
            left = int(line[0])
            right = int(line[1])
            cost = int(line[2])

            self._dictOut[left].append(right)
            self._dictIn[right].append(left)
            self._dictCosts[(left,right)] = cost

        print(self._dictCosts)
        print()
        print(self._dictIn)
        print()
        print(self._dictOut)

    def _storeGraph(self, filename):
        pass

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
        self._dictIn[y].append(x)
        self._dictOut[x].append(y)
        self._dictCosts[(x,y)].append(cost)

    def get_nr_vertices(self):
        '''
        :return: number of vertices
        '''
        return self._vertices

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
        :return: the list of target vertices
        :exception: the vertex doesn't exist
        """
        if self.is_vertice(vertex) == False:
            raise VertexException("Vertex doesn't exist")
        return self._dictOut[vertex][:]

    def parse_inbound(self, vertex):
        """
        :param vertex: a vertex of the graph
        :return: the list of target vertices
        :exception: the vertex doesn't exist
        """
        if self.is_vertice(vertex) == False:
            raise VertexException("Vertex doesn't exist")
        vertices = []
        for v in self._dictOut.keys():
            if vertex in self._dictOut[v]:
                vertices.append(v)
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

