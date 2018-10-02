# som
Self Organizing Map

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/8992ab04aeb34aed93fecd777b5c0176)](https://www.codacy.com/app/sumedhe/som?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=sumedhe/som&amp;utm_campaign=Badge_Grade)

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

## Run tests
Using `unit_tests`:
```
$ ./bin/unit_tests
```

Using `ctest`:
```
$ ctest
```

