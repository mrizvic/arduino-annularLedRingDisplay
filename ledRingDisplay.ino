volatile byte muxCount = 0;
volatile byte maskD[16] = {196, 200, 208, 224, 196, 200, 208, 224, 68, 72, 80, 96, 132, 136, 144, 160};
volatile byte maskB[16] = {1,1,1,1,2,2,2,2,3,3,3,3,3,3,3,3};
volatile byte ledSegments1[16];

byte n=0;
byte rxByte=0;

void setup() {
  cli();
  DDRD = 252;  // sets Arduino pins 2 to 7 as outputs
  DDRB = 255; // sets Arduino pins 8 and 9 as outputs
  //timer setup
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 58000;
  TCCR1B = _BV(CS10); //prescaler
  TIMSK1 = _BV(TOIE1); //enable overflow interrupt
  sei();
  Serial.begin(9600);
}

ISR(TIMER1_OVF_vect) {
  TCNT1 = 58000;
  if (ledSegments1[muxCount]) {
    PORTD = maskD[muxCount];
    PORTB = maskB[muxCount];
  } else {
    PORTD = 0;
    PORTB = 0;
  }
  muxCount = ++muxCount % 16;
}

void loop() {
  if (Serial.available()>0) {
    rxByte = Serial.read();
    if (rxByte == '0') {
      ledSegments1[n] = 0;
    } else {
      ledSegments1[n] = 1;
    }
    n = ++n % 16;
  }
}
