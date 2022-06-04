#include "motors.h"
#include "PS2_controller.h"
bool check = false;
int x;
void setup()
{
  Serial.begin(115200);
  initMotors();
  setupPS2controller();
  Serial.println("Done setup!");
}

void loop()
{
  ps2x.read_gamepad(false, 0);
  if (ps2x.ButtonPressed(PSB_START)) {
    x++;
    Serial.println(x);
  }
  if (x == 2) {
    x = 0;
  }
  switch (x) {
    case 0:
      PS2control();
      break;
    case 1:
      linefollow();
      break;
  }
  delay(10);
}
