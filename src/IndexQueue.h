#pragma once
#include <Arduino.h>
#include "Queue.h"

template <class T>
class IndexQueue : public Queue <T> {
public:
  IndexQueue(){
    index = this->capacity;
  }
  IndexQueue(int capa){
    index = this->capacity;
  }
  ~IndexQueue(){}
  void push(const T &element){
    if(this->length() == this->capacity) pop();
    this->tail = (this->tail + 1) % this->size;
    this->data[this->tail] = element;
  }
  T pop(){
    if(this->length() == 0) {
      Serial.println("This IndexQueue is already empty.");
      exit(1);
    }
    T element = this->data[this->head];
    if(index == this->head) index = (index + 1) % this->size;
    this->head = (this->head + 1) % this->size;
    return element;
  }
  T next(){
    int nextIndex = (index + 1) % this->size;
    if(nextIndex > this->tail && nextIndex <= this->head) {
      Serial.println("Index have already reached the tail.");
      exit(1);
    }
    index = (index + 1) % this->size;
    return this->data[index];
  }
protected:
  int index;
};