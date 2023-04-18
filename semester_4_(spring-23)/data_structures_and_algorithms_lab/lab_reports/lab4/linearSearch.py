def linearSearch(data, key):
    for i  in range(len(data) - 1):
        if data[i] == key:
            return i
    else:
        return -1

def displayResult(index, key):
    print(f"The key('{key}') is found at index: '{index}'") if index > -1 else print(f"The key('{key}') is't present in given data")


array = [87, 0, 5, 1, 4, 2, 8, -5 ,7 ,9, 10, 87, -3]

in_1 = linearSearch(array, 4)
displayResult(in_1, 4)
in_2 = linearSearch(array, 3)
displayResult(in_2, 3)
in_3 = linearSearch(array, 10)
displayResult(in_3, 10)