## Lab 06: UNIX I/O (continued)
### Tasks
**Task 01:** Write a program for parallel file copying using multiple processes. (First check if the no of files entered are even and if yes then create a child process for each pair and read from one and write to other)
`./task.o f1.txt f2.txt f3.txt ...`

**Task 02:** Implement “Cat” utility.
1. Cat
    - Src: STDIN_FILENO
    - Dest: STDOUT_FILENO
2. Cat > file1.txt
    - Src: STDIN_FILENO
    - Dest: file1.txt
3. Cat file1.txt
    - Src: file1.txt
    - Dest: STDOUT_FILENO
4. Cat f1.txt > f2.txt
    - Src: f1.txt
    - Dest: f2.txt