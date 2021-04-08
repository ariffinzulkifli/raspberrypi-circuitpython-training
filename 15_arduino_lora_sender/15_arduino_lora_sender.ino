#include <SPI.h>
#include <LoRa.h>
#include <SimpleDHT.h>

String identifier = "fav";
String device_developer_id = "LoRaDevice@ariffinastute";
String access_token = "jSJxvHiLOGkqwh8T29HSPmuu3frp5S4l";

int pinDHT11 = 2;
SimpleDHT11 dht11(pinDHT11);

void setup() {
  Serial.begin(9600);

  Serial.println("LoRa Sender");

  if (!LoRa.begin(923E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  
  byte temperature = 0;
  byte humidity = 0;
  
//  int err = SimpleDHTErrSuccess;
//  
//  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
//    return;
//  }

  String data = "{";
  data += "\"" + (String)"temperature" + "\":\"" + String(temperature) + "\",";
  data += "\"" + (String)"humidity" + "\":\"" + String(humidity)+ "\"";
  data += "}";
  
  String data_send = identifier + ",";
  data_send += access_token + ",";
  data_send += device_developer_id + ",";
  data_send += data;

  Serial.println(data_send);
  Serial.println(data_send.length());

  LoRa.beginPacket();
  LoRa.print("    ");
  LoRa.print(data_send);
  LoRa.endPacket();

  delay(1000);
}