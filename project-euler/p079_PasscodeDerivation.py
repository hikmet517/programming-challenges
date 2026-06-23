from subprocess import run
from queue import Queue


def read_graph() -> dict[int, list[int]]:
    graph = {}
    with open("p079_keylog.txt") as f:
        for line in f:
            line = line.strip()
            x = int(line[0])
            y = int(line[1])
            z = int(line[2])
            if x not in graph:
                graph[x] = []
            graph[x].append(y)
            graph[x].append(z)
            if y not in graph:
                graph[y] = []
            graph[y].append(z)
        for x in graph:
            graph[x] = list(set(graph[x]))
        return graph


def draw_graph(graph):
    with open("p079_passcode-graph.dot", "w") as fp:
        fp.write("digraph {\n")
        for n in graph:
            for m in graph[n]:
                fp.write(f"  {n} -> {m}\n")
        fp.write("}\n")

    run("dot -Tpng 079_passcode-graph.dot -o 079_passcode-graph.png", shell=True)


def topological_sort(graph: dict[int, list[int]]):
    # find all nodes
    nodes = set()
    for fr in graph:
        nodes.add(fr)
        for to in graph[fr]:
            nodes.add(to)

    l = []
    marked = set()

    def visit(n):
        if n in marked:
            return

        if n in graph:
            for m in graph[n]:
                visit(m)

        marked.add(n)
        l.append(n)

    while True:
        unmarked = nodes - marked
        if len(unmarked) == 0:
            l.reverse()
            return l
        visit(unmarked.pop())


graph = read_graph()
# draw_graph(graph)
sorted = topological_sort(graph)
print(sorted)
