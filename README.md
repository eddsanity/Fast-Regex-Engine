# Fast-Regex-Engine
This is my implementation of Ken Thompson's regular expressions engine, discussed in his 1968 CACM paper.

# Building

`git clone https://github.com/eddsanity/Fast-Regex-Engine.git`

`cd Fast-Regex-Engine`

Note that `main.c` isn't part of the repository, you have to provide this yourself. (Assuming you'll be using the regex engine in main.c)

`gcc main.c src/*.c -Iinclude/ -o RE.exe`

# Running tests

`cd tests/`

`gcc test.c ../src/*.c -I../include/ -o test.exe`

Console will write on screen unit tests and overall testing result.

# Documentation
Code is heavily commented.



### TBC
