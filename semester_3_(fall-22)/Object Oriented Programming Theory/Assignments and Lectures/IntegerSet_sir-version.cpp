// Aimal Khan.

#include <iostream>
using namespace std;

const int blockSize = 5;

int* reAllocateMemory(int* oldMemory, int oldSize, int newSize) {
    /*This function takes in a pointer to an existing block of memory (oldMemory), along with the current size of that memory block (oldSize) and
    the desired new size of the memory block (newSize). It then creates a new block of memory of the desired size (newMemory),
    and if the old memory block is not null, it copies the contents of the old memory block to the new memory block.
    Finally, it deletes the old memory block and returns a pointer to the new memory block.*/
    int* newMemory = new int[newSize];
    if (oldMemory != NULL) { // copy from old memory to new memory:
        for (int i = (oldSize < newSize ? oldSize : newSize) - 1; i >= 0; i--)
            newMemory[i] = oldMemory[i];
        delete[] oldMemory;
    }
    return newMemory;
}

int binarySearch(int searchIt, int *arr, int sizeOfArr){ //Find a number in set of given size.
    if(sizeOfArr == 0 || searchIt <= arr[0]) return 0;
    if(searchIt > arr[sizeOfArr-1]) return sizeOfArr;

    int mid, leftHalf = 0, rightHalf = sizeOfArr - 1;
    while(rightHalf - leftHalf > 1){
        mid = (leftHalf + rightHalf) / 2;
        (searchIt <= arr[mid] ? rightHalf : leftHalf) = mid;
    }
    return rightHalf;
}

static int* deepCopyIntArray(int n, int* originalArray) {
    int* copiedArray = new int[n];
    for (int i = 0; i < n; i++) {
        copiedArray[i] = originalArray[i];
    }
    return copiedArray;
}


class IntegerSet {
    private:
        int setSize; // number of elements in the set
        int* setData; // pointer to the array containing the set

    public:
        IntegerSet(): setSize(0), setData(NULL) {}
        IntegerSet(int x) :setSize(0){
            setData = new int [blockSize];
            setData[0]=x;
            setSize++;
        }
        ~IntegerSet() {
            delete[] setData;
        }
        IntegerSet& operator+=(int x) { // adds x to the set
            int index = binarySearch(x, setData, setSize);
            if (index >= setSize || x != setData[index]) { // x is not yet in set?
                if (setSize % blockSize == 0) {
                    setData = reAllocateMemory(setData, setSize, setSize + blockSize);
                }
                for (int i = setSize; i > index; i--) {
                    setData[i] = setData[i-1];
                }
                setSize++;
                setData[index] = x;
            }
            return *this;
        }
        IntegerSet& operator-=(int x) { // removes x from the set
            int index = binarySearch(x, setData, setSize);
            if (index < setSize && x == setData[index]) {
                setSize--;
                for (int i = index; i < setSize; i++)
                    setData[i] = setData[i+1];
                if (setSize % blockSize == 0)
                    setData = reAllocateMemory(setData, setSize+1, setSize); // release one block
            }
            return *this;
        }
        bool operator()(int x) const { // returns true if x is in the set
            int index = binarySearch(x, setData, setSize);
            return index < setSize && x == setData[index];
        }
        void print() const { // prints all elements of the set on one line
            for (int i = 0; i < setSize; i++)
                cout << setData[i] << " ";
            cout<<endl;
        }
        IntegerSet& operator=(const IntegerSet& other) { // assignment operator
            delete setData;
            setSize = other.setSize;
            setData = deepCopyIntArray(setSize, other.setData);
            return *this;
        }
        IntegerSet(const IntegerSet& other) { // copy constructor
            setSize = other.setSize;
            setData = deepCopyIntArray(setSize, other.setData);
        }
        operator int() { // convert IntegerSet to int
            return setSize;
        }
};

int main(){

    IntegerSet S = 1000, T, U = S;
    if (!T)
        cout << "T is empty.\n";
    if (int(U))
        cout << "U is not empty.\n";

    S = S + 1002; S += 10000;
    (((S += 10) +=1) += 20) += 200;
    //S = S + 12;
    cout << "There are " << int(S) << " elements in S\n";

    T += 50; T += 50;
    cout << "S: "; S.print();
    S -= 1000; cout <<"1000 removed from S\n";

    if (S(1000))
        cout << "1000 belongs to S (error)\n";
    else
        cout << "1000 is no longer in S\n";
    if (S(100))
        cout << "100 still belongs to s\n";

    cout << "S: "; S.print();
    cout << "T: "; T.print();
    cout << "U: "; U.print();

    T = S;
    cout << "After assigning S to T, we have T: ";
    T.print();

    return 0;
    //Refactor and Debugged by: Aimal Khan
}
