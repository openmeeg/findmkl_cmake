#include <Speaker.h>
#include <stdio.h>

using namespace std;
using namespace Hello;

int main(int argc, char *argv[]) {
  Speaker* speaker = new Speaker();

  speaker->sayHello();

}
