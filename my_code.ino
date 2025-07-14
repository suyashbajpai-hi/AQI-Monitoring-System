#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <SoftwareSerial.h>

// **Pin Definitions**
#define DHTPIN 4          
#define DHTTYPE DHT11     
#define MQ135_PIN A0      
#define MQ2_PIN A1        
#define MQ7_PIN A2        
#define LED_PIN 8         
#define ESP_RX 2          
#define ESP_TX 3          

// **Initialize Sensors and Modules**
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
SoftwareSerial esp(ESP_RX, ESP_TX);  

// **WiFi and ThingSpeak Credentials**
const char* ssid = "M31";
const char* password = "suyashbajpai-hi";
String apiKey = "E7GLQRKQA8MRJWK9";

const int AQI_THRESHOLD = 100;  // Threshold to activate water sprinkler

void setup() {
    Serial.begin(115200);
    esp.begin(9600);

    dht.begin();
    lcd.init();
    lcd.backlight();
    
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW); 

    lcd.setCursor(0, 0);
    lcd.print("IIIT Sonepat");
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("CodersBase");
    delay(1000);
    
    connectWiFi();
}

void loop() {
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();
    
    if (isnan(temperature) || isnan(humidity)) {
        Serial.println("Failed to read from DHT sensor!");
        return;  
    }

    // **Simulate AQI Variation Between 50 to 164**
    int aqiValue = 107 + 57 * sin(millis() / 30000.0);  // Faster oscillation

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("AQI: "); 
    lcd.print(aqiValue);

    lcd.setCursor(10, 0);
    if (aqiValue > AQI_THRESHOLD) {
        digitalWrite(LED_PIN, HIGH);
        lcd.print("P : ON");
    } else {
        digitalWrite(LED_PIN, LOW);
        lcd.print("P : OFF");
    }

    lcd.setCursor(0, 1);
    lcd.print("T:");
    lcd.print(temperature, 1);
    lcd.write(223);
    lcd.print("C ");

    lcd.setCursor(8, 1);
    lcd.print(" H:");
    lcd.print(humidity, 1);
    lcd.print("%");

    sendDataToThingSpeak(aqiValue, temperature, humidity);
    delay(5000);  // Update AQI every 5 seconds
}

// **WiFi Connection Function**
void connectWiFi() {
    Serial.println("Connecting to WiFi...");
    esp.println("AT");
    delay(1000);
    esp.println("AT+CWMODE=1");
    delay(1000);
    esp.println("AT+CWJAP=\"" + String(ssid) + "\",\"" + String(password) + "\"");

    long timeout = millis() + 15000;
    while (millis() < timeout) {
        if (esp.find("WIFI CONNECTED")) {
            Serial.println("WiFi Connected!");
            return;
        }
    }
    Serial.println("WiFi Connection Failed!");
}

// **Send Data to ThingSpeak**
void sendDataToThingSpeak(int aqi, float temp, float hum) {
    Serial.println("Sending data to ThingSpeak...");
    
    String url = "GET /update?api_key=" + apiKey + "&field1=" + String(aqi) +
                 "&field2=" + String(temp, 1) + "&field3=" + String(hum, 1) + " HTTP/1.1\r\n" +
                 "Host: api.thingspeak.com\r\n" +
                 "Connection: close\r\n\r\n";

    esp.println("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80");
    delay(2000);
    esp.println("AT+CIPSEND=" + String(url.length()));
    delay(2000);
    esp.print(url);
    delay(2000);
    esp.println("AT+CIPCLOSE");

    Serial.println("Data sent to ThingSpeak!");
}