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

See the [src/](/src) folder. For this project, just builds each .cpp file in place and ignore the binary.
