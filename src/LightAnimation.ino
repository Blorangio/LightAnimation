SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);
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
void setup() {
  b1.initialize(D0);
  pinMode(D4, OUTPUT);
}
void loop() {
  b1.update();
  if(b1.val) {
    digitalWrite(D4, HIGH);
  } else {
    digitalWrite(D4, LOW);
  }
}