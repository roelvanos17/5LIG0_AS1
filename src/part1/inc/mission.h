//
// Created by roelv on 21/11/2022.
//
#include <fstream>
#include <vector>


#ifndef INC_5LIG0_AS1_MISSION_H
#define INC_5LIG0_AS1_MISSION_H


class Mission {
public:
    std::vector<std::vector<std::string>> data;

    unsigned int makespan;
    std::vector<unsigned int> completionTimes;
    int64_t elapsedTime;
    std::string path;

    void setMissionFileName(std::string pFilename);
    void setOutputFileName(std::string pFilename);

    void readMission();
    void writeResults(

    );

private:
    std::string missionFileName;
    std::string outputFileName;

};


#endif //INC_5LIG0_AS1_MISSION_H
