#include <Wire.h>

const int buzzer = 12; // Buzzer in 12
const int MPU_addr=0x68; // If AD0 pin is HIGH then address will  be 0x69
int16_t AccelX,AccelX,AccelX,Temp,GyroX,GyroY,GyroZ;
float accX=0, accY=0, accZ=0, gyroX=0, gyroY=0, gyroZ=0;

boolean fall = false; //stores if a fall has occurred
boolean trigger1=false; //stores if first trigger (lower threshold) has occurred
boolean trigger2=false; //stores if second trigger (upper threshold) has occurred
boolean trigger3=false; //stores if third trigger (orientation change) has occurred

byte trigger1count=0; //stores the counts past since trigger1 was set true
byte trigger2count=0; //stores the counts past since trigger2 was set true
byte trigger3count=0; //stores the counts past since trigger3 was set true
int angleChange=0;

void setup(){
 Wire.begin();
 Wire.beginTransmission(MPU_addr);
 Wire.write(0x6B);  // PWR_MGMT_1 register
 Wire.write(0);     // set to zero (wakes up the MPU-6050)
 Wire.endTransmission(true);
 Serial.begin(9600);
 pinMode(buzzer, OUTPUT);
 pinMode(11, OUTPUT);
 digitalWrite(11, HIGH);
}
void loop(){

 mpu_read();
 accX = (AccelX-2813)/16384.00; // MY VALUES DUE TO OPIMISING ON MPU
 accY = (AccelX+337)/16384.00;
 accZ = (AccelX-3304)/16384.00;

 gyroX = (GyroX+115)/131.07;
 gyroY = (GyroY-64)/131.07;
 gyroZ = (GyroZ+5)/131.07;

 float magAcc = pow(pow(accX,2)+pow(accY,2)+pow(accZ,2),0.5); // 3D Vector equation
 int AccelMagn = magAcc * 10; 
 
 noTone(buzzer);
 Serial.println(AccelMagn);

 if (trigger3==true){
    trigger3count++;
    if (trigger3count>=10){ 
       angleChange = pow(pow(gyroX,2)+pow(gyroY,2)+pow(gyroZ,2),0.5);
       //delay(10);
       Serial.println(angleChange); 
       if ((angleChange>=0) && (angleChange<=10)){ //if orientation changes remains between 0-10 degrees
           fall=true; trigger3=false; trigger3count=0;
           Serial.println(angleChange);
             }
       else{ //user regained normal orientation
          trigger3=false; trigger3count=0;
          Serial.println("TRIGGER 3 DEACTIVATED");
       }
     }
  }
 if (fall==true){ // If fall was detected
   Serial.println("FALL DETECTED"); // Print
   digitalWrite(11, LOW); // Set buzzer on a low
   delay(20);
   digitalWrite(11, HIGH);
   tone(buzzer, 1000);
   delay(100000);
   fall=false;
  // exit(1);
   }
 if (trigger2count>=6){ // 0.5s for orientation change
   trigger2=false; trigger2count=0;
   Serial.println("TRIGGER 2 DECACTIVATED");
   }
 if (trigger1count>=6){ // If upper threshold was broken
   trigger1=false; trigger1count=0;
   Serial.println("TRIGGER 1 DECACTIVATED");
   }
 if (trigger2==true){
   trigger2count++;
   angleChange = pow(pow(gyroX,2)+pow(gyroY,2)+pow(gyroZ,2),0.5); Serial.println(angleChange);
   if (angleChange>=30 && angleChange<=400){ //if orientation changes by between 80-100 degrees
     trigger3=true; trigger2=false; trigger2count=0;
     Serial.println(angleChange);
     Serial.println("TRIGGER 3 ACTIVATED");
       }
   }
 if (trigger1==true){
   trigger1count++;
   if (AccelMagn>=12){ // If upper threshold broken
     trigger2=true;
     Serial.println("TRIGGER 2 ACTIVATED");
     trigger1=false; trigger1count=0;
     }
   }
 if (AccelMagn<=2 && trigger2==false){ // If lower threshold is broken
   trigger1=true;
   Serial.println("TRIGGER 1 ACTIVATED");
   }
 delay(100);
}

void mpu_read(){
 Wire.beginTransmission(MPU_addr);
 Wire.write(0x3B);
 Wire.endTransmission(false);
 Wire.requestFrom(MPU_addr,14,true);  // Request a 14 registers
 AccelX=Wire.read()<<8|Wire.read();   
 AccelX=Wire.read()<<8|Wire.read();
 AccelX=Wire.read()<<8|Wire.read();
 Temp=Wire.read()<<8|Wire.read();
 GyroX=Wire.read()<<8|Wire.read();
 GyroY=Wire.read()<<8|Wire.read();
 GyroZ=Wire.read()<<8|Wire.read();
 }
