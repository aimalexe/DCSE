def bubbleSort (array):
    for step in range(0, len(array)):
        for i in range(0, len(array)-1):
            if(array[i] > array[i + 1]):
                array[i + 1], array[i] = array[i], array[i + 1]
    
    return array

print("Unsorted list:")
data = [2, -7, 8 , 2, -3, 5, 0 , 1]
print(data)

print("Sorted list:")
sortedData = bubbleSort(data)

print(sortedData)