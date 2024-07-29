#This is about a implementation of dijkstra algorithm
infinite = float('inf')

graph = {}

#Defines the linking beetween start node and 'a' and 'b' nodes. The value is the weigth
graph['start'] = {}
graph['start']['a'] = 6
graph['start']['b'] = 2 

#Defines the linkings of 'a' node
graph['a'] = {}
graph['a']['end'] = 1

#Defines the linkings of 'b' node
graph['b'] = {}
graph['b']['a'] = 3
graph['b']['end'] = 5

graph['end'] = {} #Final node doesn't have a link to another node

#Creates the table of weigths to go from 'start' to that node. Initially, we consider 'end' to have an infinite weigth once it's not directly linked to 'start'
costs = {}
costs['a'] = 6
costs['b'] = 2
costs['end'] = infinite

#Creates the table of parents of each node considering the cheapest way
parents = {}
parents['a'] = 'start'
parents['b'] = 'start'
parents['end'] = 'none'

processed = [] #It's important to control the processed nodes to not process them twice

def findLowerCost(costs):
    lowerCost = infinite #Initially, the lowest cost is infinite
    lowerCostNode = None #Initially, the lowest cost node is not known
    for node in costs: #We are looking in a dictionary, so node will get the keys of each value
        cost = costs[node] 
        if cost < lowerCost and node not in processed:
            lowerCost = cost
            lowerCostNode = node
    return lowerCostNode #Returns the cheapest neighbour node. If 'None', there are no more nodes to process

node = findLowerCost(costs) #It will look for the lowest cost node that is linked to 'start'. In this case, it's 'b' in the beginning
while node is not None: 
    cost = costs[node] #cost get the costs['b'], which is 2, in the first execution
    neighbors = graph[node] #This will get the dictionary of the nodes that are linked to the current node. First, it will get the neighbors of 'b'
    for n in neighbors.keys(): #neighbors.keys() returns an array containing all the keys in the dictionary. In the first run, it's 'a' because of how it was declared
        newCost = cost + neighbors[n] #Checks the whole cost to get to that neighbor node from 'start'. In the first run, it's the cost to get to 'a' from 'start'
        if costs[n] > newCost: #If the cost of the node was bigger than the new cost, we found a cheaper way
            costs[n] = newCost #The cost is updated. In the case of the first run, with 'a', it went from 6 to 5
            parents[n] = node #The parent node changed. For 'a' in the first run it was 'start', now it's 'b'
    processed.append(node) #Adds the node to the processed array. In the first run, 'b' will be added here
    node = findLowerCost(costs) #Finds a new node to look for

print(costs)
print(parents)


