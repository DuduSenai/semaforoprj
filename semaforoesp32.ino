#include <WiFi.h>
#include <WiFiClient.h>

#include <WebServer.h>
#include <string.h>

WebServer server(80);

const char *ssid = "Wifi-TREV";
const char *password = "12345678";

IPAddress local_IP(192,168,0,80);
IPAddress gateway(192,168,0,1);
IPAddress subnet(255,255,255,0);


const int pinLed1 = 2;
const int pinLed2 = 4;
const int pinLed3 = 5;

const int pinLed4 = 18;
const int pinLed5 = 19;
const int pinLed6 = 21;

bool semaforo1 = true;
bool semaforo2 = false;

int tempoverde = 5000;
int tempoamarelo = 2000;

void setup() {
Serial.begin(115200);
Serial.print("Configurando AP.....");
Serial.println(WiFi.softAPConfig)(local_IP, gateway, subnet)? "OK" : "Erro");
Serial.print("Iniciando o Wifi.....");
Serial.println(WiFi.softAP(ssid, password));
Serial.print("Endereço IP");
Serial.println(WiFi.softAPIP());


pinMode(pinLed1, OUTPUT);
pinMode(pinLed2, OUTPUT);
pinMode(pinLed3, OUTPUT);
pinMode(pinLed4, OUTPUT);
pinMode(pinLed5, OUTPUT);
pinMode(pinLed6, OUTPUT);
}

void loop() {


if (semaforo2){
diminuiLuz(pinLed4);
acendeLuz(pinLed1);
acendeLuz(pinLed6);
delay(tempoverde);
diminuiLuz(pinLed6);
acendeLuz(pinLed5);
delay(tempoamarelo);
diminuiLuz(pinLed5);
semaforo1 = true;
diminuiLuz(pinLed1); 
acendeLuz(pinLed4);
} else {
  acendeLuz(pinLed4);
}


if (semaforo1){
  acendeLuz(pinLed3);
  delay(tempoverde);
  diminuiLuz(pinLed3);
  acendeLuz(pinLed2);
  delay(tempoamarelo);
  diminuiLuz(pinLed2);
  semaforo1 = false;
  semaforo2 = true;
} else {
  acendeLuz(pinLed1);
}


}

void acendeLuz(int p){
  digitalWrite(p, HIGH);
}

void diminuiLuz(int p){
  digitalWrite(p, LOW);
}