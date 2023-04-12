using namespace std;
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

#ifndef FREQUENCY_CALCULATION
#define FREQUENCY_CALCULATION
//Helper class to calculate the frequency of character in the file given from input
class FrequencyCalculation{

    public:
        FrequencyCalculation(const string &strFile);
        void CreateFrequencyTable();
        map<unsigned char, int> getFreq();
        vector<unsigned char> getBufferInput();
        bool checkInit();
    private:
        ifstream file;
        bool isInitialized = false;
        vector<unsigned char> vecBuffer;
        map<unsigned char, int> char_freq; //Frequency of the char
};

//The constructor initialize some variable and read the file
FrequencyCalculation::FrequencyCalculation(const string &strFile){

    file.open(strFile);
    
    if(!file.is_open()){
        cout << "File doesn't exist";
        return;
    }
    isInitialized = true;

    istream_iterator<unsigned char> begin = file;

    vector<unsigned char> buffer(begin, istream_iterator<unsigned char> ());
    vecBuffer = buffer;
}

void FrequencyCalculation::CreateFrequencyTable(){

    vector<unsigned char>::iterator it;
    map<unsigned char, int>::iterator char_freq_iter;

    for(it = vecBuffer.begin(); it != vecBuffer.end(); it++){
        char_freq_iter = char_freq.find(*it);

        if(char_freq_iter!=char_freq.end()){
            char_freq_iter->second += 1;
        }
        else{
            char_freq[*it]=1;
        }
    }
}

map<unsigned char, int> FrequencyCalculation::getFreq(){
    return char_freq;
}

vector<unsigned char> FrequencyCalculation::getBufferInput(){
    return vecBuffer;
}

bool FrequencyCalculation::checkInit(){
    return isInitialized;
}
#endif