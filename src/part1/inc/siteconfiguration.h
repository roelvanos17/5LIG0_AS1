//
// Created by roelv on 21/11/2022.
//

#include <fstream>
#include <vector>

#ifndef INC_5LIG0_AS1_SITECONFIGURATION_H
#define INC_5LIG0_AS1_SITECONFIGURATION_H

enum pointType {
    START,
    UNLOADING,
    LOADING,
};

class SiteConfiguration {
public:
    unsigned int n_Hauler = 1;
    unsigned int n_LP = 0;
    unsigned int n_ULP = 0;
    unsigned int n_SO = 0;
    unsigned int n_CS = 1;
    std::vector<std::pair<unsigned int, unsigned int>> init_haulers;
    std::vector<std::pair<unsigned int, unsigned int>> LP_positions;
    std::vector<std::pair<unsigned int, unsigned int>> ULP_positions;
    std::vector<std::pair<unsigned int, unsigned int>> SO_positions;
    std::vector<std::pair<unsigned int, unsigned int>> CS_positions;
    unsigned int batery_capacity = 0;
    unsigned int initial_energy = 0;

    void setFileName(std::string pFilename);
    void readConfig();

    std::pair<unsigned int, unsigned int> getPointCoordinates(pointType type, int pPointNumber);


private:
    std::string fileName;

};


#endif //INC_5LIG0_AS1_SITECONFIGURATION_H
