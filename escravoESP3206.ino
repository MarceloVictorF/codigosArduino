// Marcelo Victor Ferreira Barbosa
// Engenharia de Controle e Automação
// IFES - Serra
// Esse trabalho tem o objetivo de simular uma rede CAN
// através da implementação de transmissores e do uso de ESP32 como mestre-escravo
// para fixação de conteúdo aprendido na discliplina de comunicação de dados
// no mês de junho de 2023.
// Código para uma ESP32 mestre se comunicar via protocolo CAN com outras ESP32
// Endereço 387 ou 001 1000 0011
// Inicializa as entradas a serem lidas, a saída é de 0 a 4095.
int CANH = 0;
int CANL = 0;

// Inicializa as tensões a serem lidas, a saída é de 0v a 3.3v.
float CANHV = 0;
float CANLV = 0;

// CAN_H e CAN_H são pinos usados para ler as tensões no barramento.
const int CAN_H = 15;
const int CAN_L = 13;

// CAN_H1 e CAN_H2 são pinos usados para gerar tensões de 1.65v e 3.3v sobre o CAN_H através do divisor de tensão da camada física.
const int CAN_H1 = 4;
const int CAN_H2 = 5;

// CAN_L1 e CAN_L2 são pinos usados para gerar tensões de 0v e 1.65v sobre o CAN_L através do divisor de tensão da camada física.
const int CAN_L1 = 0;
const int CAN_L2 = 2;

// E1 e E2 são pinos usados para determinar a menssagem que será enviada.
int E1 = 12;
int E2 = 34;

// Sincroniza é o pino usado para sincronização de envio e recepção da menssagem.
const int Sincroniza = 26;
const int SincronizaRecebe1 = 25;
const int SincronizaRecebe = 33;

// Incializa o estado da menssagem a ser enviada como 00.
int estadoE1 = 0;
int estadoE2 = 0;

// Incializa o estado do pino de sincronização em 0.
int estadoSincroniza = 0;
int estadoSincronizaRecebe = 0;
int estadoSincronizaRecebe1 = 0;

void setup() {
  // Inicializa o terminal serial.
  Serial.begin(9600);
  Serial.println("incio");
  // Indica que os pinos CAN_H e CAN_L serão usados como entrada.
  pinMode(CAN_H, INPUT);
  pinMode(CAN_L, INPUT);

  // Indica que os pinos CAN_H1 e CAN_H2 serão usados como saída.
  pinMode(CAN_H1, OUTPUT);
  pinMode(CAN_H2, OUTPUT);

  // Indica que os pinos CAN_L1 e CAN_L2 serão usados como saída.
  pinMode(CAN_L1, OUTPUT);
  pinMode(CAN_L2, OUTPUT);

  // Indica que os pinos E1 e E2 serão usados como entrada.
  pinMode(E1, INPUT);
  pinMode(E2, INPUT);

  // Indica que o pino Sincroniza será usado como entrada.
  pinMode(Sincroniza, INPUT);
  pinMode(SincronizaRecebe, INPUT);
  pinMode(SincronizaRecebe1, INPUT);
}

void loop() {
  // Lê o valor do estado de sincronização, caso o botão seja apertado o estadoSincroniza guardará valor alto.
  estadoSincroniza = digitalRead(Sincroniza);
  estadoSincronizaRecebe = digitalRead(SincronizaRecebe);
  estadoSincronizaRecebe1 = digitalRead(SincronizaRecebe1);
  // Lê os valores analógicos do barramento.
  CANH = analogRead(CAN_H);
  CANL = analogRead(CAN_L);
  // Representa os valores analógicos dos barramentos em tensão.
  CANHV = CANH*(3.3/4095);
  CANLV = CANL*(3.3/4095);
  // Se o botão de sincronização for pressionado, ou seja, estadoSincroniza for alto.
  if(estadoSincroniza == HIGH){
    Serial.println("O botão de sincronização foi pressionado.");
    // Lê os estados das portas do dip switch que pode ser 00, 01, 10 e 11. Para cada estado uma menssagem diferente será enviada. 
    estadoE1 = digitalRead(E1);
    estadoE2 = digitalRead(E2);
    Serial.print("E1: ");
    Serial.print(estadoE1);
    Serial.print(". E2: ");
    Serial.print(estadoE2);
    Serial.println(".");
    // Para mestre
    if((estadoE1 == LOW) && (estadoE2 == LOW)){
      Serial.println("Enviando MSG1.");
      // Start of Frame(SOF) tem que ser dominante.
      bitZero();
      // Identifier(ID == 00110000001)
      // Function code.
      bitZero();
      bitZero();
      bitUm();
      bitUm();
      // ID:
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitUm();
      // Remote Transmisson Request(RTR), como é dataframe deve ser dominante, ou seja, zero.
      //bitZero();
      // Data Field: MSG1
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();

      bitZero();
      bitUm();
      bitZero();
      bitZero();
      bitUm();
      bitUm();
      bitZero();
      bitUm();

      bitZero();
      bitUm();
      bitZero();
      bitUm();
      bitZero();
      bitZero();
      bitUm();
      bitUm();

      bitZero();
      bitUm();
      bitZero();
      bitZero();
      bitZero();
      bitUm();
      bitUm();
      bitUm();

      bitZero();
      bitZero();
      bitUm();
      bitUm();
      bitZero();
      bitZero();
      bitZero();
      bitUm();
      // End Of Frame(EOF) tem que ser recessivo.
      bitUm();
      bitUm();
      bitUm();
      bitUm();
      bitUm();
      bitUm();
      bitUm();
      Serial.println("MSG1 enviada.");
    }
    // Para mestre
    if((estadoE1 == HIGH) && (estadoE2 == LOW)){
      Serial.println("Enviando MSG2.");
      // Start of Frame(SOF) tem que ser dominante.
      bitZero();
      // Identifier(ID == 00110000010)
      // Function code.
      bitZero();
      bitZero();
      bitUm();
      bitUm();
      // ID:
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitUm();
      // Remote Transmisson Request(RTR), como é dataframe deve ser dominante, ou seja, zero.
      //bitZero();
      // Data Field: MSG2
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();

      bitZero();
      bitUm();
      bitZero();
      bitZero();
      bitUm();
      bitUm();
      bitZero();
      bitUm();

      bitZero();
      bitUm();
      bitZero();
      bitUm();
      bitZero();
      bitZero();
      bitUm();
      bitUm();

      bitZero();
      bitUm();
      bitZero();
      bitZero();
      bitZero();
      bitUm();
      bitUm();
      bitUm();

      bitZero();
      bitZero();
      bitUm();
      bitUm();
      bitZero();
      bitZero();
      bitUm();
      bitZero();
      // End Of Frame(EOF) tem que ser recessivo.
      bitUm();
      bitUm();
      bitUm();
      bitUm();
      bitUm();
      bitUm();
      bitUm();
      Serial.println("MSG2 enviada.");
    }
    // Para escravo
    if((estadoE1 == LOW) && (estadoE2 == HIGH)){
      Serial.println("Enviando MSG3.");
      // Start of Frame(SOF) tem que ser dominante.
      bitZero();
      // Identifier(ID == 00110000001)
      // Function code.
      bitZero();
      bitZero();
      bitUm();
      bitUm();
      // ID:
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitUm();
      bitZero();
      // Remote Transmisson Request(RTR), como é dataframe deve ser dominante, ou seja, zero.
      //bitZero();
      // Data Field: MSG3
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitUm();
      bitZero();
      bitZero();
      bitUm();
      bitUm();
      bitZero();
      bitUm();
      bitZero();
      bitUm();
      bitZero();
      bitUm();
      bitZero();
      bitZero();
      bitUm();
      bitUm();
      bitZero();
      bitUm();
      bitZero();
      bitZero();
      bitZero();
      bitUm();
      bitUm();
      bitUm();

      bitZero();
      bitZero();
      bitUm();
      bitUm();
      bitZero();
      bitZero();
      bitUm();
      bitUm();
      // End Of Frame(EOF) tem que ser recessivo.
      bitUm();
      bitUm();
      bitUm();
      bitUm();
      bitUm();
      bitUm();
      bitUm();
      Serial.println("MSG3 enviada.");
    }
    // Para escravo
    if((estadoE1 == HIGH) && (estadoE2 == HIGH)){
      Serial.println("Enviando MSG4.");
      // Start of Frame(SOF) tem que ser dominante.
      bitZero();
      // Identifier(ID == 00110000001)
      // Function code.
      bitZero();
      bitZero();
      bitUm();
      bitUm();
      // ID:
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitUm();
      bitZero();
      // Remote Transmisson Request(RTR), como é dataframe deve ser dominante, ou seja, zero.
      //bitZero();
      // Data Field: MSG4
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();

      bitZero();
      bitUm();
      bitZero();
      bitZero();
      bitUm();
      bitUm();
      bitZero();
      bitUm();

      bitZero();
      bitUm();
      bitZero();
      bitUm();
      bitZero();
      bitZero();
      bitUm();
      bitUm();

      bitZero();
      bitUm();
      bitZero();
      bitZero();
      bitZero();
      bitUm();
      bitUm();
      bitUm();

      bitZero();
      bitZero();
      bitUm();
      bitUm();
      bitZero();
      bitUm();
      bitZero();
      bitZero();
      // End Of Frame(EOF) tem que ser recessivo.
      bitUm();
      bitUm();
      bitUm();
      bitUm();
      bitUm();
      bitUm();
      bitUm();
      Serial.println("MSG4 enviada.");
    }
  }
  if(estadoSincronizaRecebe == HIGH || estadoSincronizaRecebe1 == HIGH) {
    // Se no barramento o bit for 0.
    if((CANHV>2.8) && (CANLV<0.5)) {
      Serial.println("Recebi uma menssagem.");
      delay(10);
      int i = 0;
      int id_msg[11];
      int msg[64];
      int id_msg_decimal = 0;
      int msg_decimal = 0;
      while(i<11) {
        delay(5);
        // Lê os valores analógicos do barramento.
        CANH = analogRead(CAN_H);
        CANL = analogRead(CAN_L);
        // Converte os valores analógicos dos barramentos em tensão.
        CANHV = CANH*(3.3/4095);
        CANLV = CANL*(3.3/4095);
        if((CANHV<2) && (CANLV>1)) {
          id_msg[i] = 1;
          id_msg_decimal = id_msg_decimal + pow(2, 10 - i);
        }
        if((CANHV>2.8) && (CANLV<0.5)) {
          id_msg[i] = 0;
        }
        delay(5);
        i = i+1;
      }
      if(id_msg_decimal == 387) {
        while(i<75) {
          delay(5);
          // Lê os valores analógicos do barramento.
          CANH = analogRead(CAN_H);
          CANL = analogRead(CAN_L);
          // Converte os valores analógicos dos barramentos em tensão.
          CANHV = CANH*(3.3/4095);
          CANLV = CANL*(3.3/4095);
          if((CANHV<2) && (CANLV>1)) {
            msg[i-11] = 1;
          }
          if((CANHV>2.8) && (CANLV<0.5)) {
            msg[i-11] = 0;
          }
          delay(5);
          i = i + 1;
        }
        Serial.print("Id da menssagem: "); 
        for (int j = 0; j < 11; j = j + 1) {
          Serial.print(id_msg[j]);
        }
        Serial.println("");
        Serial.print("Menssagem: "); 
        for (int j = 0; j < 64; j = j + 1) {
          Serial.print(msg[j]);
        }
      }
      else {
        delay(128000);
      }
    }
  }
}

void bitUm() {
  digitalWrite(CAN_H1, HIGH);
  digitalWrite(CAN_H2, LOW);
  digitalWrite(CAN_L1, HIGH);
  digitalWrite(CAN_L2, LOW);
  delay(8);
  digitalWrite(CAN_H1, LOW);
  digitalWrite(CAN_H2, LOW);
  digitalWrite(CAN_L1, LOW);
  digitalWrite(CAN_L2, LOW);
  delay(2);
}
void bitZero() {
  digitalWrite(CAN_H1, HIGH);
  digitalWrite(CAN_H2, HIGH);
  digitalWrite(CAN_L1, LOW);
  digitalWrite(CAN_L2, LOW);
  delay(8);
  digitalWrite(CAN_H1, LOW);
  digitalWrite(CAN_H2, LOW);
  digitalWrite(CAN_L1, LOW);
  digitalWrite(CAN_L2, LOW);
  delay(2);
}
