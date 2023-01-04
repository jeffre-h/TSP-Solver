#include <iostream>

#include "tspcycle.hpp"

TSPCycle::TSPCycle() {
  cout << "default TSPCycle constructor" << endl;
}

// returns the length of the cycle
float TSPCycle::getLength() const {
  float len = 0;
  
  for (int i=0; i<getSize()-1; i++) {
    len += m_points[i].getDistance(m_points[i+1]); //take distance from point at index i to next index (i+1)
    if (i==getSize()-2) { //when i is the 2nd last index, take distance from last point to first point (finished)
      len += m_points[getSize()-1].getDistance(m_points[0]);
    }
  }
  return len; 
}
