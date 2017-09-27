#include "Pause.h"

#include <iostream>

using namespace std;

void Pause()
{
  char buffer[20];
  cout << endl << "--> RETURN <--" << endl << endl;
  cin.getline(buffer,20);
}
