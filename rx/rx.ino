
//  PWM output on pins D2, D3, D4, D5, D6, D7 (Çıkış pinleri)

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

int ch_width_1;

Servo ch1;

struct Signal {
byte ml;      
byte mr;
byte pitch;
};

Signal data;

const uint64_t pipeIn = 0xE9E8F0F0E1LL;
RF24 radio(9, 10); 

void ResetData()
{
// Define the inicial value of each data input. | Veri girişlerinin başlangıç değerleri
// The middle position for Potenciometers. (254/2=127) | Potansiyometreler için orta konum
data.ml = 0;   // Center | Merkez
data.mr = 0;  // Center | Merkez
data.pitch = 127; // Motor Stop | Motor Kapalı

}

void setup()
{

  //Set the pins for each PWM signal | Her bir PWM sinyal için pinler belirleniyor.
  ch1.attach(7);

  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);

  //Configure the NRF24 module
  ResetData();
  radio.begin();
  radio.openReadingPipe(1,pipeIn);
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.startListening(); //start the radio comunication for receiver | Alıcı olarak sinyal iletişimi başlatılıyor

}

unsigned long lastRecvTime = 0;

void recvData()
{
while ( radio.available() ) {
radio.read(&data, sizeof(Signal));
lastRecvTime = millis();   // receive the data | data alınıyor
}
}

void loop()
{
recvData();
unsigned long now = millis();
if ( now - lastRecvTime > 1000 ) {
ResetData(); // Signal lost.. Reset data | Sinyal kayıpsa data resetleniyor
}

ch_width_1 = map(data.pitch,     0, 255, 1000, 2000);     // pin D2 (PWM signal)


analogWrite(5,data.ml);
analogWrite(6,data.mr);

// Write the PWM signal | PWM sinyaller çıkışlara gönderiliyor
ch1.writeMicroseconds(ch_width_1);
}
