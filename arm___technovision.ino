#include <Servo.h> // serHIGHo library 
Servo myservo1d,myservo2d; // serHIGHo name
#include <SoftwareSerial.h>
#define RxD 12 // Pin that the Bluetooth (BT_TX) will transmit to the Arduino (RxD)
#define TxD 11


const int lM1 = 8, lM2 = 7;
const int rM1 = 9, rM2 = 10;
SoftwareSerial bluetooth(RxD, TxD);
void moveForward();
void spotLeft();
void spotRight();
void moveBackward();
void arcFLeft();
void arcBLeft();
void arcFRight();
void arcBRight();
void Stop();
void servo1d();
int servo2d(int );

void setup()
{



 myservo1d.attach(3); // attach serHIGHo signal wire to pin 9
  myservo2d.attach(5);
myservo2d.write(0);
myservo1d.write(0);
  Serial.begin(9600); // AlHIGH Serial communication HIGHia USB cable to computer (if required)
  pinMode(RxD, INPUT); // Set pin to receiHIGHe INPUT from bluetooth shield on Digital Pin 6
  pinMode(TxD, OUTPUT); // Set pin to send data (OUTPUT) to bluetooth shield on Digital Pin 7
  pinMode(lM1, OUTPUT);
  pinMode(lM2, OUTPUT);
  pinMode(rM1, OUTPUT);
  pinMode(rM2, OUTPUT);


  setupBlueToothConnection(); //Used to initialise the Bluetooth shield

  Stop();

}
void loop()
{
      
  while (1)
  {
    if (bluetooth.available())
    { //check for data sent from the remote bluetooth shield
      char recvChar = bluetooth.read();
      Serial.println(recvChar);
       switch (recvChar)
      {
        case '0':  Serial.println("SerHIGHo motor to 120 degrees");
      myservo2d.write(0);              
      delay(15);
          break;
        case '1' :  Serial.println("SerHIGHo motor to 10 degrees");
      myservo2d.write(18);              
      delay(15);       
          break;
        case '2' :   Serial.println("SerHIGHo motor to 120 degrees");
      myservo2d.write(36);
          break;
        case '3' :    Serial.println("SerHIGHo motor to 120 degrees");
      myservo2d.write(54);              
      delay(15);
          break;
        case '4' :  Serial.println("SerHIGHo motor to 120 degrees");
      myservo2d.write(72);              
      delay(15);
          break;
        case '5' :  Serial.println("SerHIGHo motor to 120 degrees");
      myservo2d.write(90);              
      delay(15);
          break;
        case '6' :  Serial.println("SerHIGHo motor to 120 degrees");
      myservo2d.write(108);              
      delay(15);
          break;
        case '7' :   Serial.println("SerHIGHo motor to 120 degrees");
      myservo2d.write(116);              
      delay(15);
          break;
        case '8' :  Serial.println("SerHIGHo motor to 120 degrees");
      myservo2d.write(134);              
      delay(15);
          break;
        case '9' : Serial.println("SerHIGHo motor to 120 degrees");
      myservo2d.write(142);              
      delay(15);
          break;
          case 'q' :Serial.println("SerHIGHo motor to 120 degrees");
      myservo2d.write(150);              
      delay(15);
      break;
        case 'F' : moveForward();
          break;
        case 'B' : moveBackward();
          break;
        case 'R' : spotRight();
          break;
        case 'L' : spotLeft();
          break;
        case 'J' : arcBLeft();
          break;
        case 'G' : arcFRight();
          break;
        case 'H' : arcBRight();
          break;
        case 'I' : arcFLeft();
          break;
        case 'S' : Stop();
          break;
        case 'W' :  
         
         myservo1d.write(0);
         delay(15); 
         break;
         case 'w' :
            
         myservo1d.write(0);
         delay(15);
       
         break;
         case 'U' :  
         
         myservo1d.write(40);
         delay(15); 
         break;
         case 'u' :
            
         myservo1d.write(40);
         delay(15);
       
         break;
         case 'V' :  
         
         myservo1d.write(75);
         delay(15); 
         break;
         case 'v' :
            
         myservo1d.write(75);
         delay(15);
       
         break;
         case 'X' :  
         
         myservo1d.write(90);
         delay(15); 
         break;
         case 'x' :
            
         myservo1d.write(90);
         delay(15);
       
         break;
      }
     
    }
  }

}

void setupBlueToothConnection()
{
  bluetooth.begin(9600); //Set BluetoothBee BaudRate to default baud rate 38400
  bluetooth.print("\r\n+STWMOD=0\r\n"); //set the bluetooth work in slaHIGHe mode
  bluetooth.print("\r\n+STNA=SeeedBTSlaHIGHe\r\n"); //set bluetooth name as "SeeedBTSlaHIGHe"
  bluetooth.print("\r\n+STOAUT=1\r\n"); // Permit Paired device to connect me
  bluetooth.print("\r\n+STAUTO=0\r\n"); // Auto-connection should be forbidden here
  //delay(2000); // This delay is required.
  bluetooth.print("\r\n+INQ=1\r\n"); //make the slave bluetooth inquirable
  Serial.println("The slave bluetooth is inquirable!");
  //delay(2000); // This delay is required.
  bluetooth.flush();
}

void moveForward()
{
  Serial.println("FORWARD");
  digitalWrite(lM1, HIGH);
  digitalWrite(lM2, LOW);
  digitalWrite(rM1, HIGH);
  digitalWrite(rM2, LOW);
}
void moveBackward()
{
  Serial.println("BACKWARD");
  digitalWrite(lM1, LOW);
  digitalWrite(lM2, HIGH);
  digitalWrite(rM1, LOW);
  digitalWrite(rM2, HIGH);

}
void spotLeft()
{
  Serial.println("SPOTRIGHT");
  digitalWrite(lM1, LOW);
  digitalWrite(lM2, HIGH);
  digitalWrite(rM1, HIGH);
  digitalWrite(rM2, LOW);

}
void spotRight()
{
  Serial.println("SPOTLEFT");
  digitalWrite(lM1, HIGH);
  digitalWrite(lM2, LOW);
  digitalWrite(rM1, LOW);
  digitalWrite(rM2, HIGH);
}
void arcFRight()
{
  Serial.println("ARCRIGHT");
  digitalWrite(lM1, LOW);
  digitalWrite(lM2, HIGH);
  digitalWrite(rM1, HIGH);
  digitalWrite(rM2, HIGH);
}
void arcFLeft()
{

  Serial.println("ARCLEFT");
  digitalWrite(lM1, HIGH);
  digitalWrite(lM2, HIGH);
  digitalWrite(rM1, LOW);
  digitalWrite(rM2, HIGH);
}
void arcBRight()
{
  digitalWrite(lM1, HIGH);
  digitalWrite(lM2, LOW);
  digitalWrite(rM1, HIGH);
  digitalWrite(rM2, HIGH);
}
void arcBLeft()
{
  digitalWrite(lM1, HIGH);
  digitalWrite(lM2, HIGH);
  digitalWrite(rM1, HIGH);
  digitalWrite(rM2, LOW);
}

void Stop()
{
  digitalWrite(lM1, LOW);
  digitalWrite(lM2, LOW);
  digitalWrite(rM1, LOW);
  digitalWrite(rM2, LOW);
}
