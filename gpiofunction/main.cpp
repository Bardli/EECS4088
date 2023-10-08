#include "gpio/const.h"
#include "gpio/manager.h"
#include <unistd.h>

using namespace beagle::gpio;

int main() {
  GPIOManager *gp = GPIOManager::getInstance();
  auto pin = getPin("P9_12");

  if (!pin) {
    return 255;
  }

  gp->exportPin(pin.value().gpio);
  gp->setDirection(pin.value().gpio, OUTPUT);
  gp->setEdge(pin.value().gpio, RISING);

  gp->waitForEdge(pin.value().gpio);
  
  for(int i=1;i=10;i++)
 {
  // LED On
  gp->setValue(pin.value().gpio,HIGH);
  sleep(1);
  // LED off;
  gp->setValue(pin.value().gpio,LOW);
  sleep(1);
 }
 gp->~GPIOManager();
  return 0;
}
