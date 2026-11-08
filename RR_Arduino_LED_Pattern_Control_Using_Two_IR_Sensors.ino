/*
* Created by Balaji for Rajan Robotica
* Rajan Robotics
*/

int no_led=6;
int led[]={13,12,11,10,9,8};
int left_ir=7,right_ir=5;
/*
IR sensor
Obs yes = 0
Obs No = 1
*/

void setup() {
 pinMode(left_ir,INPUT);
 pinMode(right_ir,INPUT);
 Serial.begin(9600);
 Serial.println("Rajan Robotics");
  for(int i=0;i<no_led;i++){
    pinMode(led[i],OUTPUT);
    digitalWrite(led[i],HIGH);
    delay(300);
  }
  delay(500);

  for(int i=no_led;i>0;i--){
    pinMode(led[i],OUTPUT);
    digitalWrite(led[i],LOW);
    delay(300);
  }
  Serial.println("LED_IR-Pattern");
}

void loop() {
int left_status=digitalRead(left_ir);
int right_status=digitalRead(right_ir);

Serial.print("left_status = ");
Serial.println(left_status);

Serial.print("right_status = ");
Serial.println(right_status);

/*
IR sensor
Obs yes = 0
Obs No = 1
*/
if( (left_status==0) && (right_status==0) ){
  Serial.println("Both IR");
  both();
  int left_status=digitalRead(left_ir);
int right_status=digitalRead(right_ir);

Serial.print("left_status = ");
Serial.println(left_status);

Serial.print("right_status = ");
Serial.println(right_status);
}

while(left_status==0){//Obs
all_off();
delay(500);

lt_rt_all();
delay(500);
left_status=digitalRead(left_ir);
Serial.print("left_status = ");
Serial.println(left_status);
}

while(right_status==0)//right obs Yes
{
all_off();
delay(500);

rt_lt_all();
delay(500);
right_status=digitalRead(right_ir);
Serial.print("right_status = ");
Serial.println(right_status);
}

def();
}

void lt_rt(){
//Serial.print("Currently executing: ");
//Serial.println(__func__); 
for(int i=0;i<no_led;i++){
    digitalWrite(led[i],HIGH);
    delay(100);
    digitalWrite(led[i],LOW);
  }
}

void rt_lt(){
//  Serial.print("Currently executing: ");
//  Serial.println(__func__); 
for(int i=no_led;i>=0;i--){
    digitalWrite(led[i],HIGH);
    delay(100);
    digitalWrite(led[i],LOW);
  }
}

void lt_rt_all(){
  Serial.print("Currently executing: ");
  Serial.println(__func__); 
 for(int i=0;i<no_led;i++){
    digitalWrite(led[i],HIGH);
    delay(300);
  } 
}

void rt_lt_all(){
  Serial.print("Currently executing: ");
  Serial.println(__func__); 
 for(int i=no_led;i>=0;i--){
    digitalWrite(led[i],HIGH);
    delay(300);
  } 
}

void all_off(){
 Serial.print("Currently executing: ");
 Serial.println(__func__); 
   for(int i=no_led;i>=0;i--){
    digitalWrite(led[i],LOW);
  } 
}

void def(){
  Serial.print("Currently executing: ");
 Serial.println(__func__); 
lt_rt();
delay(500);
rt_lt();
delay(500);
}

void both(){
  Serial.print("Current Func is:");
  Serial.println(__func__);
  int step=1;
  for(int i=2;i>=0;i--){//
  digitalWrite(led[i],HIGH);//2;1;0
    digitalWrite(led[i+step],HIGH);//2+1(3)//1+3(4)//0+5(5)
    step+=2;//3//5//7
  delay(500);
  }
  Serial.println("*******");
  delay(1000);
  all_off();
  delay(1000);
  step=5;
  for(int i=0;i<=2;i++){//
  digitalWrite(led[i],HIGH);//2;1;0
    digitalWrite(led[i+step],HIGH);//2+1(3)//1+3(4)//0+5(5)
    step-=2;//3//5//7
  delay(500);
  }
  delay(1000);
  all_off();
  delay(1000);
}
