from copy import deepcopy
import random

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
        Checks whether or not there is an endge between x and y
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

        toBeRemoved = []
        for edge in self._dictCosts.keys():
            if vertex in edge:
                toBeRemoved.append(edge)
                self.edges -= 1
        for edge in toBeRemoved:
            self._dictCosts.pop(edge)


        for i in self._dictOut[vertex].values():
            toBeRemoved = []
            for j in self._dictIn[i]:
                if self._dictIn[i][j] == vertex:
                    toBeRemoved.append(j)

            for j in toBeRemoved:
                self._dictIn[i].pop(j)

        for i in self._dictIn[vertex].values():
            toBeRemoved = []
            for j in self._dictOut[i]:
                if self._dictOut[i][j] == vertex:
                    toBeRemoved.append(j)

            for j in toBeRemoved:
                self._dictOut[i].pop(j)

        self._dictIn.pop(vertex)
        self._dictOut.pop(vertex)
        self.vertices -= 1

        for i in range(vertex+1, self._vertices):
            self._dictIn[i-1] = self._dictIn[i]
            self._dictIn.pop[i]
            self._dictOut[i-1] = self._dictOut[i]
            self._dictOut.pop(i)
            #


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

        self.edges += 1

    def remove_edge(self, x, y):
        '''
        Removes the edge from x to y
        :param x: left endpoint
        :param y: right endpoint
        :return:
        :exception: if the edge doesn't exist
        '''
        if (x,y) not in self._dictCosts:
            raise EdgeException("Edge does not exist")

        self._dictCosts.pop((x,y))
        for i in self._dictOut[x]:
            if self._dictOut[x][i] == y:
                self._dictOut[x].pop(i)
                break

        for i in self._dictIn[y]:
            if self._dictIn[y][i] == x:
                self._dictIn[y].pop(i)
                break

        self.edges -= 1

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

    def copy(self):
        return deepcopy(self)

    def get_costs(self):
        return self._dictCosts

def loadGraph(graph, filename):
    '''
    Loads a graph from a text file in the memory
    :param graph: a graph
    :param filename: the filename
    :return:
    '''
    f = open(filename, "r")
    lines = f.readlines()
    graph.__init__()
    firstLine = lines[0].strip().split()
    vertices = int(firstLine[0])

    lines.pop(0)
    for i in range(vertices):
        graph.add_vertex(i)

    for line in lines:
        line = line.strip().split()
        graph.add_edge(int(line[0]), int(line[1]), int(line[2]))

def storeGraph(graph, filename):
    '''
    Stores a graph from memory to a text file
    :param graph: a graph
    :param filename: the filename
    :return:
    '''
    f = open(filename, "w")
    s = ""
    s += str(graph.vertices) + " " + str(graph.edges) + "\n"
    for i in graph.get_vertices():
        for j in graph.parse_outbound(i):
            cost = graph.get_cost(i,j)
            s += str(i) + " " + str(j) + " " + str(cost) + "\n"
    f.write(s)

def generateRandomGraph(vertices, edges):
    randomGraph = DoubleDictGraph()
    for i in range(vertices):
        randomGraph.add_vertex(i)
    while edges != 0:
        left = random.choice(range(vertices))
        right = random.choice(range(vertices))
        if randomGraph.is_edge(left,right) == False:
            cost = random.choice(range(100))
            randomGraph.add_edge(left,right,cost)
            edges -= 1
    return randomGraph

class AlreadyExists (Exception):
    pass

class VertexException(Exception):
    pass

class EdgeException(Exception):
    pass

'''
d = {1:{0:1,1:2,2:3},
     2:{0:0,1:5,2:6}
     }
vertex=1
d.pop(vertex)
d[vertex] = d[vertex+1]
d.pop(vertex+1)
for i in d[vertex]:
    if(d[vertex][i] > vertex):
        d[vertex][i] -= 1
print(d)
'''