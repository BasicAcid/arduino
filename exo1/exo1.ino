#define LED 13
#define DUREE_POINT 300
#define DUREE_BARRE (DUREE_POINT*3)
#define DUREE_ENTRE_MOTS (DUREE_POINT*7)
#define DUREE_ENTRE_LETTRES (DUREE_POINT*3)

const char * morse[]={
	".-", 
	"-...", 
	"-.-.", 
	"-..", 
	".", 
	"..-.", 
	"--.", 
	"....", 
	"..", 
	".---", 
	"-.-", 
	".-..", 
	"--", 
	"-.", 
	"---", 
	".--.", 
	"--.-", 
	".-.", 
	"...", 
	"-", 
	"..-", 
	"...-", 
	".--", 
	"-..-", 
	"-.--", 
	"--.." };

const char message[] = "TEST SOS";

void setup(){
    pinMode(LED, OUTPUT);
}

void loop(){
    for(int i=0; message[i] != '\0'; i++){
	if (message[i] == ' '){
	    delay(DUREE_ENTRE_MOTS - DUREE_ENTRE_LETTRES);
	}
	else {
	    assert('A' <= message[i] && message[i] <= 'Z');
	    int indice_lettre = message[i] - 'A';
	    const char * morse_lettre = morse[indice_lettre];

	    for(int j=0; morse_lettre[j] != '\0', j++){
		digitalWrite(LED, HIGH);
		if(morse_lettre[j] == '.'){
		    delay(DUREE_POINT);
		}
		else {
		    assert(morse_lettre[j] == '-');
		    delay(DUREE_BARRE);
		}
		digitalWrite(LED, LOW);
		delay(DUREE_POINT);		    
	    }
	    delay(DUREE_ENTRE_LETTRES - DUREE_POINT);
	}
    }
    exit(0);
}
