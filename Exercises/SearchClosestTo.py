import random

def RandomOrderList(n) -> list: # return shuffled list of ordered elements
    mylist = list(range(10))
    random.shuffle(mylist)
    return mylist

def findLostElement(list) -> int:
    sum = 0
    for element in list:
        sum += element
    return (int)(len(list)*(len(list)+1)/2) - sum # Gauss formula - list sum = lost element
    
mylist = RandomOrderList(10)
mylist.remove(7)
print(mylist)
print("lost element: " + str(findLostElement(mylist)))
