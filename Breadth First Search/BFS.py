#Basic implementation of Breadth First Search algorithm, which searches in graphos

def sellsMango(person):
    return person[-1] == 'm'
from collections import deque #deque is for double ended queue

grapho = {}
grapho["first"] = ["alice", "bob", "claire"]
grapho["bob"] = ["anuj", "peggy"]
grapho["alice"] = ["peggy"]
grapho["claire"] = ["thom", "jhonny"]
grapho["anuj"] = [] 
grapho["peggy"] = []
grapho["thom"] = []
grapho["johnny"] = []

def search(name):
    search_queue = deque()
    search_queue += grapho[name]
    verified = [] #Receives the people that were already verified
    while search_queue: #Runs while the queue isn't empty
        person = search_queue.popleft() #Takes the first element of the queue
        if not person in verified:
            if sellsMango(person): #If the elements sells Mango
                print(person + " sells mango")
                return True
            else: 
                search_queue += grapho[person] #If the element doesn't sells mango, their neighbors enter the queue
                verified.append(person)
    return False 

search("thom")
        
