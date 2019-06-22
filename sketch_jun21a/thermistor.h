class Thermistor {
  private:
    byte _pin;
    double _BETA = 4500.0;
    double _roomTemp = 298.15;
    double _balanceResistance = 10000.0;
    double _calculateResistance(double sensorVal) {
      return this->_balanceResistance * (1023.0 / sensorVal - 1);
    }
    
  public:
    void setupPin(byte pin) {
      this->_pin = pin;
    }

    void setupBalanceResistance(float resistance) {
      this->_balanceResistance = resistance;
    }

    void setupRoomTemp(float roomTemp) {
      this->_roomTemp = roomTemp;
    }

    void setupBeta(float beta) {
       this->_BETA = beta;
    }
    double measureKelvin() {
      double sensorVal =  analogRead(this->_pin);
      double sensorResistance = this->_calculateResistance(sensorVal);
      double temperature = (this->_BETA * this->_roomTemp) / (this->_BETA + (this->_roomTemp * log(sensorResistance / this->_balanceResistance)));
      return temperature;
   }

   float measureFahrenheit() {
     float kelvins = this->measureKelvin();
     return (9.0 / 5) * (kelvins - 273.15) + 32;
   }

   float measureCelcium() {
    float kelvins = this->measureKelvin();
    return kelvins - 273.15;
   }
  
 };
