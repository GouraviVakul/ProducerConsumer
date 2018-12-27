    /*
     * ConsumerThread.cpp
     *
     *  Created on: Dec 27, 2018
     *      Author: Gouravi
     */
    #include "ConsumerThread.h"
    #include "SynchronizedFile.h"
    #include "Item.h"
    #include <unistd.h>
    #include "Writer.h"
    #include <iostream>
    #include <memory>
    #include <type_traits>
    
    
    ConsumerThread::ConsumerThread(BufferQueue<WorkItem*>& queue, const char* outFile, const char* sort) : m_queue(queue), m_outFile(outFile), m_sortAlgorithm(sort){
    
        }
    
        void* ConsumerThread::run()
        {
        // Remove 1 item at a time and process it. Blocks if no items are
            // available to process.
            for (int i = 0;; i++) {
                
            //cout<<"Customer Thread"<<(long unsigned int)self()<<endl;
            WorkItem* workitem = (WorkItem*)m_queue.remove();
            
            std::string data(workitem->getMessage());
            delete workitem;

	    //create Item object to process the item from the input file
            Item item(data.c_str());
		
            //remove spaces from the item
            if(item.SplitItem())
            {
               sleep(1);
            }

	    //sort the item using the sort method passed in input commandline argument
            item.Sort(m_sortAlgorithm);

	    //get the comma seperated sorted result item
            string resultItem = item.ResultItem();

            // Create the synchronized file, accessed by all customer threads
            auto synchronizedFile = std::make_shared<SynchronizedFile>(m_outFile);
    
            // Create the writers object using the same synchronized file
            Writer writerobj(synchronizedFile);

	    // Writes sorted item to the outfile
            writerobj.WritesToFile(resultItem);

            //cout<<"end of customer thread";
    
            }
            return NULL;
        }
    
    

