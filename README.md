# Advent of Code 2020

This is a flat C++ sandbox, just build each .cpp file in place and ignore the binary.

Also here is a solution to the first puzzle, in one shell command:

```shell
time for i in $(cat _inputs); do \
  for j in $(cat _inputs); do \
    if (($i + $j == 2020)); then \
      let "k = $i * $j"; echo "ANSWER IS $i * $j = $k"; \
      fi; done; done
```

