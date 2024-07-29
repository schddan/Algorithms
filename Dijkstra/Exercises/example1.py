#The algorithm implemented using the example of the video https://www.youtube.com/watch?v=hsJBilAiZDY
graph = {}

graph['a'] = {}
graph['a']['b'] = 2
graph['a']['c'] = 1

graph['b'] = {}
graph['b']['d'] = 1

graph['c'] = {}
graph['c']['d'] = 3
graph['c']['e'] = 4

graph['d'] = {}
graph['d']['f'] = 2

graph['e'] = {}
graph['e']['f'] = 2

graph['f'] = {}

infinite = float('inf')

costs = {}
costs['b'] = 2
costs['c'] = 1
costs['d'] = infinite
costs['e'] = infinite
costs['f'] = infinite

parents = {}
parents['b'] = 'a'
parents['c'] = 'a'
parents['d'] = 'b'
parents['e'] = 'c'
parents['f'] = 'e'

processed = []

def findLowerCost(costs):
    lowerCost = float('inf') 
    lowerCostNode = None 
    for node in costs: 
        cost = costs[node] 
        if cost < lowerCost and node not in processed:
            lowerCost = cost
            lowerCostNode = node
    return lowerCostNode 

node = findLowerCost(costs) 
while node is not None: 
    cost = costs[node] 
    neighbors = graph[node] 
    for n in neighbors.keys(): 
        newCost = cost + neighbors[n] 
        if costs[n] > newCost:
            costs[n] = newCost 
            parents[n] = node 
    processed.append(node) 
    node = findLowerCost(costs)

print(costs)
print(parents)


