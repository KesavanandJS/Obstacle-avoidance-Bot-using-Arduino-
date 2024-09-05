#define TRIG 3//UltraSonic Sensor TRIG In PIN 3
#define ECHO 4//UltraSonic Sensor ECHO In PIN 4
#define MOTOR_R1 5//In1 is connected to PIN 6
#define MOTOR_R2 6//In2 is connected to PIN 7
#define MOTOR_L1 7//In3 is connected to PIN 8
#define MOTOR_L2 8//In4 is connected to PIN 9
#define EN_A 9//ENABLE_A is Connected into PIN 10
#define EN_B 10//ENABLE_B is Connected into PIN 11
const int safeDist = 20;
const int maxDist = 70;
void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(MOTOR_R1, OUTPUT);
  pinMode(MOTOR_R2, OUTPUT);
  pinMode(MOTOR_L1, OUTPUT);
  pinMode(MOTOR_L2, OUTPUT);
  pinMode(EN_A, OUTPUT);
  pinMode(EN_B,OUTPUT);
  Serial.begin(9600);
}
void loop() {
  digitalWrite(TRIG,LOW);
  digitalWrite(MOTOR_R1,LOW);digitalWrite(MOTOR_R2,LOW);digitalWrite(MOTOR_L1,LOW);digitalWrite(MOTOR_L2,LOW);
  int distance = meaDist();
  if(distance <= safeDist) {
    killPower();
    moveReverse();
    delay(300);
    moveRight();
    moveForward();
  }
  else if(distance >= safeDist || distance == maxDist) {
    moveForward();
  }
}
int meaDist() {
  digitalWrite(TRIG,LOW);
  delay(1);
  digitalWrite(TRIG, HIGH);
  delay(10);
  digitalWrite(TRIG,LOW);
  float duration = pulseIn(ECHO,HIGH);
  float distance = (duration * 0.034)/2;
  Serial.print("Measured Distance:");
  Serial.println(distance);
  return distance;
}
void killPower() {
  digitalWrite(MOTOR_R1,LOW);digitalWrite(MOTOR_R2,LOW);digitalWrite(MOTOR_L1,LOW);digitalWrite(MOTOR_L2,LOW);
  Serial.println("STOP");
  delay(800);
}
void moveForward() {
  digitalWrite(MOTOR_R1,HIGH);digitalWrite(MOTOR_R2,LOW);digitalWrite(MOTOR_L1,HIGH);digitalWrite(MOTOR_L2,LOW);
  Serial.println("FORWARD");
  delay(800);
}
void moveReverse() {
  digitalWrite(MOTOR_R1,LOW);digitalWrite(MOTOR_R2,HIGH);digitalWrite(MOTOR_L1,LOW);digitalWrite(MOTOR_L2,HIGH);
  Serial.println("REVERSE");
  delay(800);
}
void moveRight() {
  digitalWrite(MOTOR_R1,LOW);digitalWrite(MOTOR_R2,HIGH);digitalWrite(MOTOR_L1,HIGH);digitalWrite(MOTOR_L2,LOW);
  Serial.println("RIGHT");
  delay(800);
}
void moveLeft() {
  digitalWrite(MOTOR_R1,HIGH);digitalWrite(MOTOR_R2,LOW);digitalWrite(MOTOR_L1,LOW);digitalWrite(MOTOR_L2,HIGH);
  Serial.println("LEFT");
  delay(800);
}