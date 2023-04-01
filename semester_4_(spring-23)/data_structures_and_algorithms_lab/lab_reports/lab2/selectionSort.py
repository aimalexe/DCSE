def selectionSort(data):
    for step in range(0, len(data) - 1):    #for swapping smallest with current index
        min = step
        for i in range(step + 1, len(data)):    # for finding a minimum number.
            if(data[min] > data[i]):
                min = i
        data[min], data[step] = data[step], data[min] # swapping
    return data;

print("Unsorted list:")
data = [2, -7, 8 , 2, -3, 5, 0 , 1]
print(data)

print("Sorted list:")
sortedData = selectionSort(data)

print(sortedData)