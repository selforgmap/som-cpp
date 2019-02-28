# som
Self Organizing Map

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/3edaa95bc0d242f882c1df67fc161991)](https://www.codacy.com/app/sumedhe/som-cpp?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=selforgmap/som-cpp&amp;utm_campaign=Badge_Grade)

# Setting up the project
Here are the instructions on how to setup the project.
## Build
Clone the repository
```
$ git clone https://github.com/sumedhe/som.git
$ cd som
```
Then run `cmake`
```
$ cmake -H. -Bbuild
$ cd build
$ cmake --build .
```
## Run program
To start the program,
```
$ ./bin/som
```
## Run tests
Using `unit_tests`:
```
$ ./bin/unit_tests
```

Using `ctest`:
```
$ ctest
```

