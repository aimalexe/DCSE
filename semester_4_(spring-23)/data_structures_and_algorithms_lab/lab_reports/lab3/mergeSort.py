def mergeSort(array):
    if len(array) > 1:
        # Finding mid by floor division
        mid = len(array) // 2 

        # copying to two sub arrays
        leftSubArray = array[ :mid]
        rightSubArray = array[mid: ]

        mergeSort(leftSubArray)
        mergeSort(rightSubArray)

        # Merging arrays again
        array_index = 0
        l_index = 0
        r_index = 0

        # Merging in order
        while l_index < len(leftSubArray) and r_index < len(rightSubArray):
            if(leftSubArray[l_index] <= rightSubArray[r_index]):
                array[array_index] = leftSubArray[l_index]
                l_index += 1
            else:
                array[array_index] = rightSubArray[r_index]
                r_index += 1
            array_index +=1
        
        # Merging the remaining elements of left array
        while l_index < len(leftSubArray):
            array[array_index] = leftSubArray[l_index]
            l_index += 1
            array_index +=1

        # Merging the remaining elements of right array
        while r_index < len(rightSubArray):
            array[array_index] = rightSubArray[r_index]
            r_index += 1
            array_index +=1

    # Returning The sorted array!
    return array

# Driver Program
print("Unsorted list:")
data = [87, 0, 5, 1, 4, 2, 8, -5, 7 ,9, 10, 87, -3]
print(data)

print("Sorted list:")
sortedData = mergeSort(data)
print(sortedData)