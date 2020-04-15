from DirectedGraph import *
from Traversals import *
from queue import PriorityQueue
from Utility import *


def lowest_length_path_forward_breadth_first(graph, start):
    '''
    :param graph: directed graph
    :param start: starting vertex
    :return: lowest length path between a staring node and all accessible nodes, by using a forward breadth-first search from the starting vertex
    '''
    if start not in graph.get_vertices():
        raise VertexException("Vertex doesn't exist")

    queue = []
    predecesors = {}
    lengths = {}
    visited = set()
    queue.insert(0, start)
    visited.add(start)
    lengths[start] = 0
    predecesors[start] = -1

    while len(queue) != 0:
        x = queue.pop()
        for y in graph.parse_outbound(x):
            if y not in visited:
                queue.insert(0, y)
                visited.add(y)
                lengths[y] = lengths[x] + 1
                predecesors[y] = x

    return predecesors


def forward_Dijkstra(graph, start, end):
    '''
    :param graph: directed graph with positive costs
    :param start: starting vertex
    :param end: starting vertex
    :return: a map that maps each accessible vertex to its predecessor on a path from s to it
    '''
    if start not in graph.get_vertices():
        raise VertexException("End vertex doesn't exist\n")
    if end not in graph.get_vertices():
        raise VertexException("End vertex doesn't exist\n")

    queue = PriorityQueue()
    predecesors = {}
    predecesors[start] = -1
    distances = {}
    queue.put((0, start)) # first argument in tuple is priority
    distances[start] = 0
    found = False

    while queue.qsize() != 0 and not found:
        x = queue.get()[1]
        for y in graph.parse_outbound(x):
            if y not in distances.keys() or distances[x] + graph.get_cost(x,y) < distances[y]:
                distances[y] = distances[x] + graph.get_cost(x,y)
                queue.put((distances[y], y))
                predecesors[y] = x
        if x == end:
            found = True

    return  (predecesors, distances)

def backwards_dijkstra(graph, start, end):
    '''
        :param graph: directed graph with positive costs
        :param start: starting vertex
        :param end: starting vertex
        :return: a map that maps each accessible vertex to its predecessor on a path from s to it
        '''
    if start not in graph.get_vertices():
        raise VertexException("End vertex doesn't exist\n")
    if end not in graph.get_vertices():
        raise VertexException("End vertex doesn't exist\n")

    queue = PriorityQueue()
    sucesors = {}
    sucesors[end] = -1
    distances = {}
    queue.put((0, end))  # first argument in tuple is priority
    distances[end] = 0
    found = False

    while queue.qsize() != 0 and not found:
        x = queue.get()[1]
        for y in graph.parse_inbound(x):
            if y not in distances.keys() or distances[x] + graph.get_cost(y, x) < distances[y]:
                distances[y] = distances[x] + graph.get_cost(y, x)
                queue.put((distances[y], y))
                sucesors[y] = x
        if x == start:
            found = True

    return (sucesors, distances)

def dynamic_programming_minimum_cost_walk(graph, mxLen, start):
    '''
    :param graph:
    :param mxLen:
    :return: the cost of minimum cost walk of length at most k from s to x, or ∞ if no such walk exists
    '''
    walk = Matrix(mxLen, graph.vertices)

    for i in range(walk.columns):
        walk[0][i] = math.inf

    walk[0][start] = 0

    for k in range(1, mxLen):
        for x in range(graph.vertices):
            mn = math.inf
            for y in graph.parse_inbound(x):
                current = walk[k-1][y] + graph.get_cost(y,x)
                if mn > current:
                    mn = current
            walk[k][x] = min(mn, walk[k-1][x])
    return walk


def distinct_walks_of_minimum_cost(graph, start, end):
    '''
    :param graph:
    :param start:
    :param end:
    :return: the number of distinct walks between start and end vertices
    '''
    distances = forward_Dijkstra(graph, start, end)[1]
    if end not in distances:
        raise VertexException("Vertex not accessible from start\n")

    minimumDistance = distances[end]

g = DoubleDictGraph()

loadGraph(g, "Graphs/min_walks.txt")
print(dynamic_programming_minimum_cost_walk(g, 10, 0))

