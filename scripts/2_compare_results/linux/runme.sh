#!/bin/bash
## (c) Pourya Gohari 2022
#Colors
RED='\033[0;31m' #RED
NC='\033[0m'     # No Color
GR='\033[0;32m'  # GREEN
BL='\033[0;34m'  # BLUE

parts=(Part1 Part2 Part3 Part4)

level=(0-Easy 1-Medium 2-Hard)

length=(4 6 8 10 12 14)
# For Part4
length_extended=(8 10 12 14 16 18)

rm -rf final_result.csv

for i in "${!parts[@]}"; do
  echo "${parts[$i]} Started..."
  if [[ "${parts[$i]}" == "Part4" ]]; then
    for j in "${!level[@]}"; do
      echo "level: ${level[$j]}"
      for k in "${!length_extended[@]}"; do
        echo "Mission length=${length_extended[$k]}"
        for l in {1..5}; do
          cp -rf ./inputs/"${parts[$i]}"/"${level[$j]}"/"${length_extended[$k]}"/"${l}"_config.txt ./config.txt
          cp -rf ./inputs/"${parts[$i]}"/"${level[$j]}"/"${length_extended[$k]}"/"${l}"_mission.txt ./mission.txt
          cp -rf ./results/"${parts[$i]}"/"${level[$j]}"/"${length_extended[$k]}"/"${l}"_output.txt ./output.txt
          ##########
          python3 ./sanity_check.py
          python3 ./write_csv.py
          ##########
          rm -rf ./output.txt
          rm -rf ./config.txt
          rm -rf ./mission.txt
          rm -rf ./result.txt
        done
      done
    done
  else
    for j in "${!level[@]}"; do
      echo "level: ${level[$j]}"
      for k in "${!length[@]}"; do
        echo "Mission length=${length[$k]}"
        for l in {1..5}; do
          cp -rf ./inputs/"${parts[$i]}"/"${level[$j]}"/"${length[$k]}"/"${l}"_config.txt ./config.txt
          cp -rf ./inputs/"${parts[$i]}"/"${level[$j]}"/"${length[$k]}"/"${l}"_mission.txt ./mission.txt
          cp -rf ./results/"${parts[$i]}"/"${level[$j]}"/"${length[$k]}"/"${l}"_output.txt ./output.txt
          ##########
          python3 ./sanity_check.py
          python3 ./write_csv.py
          ##########
          rm -rf ./output.txt
          rm -rf ./config.txt
          rm -rf ./mission.txt
          rm -rf ./result.txt
        done
      done
      if [[ "${parts[$i]}" == "Part1" ]]; then
        break
      fi
    done
  fi
done
echo DONE!
