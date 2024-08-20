#include <iostream>
#include <fstream>
#include <string>

#include "compact_enc_det/compact_enc_det.h"

/*
clang++ -I.. -L../lib -lced  main.cpp
*/

int main(){
    std::ifstream in("utf8_bom.csv");
    std::string contents((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
    const char* text = contents.c_str();

    bool is_reliable;
    int bytes_consumed;

    Encoding encoding = CompactEncDet::DetectEncoding(
        text, contents.length(),
        nullptr, nullptr, nullptr,
        UNKNOWN_ENCODING,
        UNKNOWN_LANGUAGE,
        CompactEncDet::WEB_CORPUS,
        false,
        &bytes_consumed,
        &is_reliable);
    
    std::cout << "Encoding: " << encoding <<  " Name: " << EncodingName(encoding) << std::endl;

    return 0;
}