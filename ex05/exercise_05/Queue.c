/******************************************************************************
 * File:         Queue.c
 * Version:      1.1
 * Date:         2016-03-31
 * Author:       M. van der Sluys, J. Onokiewicz
 * Description:  OPS excercise 5: Queues
 ******************************************************************************/


#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

void createQueue(queue_t* pQueue, data_t data) {
  if(pQueue != NULL) {
printf("test\n");
    printf("Size of queue before delete: %lu\n", sizeQueue(pQueue));
    deleteQueue(pQueue);
    printf("Size of queue after delete: %lu\n", sizeQueue(pQueue));
  }
  node_t* pNew = (node_t*) malloc(sizeof(node_t));
  pQueue->pLastNode = pNew;
  if(pNew != NULL) {
    pNew->data = data;
    pNew->pNextNode = pNew;
  }
}

int emptyQueue(const queue_t* pQueue) {
  return (pQueue->pLastNode == NULL);
}

size_t sizeQueue(const queue_t* pQueue) {
  size_t size = 0;
  const node_t* pNext = pQueue->pLastNode;
    if(emptyQueue(pQueue)){return 0;}
    do {
      pNext = pNext->pNextNode;
      size++;
    } while(pNext != pQueue->pLastNode);
  return size;
}

data_t* frontQueue(const queue_t* pQueue) {
  return &(pQueue->pLastNode->pNextNode->data);
}

data_t* backQueue(const queue_t* pQueue) {
  return &(pQueue->pLastNode->data);
}

void pushQueue(queue_t* pQueue, data_t data) {
  node_t* pNew = (node_t*) malloc(sizeof(node_t));
  if(pNew != NULL) {
    pNew->data = data;                               // Set data
    pNew->pNextNode = pQueue->pLastNode->pNextNode;  // New last node points to first node
    pQueue->pLastNode->pNextNode = pNew;             // Old last node points to new last node
    pQueue->pLastNode = pNew;                        // Set new last-node pointer
  }
}

void popQueue(queue_t* pQueue) {
  if(pQueue->pLastNode != NULL) {
    node_t* pDelete = pQueue->pLastNode->pNextNode;
    if(pDelete == pQueue->pLastNode) {
      /* size queue == 1 */
      pQueue->pLastNode = NULL;
    } else {
      pQueue->pLastNode->pNextNode = pDelete->pNextNode;
    }
    //free(pDelete);
  }
}

void deleteQueue(queue_t* pQueue) {
  while(pQueue->pLastNode!=NULL){
    popQueue(pQueue);
  }
}

void showQueue(const queue_t* pQueue) {
  const node_t* pNext = pQueue->pLastNode;
  if(pNext == NULL) {
    printf("Queue is empty, last node is %p\n", (void*) pQueue->pLastNode);
  } else {
    printf("Queue size: %lu\n", sizeQueue(pQueue));
    printf("Queue contains:\n");
    printf("Last node: %p\n", (void*) pQueue->pLastNode);
    do {
      pNext = pNext->pNextNode;
      printf("pNode = %p  Data = '%d' '%s'  pNext = %p\n",
             (void*)pNext, pNext->data.intVal, pNext->data.text, (void*)pNext->pNextNode);
    } while(pNext != pQueue->pLastNode);
  }
}
