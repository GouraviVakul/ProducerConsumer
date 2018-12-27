/*
 * bufferqueue.h
 *
 *  Created on: Dec 27, 2018
 *      Author: Gouravi
 */

#ifndef BUFFERQUEUE_H_
#define BUFFERQUEUE_H_

#include <iostream>
#include <list>
#include <pthread.h>

using namespace std;

template <typename T> class BufferQueue
{
    list<T>          m_queue;
    pthread_cond_t   m_condv;
    pthread_mutex_t  m_mutex;

  public:
    BufferQueue() {
        pthread_mutex_init(&m_mutex, NULL);
        pthread_cond_init(&m_condv, NULL);
    }
    ~BufferQueue() {
        pthread_mutex_destroy(&m_mutex);
        pthread_cond_destroy(&m_condv);
    }
    void add(T item) {
        pthread_mutex_lock(&m_mutex);
	std::cout<< "Buffer Queue " << item << std::endl;
        m_queue.push_back(item);
	std::cout<< "List Size" << m_queue.size() << std::endl;
        pthread_cond_signal(&m_condv);
        pthread_mutex_unlock(&m_mutex);
    }
    T remove() {
        pthread_mutex_lock(&m_mutex);
        while (m_queue.size() == 0) {
            pthread_cond_wait(&m_condv, &m_mutex);
        }
        T item = m_queue.front();
        m_queue.pop_front();
        pthread_mutex_unlock(&m_mutex);
        return item;
    }
    int size() {
        pthread_mutex_lock(&m_mutex);
        int size = m_queue.size();
        pthread_mutex_unlock(&m_mutex);
        return size;
    }
};


#endif /* BUFFERQUEUE_H_ */
