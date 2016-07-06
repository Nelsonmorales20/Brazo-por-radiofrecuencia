int Pinsensor[5] = {A0, A1, A2, A3, A4}; //arreglo de sensores
int cantidadsensores = 5; //cuantos sensores hay
int valor[5] = {0, 0, 0, 0, 0}; //valor actual
int valormax[5] = {0, 0, 0, 0, 0}; // valor maximo que se ajusta acorde a cada sensor valor maximo menos maximo
int valormin[5] = {1023, 1023, 1023, 1023, 1023}; // valor minimo que depende del sensor el menos minimo
void setup() {
  Serial.begin(9600); //abre el puerto serial
  for (int i = 0; i < cantidadsensores; i++) { // para contar todos los sensores y se incrementara en uno hasta llegar a 5
    pinMode(Pinsensor[i], INPUT); //lo ponemos en de entrada
  }
}

void loop() {
  // muestra en pantalla los valores de los sensores 
  for (int i = 0; i < cantidadsensores; i++) {
    Serial.print("s"); 
    Serial.print(i);
    Serial.print(" ");
    Serial.print(calcularsensor(i));
    Serial.print(" ");
    

  }
  Serial.println();
  delay(500);
}

//funcion hecha para calcular y ajustar valor de los sensores de los dedos para enviar despues
int calcularsensor(int sensoractual ) {
  int dedo = analogRead(Pinsensor[sensoractual]); //lee el valor del sensor
  if (dedo > valormax[sensoractual]) { // se ve si corresponde los datos
    valormax[sensoractual] = dedo; // se ajusta el sensor
  }
  if (dedo < valormin[sensoractual]) {
    valormin[sensoractual] = dedo;
  }
  dedo = map(dedo, valormin[sensoractual], valormax[sensoractual], 0, 1000); //ajustar el sensor dependiendo de cada flex

  dedo = constrain(dedo, 0, 1000); //asegurar que los valores se mantengan en rango
  return dedo; //devuelvo el valor ya ajustado
}


