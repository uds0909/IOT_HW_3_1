#include <Arduino.h>
#include <Wire.h>
#include <SSD1306.h>
#include <SparkFun_APDS9960.h>
#include <DHTesp.h>
#include <Adafruit_Sensor.h>

///////////////////////////////////LAB2/////////////////////////////////////

SSD1306       display(0x3c, 4, 5, GEOMETRY_128_32);

const int RELAY = 15;
int a = 10;

///////////////////////////////////LAB3/////////////////////////////////////
SparkFun_APDS9960 apds = SparkFun_APDS9960();
int isr_flag = 0;

void handleGesture(){
  if(apds.isGestureAvailable()){
    switch(apds.readGesture()){
      case DIR_UP :
        digitalWrite(RELAY,HIGH);
        display.init();
        display.drawString(10,10,"UP");
        display.display();
        delay(500);
        break;
      case DIR_DOWN :
        digitalWrite(RELAY,LOW);
        display.init();
        display.drawString(10,10,"DOWN");
        display.display();
        delay(500);
        break;
        case DIR_LEFT :
        delay(500);
        break;
        case DIR_RIGHT :
        delay(500);
        break;
        default :
        display.init();
        display.drawString(10,10,"NONE");
        display.display();
        delay(500);
    }

  }

}

///////////////////////////////////LAB4/////////////////////////////////////
// DHTesp    dht;
// int       interval = 2000;
// unsigned long lastDHTReadMillis = 0;
// float     humidity = 0;
// float     temperature = 0;

// void readDHT22(){
//   unsigned long currentMillis = millis();

//   if((currentMillis - lastDHTReadMillis) >= interval){
//     lastDHTReadMillis = currentMillis;
//     humidity = dht.getHumidity();
//     temperature = dht.getTemperature();
//     display.init();
//     display.drawString(10,10,(String)humidity);
//     display.drawString(70,10,(String)temperature);
//     display.display();
//     delay(1000);
//     //display.drawString(0,0, "Counter: " + String(counter));
//   }
//   delay(1000);
// }



void setup() {
  // put your setup code here, to run once:
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_16);
  ///////////////////////////////////LAB3/////////////////////////////////////
  Serial.begin(115200);
  pinMode(RELAY,OUTPUT);
  if(apds.init()){
    Serial.println("APDS-9960 initialization complete");
  }else {
    Serial.println("Something went wrong during APDS_9960 init!");
  }
  if(apds.enableGestureSensor(true)){
    Serial.println("Gesture sensor is now running");
  }else {
    Serial.println("Something went wrong during gesture sensor init!");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  
  /////////////////////////////LAB2_1/////////////////////////////////
  // lux = analogRead(0);
  // display.init();
  // display.drawString(10,10,(String)lux);
  // display.display();
  // delay(500);
  /////////////////////////////LAB2_2/////////////////////////////////

  // 여기는 수업시간에 하기 

  ///////////////////////////////////LAB3/////////////////////////////////////
  handleGesture();
  ///////////////////////////////////LAB4/////////////////////////////////////
  //readDHT22();
}