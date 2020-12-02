#!/usr/bin/env bash

time for i in $(cat inputs); do for j in $(cat inputs); do if (($i + $j == 2020)); then let "k = $i * $j"; echo "ANSWER IS $i * $j = $k"; fi; done; done