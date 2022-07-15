# generate all possible permutations of an array (heap's algorithm)
# generate directionality index of each possible permutation (bubble-sort times)

def heapPermutation(array):
    arraySize = len(array)
    ct = []
    for i in range(arraySize):
        ct.append(0)
    permutationArray = []
    arr = []
    arr.extend(array)
    permutationArray.append(arr)
    i = 1
    while i < arraySize:
        if ct[i] < i:
            if i % 2 == 0:
                temp = array[0]
                array[0] = array[i]
                array[i] = temp
            else:
                temp = array[ct[i]]
                array[ct[i]] = array[i]
                array[i] = temp
            per = []
            for j in range(arraySize):
                per.append(array[j])
            permutationArray.append(per)
            ct[i] += 1
            i = 1
        else:
            ct[i] = 0
            i += 1
    return permutationArray

def bubbleSort(arr):
    DI = 0
    array = arr.copy()
    arraySize = len(array)
    for i in range(arraySize):
        for j in range(0, arraySize - i - 1):
            if array[j] > array[j+1]:
                temp = array[j]
                array[j] = array[j+1]
                array[j+1] = temp
                DI += 1
    return DI

array = [1,2,3,4,5]
permutationArray = heapPermutation(array)
directionalityIndex = []  # directionality index, defined by times of bubblesorting
for i in range(120):
    directionalityIndex.append(bubbleSort(permutationArray[i]))
    # print("{}\t{}\t{}".format(i, directionalityIndex[i], permutationArray[i]))

file = open('sequences_directionalityIndex.csv', mode='w')
print("RUN,SEQ1,SEQ2,SEQ3,SEQ4,SEQ5,DI", file=file)
for i in range(120):
    print("%d,%d,%d,%d,%d,%d,%d" %(i,permutationArray[i][0],permutationArray[i][1],permutationArray[i][2],permutationArray[i][3],permutationArray[i][4],directionalityIndex[i]), file=file)
file.close()