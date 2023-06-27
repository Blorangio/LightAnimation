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
LED l1;
void setup() {
  b1.initialize(D0);
  l1.initialize(D4);
}
void loop() {
  
}