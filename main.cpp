#include "DS.h"

int main() {
  vector<char> data = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
  DisjoinSetArray<char> *ds = new DisjoinSetArray<char>(data);

  cout << "Insertando letras del 'a' hasta 'h' " << endl;

  cout << "Numero de sets : " << ds->sets() << endl;
  ds->Union(0, 2);
  ds->Union(5, 6);
  ds->Union(1, 6);
  ds->Union(7, 0);
  ds->Union(4, 3);
  cout << "Numero de sets : " << ds->sets() << endl;
  cout << "¿1 conectado con 5? " << boolalpha << ds->isConnected(1, 5) << endl;
  cout << "¿2 conectado con 4? " << ds->isConnected(2, 4) << endl;
  cout << "¿7 conectado con 2? " << ds->isConnected(7, 2) << endl;

  vector<char> set1 = ds->getElementsSet(3);
  cout << "elementos conectados del set de la posicion 3 ('d') : " << endl;
  for (auto it = set1.begin(); it != set1.end(); ++it) {
    cout << *it << " ";
  }
  cout << endl;

  cout << "Tamaño del set de la posicion 5 ('f')  : " << ds->size(5) << endl;
  vector<char> set2 = ds->getElementsSet(5);

  for (auto it = set2.begin(); it != set2.end(); ++it) {
    cout << *it << " ";
  }
  cout << endl;

  ds->Union(2, 5);
  ds->Union(3, 1);
  cout << "Numero de sets : " << ds->sets() << endl;

  return 0;
}
