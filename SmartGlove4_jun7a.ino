
#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <LiquidCrystal_I2C.h> 
#include <SoftwareSerial.h>

//Variables for The sensor Pin
int sensorPin1 = A0;
int sensorPin2 = A1;
int sensorPin3 = A2;
int sensorPin4 = A3;
int sensorPin5 = A4;

//Declare sensors
 int sensor1;
 int sensor2;
 int sensor3;
 int sensor4;
 int sensor5;

LiquidCrystal_I2C lcd(0x27,16,2); 
Adafruit_MPU6050 mpu;

SoftwareSerial mySerial(0, 1);//RX and TX

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);

  lcd.init();    
  // while (!Serial)
  delay(10); // wait for Serial monitor
  Serial.println("Initializing MPU6050...");
  mpu.begin();
  Serial.println("MPU6050 initialized.");
  lcd.begin(16, 2); // Initialize the LCD
  lcd.print("Welcome User!");
  lcd.setCursor(0, 1);
  lcd.print("Today's agenda?");
  lcd.backlight();   
  delay(2000);
  lcd.clear();
}

void loop() {

  //Sensor PinMode
    sensor1 = analogRead(sensorPin1);
    sensor2 = analogRead(sensorPin2);
    sensor3 = analogRead(sensorPin3);
    sensor4 = analogRead(sensorPin4);
    sensor5 = analogRead(sensorPin5);
    Serial.print("Reading1: ");
  	Serial.println(sensor1);
    Serial.print("Reading2: ");
  	Serial.println(sensor2);
    Serial.print("Reading3: ");
  	Serial.println(sensor3);
  	Serial.print("Reading4: ");
  	Serial.println(sensor4);
  	Serial.print("Reading5: ");
  	Serial.println(sensor5);
    
    delay(1000); // delay for 1 second
    
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  Serial.print("Acceleration: X=");
  Serial.print(a.acceleration.x);
  Serial.print(" Y=");
  Serial.print(a.acceleration.y);
  Serial.print(" Z=");
  Serial.println(a.acceleration.z);

// Accelerometer Movement
     if(a.acceleration.x<=1 && a.acceleration.y>=-10){
    lcd.clear();
  	lcd.setCursor(0, 0);
  	lcd.print(" HELLO!");
    lcd.setCursor(0, 1);
    lcd.print(" How are You?");

//Text Of Bluetooth will Be Displayed Here
}
      else if(a.acceleration.x>=4 && a.acceleration.y>=-6){
    mySerial.println("Can you Hear me");
    lcd.clear();
  	lcd.setCursor(0, 0);
  	lcd.print("Can you hear Me?");
    lcd.setCursor(0, 1);
    lcd.print("Mister");

}
    else if(a.acceleration.x<=2 && a. acceleration.y<=8){
    lcd.clear();
  	lcd.setCursor(0, 0);
  	lcd.print("Speak Louder");
    lcd.setCursor(0, 1);
    lcd.print("Please.");

}
      else if(a.acceleration.x>=1 && a. acceleration.y>=8){
    lcd.clear();
  	lcd.setCursor(0, 0);
  	lcd.print("Let's Chat later");
    lcd.setCursor(0, 1);
    lcd.print("Friend");

    }
        else if(a.acceleration.x>=3 && a. acceleration.y>=-10){
    lcd.clear();
  	lcd.setCursor(0, 0);
  	lcd.print("Nice to Meet you ");
  	lcd.setCursor(0, 1);
  	lcd.print("Friend!");

}
        else if(a.acceleration.x<=4 && a. acceleration.y<=-1){
    lcd.clear();
  	lcd.setCursor(0, 0);
  	lcd.print("Are you Ok?");
    lcd.setCursor(0, 1);
    lcd.print("Friend");

    }

     if(a.acceleration.x<=9 && a.acceleration.y>=9){
    lcd.clear();
  	lcd.setCursor(0, 0);
  	lcd.print("Please Repeat.");

    }  
    //    else if(a.acceleration.x>=2 && a.acceleration.y<=9 &&  a.acceleration.z>=-1){
    // lcd.clear();
  	// lcd.setCursor(0, 0);
  	// lcd.print("Please Repeat.");

    // }   
    // else if(a.acceleration.x<=1 && a. acceleration.y>=-10){
//     lcd.clear();
//   	lcd.setCursor(0, 0);
//   	lcd.print("Take Your Time");
//     lcd.setCursor(0, 1);
//     lcd.print("Sir");

//     }    else if(a.acceleration.x<=1 && a. acceleration.y>=-10){
//     lcd.clear();
//   	lcd.setCursor(0, 0);
//   	lcd.print(" I Understand ");
//     lcd.setCursor(0, 1);
//     lcd.print("Continue");

//     }
//         else if(a.acceleration.x<=1 && a. acceleration.y>=-10){
//     lcd.clear();
//   	lcd.setCursor(0, 0);
//   	lcd.print(" Thank You ");
//     }  
//       else if(a.acceleration.x<=1 && a. acceleration.y>=-10){
//     lcd.clear();
//   	lcd.setCursor(0, 0);
//   	lcd.print("What's up");

//     }
//         else if(a.acceleration.x<=1 && a. acceleration.y>=-10){
//     lcd.clear();
//   	lcd.setCursor(0, 0);
//   	lcd.print("Tell me More");
//     lcd.setCursor(0, 1);
//     lcd.print("Please.");

//     }
//         else if(a.acceleration.x<=1 && a. acceleration.y>=-10){
//     lcd.clear();
//   	lcd.setCursor(0, 0);
//   	lcd.print("I am here For You");
//     lcd.setCursor(0, 1);
//     lcd.print("Keep talking");

//     }
//         else if(a.acceleration.x<=1 && a. acceleration.y>=-10){
//     lcd.clear();
//   	lcd.setCursor(0, 0);
//   	lcd.print("You are Amazing");

//     }
//         else if(a.acceleration.x<=1 && a. acceleration.y>=-10){
//     lcd.clear();
//   	lcd.setCursor(0, 0);
//   	lcd.print("I Need Help");
//     lcd.setCursor(0, 1);
//     lcd.print("EMERGENCY!!");

//     }
//         else if(a.acceleration.x<=1 && a. acceleration.y>=-10){
//     lcd.clear();
//   	lcd.setCursor(0, 0);
//   	lcd.print("Let's Talk Soon");

    // }
//The key is following the Accelerometer as it move
//       if(a.acceleration.x>=10 && a.acceleration.y>=12){

// }
//   }


   else {
  	delay(200);

  }
      if(sensor1 >= 990 ){
    digitalWrite(sensor1, HIGH);
    digitalWrite(sensor2, LOW);
    digitalWrite(sensor3, LOW);
    digitalWrite(sensor4, LOW);
    digitalWrite(sensor5, LOW);
    // Sensor1 Initial 984
    //Sensor 2 992
    // Sensor3 982
    // Sensor 4 988
    //Sensor 5 915

 
    lcd.clear();
  	lcd.setCursor(0, 0);
  	lcd.print(" Nice ");
    lcd.setCursor(0, 1);
    lcd.print("..A..");
     
      
   }
       if(sensor1 >= 1003 ){
    digitalWrite(sensor1, HIGH);
    digitalWrite(sensor2, LOW);
    digitalWrite(sensor3, LOW);
    digitalWrite(sensor4, LOW);
    digitalWrite(sensor5, LOW);

    lcd.clear();
  	lcd.setCursor(0, 0);
  	lcd.print(" The Letter..");
    lcd.setCursor(0, 1);
    lcd.print("..B..");
     
      
   }
          if(sensor2 >= 995 ){
    digitalWrite(sensor1, LOW);
    digitalWrite(sensor2, HIGH);
    digitalWrite(sensor3, LOW);
    digitalWrite(sensor4, LOW);
    digitalWrite(sensor5, LOW);

    lcd.clear();
  	lcd.setCursor(0, 0);
  	lcd.print(" Meet");
    lcd.setCursor(0, 1);
    lcd.print("..C..");
     
      
   }
          if(sensor2 >= 1001 ){
    digitalWrite(sensor1, LOW);
    digitalWrite(sensor2, HIGH);
    digitalWrite(sensor3, LOW);
    digitalWrite(sensor4, LOW);
    digitalWrite(sensor5, LOW);

    lcd.clear();
  	lcd.setCursor(0, 0);
  	lcd.print(" you ");
    lcd.setCursor(0, 1);
    lcd.print("..Q..");
     
      
   }
        if(sensor3 >= 995 ){
    digitalWrite(sensor1, LOW);
    digitalWrite(sensor2, LOW);
    digitalWrite(sensor3, HIGH);
    digitalWrite(sensor4, LOW);
    digitalWrite(sensor5, LOW);

    lcd.clear();
  	lcd.setCursor(0, 0);
  	lcd.print(" Please ");
    lcd.setCursor(0, 1);
    lcd.print("..D..");
     
      
   }
        if(sensor3 >= 1000 ){
    digitalWrite(sensor1, LOW);
    digitalWrite(sensor2, LOW);
    digitalWrite(sensor3, HIGH);
    digitalWrite(sensor4, LOW);
    digitalWrite(sensor5, LOW);

    lcd.clear();
  	lcd.setCursor(0, 0);
  	lcd.print(" Medicine");
    lcd.setCursor(0, 1);
    lcd.print("..G..");
     
      
   }
           if(sensor4 >= 1000 ){
    digitalWrite(sensor1, LOW);
    digitalWrite(sensor2, LOW);
    digitalWrite(sensor3, LOW);
    digitalWrite(sensor4, HIGH);
    digitalWrite(sensor5, LOW);

    lcd.clear();
  	lcd.setCursor(0, 0);
  	lcd.print(" Me ");
    lcd.setCursor(0, 1);
    lcd.print("..K..");
     
      
   }
           if(sensor4 >= 1010 ){
    digitalWrite(sensor1, LOW);
    digitalWrite(sensor2, LOW);
    digitalWrite(sensor3, LOW);
    digitalWrite(sensor4, HIGH);
    digitalWrite(sensor5, LOW);

    lcd.clear();
  	lcd.setCursor(0, 0);
  	lcd.print(" The Letter..");
    lcd.setCursor(0, 1);
    lcd.print("..O..");
     
      
   }
        if(sensor5 >=935 ){
    digitalWrite(sensor1, LOW);
    digitalWrite(sensor2, LOW);
    digitalWrite(sensor3, LOW);
    digitalWrite(sensor4, LOW);
    digitalWrite(sensor5, HIGH);

    lcd.clear();
  	lcd.setCursor(0, 0);
  	lcd.print(" The Letter..");
    lcd.setCursor(0, 1);
    lcd.print("..J..");
     
      
   }
       if(sensor5 >= 1003 ){
    digitalWrite(sensor1, LOW);
    digitalWrite(sensor2, LOW);
    digitalWrite(sensor3, LOW);
    digitalWrite(sensor4, LOW);
    digitalWrite(sensor5, HIGH);

    lcd.clear();
  	lcd.setCursor(0, 0);
  	lcd.print(" The Letter..");
    lcd.setCursor(0, 1);
    lcd.print("..I..");
     
      
   }

    if(sensor1 >= 1000 && sensor2 >=1000){
        digitalWrite(sensor1, HIGH);
    digitalWrite(sensor2, HIGH);
    digitalWrite(sensor3, LOW);
    digitalWrite(sensor4, LOW);
    digitalWrite(sensor5, LOW);

    lcd.clear();
  	lcd.setCursor(0, 0);
  	lcd.print(" ..The Letter..");
    lcd.setCursor(0, 1);
    lcd.print("..F..");

   }

    if(sensor2 >= 1000 && sensor4 >=1000){
        digitalWrite(sensor1, LOW);
    digitalWrite(sensor2, HIGH);
    digitalWrite(sensor3, LOW);
    digitalWrite(sensor4, HIGH);
    digitalWrite(sensor5, LOW);

    lcd.clear();
  	lcd.setCursor(0, 0);
  	lcd.print(" Food");
    lcd.setCursor(0, 1);
    lcd.print("..U..");

   }

    if(sensor2 >= 1000 && sensor3 >=1000 && sensor4 >=1000){
        digitalWrite(sensor1, LOW);
    digitalWrite(sensor2, HIGH);
    digitalWrite(sensor3, HIGH);
    digitalWrite(sensor4, HIGH);
    digitalWrite(sensor5, LOW);

    lcd.clear();
  	lcd.setCursor(0, 0);
  	lcd.print(" ..The Letter..");
    lcd.setCursor(0, 1);
    lcd.print("..Y..");

   }
       if(sensor3 >= 1000 && sensor4 >=1000 && sensor5 >=1000){
        digitalWrite(sensor1, LOW);
    digitalWrite(sensor2, LOW);
    digitalWrite(sensor3, HIGH);
    digitalWrite(sensor4, HIGH);
    digitalWrite(sensor5, HIGH);

    lcd.clear();
  	lcd.setCursor(0, 0);
  	lcd.print(" ..The Letter..");
    lcd.setCursor(0, 1);
    lcd.print("..L..");

   }
    if(sensor1 >= 1000 && sensor3 >=1000 ){
        digitalWrite(sensor1, HIGH);
    digitalWrite(sensor2, LOW);
    digitalWrite(sensor3, HIGH);
    digitalWrite(sensor4, LOW);
    digitalWrite(sensor5, LOW);

    lcd.clear();
  	lcd.setCursor(0, 0);
  	lcd.print(" ..The Letter..");
    lcd.setCursor(0, 1);
    lcd.print("..P..");

   }
       if(sensor2 >= 1000 && sensor4 >=1000 && sensor5 >=1000){
    digitalWrite(sensor1, LOW);
    digitalWrite(sensor2, HIGH);
    digitalWrite(sensor3, LOW);
    digitalWrite(sensor4, HIGH);
    digitalWrite(sensor5, HIGH);

    lcd.clear();
  	lcd.setCursor(0, 0);
  	lcd.print(" ..The Letter..");
    lcd.setCursor(0, 1);
    lcd.print("..R..");

   }
    if(sensor1 >= 1000 && sensor3 >=1000 && sensor4 >=1000 && sensor5 >=1000){
        digitalWrite(sensor1, HIGH);
    digitalWrite(sensor2, LOW);
    digitalWrite(sensor3, HIGH);
    digitalWrite(sensor4, HIGH);
    digitalWrite(sensor5, HIGH);

    lcd.clear();
  	lcd.setCursor(0, 0);
  	lcd.print(" ..The Letter..");
    lcd.setCursor(0, 1);
    lcd.print("..Z..");

   }
 


 delay(1000);



}