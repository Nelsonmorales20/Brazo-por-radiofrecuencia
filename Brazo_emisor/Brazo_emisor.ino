int sensor[5] = {A0, A1, A2, A3, A4};
int cantidadsensores = 5;
void setup() {
  for (int i = 0; i < cantidadsensores; i++) {
    pinMode(sensor[i], INPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
