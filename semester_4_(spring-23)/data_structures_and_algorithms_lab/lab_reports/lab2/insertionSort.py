def insertionSort(data):
    for i in range(1, len(data)):
        key = data[i]
        j = i -1
        while(j >= 0 and key < data[j] ):
            data[j + 1] = data[j]
            j = j -1
        data[j+1] = key
    return data

print("Unsorted list:")
data = [2, -7, 8 , 2, -3, 5, 0 , 1]
print(data)

print("Sorted list:")
sortedData = insertionSort(data)
print(sortedData)