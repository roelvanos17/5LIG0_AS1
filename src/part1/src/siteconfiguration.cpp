//
// Created by roelv on 21/11/2022.
//

#include <iostream>
#include "../inc/siteconfiguration.h"

void SiteConfiguration::setFileName(std::string pFilename) {
    fileName = pFilename;
}

void SiteConfiguration::readConfig() {
    std::ifstream file(fileName);
    std::string line;

    // variable to keep track of file line
    std::size_t index = 1;
    while (getline(file, line))
    {
        // read number of Haulers
        if (index == 1)
        {
            n_Hauler = std::stoi(line.substr(0, line.find("\t//")));
        }
            // read number of LPs
        else if (index == 2)
        {
            n_LP = std::stoi(line.substr(0, line.find("\t//")));
        }
            // read number of ULPs
        else if (index == 3)
        {
            n_ULP = std::stoi(line.substr(0, line.find("\t//")));
        }
            // read number of SOs
        else if (index == 4)
        {
            n_SO = std::stoi(line.substr(0, line.find("\t//")));
        }
            // read number of CSs
        else if (index == 5)
        {
            n_CS = std::stoi(line.substr(0, line.find("\t//")));
        }
            // read Initial position of haulers
        else if (index == 6)
        {
            std::string temp = line.substr(0, line.find("\t//"));
            std::size_t pos = 0;
            std::string token;
            std::string delimiter = "-";
            unsigned int x, y;
            while ((pos = temp.find(delimiter)) != std::string::npos)
            {
                token = temp.substr(0, pos);
                sscanf(token.c_str(), "[%d,%d]", &x, &y);
                init_haulers.push_back(std::make_pair(x, y));
                temp.erase(0, pos + delimiter.length());
            }
            sscanf(temp.c_str(), "[%d,%d]", &x, &y);
            init_haulers.push_back(std::make_pair(x, y));
        }

            // read position of LPs
        else if (index == 7)
        {
            std::string temp = line.substr(0, line.find("\t//"));
            std::size_t pos = 0;
            std::string token;
            std::string delimiter = "-";
            unsigned int x, y;
            while ((pos = temp.find(delimiter)) != std::string::npos)
            {
                token = temp.substr(0, pos);
                sscanf(token.c_str(), "[%d,%d]", &x, &y);
                LP_positions.push_back(std::make_pair(x, y));
                temp.erase(0, pos + delimiter.length());
            }
            sscanf(temp.c_str(), "[%d,%d]", &x, &y);
            LP_positions.push_back(std::make_pair(x, y));
        }

            // read position of ULPs
        else if (index == 8)
        {
            std::string temp = line.substr(0, line.find("\t//"));
            std::size_t pos = 0;
            std::string token;
            std::string delimiter = "-";
            unsigned int x, y;
            while ((pos = temp.find(delimiter)) != std::string::npos)
            {
                token = temp.substr(0, pos);
                sscanf(token.c_str(), "[%d,%d]", &x, &y);
                ULP_positions.push_back(std::make_pair(x, y));
                temp.erase(0, pos + delimiter.length());
            }
            sscanf(temp.c_str(), "[%d,%d]", &x, &y);
            ULP_positions.push_back(std::make_pair(x, y));
        }

            // read position of SOs
        else if (index == 9)
        {
            if (n_SO != 0)
            {
                std::string temp = line.substr(0, line.find("\t//"));
                std::size_t pos = 0;
                std::string token;
                std::string delimiter = "-";
                unsigned int x, y;
                while ((pos = temp.find(delimiter)) != std::string::npos)
                {
                    token = temp.substr(0, pos);
                    sscanf(token.c_str(), "[%d,%d]", &x, &y);
                    SO_positions.push_back(std::make_pair(x, y));
                    temp.erase(0, pos + delimiter.length());
                }
                sscanf(temp.c_str(), "[%d,%d]", &x, &y);
                SO_positions.push_back(std::make_pair(x, y));
            }
        }

            // read position of CSs
        else if (index == 10)
        {
            if (n_CS != 0)
            {
                std::string temp = line.substr(0, line.find("\t//"));
                std::size_t pos = 0;
                std::string token;
                std::string delimiter = "-";
                unsigned int x, y;
                while ((pos = temp.find(delimiter)) != std::string::npos)
                {
                    token = temp.substr(0, pos);
                    sscanf(token.c_str(), "[%d,%d]", &x, &y);
                    CS_positions.push_back(std::make_pair(x, y));
                    temp.erase(0, pos + delimiter.length());
                }
                sscanf(temp.c_str(), "[%d,%d]", &x, &y);
                CS_positions.push_back(std::make_pair(x, y));
            }
        }

        // read battery capacity
        if (index == 11)
        {
            if (n_CS != 0)
                batery_capacity = std::stoi(line.substr(0, line.find("\t//")));
        }

        // read initial energy
        if (index == 12)
        {
            if (n_CS != 0)
                initial_energy = std::stoi(line.substr(0, line.find("\t//")));
        }

        index++;
    }

    file.close();
}

std::pair<unsigned int, unsigned int> SiteConfiguration::getPointCoordinates(pointType type, int pPointNumber) {
    unsigned int row;
    unsigned int col;

    switch (type) {
        case START:
            row = init_haulers[pPointNumber - 1].first;
            col = init_haulers[pPointNumber - 1].second;
            return {row, col};
        case UNLOADING:
            row = ULP_positions[pPointNumber - 1].first;
            col = ULP_positions[pPointNumber - 1].second;
            return {row, col};
        case LOADING:
            row = LP_positions[pPointNumber - 1].first;
            col = LP_positions[pPointNumber - 1].second;
            return {row, col};
        default:
            return {0, 0};
    }
}