from DirectedGraph import *

def BF(vertex, graph):
    '''
    Breadth-first traversal
    :param vertex:
    :param graph:
    :return: the path
    :exception: vertex not valid
    '''
    #graph = DoubleDictGraph()
    if not vertex < graph.vertices:
        raise VertexException("Vertex doesn't exist")

    queue = graph.parse_outbound(vertex)
    visited = [vertex]

    current = 0
    while len(queue) > current:
        vertex = queue[current]
        if vertex not in visited:
            queue += graph.parse_outbound(vertex)
            visited.append(vertex)
        current += 1

    return visited

def connected_components(graph):
    '''
    :param graph: undirected graph
    :return: list of all connected components
    '''
    connectedComponents = []
    for i in range(graph.vertices):
        visited = 0
        for component in connectedComponents:
            if i in component:
                visited = 1
                break
        if visited == 0:
            connectedComponents.append(BF(i, graph))
    return connectedComponents

