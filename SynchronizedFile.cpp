/*
 * SynchronizedFile.cpp
 *
 *  Created on: Dec 27, 2018
 *      Author: Gouravi
 */

#include <iostream>
#include "SynchronizedFile.h"


SynchronizedFile::SynchronizedFile(const string& path) : m_path(path) {
    m_outFile.open(path.c_str(), ofstream::out | ofstream::app);
}

SynchronizedFile::~SynchronizedFile () {
    m_outFile.close();
}

void SynchronizedFile::Write(const string& dataToWrite) {
    // Ensure that only one thread can execute at a time
    std::mutex writerMutex;
    std::lock_guard<std::mutex> lock(writerMutex);
    // Write to the file.
    m_outFile<<dataToWrite<<endl;;
}



