#pragma once

#include <iostream>
#include <fstream>

class FileUtil
{
    public:

        static void load_sprite(char sprite[], int w, int h, std::string filePath)
        {
            std::ifstream inputFile;
            inputFile.open(filePath);

            for(int i = 0; i < h; i++)
            {
                for(int j = 0; j < w; j++)
                {
                    inputFile >> sprite[(i * w) + j];
                }
            }
        }
};
