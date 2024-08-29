#This is about an example greedy algorithm that deals with the problem of the radio station (chapter 8 of the book). The ideal solution would be O(2^n).

states_to_include = set(["mt", "wa", "or", "id", "nv", "ut", "ca", "az"]) #The states that the radio wants to include

#Hash table to show the states that each station include:
stations = {}
stations["kone"] = set(["id", "nv", "ut"])
stations["ktwo"] = set(["wa", "if", "mt"])
stations["kthree"] = set(["or", "nv", "ca"])
stations["kfour"] = set(["nv", "ut"])
stations["kfive"] = set(["ca", "az"])

final_stations = set() #Will save the answer

while states_to_include:
    best_station = None
    included_states = set()
    for station, states in stations.items():
        included = states_to_include & states #Intersection between two sets
        if len(included) > len(included_states):
            best_station = station
            included_states = included

    states_to_include -= included_states
    final_stations.add(best_station)

print(final_stations)


