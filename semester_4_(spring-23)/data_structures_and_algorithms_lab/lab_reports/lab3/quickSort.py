def partition(data, first, last):
    pivot = data[first]

    lower = first + 1
    upper = last

    done = False
    while not done:
        while lower <= upper and data[lower] <= pivot:
            lower = lower + 1

        while lower <= upper and data[upper] >= pivot:
            upper = upper - 1

        if upper < lower:
            done = True
        else:
            data[lower], data[upper] = data[upper], data[lower]

    data[first], data[upper] = data[upper], data[first]
    return upper;

def quickSort(data, left, right):
    if left < right:
        pivot = partition(data, left, right)
        
        quickSort(data, left, pivot - 1)
        quickSort(data, pivot + 1, right)

    return data

# Driver Program
print("Unsorted list:")
data = [87, 0, 5, 1, 4, 2, 8, -5, 7 ,9, 10, 87, -3]
print(data)

print("Sorted list:")
sortedData = quickSort(data, 0, len(data)-1)
print(sortedData)