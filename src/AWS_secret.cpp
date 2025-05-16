#include "AWS_secret.h"


WiFiClientSecure net = WiFiClientSecure();
MQTTClient client = MQTTClient(256);


void messageHandler(String &topic, String &payload) {
  //printf("Incoming message: %s",payload);
  printf("Message arrived on topic: %s",topic);
  printf("Message: %s",payload);
}

void connectAWS()
{
  // Configure WiFiClientSecure to use the AWS IoT device credentials
  net.setCACert(AWS_CERT_CA);
  net.setCertificate(AWS_CERT_CRT);
  net.setPrivateKey(AWS_CERT_PRIVATE);

  // Connect to the MQTT broker on the AWS endpoint we defined earlier
  client.begin(AWS_IOT_ENDPOINT, 8883, net);

  // Create a message handler
  client.onMessage(messageHandler);

  printf("Connecting to AWS IOT \n");

  while (!client.connect(THINGNAME)) {
    printf(".");
    delay(100);
  }

  if(!client.connected()){
    printf("AWS IoT Timeout! \n");
    return;
  }

  // Subscribe to a topic
  //client.subscribe(AWS_IOT_SUBSCRIBE_TOPIC);
  printf("AWS IoT Connected! \n");
}


/*
void publishMessage()
{
  StaticJsonDocument<200> doc;
  doc["time"] = millis();
  doc["sensor_a0"] = analogRead(0);
  char jsonBuffer[512];
  serializeJson(doc, jsonBuffer); // print to client

  client.publish(AWS_IOT_PUBLISH_TOPIC, jsonBuffer);
}
*/
