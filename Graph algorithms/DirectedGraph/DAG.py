from DirectedGraph import *

def topological_sort_predecessor_counting(graph):
    '''
    :param graph: graph with costs
    :return: a list of vertices in topological sorting order, or None if the graph has cycles
    '''
    sorted = []
    queue = []
    count = {}
    for x in graph.get_vertices():
        count[x] = graph.get_in_degree(x)
        if count[x] == 0:
            queue.append(x)

    while len(queue) != 0:
        x = queue.pop(0)
        sorted.append(x)
        for y in graph.parse_outbound(x):
            count[y] -= 1
            if count[y] == 0:
                queue.append(y)

    if len(sorted) < len(graph.get_vertices()):
        return None
    return sorted


g=DoubleDictGraph()
loadGraph(g, "Graphs/Example.txt")

#print(topological_sort_predecessor_counting(g))
