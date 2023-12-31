
#include <SoftwareSerial.h>           //я тестирую на wemos mini, у вас может быть и ардуинка, а следовательно и другая инициализация сериала
#define MYPORT_TX D5
#define MYPORT_RX D6
EspSoftwareSerial::UART myPort;

#include <JDY-40.h>
JDY40 jdi(&myPort);  //передать Stream объект, например Serial, либо объект софтсериала!!!обязательно АДРЕС, т.е. &объект


void setup() {
  myPort.begin(9600, SWSERIAL_8N1, MYPORT_RX, MYPORT_TX, false);  //по стандарту у JDI стоит 9600, я не менял и думаю ненужно. Для большей
  //стабильности можно опустить ниже, но перед этим сделать jdi.setBaud(uint8_t baud);

  Serial.begin(9600);  //


  jdi.configDevice(_SIMPLEX, D1, D2);

  if (jdi.begin()) Serial.println("JDI запустилась");
  else Serial.println("no");


  if (jdi.setRfID(8899)) Serial.println("RfID ок");    //ИД сети!!!ПОКА ЧТО от 1000 до 9999, 4 знака, можно и больше(16 битное). В разработке
  if (jdi.setDevID(8899)) Serial.println("DevID ок");  //ИД девайса!!!ПОКА ЧТО от 1000 до 9999, 4 знака, можно и больше(16 битное). В разработке
  if (jdi.setChannel(122)) Serial.println("Канал ок");
  if (jdi.setPower(9)) Serial.println("Мощность ок");


  if (jdi.setAllSettings(4, 8899, 8899, 12, 9)) Serial.println("Все хорошо");

  jdi.print("Hi!");  //эксперементальная функция, для симплекса
}

void loop() {
}