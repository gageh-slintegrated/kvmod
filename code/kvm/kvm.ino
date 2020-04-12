
int sw = 12;

//declare class and assign objects
class kvm{
  public:
    char ch1;
    float ch1_voltage;
    bool ch1_state;
    
    char ch2;
    float ch2_voltage;
    bool ch2_state;
    
    int sw;
};

auto kvm_1 = kvm();
auto kvm_2 = kvm();


//setup
void setup()
{
    Serial.begin(9600);
    pinMode(kvm_1.ch1=A0,INPUT);
    pinMode(kvm_1.ch2=A1,INPUT);
    pinMode(kvm_1.sw=7,OUTPUT);
    
    pinMode(kvm_2.ch1=A2,INPUT);
    pinMode(kvm_2.ch2=A3,INPUT);
    pinMode(kvm_2.sw=8,OUTPUT);
}

bool change_ch(bool ch1_state, bool ch2_state)
{
  
}


void loop()
{
    //read sw state
    bool sw_state = digitalRead(sw);   
    kvm_1.ch1_voltage = analogRead(kvm_1.ch1) * (5.0 / 1024.0);
    kvm_1.ch2_voltage = analogRead(kvm_1.ch2) * (5.0 / 1024.0);
    

    if(kvm_1.ch1_voltage < 1){
      kvm_1.ch1_state = true;
      kvm_1.ch2_state = false;
    }
    else if(kvm_1.ch2_voltage < 1){
      kvm_1.ch1_state = false;
      kvm_1.ch2_state = true;
    }

    
    /*
    if(kvm_1.ch1_state){
      Serial.print("On Channel 1\n");
    }
    else if(kvm_1.ch2_state){
      Serial.print("On Channel 2\n");
    }*/

    if(sw_state)
    {
      Serial.println("ON!");
      digitalWrite(kvm_1.sw, HIGH);
      delay(1000);
      digitalWrite(kvm_1.sw, LOW);
    }
    
    delay(1000);
}

