
#include<ESP8266WiFi.h>
#include<SoftwareSerial.h>
#include<FirebaseArduino.h>
#include<Arduino.Json.h>
#include<ESP8266HTTPClient.h>

#define FIREBASE_HOST"server path address"
#define FIREBASE_AUTH"Authentication key"
#define WIFI_SSID"sample"
#define WIFI_PASSWORD"123456789"
String rainwater_drop_string,rainwater_flow-string,rainwater_storage_string;
int rain_drop = 4;
int rain_flow = 20;
int rain_storage = A0;
int sdata =0;
int rainsbuff=0;
int rainflowbuff=0;
void setup()
{
  //Debug console
  Serial.begin(9600);
  pinMode(rain_drop ,INPUT);
  pinMode(rain_flow ,INPUT);
  pinMode(rain_storage ,INPUT);

   //connect to wifi.
  // pinMode(D0,OUTPUT);
  WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
  Serial.print("connecting");
  while(WiFi.status()!=WL_CONNECTED)
     {
      Serial.print(".");
      delay(500);
     }
   Serial.print();
   Serial.print("connected:");
   Serial.printn(WiFi.locallP());
   Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
    Firebase.setString("Rain_Drop_Level/Value","Accessing Database");
    Firebase.setString("Rain_Flow_Level/Value","Accessing Database");
    Firebase.setString("Rain_Storage_Level/Value","Accessing Database");
}

void loop()
{
  sdata = analogRead(rain_drop);
  rainsbuff= analogRead(rain_flow);
  rainflowbuff = analogRead(rain_storage);
  rainwater_drop_string = String(sdata);
  rainwater_flow_string = String(rainsbuff);
  rainwater_storage_string = String(rainflowbuff);
  Firebase.setString("Rain_Drop_Level/Value","rainwater_drop_string");  
  Firebase.setString("Rain_Flow_Level/Value","rainwater_flow_string");
  Firebase.setString("Rain_Storage_Level/Value","rainwater_storage_string");
  Serial.println(rainwater_drop_string);
  Serial.println(rainwater_flow_string);
  Serial.println(rainwater_storage_string);
  delay(1000);
}
