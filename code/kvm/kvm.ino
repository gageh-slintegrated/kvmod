
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

    int current_channel;
    
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

int check_channel(int ch1, int ch2)
{
  if(ch1 < 1)
  {
    return 1;
  }
  else if(ch2 < 1)
  {
    return 2;
  }
}

float voltage(char ch)
{
  return analogRead(ch) * (5.0 / 1024.0);
}

void loop()
{
    //read sw state
    bool sw_state = digitalRead(sw);   

    //get kvm_1 current channel
    kvm_1.ch1_voltage = voltage(kvm_1.ch1);
    kvm_1.ch2_voltage = voltage(kvm_1.ch2);
    kvm_1.current_channel = check_channel(kvm_1.ch1_voltage,kvm_1.ch2_voltage);

    //get kvm_2 current channel
    kvm_2.ch1_voltage = voltage(kvm_2.ch1);
    kvm_2.ch2_voltage = voltage(kvm_2.ch2);
    kvm_2.current_channel = check_channel(kvm_2.ch1_voltage,kvm_2.ch2_voltage);

    if(sw_state)
    {
      if(kvm_1.current_channel == kvm_2.current_channel)
      {
         digitalWrite(kvm_1.sw, HIGH);
         digitalWrite(kvm_2.sw, HIGH);
         delay(100);
         digitalWrite(kvm_1.sw, LOW);
         digitalWrite(kvm_2.sw, LOW);
      }
      else //get 2 in sync with kvm 1
      {
         digitalWrite(kvm_2.sw, HIGH);
         delay(100);
         digitalWrite(kvm_2.sw, LOW);
      }
    }
    delay(100);
}

