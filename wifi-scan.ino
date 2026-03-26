#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>

// Credenciais da rede industrial
const char* ssid = "Galaxy A71A624";
const char* password = "12345678";
const int PINO_Verde = 18;
const int PINO_Vermelho = 19;

// URL de teste (SOMOSPlacaHandler é um serviço comum para testes de API)
const char* serverName = "https://jsonplaceholder.typicode.com/todos/1";

int tentativa = 0;
void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  pinMode(PINO_Verde, OUTPUT);
   pinMode(PINO_Vermelho, OUTPUT);
   
  Serial.print("Conectando ao Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
  
    delay(500);
    Serial.print(".");''
    if(tentativa > 5){
    digitalWrite(PINO_Vermelho, HIGH);
    digitalWrite(PINO_Verde, LOW);
    tentativa = 0;
    }
     
    tentativa ++;
  }
  if (WiFi.status() == WL_CONNECTED) {
  Serial.println("\nConectado!");
} else {
  Serial.println("\nFalha ao conectar!");
  digitalWrite(PINO_Vermelho, HIGH);
}

}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    // Cliente seguro
    WiFiClientSecure *client = new WiFiClientSecure;

    if (client) {
      // Em cenário real, você usaria client->setCACert(rootCACertificate);
      // Para este exemplo simples, vamos ignorar a validação do certificado:
      client->setInsecure();

      HTTPClient https;

      Serial.print("[HTTPS] Iniciando requisição...\n");

      if (https.begin(*client, serverName)) {

        // Realiza o GET
        int httpCode = https.GET();

        // httpCode será positivo se o servidor responder
        if (httpCode > 0) {
          Serial.printf("[HTTPS] Código de resposta: %d\n", httpCode);

          if (httpCode == HTTP_CODE_OK) {
            String payload = https.getString();
            Serial.println("Conteúdo recebido:");
            Serial.println(payload);
             digitalWrite(PINO_Verde, HIGH);
             digitalWrite(PINO_Vermelho, LOW);
          }

        } else {
          Serial.printf("[HTTPS] Falha na requisição, erro: %s\n", https.errorToString(httpCode).c_str());
          digitalWrite(PINO_Vermelho, HIGH);
			    digitalWrite(PINO_Verde, LOW);
        }

        https.end();
      } else {
        Serial.printf("[HTTPS] Não foi possível conectar ao servidor\n");
      }

      delete client; // Libera memória
    }
  }

  // Aguarda 10 segundos para a próxima leitura (evita sobrecarga no servidor)
  delay(10000);
}