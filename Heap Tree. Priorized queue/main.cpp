//Iker Guerrero Gonzalez - A00830026
//Francisco Rocha Juarez - A01730560
//Aldo Mauricio Cruz Lozada - A01732372

#include <iostream>
#include <cstdlib>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class queue_first{
    public:
      vector <int> queue;

      queue_first(){};

      void push(int); //O
      void pop(); //O
      void print(); //O
      void top(); //O
      void empty(); //O
      int size(); //O
};

//aquí se retorna la longitud de la cola
int queue_first::size(){
    return queue.size();
}

//aquí se inserta un dato en la cola
void queue_first::push(int value){
  //Complejidad: O(log2n)
  queue.push_back(value);   
  int curr = queue.size() - 1;
  while(curr>0 and queue[(curr-1)/2]<queue[curr])
  {
      int temp = queue[(curr-1)/2];
      queue[(curr-1)/2] = queue[curr];
      queue[curr] = temp;
      curr = (curr-1)/2;    
  }
}

void queue_first::pop(){
  //Complejidad: O(log2n)
  int curr = 0;  
  int popped = queue[0];    
  queue[0] = queue[queue.size() - 1];   
  queue.pop_back();  
  while((2*curr+1)< queue.size())   
  {
    int child;
    if((2*curr+2) == queue.size())    
        child = 2*curr+1;
    else  
    {
      if(queue[2 * curr + 1] > queue[2 * curr + 2])
          child = 2 * curr + 1;
      else
          child = 2 * curr + 2;
    }
    if(queue[curr] < queue[child])
    {
      int temp = queue[curr];
      queue[curr] = queue[child];
      queue[child] = temp;
      curr = child;
    }
    else    
        break;
  }
  cout << popped << endl;
}

//función de impresión
void queue_first::print(){
  for (int i = 0 ; i < queue.size(); i++){
    cout << queue[i] << " ";
  }
  cout << "\n";
}

//entrega el valor con mayor prioridad
void queue_first::top(){
  //Regresa el valor del dato que esta con mayor prioridad en la fila priorizada
  int mayor, menor;
  if (queue.size() > 0)
  {
    mayor = menor = queue[0];

    for (int i = 1; i < sizeof(queue) / sizeof(queue[0]); ++i)
    {
      if (queue[i] > mayor) mayor = queue[i];
      if (queue[i] < menor) menor = queue[i];
    }
    cout<< mayor <<endl;
  }
  else{
    cout << "Empty heap" << endl;
  }
}

//dicta si la cola está vacía
void queue_first::empty(){
  if (queue.size() == 0){
      cout << "true" << endl;
  }
  else{
      cout << "false" << endl;
  }
}



int main(){
  queue_first cola;
  int dat, value, a;
  // Cuando la opción "dat" no sea 0, el programa aun funciona.
  do {
      cin >> dat;
      // Switch que presenta las opciones del usuraio.
      switch (dat) {
        case 1:
          cin >> value;
          cola.push(value);
          break;
        case 2:
          cola.pop();
          break;
        case 3:
          cola.print();
          break;
        case 4:
          //Top function
          cola.top();
          break;
        case 5:
          //emptycalue function
          cola.empty();
            break;
        case 6:
          //size function
          a = cola.size();
          cout << a << endl;
          break;
        case 0:
          break;
      }
  } while (dat != 0);
  return 0;
};