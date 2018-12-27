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
                //printf("thread %lu, loop %d - waiting for item...\n",
                  //    (long unsigned int)self(), i);
            cout<<"CusThread"<<(long unsigned int)self()<<endl;
                WorkItem* workitem = (WorkItem*)m_queue.remove();
                //printf("thread %lu, loop %d - got one item\n",
                  //    (long unsigned int)self(), i);
                //printf("thread %lu, loop %d - item: message - %s, number - %d\n",
                  //    (long unsigned int)self(), i, item->getMessage(),
                    //   item->getNumber());
                //const char* data = workitem->getMessage();
            std::string data(workitem->getMessage());
            std::cout << "Consu Thread " << data.c_str() << std::endl;
                delete workitem;
                Item item(data.c_str());
            std::cout << "Consu Thread2 " << data.c_str() << std::endl;
                if(item.SplitItem())
                {
                    //sleep(1000);
                }
                item.Sort(m_sortAlgorithm);
            cout<<"end of sort"<<endl;
                string resultItem = item.ResultItem();
            std::cout<<"resultItem"<<resultItem.c_str()<<endl;
                // Create the synchronized file
                auto synchronizedFile = std::make_shared<SynchronizedFile>(m_outFile);
    
                // Create the writers using the same synchronized file
                Writer writerobj(synchronizedFile);
                writerobj.WritesToFile(resultItem);
            cout<<"end of cus thread";
    
            }
            return NULL;
        }
    
    

