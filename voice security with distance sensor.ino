#include <Keypad.h>  // keypad kütüphanesini programa dahil ediyoruz.
const byte Satir= 4;  // keypad satır sayısı
const byte Sutun= 4;  // keypad sütün sayısı
String Sifre;     // girilen şifre 
String sonuc = "1234";
bool sifreGirildi = false;
int buzzerPin = A0;
// Keypad tuş yapısını hazırlıyoruz.
char key[Satir][Sutun]= 
{
{'1', '2', '3', 'A'}, 
{'4', '5', '6', 'B'}, 
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};
 
// Arduino bağlantı bacaklarını belirliyoruz
byte SatirPinleri[Satir] = {9,8,7,6}; 
byte SutunPinleri[Sutun]= {5,4,3,2}; 

// bu TusTakimi keypad nesnesine tanımlıyoruz.
Keypad TusTakimi= Keypad(makeKeymap(key), SatirPinleri, SutunPinleri, Satir, Sutun);
////////////////////////////////////////////////////////


const int ledPin = 10; // kirmizi
const int ledYesil = 11;
const int echoPin = 13;
const int trigPin = 12;
long sure, mesafe;
void setup() {
  // put your setup code here, to run once:
  
  pinMode(ledPin, OUTPUT);
  pinMode(ledYesil, OUTPUT);

  // Uzaklik Sensoru
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:

    
  // Mesafe olcumu
  if (!sifreGirildi){
    digitalWrite(trigPin, LOW);
    delayMicroseconds(3);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    sure = pulseIn(echoPin, HIGH);
    mesafe = sure /29.1/2;
    delay(500);
  
    digitalWrite(ledYesil, HIGH);
    if (mesafe > 20){
      digitalWrite(ledYesil, LOW); 
      digitalWrite(ledPin, HIGH);
      tone(buzzerPin, 2620);
      delay(500);
      digitalWrite(ledPin, LOW);
      noTone(buzzerPin);
      
      }
      }
      
  else{
    digitalWrite(ledYesil, HIGH);
    delay(500);
    digitalWrite(ledYesil, LOW);
    char basilanTus = TusTakimi.getKey();
      if (basilanTus == 'B'){
        sifreGirildi = false;}
    }
  char basilanTus = TusTakimi.getKey();
  char bas;
  if (basilanTus == 'A') {
  
    while (bas != '#' && bas != '*'){ 
      char bas = TusTakimi.getKey();
      if (bas != NULL){
      Serial.print("Basılan Tuş:");    
      Serial.println(bas);
      if (bas != '#' && bas != '*'){
        Sifre = Sifre + bas;
        Serial.println("Girilen Sifre: " + Sifre );}
        
      if (bas == '#'){
          if (Sifre == sonuc){
            Serial.println("Dogru");
            sifreGirildi = true;
            Sifre = "";
            break;}
           else{
              Serial.println("Yanlis");
               Sifre = "";}
               break;}
      if (bas == '*'){
        Serial.println("Temizlendi");
        Sifre = "";}}
    }
    
    }  
  

  if (basilanTus == 'B'){
    sifreGirildi = false;}
  }

// Malzeme listesi
/*
- 2 adet led
- 1 adet mesafe ölçer
- 1 Uno R3
- 2 adet direnç
- Güç kaynağı
- Keypad
- Kablolar
- Breadboard
- Buzzer
*/
  
