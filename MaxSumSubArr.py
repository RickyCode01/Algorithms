''' questo programma si propone di realizzare un algoritmo per ricavare un sottoarray di elementi 
di un dato array, tale che i suoi elementi rappresentino la somma di valore più alto contenuta 
nell'array di partenza 

1. creare funzione per ricercare la serie di valori positivi consecutivi la cui somma
 sia il valore più alto tra le serie trovate: scorrendo l'array per tutti i suoi elementi ho che
 la big-oh della mia funzione è n'''

import random

def randArr(min: int, max:int, n: int) -> list:
    if n < 0: n = -n
    random.seed()
    randArr = []
    for i in range(n):
        randArr.append(random.randint(min, max))
    return randArr

# print(randArr(-10, 10, 10))

def searchMaxSum(A:list) -> list:
    series = [] # create an array to store max serie
    i = 0 # index
    while i < len(A)-1:
        # print(series) # debug
        s = 0 # var to save sum
        row = [] # row = [start index, lenght, sum]
        if A[i] >= 0 and A[i+1] >= 0: # find two consecutive positive number
            row.append(i) # save start index
            while A[i] >= 0: # calculate sum
                s += A[i] # save value
                # print(A[i]) # debug
                if i != len(A)-1: # check last element -> avoid go out of bound
                    i += 1 # increment index
                else:
                    break
            row.append(i - row[0]) # calculate and save lenght
            row.append(s) # add sum
        if len(row) != 0: # add series to array if exist
            # add if series is empty or new series is major
            # print(row)
            if len(series) == 0 or series[2] < row[2]:
                series = row
        i += 1 # increment index
    return series if len(series) > 0 else None

# testArr = [1, 2, -10, -5, 5, 7, -9, 8, 10, 3, 2, -1]
# print(searchMaxSum(testArr))

'''2.  A questo punto devo ricercare i valori a dx e sx della serie con valore positivo e tali 
che sommando i numeri precedenti la somma rimanga > 0: se durante la ricerca trovo anche solo
un numero positivo con questi parametri lo aggiungo alla serie'''

def extendSeriesSX(A:list, S:list) -> list:
    if S != None:
        subArr = A[:(S[0] + S[1])] # get subarray from start index to beginning
        # print(subArr)
        s = 0 # var to store sum
        j = -1 # index for new elements
        for i in range(S[0]-1, 0, -1): # cycle from the element before series
            s += subArr[i]
            # print(subArr[i])
            if s >= 0: # if sum is positive
                j = i # update index
        if j > 0 : # positive index = other positive number to add to series
            return subArr[j:] # return subarray updated
        else:
            return subArr[S[0]:] # otherwise original series
    else:
        None
    
# testArr = [1, 2, -10, -5, 5, 7, -9, 8, 10, 3, 2, -1, 10]
# print(extendSeriesSX(testArr, searchMaxSum(testArr)))

def extendSeriesDX(A:list, S:list) -> list:
    subArr = A[S[0]+S[1]:] # get subarray from new element
    # print(subArr)
    s = 0 # var to store sum
    j = -1 # index for new elements
    for i in range(len(subArr)): # cycle from the element after series
        # print(subArr[i]) # debug
        s += subArr[i]
        if s >= 0: # if sum is positive
            j = i # update index
    if j > 0 : # positive index = other positive number to add to series
        return subArr[:j+1] # return extended DX part of subarray
    
# testArr = [1, 2, -10, -5, 5, 7, -9, 8, 10, 3, 2, -1, 10]
# print(extendSeriesDX(testArr, searchMaxSum(testArr)))

def extendSeries(A:list, S:list) -> list:
    Ssx = extendSeriesSX(A,S)
    Sdx = extendSeriesDX(A,S)
    # print(Ssx)
    # print(Sdx)
    if Ssx != None and Sdx != None:
        Ssx.extend(Sdx)
    return Ssx
    
testArr = randArr(-10, 10, 10)
# testArr = [-9, -7, 10, -6, -9, -1, 3, 0, 1, 9]
# testArr = [0, -7, 6, 5, 5, -2, 1, 2, 2, -10]
# testArr = [3, 10, 7, -1, -10, -7, -5, 6, 10, 3]
print(testArr)
print(extendSeries(testArr, searchMaxSum(testArr)))
''' problemi: se la serie non contiene coppie è necessario prendere i singoli numeri'''


