#define SPEED 500
#define A_PIN 9
#define B_PIN 8

int compteur = 0;
int butA = 0;
int butB = 0;
const int LED[4]={10,11,12,13};

void setup(){
    Serial.begin(9600);
  
    for(int i=0; i<=3; i++){
   	pinMode(LED[i], OUTPUT);
    }
  
    pinMode(A_PIN, INPUT_PULLUP);
    pinMode(B_PIN, INPUT_PULLUP);
}

void loop(){
    butA = digitalRead(A_PIN); 
    butB = digitalRead(B_PIN); 
    if (digitalRead(A_PIN) == 0){
  	Serial.println(butA);
  	Serial.println(butB);
    }
  
    for(int i=0; i<=3; i++){
  	digitalWrite(LED[i], bitRead(compteur ,i));
    }
     
    compteur=compteur+1;
  
    if (compteur>=16 || butA == LOW) compteur=0;
  
    delay(SPEED);
}
