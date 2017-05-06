/******************************************************************************
 * File:         main.c
 * Version:      1.1
 * Date:         2016-03-31
 * Author:       M. van der Sluys, J. Onokiewicz
 * Description:  OPS excercise 5: Queues
 ******************************************************************************/


#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  data_t data = {1, "Hello queue"};
  queue_t queue = {NULL};
  
  showQueue(&queue);
  
  printf("\nCreate queue\n");
  createQueue(&queue, data);
  showQueue(&queue);
  data.intVal++;
  
  
  
  printf("\nAdd new data to queue\n");
  pushQueue(&queue, data);
  showQueue(&queue);
  data.intVal++;
  
  printf("\nAdd new data to queue\n");
  pushQueue(&queue, data);
  showQueue(&queue);
  data.intVal++;
  
  printf("\nAdd new data to queue\n");
  pushQueue(&queue, data);
  showQueue(&queue);
  
  
  
  printf("\nFront iValue/first node: %d\n", frontQueue(&queue)->intVal);
  printf("Back  iValue/last node:  %d\n", backQueue(&queue)->intVal);
  
  
  
  printf("\nPop queue\n");
  popQueue(&queue);
  showQueue(&queue);
  
  printf("\nPop queue\n");
  popQueue(&queue);
  showQueue(&queue);

  printf("\nDelete queue\n");
  deleteQueue(&queue);
  showQueue(&queue);
  
  printf("\nPop queue\n");
  popQueue(&queue);
  showQueue(&queue);
  
  printf("\nPop queue\n");
  popQueue(&queue);
  showQueue(&queue);
  
  printf("\nPop queue\n");
  popQueue(&queue);
  showQueue(&queue);
  
  return 0;
}
