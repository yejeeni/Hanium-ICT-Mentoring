#include <OneWire.h>
#include <DS18B20.h>
#include <SoftwareSerial.h>
#include <TinyGPS.h>

SoftwareSerial gpsSerial(6,5); // GPS 센서 디지털 핀
DS18B20 DS18B20_Sensor(2); // 온도센서 디지털 핀
int GasPin = A0; // 가스센서 아날로그 핀
int SoundPin = A1; // 사운드센서 아날로그 핀
int sensorValue;


void setup() {
  pinMode(GasPin ,INPUT); // 아날로그 핀 A0 입력모드 설정
  Serial.begin(9600);
  gpsSerial.begin(9600);
  Serial.println("****아두이노 센서 측정****");
}

void loop() {
  Serial.print("온도: ");
  Serial.println(DS18B20_Sensor.getTempC());
  Serial.print("가스 농도: ");
  Serial.println(analogRead(GasPin)); 
  Serial.print("소리 크기: ");
  Serial.println(analogRead(SoundPin));
 
  if(gpsSerial.available())
  {
    Serial.print("현위치: ");
    Serial.write(gpsSerial.read());
  }
  else
  {
    Serial.print("현위치 파악 불가");
  }
   Serial.println("");

  //delay(5000);
}