def recursiveBinarySearch(data, key, lower, upper):
    if(lower <= upper):
        mid = lower + (upper - lower) // 2;

        if data[mid] == key:
            return mid;
        elif data[mid] < key:
            return recursiveBinarySearch(data, key, mid + 1, upper)
        else:
            return recursiveBinarySearch(data, key, lower, mid - 1)
    return -1;


def loopingBinarySearch(data, key):
    lower = 0
    upper = len(data) - 1
    
    while lower <= upper:
        mid = lower + (upper - lower) // 2;

        if data[mid] == key:
            return mid;
        elif data[mid] < key:
            lower = mid + 1
        else:
            upper = mid - 1

    return -1

def displayResult(index, key):
    print(f"The key('{key}') is found at index: '{index}'") if index > -1 else print(f"The key('{key}') is't present in given data")


sortedArray = [-5, -3, 0, 1, 2, 4, 5, 7, 8, 9, 10, 87, 87]

in_1 = recursiveBinarySearch(sortedArray, 4, 0, len(sortedArray) - 1)
displayResult(in_1, 4)
in_2 = recursiveBinarySearch(sortedArray, 3, 0, len(sortedArray) - 1)
displayResult(in_2, 3)
in_3 = recursiveBinarySearch(sortedArray, 10, 0, len(sortedArray) - 1)
displayResult(in_3, 10)

print("")

in_4 = loopingBinarySearch(sortedArray, 4)
displayResult(in_4, 4)
in_5 = loopingBinarySearch(sortedArray, 3)
displayResult(in_5, 3)
in_6 = loopingBinarySearch(sortedArray, 10)
displayResult(in_6, 10)