#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;
int health = 5;
int check = 0;
void setup(void) {
	Serial.begin(9600);

	// Try to initialize!
	if (!mpu.begin()) {
		Serial.println("Failed to find MPU6050 chip");
		while (1) {
		  delay(10);
		}
	}

	// set accelerometer range to +-8G
	mpu.setAccelerometerRange(MPU6050_RANGE_8_G);

	// set gyro range to +- 500 deg/s
	mpu.setGyroRange(MPU6050_RANGE_500_DEG);

	// set filter bandwidth to 21 Hz
	mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

	delay(100);
}

void loop() {


	/* Get new sensor events with the readings */
	sensors_event_t a, g, temp;
	mpu.getEvent(&a, &g, &temp);

	float zVal = a.acceleration.z;
	int soundVal = analogRead(A0);

	check += 1;
	
	if(soundVal >= 800 || soundVal <= 350){
		health += -1;
		check = 0;
		delay(1000);	
			
	}

	else if(zVal >= 12 || zVal <= 6){
		health += -1;
		check = 0;
		delay(1000);
		}
	//Serial.println(health);
	if(check == 100){
		health += 1;
		check == 0;
		}
	switch(health) {
		case 5:
		digitalWrite(13, HIGH);
		digitalWrite(12, HIGH);
		digitalWrite(11, HIGH);
		digitalWrite(10, HIGH);
		digitalWrite(9, HIGH);
		break;
		case 4:
		digitalWrite(13, LOW);
		digitalWrite(12, HIGH);
		digitalWrite(11, HIGH);
		digitalWrite(10, HIGH);
		digitalWrite(9, HIGH);
		break;

		case 3:
		digitalWrite(13, LOW);
		digitalWrite(12, LOW);
		digitalWrite(11, HIGH);
		digitalWrite(10, HIGH);
		digitalWrite(7, HIGH);
		break;
		case 2:
		digitalWrite(13, LOW);
		digitalWrite(12, LOW);
		digitalWrite(11, LOW);
		digitalWrite(10, HIGH);
		digitalWrite(9, HIGH);
		break;
		case 1:
		digitalWrite(13, LOW);
		digitalWrite(12, LOW);
		digitalWrite(11, LOW);
		digitalWrite(10, LOW);
		digitalWrite(9, HIGH);
		break;

		case 0:
		digitalWrite(13, LOW);
		digitalWrite(12, LOW);
		digitalWrite(11, LOW);
		digitalWrite(10, LOW);
		digitalWrite(9, LOW);
		Serial.println(20040707);
	}

	



	
}
