#!/usr/bin/env python3
import time


def read_config(file="config.txt"):
    f = open(file, "r")
    lines = f.readlines()

    n_Hauler = 1
    n_LP = 0
    n_ULP = 0
    n_SO = 0
    n_CS = 1
    init_haulers = []
    LP_positions = []
    ULP_positions = []
    SO_positions = []
    CS_positions = []
    batery_capacity = 0
    initial_energy = 0

    # for following the line number
    index = 1
    for line in lines:
        # read number of Haulers
        if(index == 1):
            n_Hauler = int(line.split("//")[0])

        # read number of LPs
        elif(index == 2):
            n_LP = int(line.split("//")[0])

        # read number of ULPs
        elif(index == 3):
            n_ULP = int(line.split("//")[0])

        # read number of SOs
        elif(index == 4):
            n_SO = int(line.split("//")[0])

        # read number of CSs
        elif(index == 5):
            n_CS = int(line.split("//")[0])

        # read Initial position of haulers
        elif(index == 6):
            t = line.split("//")[0].split("-")
            for i in range(n_Hauler):
                cordinate = t[i].replace("[", "").replace("]", "")
                x = []
                for j in range(2):
                    x.append(int(cordinate.split(",")[j]))
                init_haulers.append(x)

        # read position of LPs
        elif (index == 7):
            t = line.split("//")[0].split("-")
            for i in range(n_LP):
                cordinate = t[i].replace("[", "").replace("]", "")
                x = []
                for j in range(2):
                    x.append(int(cordinate.split(",")[j]))
                LP_positions.append(x)

        # read position of ULPs
        elif (index == 8):
            t = line.split("//")[0].split("-")
            for i in range(n_ULP):
                cordinate = t[i].replace("[", "").replace("]", "")
                x = []
                for j in range(2):
                    x.append(int(cordinate.split(",")[j]))
                ULP_positions.append(x)

        # read position of SOs
        elif (index == 9):
            t = line.split("//")[0].split("-")
            for i in range(n_SO):
                cordinate = t[i].replace("[", "").replace("]", "")
                x = []
                for j in range(2):
                    x.append(int(cordinate.split(",")[j]))
                SO_positions.append(x)
        # read position of CSs
        elif (index == 10):
            t = line.split("//")[0].split("-")
            for i in range(n_CS):
                cordinate = t[i].replace("[", "").replace("]", "")
                x = []
                for j in range(2):
                    x.append(int(cordinate.split(",")[j]))
                CS_positions.append(x)
        # read battery capacity
        elif(index == 11):
            if(line.split("//")[0] != '\t'):
                batery_capacity = int(line.split("//")[0])

        # read initial energy
        elif(index == 12):
            if(line.split("//")[0] != '\t'):
                initial_energy = int(line.split("//")[0])
        index += 1
    return init_haulers, LP_positions, ULP_positions, SO_positions, CS_positions, batery_capacity, initial_energy


def read_mission(file="mission.txt"):
    f = open(file, "r")
    lines = f.readlines()

    mission = []

    for line in lines:
        temp = line.split("\t//")[0].split(",")
        mission.append(temp)

    return mission


def write_output(makespan, completion_times, exec_time, path, file="output.txt"):
    f = open(file, "w")
    f.write("//Quantitative values\n")
    f.write(str(makespan)+"\t//Makespan" + "\n")
    for i, c in enumerate(completion_times):
        f.write(str(c)+"\t//Mission completion time hauler " + str(i+1)+"\n")
    f.write(str(exec_time)+"\t//Application execution time (in millisecond)"+"\n")
    f.write("//Path to the final points\n")
    f.write(path)
    f.close()


def main():
    """
    Replace your input files location and name.

    functions:
        read_config     -> input: config file name 
                        -> output: all variables in config file

        read_mission    -> input: mission file name
                        -> output: mission for each hauler

        write_output    -> input: scenario makespan, completion time of each hauler, elapsed time of program,
                                     path to the final points, output file name
                        -> output: void

    """
    config_file = "config.txt"
    mission_file = "mission.txt"
    output_file = "output.txt"

    init_haulers, LP_positions, ULP_positions, SO_positions, CS_positions, batery_capacity, initial_energy = read_config(
        config_file)

    mission = read_mission(mission_file)

    start = time.time()
    #################################
    # place your main code here!



    #################################
    end = time.time()
    elapsed_time = int((end - start)*1000)
    
    # call the writing function here
    # example: 
    # write_output(100, [10, 20], elapsed_time, "1,[11,9],[8,12],[7,11]\n2,[11,8],[8,11],[7.10]")



if __name__ == "__main__":
    main()
