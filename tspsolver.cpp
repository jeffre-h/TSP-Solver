#include "tspsolver.hpp"

TSPSolver::TSPSolver(ListOfPoints &list) { 
  m_list = list;
}

void TSPSolver::solve() {
  ListOfPoints sol;
  // copy over first 3 elements from m_list into sol
  for (int x=0; x<3; x++) {
    sol.addPoint(m_list.getPointAt(x));
  }

  // using the given smallest increase heuristic algorithm, test points one by one from m_list to add into sol
  for (int i=3; i<m_list.getSize(); i++) { //iterating through m_list
    //initializing min value and min index
    float min = sol.getPointAt(0).getDistance(m_list.getPointAt(i)) + m_list.getPointAt(i).getDistance(sol.getPointAt(1)) - sol.getPointAt(1).getDistance(sol.getPointAt(0));
    int minIdx = 0;
    
    for (int j=1; j<sol.getSize()-1; j++) { //iterating through sol
      float temp = sol.getPointAt(j).getDistance(m_list.getPointAt(i)) + m_list.getPointAt(i).getDistance(sol.getPointAt(j+1)) - sol.getPointAt(j+1).getDistance(sol.getPointAt(j));

      if (temp <= min) { //if increase is smaller than or equal to min, that point becomes the new min
        min = temp;
        minIdx = j;
      }
    }
    
    // testing increase using the last point and first point
    // if that distance is smaller than or equal to min, then it becomes the new min, else the min stays the same 
    // add the point that gives min increase into sol
    if (sol.getPointAt(sol.getSize()-1).getDistance(m_list.getPointAt(i)) + m_list.getPointAt(i).getDistance(sol.getPointAt(0)) - sol.getPointAt(0).getDistance(sol.getPointAt(sol.getSize()-1)) <= min) {
      sol.addAfter(m_list.getPointAt(i), sol.getPointAt(sol.getSize()-1).getName());
    }
    else {
      sol.addAfter(m_list.getPointAt(i), sol.getPointAt(minIdx).getName());
    }
  }

  // empty list then copy order of points in sol into m_list
  m_list.empty();
  for (int k=0; k<sol.getSize(); k++) {
    m_list.addPoint(sol.getPointAt(k));
  }
}

TSPCycle& TSPSolver::getSolution() {
  // copy over m_list into m_solution
  for (int i=0; i<m_list.getSize(); i++) {
    m_solution.addPoint(m_list.getPointAt(i));
  }
  return m_solution;
}
