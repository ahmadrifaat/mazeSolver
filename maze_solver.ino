// #include <AFMotor.h>

// AF_DCMotor motor_kiri(1);
// AF_DCMotor motor_kanan(2);

// Inisialisasi pin sensor ultrasonik
const int trigPinSensorDepan = 12;  // contoh pin trigger sensor depan
const int echoPinSensorDepan = 13; // contoh pin echo sensor depan

const int trigPinSensorKiri = 23;  // contoh pin trigger sensor kiri
const int echoPinSensorKiri = 22; // contoh pin echo sensor kiri

const int trigPinSensorKanan = 25;  // contoh pin trigger sensor kanan
const int echoPinSensorKanan = 33; // contoh pin echo sensor kanan

const int IN1 = 21;
const int IN2 = 18;
const int IN3 = 19;
const int IN4 = 5;

void setup() {
  // Set pin mode untuk sensor ultrasonik
  pinMode(trigPinSensorDepan, OUTPUT);
  pinMode(echoPinSensorDepan, INPUT);

  pinMode(trigPinSensorKiri, OUTPUT);
  pinMode(echoPinSensorKiri, INPUT);

  pinMode(trigPinSensorKanan, OUTPUT);
  pinMode(echoPinSensorKanan, INPUT);

  // Set pin mode untuk motor
  // motor_kiri.setSpeed(255);
  // motor_kanan.setSpeed(255);

  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  int jarakDepan = bacaJarak(trigPinSensorDepan, echoPinSensorDepan);
  int jarakKiri = bacaJarak(trigPinSensorKiri, echoPinSensorKiri);
  int jarakKanan = bacaJarak(trigPinSensorKanan, echoPinSensorKanan);
  Serial.println(jarakDepan);
  Serial.println(jarakKiri);
  Serial.println(jarakKanan);
  delay(100);

  if (jarakDepan > jarakKiri && jarakDepan > jarakKanan) {
    maju();
  } else if (jarakKiri > jarakDepan && jarakKiri > jarakKanan) {
    belokKiri();
  } else {
    belokKanan();
  }
}

int bacaJarak(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  int duration = pulseIn(echoPin, HIGH);
  int jarak = duration * 0.034 / 2;

  return jarak;
}

void maju(){
Serial.println("maju");
digitalWrite(IN1, LOW);
digitalWrite(IN2, HIGH);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, LOW);
}
void belokKiri(){
Serial.println("kanan");
digitalWrite(IN1, LOW);
digitalWrite(IN2, HIGH);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, HIGH);
// delay(1000);
}
void belokKanan(){
Serial.println("kiri");
digitalWrite(IN1, HIGH);
digitalWrite(IN2, HIGH);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, LOW);
// delay(1000);
}
