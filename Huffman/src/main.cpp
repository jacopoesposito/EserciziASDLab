using namespace std;
#include "iostream"
#include <filesystem>
#include <fstream>
#include "./lib/frequencyCalculation.hpp"
#include "./lib/huffman.hpp"

void displaymenu(){
    cout << "\n******************************************";
    cout << "\n**        HuffMan Encoder/Decoder       **";
    cout << "\n**        1)Codifica messaggio          **";
    cout << "\n**        2)Decodifica messaggio        **";
    cout << "\n******************************************";
}

int main(){
    string str;
    string nameFile;
    cin >> nameFile;
    FrequencyCalculation *FreqCalc = new FrequencyCalculation(nameFile);
    
    if(!FreqCalc->checkInit())
        return -1;
    
    FreqCalc->CreateFrequencyTable();
    
    map<unsigned char, int> freqChar = FreqCalc->getFreq();

    for(auto it = freqChar.cbegin(); it != freqChar.cend(); ++it){
        cout << it->first << " " << " " << it->second << endl;
    }

    Huffman *HF = new Huffman(FreqCalc);
    Node *root = HF->genereteHFTree();
    HF->setRoot(root);
    HF->createHFDictionary(root, str);
    HF->encodeHuffman();
    cout << "Stringa codificata-> " << HF->getEncodedString() << endl;
    HF->decodeHuffman();
    HF->calculateBitsSaving();
    cout << "Stringa decodificata-> " << HF->getDecodedString() << endl;
    cout << "Numero di bit stringa originale-> " << HF->getBitOriginalString() << endl;
    cout << "Numero di bit stringa codificata-> " << HF->getBitEncodedString() << endl;
    cout << "Risparmio totale-> " << HF->getBitOriginalString() - HF->getBitEncodedString() << endl;
}