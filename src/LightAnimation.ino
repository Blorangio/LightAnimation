SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);
class LED {
  public:
    bool val = false;
    pin_t pin;
    void initialize(pin_t PIN) {
      pin = PIN;
      pinMode(pin, OUTPUT);
    }
    void on() {
      val = true;
      digitalWrite(pin, HIGH);
    }
    void off() {
      val = false;
      digitalWrite(pin, LOW);
    }
    void vTog(bool iVal) {
      val = iVal;
      if(val) {
        digitalWrite(pin, HIGH);
      } else {
        digitalWrite(pin, LOW);
      }
    }
};
class Button {
  public:
    bool bDown = false;
    bool val = false;
    pin_t pin;
    void initialize(pin_t PIN) {
      pin = PIN;
      pinMode(pin, INPUT);
    }
    void update() {
      pinMode(pin, INPUT);
      if(digitalRead(pin)==HIGH&&!bDown) {
        bDown = true;
        val = !val;
      }
      if(digitalRead(pin)==LOW) {
        bDown = false;
      }
    }
};
Button b1;
Button b2;
Button b3;
Button b4;
LED l1;
LED l2;
LED l3;
LED l4;
LED l5;
void setup() {
  b1.initialize(D0);
  b1.initialize(D1);
  b1.initialize(D2);
  b1.initialize(D3);
  l1.initialize(D4);
  l1.initialize(D5);
  l1.initialize(D6);
  l1.initialize(D7);
  l1.initialize(D8);
}
void loop() {
  
}