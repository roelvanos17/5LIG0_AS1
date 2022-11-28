//
// Created by roelv on 21/11/2022.
//

#include "../inc/mission.h"
#include "../inc/graph.h"

void Mission::setMissionFileName(std::string pFilename) {
    missionFileName = pFilename;
}

void Mission::setOutputFileName(std::string pFilename) {
    outputFileName = pFilename;
}

void Mission::readMission() {
    std::ifstream file(missionFileName);
    std::string line;
    while (getline(file, line)) {
        std::string temp = line.substr(0, line.find("\t//"));
        std::size_t pos = 0;
        std::string token;
        std::string delimiter = ",";
        std::vector <std::string> mission_temp;
        while ((pos = temp.find(delimiter)) != std::string::npos) {
            token = temp.substr(0, pos);
            mission_temp.push_back(token);
            temp.erase(0, pos + delimiter.length());
        }
        mission_temp.push_back(temp);

        data.push_back(mission_temp);
    }
}

void Mission::writeResults() {
        std::ofstream file;
        file.open(outputFileName);
        file << ("//Quantitative values\n");
        file << std::to_string(makespan) << "\t//Makespan" << "\n";

        for (size_t i = 0; i < completionTimes.size(); i++)
        {
            file << completionTimes[i] << "\t//Mission completion time hauler " << std::to_string(i + 1) << "\n";
        }

        file << std::to_string(elapsedTime) << "\t//Application execution time (in millisecond)" << "\n";
        file << "//Path to the final points\n";
        file << path;
        file.close();
    }

std::string Mission::createPathString(std::vector<int> totalPath){
    std::string totalPath2;

    for(int i = 0; i < totalPath.size(); i++) {
        std::pair<unsigned int, unsigned int>coordinates = Graph::toCoordinates(totalPath[i]);


        totalPath2 += std::to_string(i)
                     + ",[" + std::to_string(coordinates.first + 1)
                     + "," + std::to_string(coordinates.second + 1) + "]\n";
    }

    return totalPath2;
}