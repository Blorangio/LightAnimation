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
    bool clicked = false;
    pin_t pin;
    void initialize(pin_t PIN) {
      pin = PIN;
      pinMode(pin, INPUT);
    }
    bool once = true;
    void update() {
      clicked = false;
      pinMode(pin, INPUT);
      if(digitalRead(pin)==HIGH&&!bDown) {
        bDown = true;
        if(once) {
          clicked = true;
          once = false;
        }
        val = !val;
      }
      if(digitalRead(pin)==LOW) {
        bDown = false;
        once = true;
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
LED l6;
void clear() {
  l1.vTog(false);
  l2.vTog(false);
  l3.vTog(false);
  l4.vTog(false);
  l5.vTog(false);
}
bool lightSequence[5][5];
void setup() {
  b1.initialize(D0);
  b2.initialize(D1);
  b3.initialize(D2);
  b4.initialize(D3);
  l1.initialize(D4);
  l2.initialize(D5);
  l3.initialize(D6);
  l4.initialize(D7);
  l5.initialize(D8);
  l6.initialize(D9);
  Serial.begin(9600);
}
int lightIndex = 0;
int animationIndex = 0;
int animatedIndex = 0;
void loop() {
  b1.update();
  b2.update();
  b3.update();
  b4.update();
  for(int i=0;i<lightIndex;i++) {
    if(i==0) {
      l1.vTog(lightSequence[animationIndex][i]);
    }
    if(i==1) {
      l2.vTog(lightSequence[animationIndex][i]);
    }
    if(i==2) {
      l3.vTog(lightSequence[animationIndex][i]);
    }
    if(i==3) {
      l4.vTog(lightSequence[animationIndex][i]);
    }
    if(i==4) {
      l5.vTog(lightSequence[animationIndex][i]);
    }
  }
  if(animationIndex<5) {
    if(b2.clicked||b3.clicked||b1.clicked) {
      bool notThisFrame=false;
      if(lightIndex == 5 && b1.clicked) {
        lightIndex = 0;
        animationIndex++;
        clear();
      }
      if(lightIndex == 5 && b3.clicked) {
        lightIndex = 0;
        notThisFrame=true;
        clear();
      }
      if(lightIndex!=5&&!b1.clicked&&!notThisFrame) {
        lightSequence[animationIndex][lightIndex] = !b2.clicked;
        lightIndex++;
      }
      if(lightIndex == 5) {
        l6.on();
      } else {
        l6.off();
      }
    }
  } else {
    l6.on();
    if(b4.clicked) {
      while(true) {
        l1.vTog(lightSequence[animatedIndex][0]);
        l2.vTog(lightSequence[animatedIndex][1]);
        l3.vTog(lightSequence[animatedIndex][2]);
        l4.vTog(lightSequence[animatedIndex][3]);
        l5.vTog(lightSequence[animatedIndex][4]);
        animatedIndex++;
        if(animatedIndex==5) {
          animatedIndex = 0;
        }
        delay(200);
      }
    }
  }
}