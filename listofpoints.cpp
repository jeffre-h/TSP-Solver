#include "listofpoints.hpp"
#include <stdbool.h>


ListOfPoints::ListOfPoints() {}

void ListOfPoints::addAfter(Point& newPt, string name) {
  int j = 0;
  for (auto i: m_points) {
    j++;
    //iterate through vector, if name of element = given name, insert it after that element
    if (i.getName() == name) {
      m_points.insert(m_points.begin()+j, newPt);
    }
  }
}

void ListOfPoints::empty() {
  //empties vector
  return m_points.clear();
}

void ListOfPoints::addPoint(Point& newPt)  {
  //add point to end of vector
  m_points.push_back(newPt);
}

Point& ListOfPoints::getPointAt(unsigned int i) {
  //returns point at given index
  return m_points[i];
}

int ListOfPoints::getSize() const {
  //returns size of vector
  return m_points.size();
}

void ListOfPoints::printList() const {
  //prints out every element in the vector
  for (auto i: m_points) {
    cout << ' ' << i;
  }
  cout << endl;
}

void ListOfPoints::draw() const {
  //draws out all the points on a x-y plane where 0<=x<=20 , 0<=y<=20
  bool token = false;
  
  // creating 2-dimensional grid
  for (int y=20; y>=0; y--) {
    for (int x=0; x<=20; x++) {
      token = false;
      for (auto i: m_points) {
        // iterate through vector, if point is found, token = true, the point is outputed 
        // else, token remains false, "- " is outputed to signify no point is at that spot
        if (x == i.getX() && y == i.getY()) { 
          cout << i.getName() << " ";
          token = true;
        }
      }
      if (token == false) {
        cout << "- ";
      }
    }
    cout << endl;
  }
  
}