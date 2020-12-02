# Advent of Code 2020

This is a solution to the first puzzle, in one shell command:

```shell
time for i in $(cat _inputs); do \
  for j in $(cat _inputs); do \
    if (($i + $j == 2020)); then \
      let "k = $i * $j"; echo "ANSWER IS $i * $j = $k"; \
      fi; done; done
```

I have an ulterior motive to develop C++ skills, so I also built basically solution in C++.

See the [src/](/src) folder. This project builds with [CMake](https://cmake.org).

However, the next puzzle indicates that we are going to be escalating the complexity here.
The first step escalation involves a loop within a loop to find 3 (up from 2) matching items,
therefore I will implement a recursive search function

> Find <n> items from set <amounts> having a sum of <t>
> Returns the first answer found, or an empty set

that calls itself until there are only 2.

