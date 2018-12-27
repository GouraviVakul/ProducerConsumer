/*
 * Main.cpp
 *
 *  Created on: Dec 27, 2018
 *      Author: Gouravi
 */

#include<iostream>
#include<fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include "BufferQueue.h"
#include "ConsumerThread.h"
#include "Sort.h"

using namespace std;

int main(int argc, char** argv)
{
    // Process command line arguments
    if ( argc != 4 ) {
        cout<<"incorrect input command line arguments";//todo validate input arguments
        exit(-1);
    }

	std::ofstream outfile;
    	outfile.open(argv[2], ofstream::out|ofstream::trunc);
    	outfile.close();

    // Create the queue and consumer (worker) threads
    BufferQueue<WorkItem*>  queue;

	// Create the consumer (worker) threads
    ConsumerThread* consumerthread1 = new ConsumerThread(queue, argv[2],argv[3]);
    ConsumerThread* consumerthread2 = new ConsumerThread(queue, argv[2],argv[3]);
    ConsumerThread* consumerthread3 = new ConsumerThread(queue, argv[2],argv[3]);
    ConsumerThread* consumerthread4 = new ConsumerThread(queue, argv[2],argv[3]);
    consumerthread1->start();
    consumerthread2->start();
    consumerthread3->start();
    consumerthread4->start();


    // Add items to the queue
    // Send the value of each loop iteration to the buffer(shared between consumer and main thread).
    string line;
    ifstream inputfile(argv[1]);

    if (inputfile)
    {
	WorkItem *item;
	while (getline(inputfile, line)) {
		item = new WorkItem(line.c_str());
		queue.add(item);
		std::cout << line << '\n';
	}
    }
    else
    {
	std::cout << "Unable to open file";
	return 0;
    }

    // Ctrl-C to end program 
    sleep(60);
    printf("Enter Ctrl-C to end the program...\n");
    while (1){}
    inputfile.close();
    exit(0);
}
