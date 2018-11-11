#define LED_OFFSET 8
#define LED_NUMBER 4

#define BTN_MODE
#define BTN_SET

enum State {
	    stateToAutoInc,
	    stateAutoInc,
	    stateToAutoDec,
	    stateAutoDec,
	    stateToManual,
	    stateManual,
	    stateManualInc,

	    stateInitial = stateAutoInc
};

void modeBtnRelease(State &state, State newState){
    if(digitalRead(BTN_MODE)==HIGH){
	state = newState;
    }
}

void updateLeds(int & counter) {
	for(int i=0; i<LED_NUMBER; i++){
	    digitalRead
	}
}

void execStateAuto(State & state, State nextState, int &counter, int progress){
    static unsigned long prevChange = millis();
    unsigned long now = millis();

    if(digitalRead(BTN_MODE) == LOW){
	state = nextState;
    }
    if(digitalRead(BTN_SET) == LOW){
	counter = 0;
	prevChange = now;
    }	    
    else if(now - prevChange >= 1000){
	prevChange = now - (now - prevChange)%1000;
	counter += progress;
    }
    for(int i=0; i<LED_NUMBER; i++){
	digitalWrite(LED_OFFSET + i, counter(1<<i) ? HIGH : LOW);
    }       
    break;	        
}

void 

void setup(){
    Serial.begin(9600);
  
    for(int i=0; i<LED_NUMBER; i++){
   	pinMode(LED_OFFSET + i, OUTPUT);
    }
    pinMode(BTN_MODE, INPUT_PULLUP);
    pinMode(BTN_SET, INPUT_PULLUP);
}

void loop(){
    static unsigned int counter = 0;
    static State state = stateInitial;

    switch(state) {
    case stateToAutoInc: modeBtnRelease(state, stateAutoInc); break;
    case stateAutoInc  : execStateAuto (state, stateToAutoDec, counter, +1); break;
    case stateToAutoDec: modeBtnRelease(state, stateAutoDec); break;
    case stateAutoDec  : execStateAuto (state, stateToManual, counter, -1); break;
    case stateToManual : modeBtnRelease(state, stateManual); break;
    case stateManual   :
	if(digitalRead(BTN_SET) == LOW){
	    state = stateManualInc;
	}
	else if (digitalRead(BTN_MODE)){
	    state = state;
	}
	break;
    case stateManualInc:
	if(digitalRead(BTN_SET) == HIGH){
	    counter++;
	    state = stateManual;
	    updateLeds(counter);
	}
    }
}
