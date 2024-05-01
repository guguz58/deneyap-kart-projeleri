const int buzzer = D2; 
const int sensor = D3;

int state; // 0 close - 1 open wwitch

void setup()
{
	pinMode(sensor, INPUT_PULLUP);
}

void loop()
{
	state = digitalRead(sensor);
	
	if (state == HIGH){
		tone(buzzer, 400);
	}
	else{
		noTone(buzzer);
	}
	delay(200);
}