#include <ArduinoJson.h>

int led_y = 6;
int led_r = 7;
int led_g = 8;

int alarme = 9;

int led_rgb_b = 10;
int led_rgb_g = 11;
int led_rgb_r = 12;

float pressao_1;
float pressao_2;
float temperatura;
float batimentos;
bool alerta;


void setup() {
  for (int i = 6; i < 13; i++) {
    pinMode(i, OUTPUT);
  }

  Serial.begin(9600);
}

void loop() {
  digitalWrite(led_y, LOW);
  digitalWrite(led_r, LOW);
  digitalWrite(led_g, LOW);

  digitalWrite(led_rgb_b, LOW);
  digitalWrite(led_rgb_g, LOW);
  digitalWrite(led_rgb_r, LOW);

  alerta = false;

  if (Serial.available() > 0) {
    // Lê a entrada serial até encontrar uma nova linha
    String input = Serial.readStringUntil('\n');
    // Cria um buffer para armazenar o JSON
    const size_t capacity = JSON_OBJECT_SIZE(1) + JSON_OBJECT_SIZE(7) + 100;
    DynamicJsonDocument doc(capacity);
    // Deserializa o JSON
    DeserializationError error = deserializeJson(doc, input);
    //erro
    if (error) {
      Serial.print(F("Erro na deserialização: "));
      Serial.println(error.c_str());
      return;
    }

    pressao_1 = doc["Pressao_1"];
    pressao_2 = doc["Pressao_2"];
    temperatura = doc["Temperatura"];
    batimentos = doc["Batimentos"];


    if (pressao_1 <= 10 || pressao_1 >= 14) {
      digitalWrite(led_g, HIGH);
      alerta = true;
    }
    if (pressao_2 <= 6 || pressao_2 >= 9) {
      digitalWrite(led_g, HIGH);
      alerta = true;
    }
    if (temperatura <= 35 || temperatura >= 37) {
      digitalWrite(led_r, HIGH);
      alerta = true;
    }
    if (batimentos <= 50 || batimentos >= 90) {
      digitalWrite(led_y, HIGH);
      alerta = true;
    }

    if (alerta == true) {
      digitalWrite(led_rgb_r, HIGH);
      tone(alarme, 150, 1000);
      delay(1500);
    } else {
      digitalWrite(led_rgb_g, HIGH);
      tone(alarme, 150, 500);
      delay(1000);
    }


  } else {
    digitalWrite(led_rgb_b, HIGH);
    delay(1000);
  }
}
